#include<iostream>
#include<string>

using namespace std;

#include "grammer_tree.h"
#include "symbol.h"
#include "../../../work7_PG/myparser.h"
#include "../../../work7_PG/mylexer.h"

extern int lineno;
extern symbol_table_type symtbl;

GrammerTree parse_tree;

int GrammerTree::node_seq = 0;
int GrammerTree::temp_var_seq = 0;
int GrammerTree::label_seq = 0;
int GrammerTree::temp_var_size = 0;

void GrammerTreeNode::output(void)
{
	cout.setf(ios::left);
	cout.width(2);
	cout << seq << ": ";

	//	依结点类型进行分支
	switch (node_type) {
	case STMT_NODE: {
		string names[] = { "Compound","Expression","If","Switch",
			"While","Do-While","For","Jump","Input","Print" };
		//cout.width(40);
		//	输出语句结点的具体语句类型
		cout << names[node_kind] + " statement,\t";
		break;
	}
	case EXPR_NODE: {
		string names[] = { "Primary expr","Postfix expr","Unary expr","Cast expr",
			"Op expr","Conditional expr","Expression" };
		string types[] = { "Notype","Integer","Char","Double" };
		string opnames[] = { "++", "--","+","-","*", "/", "%","<<",">>", "<", "<=", ">", ">=","==","!=",
			"&","^","|","&&","||","?",":","=",
			"+=","-=","*=","/=","%=",
			"(", ")", "{", "}",";",",","!" };

		//cout.width(20);
		cout << names[node_kind]<< ",\t";
		//cout.width(20);

		//	根据表达式的具体类型输出属性
		switch (node_kind) {
		case PRIMARY_EXPR: {
			cout << "Primary Expression" << "\t";
			break;
		}
		case POSTFIX_EXPR: {
			cout << "postfix op:" << opnames[attr.op - PLUS2] << "\t";
			break;
		}
		case UNARY_EXPR: {
			cout << "unary op:" << opnames[attr.op - PLUS2] << "\t";
			break;
		}
		case CAST_EXPR: {
			cout << "cast expression" << "\t";
			break;
		}
		case OP_EXPR: {
			cout << "op:" << opnames[attr.op - PLUS2]<<"\t";
			break;
		}
		case COND_EXPR: {
			cout << "conditional expression op: \"" << opnames[QMARK - PLUS2] << " " << opnames[COLON - PLUS2]<<"\"";
			break;
		}
		case EXPR_EXPR: {
			cout << "expression\t";
			break;
		}
		}//	end switch

		break;
	}
	case DECL_NODE: {
		string names[] = { "Var Declaration","Array Declaration","Declarator" };
		//cout.width(40);
		cout << names[node_kind] + ",\t";
		switch (node_kind) {
		case VAR_DECL: {
			break;
		}
		case ARRAY_DECL: {
			break;
		}
		case DECLARATOR: {
			if (children.size() == 2)
				cout << "op: =\t";
			else
				cout << "\t";
			break;
		}
		}
		
		break;
	}
	case LEAF_NODE: {
		cout << "Leaf node,\t";
		switch (node_kind)
		{
		case TYPE_LEAF: {
			string types[] = { "Notype","Integer","Char","Double" };
			cout << types[type] + ", ";
			break;
		}
		case CONST_LEAF: {
			switch (type) {
			case Notype: {
				cout << "No Type";
				break;
			}
			case Integer: {
				cout << "value: ";
				cout << attr.vali;
				//cout << ",";
				break;
			}
			case Char: {
				cout << "value: '";
				cout << attr.valc;
				//cout << "',";
				break;
			}
			case Double: {
				cout << "value: ";
				cout << (attr.vald);
				//cout << ",";
				break;
			}
			}//	end sub-switch
			cout << "\t";
			break;
		}
		case ID_LEAF: {
			cout << "symbol: " + symtbl.getName(attr.symtbl_seq);
			break;
		}
		}
		break;
	}
	}//	end switch

	cout << "\tChildren: ";
	for (int i = 0; i < children.size(); i++) {
		cout << children[i]->seq << " ";
	}

	cout << endl;
}

string GrammerTree::NewLabel(void)
{
	char tmp[20];
	sprintf(tmp, "@%d", label_seq);
	label_seq++;
	cout << "Create a new label: " << tmp << endl;
	return tmp;
}

