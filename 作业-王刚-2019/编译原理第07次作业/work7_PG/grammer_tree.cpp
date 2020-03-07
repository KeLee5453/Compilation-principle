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
		case COMP_STMT: {
			GrammerTreeNode *last = NULL;
			GrammerTreeNode *p = NULL;

			for (p = t->children[0]; p->node_type == DECL_NODE; p = p->sibling);
			p->label.begin_label = t->label.begin_label;
			for (; p; p = p->sibling) {
				last = p;
				RecursiveGetLabel(p);
			}

			t->label.next_label = last->label.next_label;
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;
			break;
		}
		case IF_STMT: {
			GrammerTreeNode *e = t->children[0];
			GrammerTreeNode *s1 = t->children[1];
			GrammerTreeNode *s2 = NULL;
			if (t->children.size() == 3)
				s2 = t->children[2];

			e->label.true_label = NewLabel();
			if (t->label.next_label == "") {
				t->label.next_label = NewLabel();
			}
			s1->label.next_label = t->label.next_label;

			if (s2) {
				e->label.false_label = NewLabel();
				s2->label.next_label = t->label.next_label;
			}
			else {
				e->label.false_label = t->label.next_label;
			}

			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;

			RecursiveGetLabel(e);
			RecursiveGetLabel(s1);
			if (s2)
				RecursiveGetLabel(s2);
			break;
		}
		case WHILE_STMT: {
			GrammerTreeNode *e = t->children[0];
			GrammerTreeNode *s = t->children[1];

			if (t->label.begin_label == "") {
				t->label.begin_label = NewLabel();
			}
			e->label.true_label = NewLabel();


			if (t->label.next_label == "") {
				t->label.next_label = NewLabel();
			}		
			e->label.false_label = t->label.next_label;

			if (t->sibling) {
				t->sibling->label.begin_label = t->label.next_label;
			}
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
	if (t->node_type == STMT_NODE) {
		switch (t->node_kind)
		{
		case COMP_STMT:
			for (int i = 0; i<t->children.size(); i++) {
				if (t->children[i]->label.begin_label != "")
					out << t->children[i]->label.begin_label << ":" << endl;
				RecursiveGenCode(out, t->children[i]);
			}
			break;
		case EXPR_STMT:
			for (int i = 0; i<t->children.size(); i++) {
				RecursiveGenCode(out, t->children[i]);
			}
			break;
		case IF_STMT:
			RecursiveGenCode(out, t->children[0]);
			out << t->children[0]->label.true_label << ":" << endl;
			RecursiveGenCode(out, t->children[1]);
			out << "\tjmp " << t->label.next_label << endl;
			if (t->children.size() == 3) {
				out << t->children[0]->label.false_label << ":" << endl;
				RecursiveGenCode(out, t->children[2]);
				out << "\tjmp " << t->label.next_label << endl;
			}
			if (t->sibling);
			else
				out << t->label.next_label << ":" << endl;
			break;
		case SWITCH_STMT:
			break;
		case WHILE_STMT:
			//out << t->label.begin_label << ":" << endl;
			RecursiveGenCode(out, t->children[0]);
			out << t->children[0]->label.true_label << ":" << endl;
			RecursiveGenCode(out, t->children[1]);
			out << "\tjmp " << t->label.begin_label << endl;
			break;
		case DO_WHILE_STMT:
			break;
		case FOR_STMT:
			RecursiveGenCode(out, t->children[0]);
			out << t->children[1]->label.begin_label << ":" << endl;
			RecursiveGenCode(out, t->children[1]);
			out << t->children[1]->label.true_label << ":" << endl;
			RecursiveGenCode(out, t->children[3]);
			RecursiveGenCode(out, t->children[2]);
			out << "\tjmp " << t->children[1]->label.begin_label << endl;
			break;
		case JUMP_STMT:
			break;
		case INPUT_STMT:
			out << "\tinvoke crt_scanf, SADD(\"%d\",0), addr ";
			out << "_" << symtbl.getName(t->children[0]->attr.symtbl_seq) << endl;
			break;
		case PRINT_STMT:
			out << "\tinvoke crt_printf, SADD(\"%d\",13,10),";
			out << "_" << symtbl.getName(t->children[0]->attr.symtbl_seq) << endl;
			break;
		default:
			break;
		}
	}
	else if (t->node_type == EXPR_NODE) {
		GrammerTreeNode *e1 = NULL;
		GrammerTreeNode *e2 = NULL;
		if (t->children.size() >= 1)
			e1 = t->children[0];
		if (t->children.size() >= 2)
			e2 = t->children[1];

		switch (t->attr.op)
		{
		case PLUS2:
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
		case MINUS2:
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
		case PLUS:
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
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

			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case MINUS:
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
		case TIMES:
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
		case OVER:
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

			out << "\tidiv ecx" << endl;
			out << "\tmov _t_" << t->temp_var << ",eax" << endl;
			break;
		case MOD:
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
		case LT:
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

			out << "\tjl " << t->label.true_label << endl;
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case LE:
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

			out << "\tjle " << t->label.true_label << endl;
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case GT:
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

			out << "\tjg " << t->label.true_label << endl;
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case GE:
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
		case EQ:
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

			out << "\tje " << t->label.true_label << endl;
			out << "\tjmp " << t->label.false_label << endl;
			break;
		case NE:
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
		case AND:
			RecursiveGenCode(out, e1);
			out << e1->label.true_label << ":" << endl;
			RecursiveGenCode(out, e2);
			break;
		case OR:
			RecursiveGenCode(out, e1);
			out << e1->label.false_label << ":" << endl;
			RecursiveGenCode(out, e2);
			break;
		case ASSIGN:
			if (t->label.begin_label != "") {
				out << t->label.begin_label << ":" << endl;
			}
			RecursiveGenCode(out, e1);
			RecursiveGenCode(out, e2);
			out << "\tmov eax,";
			if (e2->node_kind == ID_LEAF) {
				out << "_" << symtbl.getName(e2->attr.symtbl_seq);
			}
			else if (e2->node_kind == CONST_LEAF) {
				out <<e2->attr.vali;
			}
			else {
				out << "_t_" << e2->temp_var;
			}
			out << endl;

			out << "\tmov ";
			if (e1->node_kind == ID_LEAF) {
				if (symtbl.getType(e1->attr.symtbl_seq) == Char) 
				out << "byte ptr _" << symtbl.getName(e1->attr.symtbl_seq);
				else 
					out << "_" << symtbl.getName(e1->attr.symtbl_seq);
			}
			else {
				out << "_t_" << e1->temp_var;
			}
			out << ",eax" << endl;
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