void GrammerTree::RecursiveGetLabel(GrammerTreeNode * t)
{
	if (t->node_type == STMT_NODE) {
		switch (t->node_kind)
		{
		case COMP_STMT: {//复合语句
			GrammerTreeNode *last = NULL;
			GrammerTreeNode *p = NULL;

			for (p = t->children[0]; p->node_type == DECL_NODE; p = p->sibling);//找到声明语句
			p->label.begin_label = t->label.begin_label;//开始标签为复合语句的开始
			for (; p; p = p->sibling) {//给声明语句的兄弟节点打标签
				last = p;//找到复合语句的最后一条
				RecursiveGetLabel(p);//递归
			}

			t->label.next_label = last->label.next_label;//整个复合语句的下一个标签就等于最后一个语句的下一个标签
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;//如果复合语句有兄弟节点，则兄弟的开始是自己的下一个
			break;
		}
		case IF_STMT: {
			GrammerTreeNode *e = t->children[0];//if的判定调节
			GrammerTreeNode *s1 = t->children[1];//if的执行体
			GrammerTreeNode *s2 = NULL;//else的执行体
			if (t->children.size() == 3)
				s2 = t->children[2];

			e->label.true_label = NewLabel();//当条件为真时生成一个标签
			if (t->label.next_label == "") {
				t->label.next_label = NewLabel();//整个语句的下一个
			}
			s1->label.next_label = t->label.next_label;//第一个执行体执行完直接跳到IF结束

			if (s2) {
				e->label.false_label = NewLabel();//如果有else那么第一个错了就跳到ELSE
				s2->label.next_label = t->label.next_label;
			}
			else {
				e->label.false_label = t->label.next_label;//否则直接跳到最后
			}

			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;

			RecursiveGetLabel(e);//递归IF的孩子节点
			RecursiveGetLabel(s1);
			if (s2)
				RecursiveGetLabel(s2);
			break;
		}
		case WHILE_STMT: {
			GrammerTreeNode *e = t->children[0];
			GrammerTreeNode *s = t->children[1];

			if (t->label.begin_label == "") {
				t->label.begin_label = NewLabel();//while的开始标签
			}
			e->label.true_label = NewLabel();//判断条件为真的标签也就是执行体


			if (t->label.next_label == "") {
				t->label.next_label = NewLabel();//while的结束
			}		
			e->label.false_label = t->label.next_label;

			if (t->sibling) {
				t->sibling->label.begin_label = t->label.next_label;
			}
			//递归孩子
			RecursiveGetLabel(e);
			RecursiveGetLabel(s);
			break;
		}
		case FOR_STMT: {
			GrammerTreeNode *e1 = t->children[0];
			GrammerTreeNode *e2 = t->children[1];
			GrammerTreeNode *e3 = t->children[2];
			GrammerTreeNode *s = t->children[3];

			if (t->label.begin_label == "") {
				t->label.begin_label = NewLabel();
			}

			if (t->label.next_label == "") {
				t->label.next_label = NewLabel();
			}

			e2->label.begin_label = NewLabel();
			e2->label.true_label = NewLabel();
			e2->label.false_label = t->label.next_label;

			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;

			RecursiveGetLabel(e1);
			RecursiveGetLabel(e2);
			RecursiveGetLabel(e3);
			RecursiveGetLabel(s);
			break;
		}
		default:
			break;
		}
	}
	else if (t->node_type == EXPR_NODE) {
		GrammerTreeNode *e1 = NULL;
		GrammerTreeNode *e2 = NULL;
		if (t->children.size() >= 1) {
			e1 = t->children[0];
		}
		if (t->children.size() >= 2) {
			e2 = t->children[1];
		}
		switch (t->attr.op)
		{
		case AND:
			e1->label.true_label = NewLabel();
			e2->label.true_label = t->label.true_label;
			e1->label.false_label = e2->label.false_label = t->label.false_label;
			RecursiveGetLabel(e1);
			RecursiveGetLabel(e2);
			break;
		case OR:
			e1->label.false_label = NewLabel();
			e2->label.false_label = t->label.false_label;
			e1->label.true_label = e2->label.true_label = t->label.true_label;
			RecursiveGetLabel(e1);
			RecursiveGetLabel(e2);
			break;
		case NOT:
			e1->label.true_label = t->label.false_label;
			e1->label.false_label = t->label.true_label;
			RecursiveGetLabel(e1);
			break;

		default:
			break;
		}
	}
	else {
		return;
	}
}

void GrammerTree::GenerateHeader(ostream & out)
{
	out << "\t.586" << endl;
	out << "\t.model flat, stdcall" << endl;
	out << "\toption casemap : none" << endl;
	out << endl;
	out << "\tinclude \\masm32\\macros\\macros.asm" << endl;
	out << endl;
	out << "\tinclude    \\masm32\\include\\msvcrt.inc" << endl;
	out << "\tincludelib \\masm32\\lib\\msvcrt.lib" << endl;

	out << endl;
	out << "\tmain PROTO" << endl;
	out << "\tWaitKeyCrt PROTO" << endl;
}

void GrammerTree::GenerateDecl(ostream & out)
{
	out << endl << endl << "\t.data" << endl;
	for (int i = 0; i < symtbl.symbol_table.size(); i++) {
		if (symtbl.symbol_table[i].type == Integer) {
			out << "\t\t_" << symtbl.getName(i) << " DWORD ?" << endl;
		}
		else if(symtbl.symbol_table[i].type == Char){
			out << "\t\t_" << symtbl.getName(i) << " BYTE ?" << endl;
		}
	}

	for (int i = 0; i < temp_var_size; i++) {
		out << "\t\t_t_" << i << " DWORD ?" << endl;
	}

	out << "\t\tnewline BYTE 13, 10, 0" << endl;
}

void GrammerTree::RecursiveGenCode(ostream & out, GrammerTreeNode * t)
{
	if (t->node_type == STMT_NODE) {//语句代码生成
		switch (t->node_kind)
		{
		case COMP_STMT:
			for (int i = 0; i<t->children.size(); i++) {
				if (t->children[i]->label.begin_label != "")
					out << t->children[i]->label.begin_label << ":" << endl;//首先输出开始
				RecursiveGenCode(out, t->children[i]);//递归孩子
			}
			break;
		case EXPR_STMT:
			for (int i = 0; i<t->children.size(); i++) {
				RecursiveGenCode(out, t->children[i]);//递归孩子
			}
			break;
		case IF_STMT:
			RecursiveGenCode(out, t->children[0]);//先生成判定语句的
			out << t->children[0]->label.true_label << ":" << endl;//当为真时，生成执行体的
			RecursiveGenCode(out, t->children[1]);
			out << "\tjmp " << t->label.next_label << endl;//执行完毕跳到下一个语句
			if (t->children.size() == 3) {
				out << t->children[0]->label.false_label << ":" << endl;//有else的话就是当判定语句为假时的标号
				RecursiveGenCode(out, t->children[2]);
				out << "\tjmp " << t->label.next_label << endl;
			}
			if (t->sibling);
			else
				out << t->label.next_label << ":" << endl;//生成兄弟的标号
			break;
		case SWITCH_STMT:
			break;
		case WHILE_STMT:
			RecursiveGenCode(out, t->children[0]);//生成判定条件
			out << t->children[0]->label.true_label << ":" << endl;
			RecursiveGenCode(out, t->children[1]);//生成执行体
			out << "\tjmp " << t->label.begin_label << endl;//跳到循环开始
			break;
		case DO_WHILE_STMT:
			break;
		case FOR_STMT:
			RecursiveGenCode(out, t->children[0]);//递归第一个分号前的第一个孩子
			out << t->children[1]->label.begin_label << ":" << endl;//判定条件的 开始
			RecursiveGenCode(out, t->children[1]);
			out << t->children[1]->label.true_label << ":" << endl;//执行体
			RecursiveGenCode(out, t->children[3]);
			RecursiveGenCode(out, t->children[2]);//控制变量的变化
			out << "\tjmp " << t->children[1]->label.begin_label << endl;//跳到判定条件
			break;
		case JUMP_STMT:
			break;
		case INPUT_STMT:
			if (symtbl.getType(t->children[0]->attr.symtbl_seq) != Char)
			{
				out << "\tinvoke crt_scanf, SADD(\"%d\",0), addr ";
				out << "_" << symtbl.getName(t->children[0]->attr.symtbl_seq) << endl;
			}
			else
			{
				out << "\tinvoke crt_scanf, SADD(\"%c\",0), addr ";
				out << "_" << symtbl.getName(t->children[0]->attr.symtbl_seq) << endl;
			}
			break;
		case PRINT_STMT:

			
			if (symtbl.getType(t->children[0]->attr.symtbl_seq) != Char)
			{
				out << "\tinvoke crt_printf, SADD(\"%d\",13,10), ";
				out << "_" << symtbl.getName(t->children[0]->attr.symtbl_seq) << endl;
			}
			else
			{
				out << "\tinvoke crt_printf, addr ";
				out << "_" << symtbl.getName(t->children[0]->attr.symtbl_seq) << endl;
				out<< "\tinvoke crt_printf, OFFSET newline"<<endl;

			}
			break;

			break;
		default:
			break;
		}
	}
	else if (t->node_type == EXPR_NODE) {//表达式
		GrammerTreeNode *e1 = NULL;
		GrammerTreeNode *e2 = NULL;
		if (t->children.size() >= 1)
			e1 = t->children[0];
		if (t->children.size() >= 2)
			e2 = t->children[1];

		switch (t->attr.op)
		{
		case PLUS2://++
			RecursiveGenCode(out, e1);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tadd eax,1" << endl;
			out << "\tmov ";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out<< ",eax" << endl;
			break;
		case MINUS2://--
			RecursiveGenCode(out, e1);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tsub eax,1" << endl;
			out << "\tmov ";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << ",eax" << endl;
			break;
		case PLUS://+
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			//看运算对象的类型，移动到寄存器
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if(e1->node_kind==CONST_LEAF){
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;
			//与第二个运算对象相加
			out << "\tadd eax,";
			if (e2->node_kind==ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind==CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;
			//把结果保存在节点的临时变量里
			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case MINUS://-
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tsub eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case TIMES://*
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\timul eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case OVER:///
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;
			out << "\tcdq" << endl;
			//它实际的作用只是把EDX的所有位都设成EAX最高位的值。扩展
			out << "\tmov ecx,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;
			//这里idiv ecx 意思就是eax除以ecx，商放在eax中，余数放在edx中。
			out << "\tidiv ecx" << endl;
			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case MOD://模
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;
			out << "\tcdq" << endl;

			out << "\tmov ecx,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;
			//只要商
			out << "\tidiv ecx" << endl;
			out << "\tmov _t_" << t->temp_var << ",edx" << endl;
			break;
		case LSHIFT:
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tmov ecx,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;
			//移位
			out << "\tshl eax,cl" << endl;
			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case RSHIFT:
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tmov ecx,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;
			out << "\tshr eax,cl" << endl;
			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case LT://小于
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tcmp eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tjl " << t->label.true_label << endl;//小于就跳到真
			out << "\tjmp " << t->label.false_label << endl;//否则跳到假
			break;
		case LE://小于等于
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tcmp eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tjle " << t->label.true_label << endl;//小于等于
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case GT://大于
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tcmp eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tjg " << t->label.true_label << endl;//大于跳到真
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case GE://大于等于
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tcmp eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tjge " << t->label.true_label << endl;
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case EQ://判断相等
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tcmp eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tje " << t->label.true_label << endl;//相等跳转
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case NE://不等
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tcmp eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tjne " << t->label.true_label << endl;
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case BIT_AND:
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tand eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case BIT_XOR:
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\txor eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case BIT_OR:
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e1->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else if (e1->node_kind == CONST_LEAF) {
				out << e1->attr.vali;
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << endl;

			out << "\tor eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out << e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case AND://与
			RecursiveGenCode(out, e1);
			out << e1->label.true_label << ":" << endl;//当第一个孩子为真时看第二个孩子
			RecursiveGenCode(out, e2);
			break;
		case OR:
			RecursiveGenCode(out, e1);
			out << e1->label.false_label << ":" << endl;//当第一个孩子为假时看第二个孩子
			RecursiveGenCode(out, e2);
			break;
		case ASSIGN://赋值
			if (t->label.begin_label != "") {
				out << t->label.begin_label << ":" << endl;//如果有输出开始标号
			}
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			//把第二个孩子放入寄存器
			if (symtbl.getType(e1->attr.symtbl_seq) == Char)
				out << "\tmov al,";
			else out << "\tmov eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				if (symtbl.getType(e1->attr.symtbl_seq) == Char)
					out <<"\'"<< e2->attr.valc<<"\'";
				else out <<e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;
			//把右值赋给
			out << "\tmov ";
			if (e1->node_kind == ID_LEAF) {
					out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			if (symtbl.getType(e1->attr.symtbl_seq) == Char)
				out << ",al" << endl;
			else out << ",eax" << endl;
			break;
		case PLUSA:
			break;
		case MINUSA:
			break;
		case TIMESA:
			break;
		case OVERA:
			break;
		case MODA:
			break;
		case NOT:
			RecursiveGenCode(out, e1);
			break;
		default:
			break;
		}
	}
	else {
		return;
	}
}

void GrammerTree::GenerateWaitKey(ostream & out)
{
	out << "WaitKeyCrt PROC" << endl;
	out << "\tinvoke crt_printf, SADD(13,10,\"Press any key to continue...\")" << endl;
	out << "\tinvoke crt__getch" << endl;
	out << "\t.if (eax == 0) || (eax == 0E0h)" << endl;
	out << "\t\tinvoke crt__getch" << endl;
	out << "\t.endif" << endl;
	out << "\tinvoke crt_printf, OFFSET newline" << endl;
	out << "\tret" << endl;
	out << "WaitKeyCrt ENDP" << endl;
}

GrammerTreeNode * GrammerTree::MakeNode(int node_type, int node_kind,
	NodeAttr attr, int type)
{
	GrammerTreeNode * new_node = new GrammerTreeNode;

	if (new_node == NULL) {
		cerr << "Out of memory at line " << lineno << endl;
	}
	else {
		new_node->node_type = node_type;
		new_node->node_kind = node_kind;
		new_node->attr = attr;
		new_node->type = type;
		//new_node->id_name = id_name;
		new_node->lineno = lineno;
		new_node->seq = GrammerTree::node_seq++;
		new_node->sibling = NULL;

		//	将根节点更新为当前节点
		root = new_node;

		//new_node->output();
#if 0
		cout << new_node->seq << ": ";
		string names[] = { "Type Specifier", "Expr", "Not Expr", "Array", "Const Declaration", "ID Declaration" };
		string types[] = { "Notype", "integer", "boolean", "char" };
		cout << names[node_kind] << ", " << types[type] << ", ";

		cout << "children: ";
		for (int i = 0; i < (new_node->children).size(); i++) {
			cout << (new_node->children)[i]->seq << " ";
		}
		cout << endl;
#endif
	}
	return new_node;
}

void GrammerTree::TypeCheck(GrammerTreeNode * t)
{
	cout << "Enter TypeCheck proc." << endl;
	return;
}

void GrammerTree::GetTempVar(GrammerTreeNode * t)
{
	if (t->node_type != EXPR_NODE) {
		return;
	}
	//表达式里面的++，--，+，-，*，/，%，>>,<<按位与，按位或，按位异或
	//+=，-=，*=，/=，%=就需要分配临时变量
	if (((t->attr.op) >= PLUS2) && ((t->attr.op) <= RSHIFT)
		|| ((t->attr.op) >= BIT_AND) && ((t->attr.op) <= BIT_OR)
		|| ((t->attr.op) >= PLUSA) && ((t->attr.op) <= MODA)) 
	{
		
		GrammerTreeNode *arg1 = NULL;
		GrammerTreeNode *arg2 = NULL;

		if (t->children.size() >= 1)
			arg1 = t->children[0];
		if (t->children.size() >= 2)
			arg2 = t->children[1];
		//作为运算对象就-1
		if (arg1 && arg1->node_kind == OP_EXPR) {
			temp_var_seq--;
		}
		if (arg2 && arg2->node_kind == OP_EXPR) {
			temp_var_seq--;
		}
		t->temp_var = temp_var_seq;
		temp_var_seq++;
		if (temp_var_seq >= temp_var_size)
			temp_var_size = temp_var_seq;
	}
	else {
		return;
	}
}

void GrammerTree::GetLabelProc(void)
{
	GrammerTreeNode *p = root;
	RecursiveGetLabel(p);
}

void GrammerTree::GenerateCodeProc(ostream & out)
{
	GenerateHeader(out);
	GenerateDecl(out);

	out << endl << endl << "\t.code" << endl;
	out << "start:" << endl<<endl;
	out << "\tinvoke main" << endl;
	out << "\tinvoke WaitKeyCrt" << endl;
	out << "\tinvoke crt__exit, 0" << endl << endl;
	out << "main PROC" << endl;

	RecursiveGenCode(out, root);

	if (root->label.next_label != "")
		out << root->label.next_label << ":" << endl;
	out << "\tret" << endl;
	out << "main ENDP" << endl << endl;
	GenerateWaitKey(out);
	out << endl << "END start" << endl;
}
