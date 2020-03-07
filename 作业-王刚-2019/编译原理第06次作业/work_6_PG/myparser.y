%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019?ê11??12è?
****************************************************************************/

#include "mylexer.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<unordered_map>
using namespace std;
#define MAX 4
enum NodeType//节点种类
{
	Stmt=0,
	Expr,
	Decl
};
enum Statement//语句种类
{
	If=0,
	While,
	For,
	Input,
	Output,
	Complex
};
enum Expression//表达式种类
{
	Op=0,//符号
	Const,//数字
	Idk,//ID
	Type//类型
};
enum Declaration//声明语句
{
	Var=0
};
enum ExpType//表达式类型
{
	Int=0,
	Char,
	Void,
	Bool
};

struct TreeNode//树的节点结构
{
	int lineno;//行数
	struct TreeNode* child[MAX];//孩子节点
	struct TreeNode* brother;//由于匹配的时候可以匹配出一整句话，故可以知道其兄弟节点，但是无法知道其父节点
	int nodetype;//节点类型
	int specifictype;//特定的类型
	ExpType type;//表达式类型
	int val;//值
};
int NUM=0;
int line=0;
TreeNode* root;
TreeNode* createNode(int nodetype,int specifictype)//创建节点函数
{
	TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
	for (int i = 0; i < MAX; ++i)
	{
		node->child[i]=NULL;
	}
	node->brother=NULL;
	node->nodetype=nodetype;
	node->specifictype=specifictype;
	node->lineno=line++;
	node->type=Void;
	return node;
}
struct idNameType
{
	string name;
	ExpType type;
};
extern idNameType ids[1000];
struct res
{
	int resLine;
	string resStr;
};
res checkRes[100];
int resKount=0;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%include{
  class mylexer;
 }
// parser name
%name myparser

// class definition
{
	// place any extra class members here
	void showCheckRes();
void typeError(struct TreeNode* t,string str);
void checkNode(struct TreeNode * t);
	void display(struct TreeNode*node);
	void shownode(struct TreeNode*node);
	void output1(string str);
	void outtype(struct TreeNode * t);
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE struct TreeNode*
#endif
}

// place any declarations here
%token IF MAIN FOR WHILE CIN COUT//关键字
%token INT CHAR VOID BOOL//数据类型
%token ID NUMBER CHARACTER
%token PLUS MINUS MUL DIV REMI DPLUS DMINUS//操作符
%token GT LT GE LE NEQ AND OR NOT ASSIGN//逻辑关系
%token LFP RFP COMMA SEMI LP RP LM RM//标点符号
//优先级
%left COMMA
%right ASSIGN
%left EQ NEQ 
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV REMI
%left DPLUS DMINUS
%left LP RP LSP RSP LFP RFP LM RM
%right ELSE

%%

/////////////////////////////////////////////////////////////////////////////
// rules section
start	:MAIN LP RP complex {$$=$4;root=$4;display(root);showCheckRes();}
		;
complex :LFP stmts RFP 		{$$=createNode(Stmt,Complex);$$->child[0]=$2;}
		;
stmts	:stmt stmts			{
							if($1!=NULL)
							{
							while($1->brother!=NULL)
							$1=$1->brother;
							$1->brother=$2;
							$$=$1;
							}
							else 
							$$=$2;
							}
		|stmt				{$$=$1;}
		;
stmt	:expr_stmt			{$$=$1;}
		|var_stmt			{$$=$1;}
		|if_stmt			{$$=$1;}
		|while_stmt			{$$=$1;}
		|for_stmt			{$$=$1;}
		|complex			{$$=$1;}
		|input_stmt			{$$=$1;}
		|output_stmt		{$$=$1;} 
		;
type_var	:INT			{$$=createNode(Expr,Type);$$->type=Int;}
			|CHAR			{$$=createNode(Expr,Type);$$->type=Char;}
			|BOOL			{$$=createNode(Expr,Type);$$->type=Bool;}
			|VOID			{$$=createNode(Expr,Type);$$->type=Void;}
			;
id_list		:id_expr COMMA id_list	{$$=$1;$$->brother=$3;}
			|id_expr 				{$$=$1;}
			;
id_expr		:ID ASSIGN expr	{$$=createNode(Expr,Op);$$->val=ASSIGN;$$->child[0]=$1;$$->child[1]=$3;}
			|ID				{$$=$1;}
			;
var_stmt	:type_var id_list SEMI	{$$=createNode(Decl,Var);$$->child[0]=$1;$$->child[1]=$2;}
			;
expr_stmt    :expr SEMI				   {$$=$1;}
             |SEMI						{$$=NULL;}
             ;
//赋值
expr         :expr ASSIGN expr         {$$=createNode(Expr,Op);$$->val=ASSIGN;$$->child[0]=$1;$$->child[1]=$3;}
			 |or_expr                  {$$=$1;}  
             ;
or_expr      :or_expr OR and_expr      {$$=createNode(Expr,Op);$$->val=OR;$$->child[0]=$1;$$->child[1]=$3;}
             |and_expr                 {$$=$1;}
             ;
and_expr     :and_expr AND eq_expr     {$$=createNode(Expr,Op);$$->val=AND;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr                  {$$=$1;}
             ;
/*>/</>=/<=*/
eq_expr      :eq_expr EQ simple_expr   {$$=createNode(Expr,Op);$$->val=EQ;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr GE simple_expr   {$$=createNode(Expr,Op);$$->val=GE;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr LE simple_expr   {$$=createNode(Expr,Op);$$->val=LE;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr GT simple_expr   {$$=createNode(Expr,Op);$$->val=GT;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr LT simple_expr   {$$=createNode(Expr,Op);$$->val=LT;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr NEQ simple_expr  {$$=createNode(Expr,Op);$$->val=NEQ;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr LM simple_expr   {$$=createNode(Expr,Op);$$->val=LM;$$->child[0]=$1;$$->child[1]=$3;}
             |eq_expr RM simple_expr   {$$=createNode(Expr,Op);$$->val=RM;$$->child[0]=$1;$$->child[1]=$3;}
             |simple_expr			   {$$=$1;}
             ;
/*+/-/*///++/--*/
simple_expr  :simple_expr PLUS term    {$$=createNode(Expr,Op);$$->val=PLUS;$$->child[0]=$1;$$->child[1]=$3;}
             |simple_expr MINUS term   {$$=createNode(Expr,Op);$$->val=MINUS;$$->child[0]=$1;$$->child[1]=$3;}
             |simple_expr MUL term     {$$=createNode(Expr,Op);$$->val=MUL;$$->child[0]=$1;$$->child[1]=$3;}
             |simple_expr DIV term     {$$=createNode(Expr,Op);$$->val=DIV;$$->child[0]=$1;$$->child[1]=$3;}
             |simple_expr REMI term    {$$=createNode(Expr,Op);$$->val=REMI;$$->child[0]=$1;$$->child[1]=$3;}
             |simple_expr DPLUS        {$$=createNode(Expr,Op);$$->val=DPLUS;$$->child[0]=$1;}
             |simple_expr DMINUS       {$$=createNode(Expr,Op);$$->val=DMINUS;$$->child[0]=$1;}
             |term					   {$$=$1;}
             ;
term         :LP expr RP               {$$=$2;}
			 |ID					   {$$=$1;}
			 |NUMBER				   {$$=$1;}
			 |CHARACTER					{$$=$1;}
			 |NOT term                 {$$=createNode(Expr,Op);$$->val=NOT;$$->child[0]=$2;}
			 ;
/*if语句说明*/
if_stmt      :IF LP expr RP stmt       {$$=createNode(Stmt,If);$$->child[0]=$3;$$->child[1]=$5;}
             |IF LP expr RP stmt ELSE stmt {$$=createNode(Stmt,If);$3->type=Bool;$$->child[0]=$3;$$->child[1]=$5;$$->child[2]=$7;}
             ;
/*for语句说明*/
for_stmt     :FOR LP expr SEMI expr SEMI expr RP stmt {$$=createNode(Stmt,For);$$->child[0]=$3;$$->child[1]=$5;$$->child[2]=$7;$$->child[3]=$9;}
	         |FOR LP SEMI expr SEMI expr RP stmt      {$$=createNode(Stmt,For);$$->child[1]=$4;$$->child[2]=$6;$$->child[3]=$8;}  
             |FOR LP expr SEMI SEMI expr RP stmt      {$$=createNode(Stmt,For);$$->child[0]=$3;$$->child[2]=$6;$$->child[3]=$8;}  
             |FOR LP expr SEMI expr SEMI RP stmt      {$$=createNode(Stmt,For);$$->child[0]=$3;$$->child[1]=$5;$$->child[3]=$8;}  
             |FOR LP SEMI SEMI expr RP stmt			  {$$=createNode(Stmt,For);$$->child[2]=$5;$$->child[3]=$7;} 
             |FOR LP SEMI expr SEMI RP stmt			  {$$=createNode(Stmt,For);$$->child[1]=$4;$$->child[3]=$7;}
             |FOR LP expr SEMI SEMI RP stmt			  {$$=createNode(Stmt,For);$$->child[0]=$3;$$->child[3]=$7;}
             |FOR LP SEMI SEMI RP stmt				  {$$=createNode(Stmt,For);$$->child[3]=$6;}
             ;
/*while语句说明*/
while_stmt   :WHILE LP expr RP stmt                   {$$=createNode(Stmt,While);$$->child[0]=$3;$$->child[1]=$5;}
             ;
/*input语句和output语句*/
input_stmt   :CIN RM term SEMI                              {$$=createNode(Stmt,Input);$$->child[0]=$3;}
             ; 
output_stmt  :COUT LM term SEMI							  {$$=createNode(Stmt,Output);$$->child[0]=$3;}
             ;               
// place your YACC rules here (there must be at least one)

Grammar
	: /* empty */
	;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section
void myparser::showCheckRes()
{
	cout<<"---------------------------------------------------"<<endl;
	for(int i=0;i<resKount;i++)
	{
		cout<<checkRes[i].resLine<<":"<<checkRes[i].resStr<<endl;
	}
}
void myparser::typeError(TreeNode* t,string str)
{
	checkRes[resKount].resLine=t->lineno;
	checkRes[resKount].resStr=str;
	resKount++;
}
void myparser::checkNode(TreeNode * t)
{ 
	if(t->nodetype==Expr)
	{
      switch (t->specifictype)
      { 
		case Op:
			if (t->val==ASSIGN)
			{
				//cout<<ids[t->child[0]->val].type<<endl;
				//cout<<t->child[1]->type<<endl<<endl;
				if(ids[t->child[0]->val].type==Void)
				{
					typeError(t,"未定义标识符"+ids[t->child[0]->val].name);
				}
				else if(ids[t->child[0]->val].type!=t->child[1]->type)
				{
					
					typeError(t,"赋值类型不符");
				}
				t->type=t->child[0]->type;
			}
			else if(t->val==AND||t->val==OR)
			{
				if((t->child[0]->type!=Bool&&t->child[0]->type!=Int&&t->child[0]->type!=Char)||
				(t->child[1]->type!=Bool&&t->child[1]->type!=Int&&t->child[1]->type!=Char)){
					typeError(t,"AND OR -- Operand is not Bool/Int/Char  ");
				}
				t->type=t->child[0]->type;
			}
			else if(t->val==NOT)
			{
				if((t->child[0]->type!=Bool&&t->child[0]->type!=Int&&t->child[0]->type!=Char))
					typeError(t,"NOT -- Operand is not Bool/Int/Char ");
				t->type=t->child[0]->type;
			}
			else if(t->val==PLUS||(t->val==MUL||t->val==REMI||t->val==DIV))
			{
				if((t->child[0]->type!=Int&&t->child[0]->type!=Char)||(t->child [1]->type!=Int&&t->child[1]->type!=Char))
					typeError(t,"PLUS MUL REMI DIV -- Operand is not Int/Char");
				if(t->child[0]->type!=t->child [1]->type )
					typeError(t,"Operand different type" );
					t->type=t->child[0]->type;
			}
			else if(t->val==MINUS)//减或负号
			{
				if(t->child[1]!=NULL)
				{  
					if((t->child[0]->type!=Int&&t->child[0]->type!=Char)||(t->child [1]->type!=Int&&t->child[1]->type!=Char))
						typeError(t,"MINUS -- Operand is not Int/Char ");
					if(t->child[0]->type !=t->child [1]->type )
						typeError(t,"Operand different type");
				}
				else 
				{
					if(t->child[0]->type!=Int&&t->child [0]->type!=Char)
						typeError(t,"MINUS -- Operand is not Int/Char ");
				}	
				t->type=t->child[0]->type;
			}
			else if(t->val==DPLUS||t->val ==DMINUS)
			{
				if(t->child[0]->type!=Int&&t->child[0]->type!=Char)
					typeError(t,"DPLUS DMINUS -- Operand is not Int/Char ");
				t->type=t->child[0]->type;
			}
			else if(t->val==EQ||t->val==GT||t->val==LT||t->val==GE||t->val==LE||t->val==NEQ)    //关系运算运算左右是integer或char
			{
				if((t->child[0]->type!=Int&&t->child[0]->type!=Char)||(t->child [1]->type!=Int&&t->child[1]->type!=Char))
					typeError(t,"关系运算符--Operand is not Int/Char");
				if(t->child[0]->type!=t->child [1]->type )
					typeError(t,"Operand different type");
				t->type=Bool;
			}	
          break;
		case Idk:
			if(ids[t->val].type!=Void)t->type=ids[t->val].type;
			break;
        default:
          break;
      }
	}
    else if(t->nodetype==Stmt)
	{
      switch (t->specifictype)
      { case If:
          if (t->child[0]->type != Bool)
            typeError(t->child[0],"IF --expr not Bool");
          break;
        case While:
          if (t->child[0]->type != Bool)
            typeError(t->child[0],"WHILE --expr not Bool");
          break;
        case For:
          if (t->child[0]!= NULL)
		  {
            if(t->child[0]->type!=Int)
				typeError(t->child[0],"FOR --child[0] is not Int");
		  }
		  if(t->child[1]!= NULL)
		  {
			if(t->child[1]->type!=Bool)
				typeError(t->child[1],"FOR --child[1] is not Bool");
	      }
		  if(t->child[2]!= NULL)
		  {
			if(t->child[2]->type!=Int)
				typeError(t->child[2],"FOR --child[2] is not Int");
		  }
		  break;
		case Output:
		{
			if(t->child[0]!=NULL)
			{
				if(t->child[0]->type==Bool)
				{
					typeError(t->child[0],"OUTPUT --expr should not be Bool");
				}
			}

		}
        default:
          break;
      }
    }
	else if(t->nodetype==Decl)//主要为了给声明语句中id的type赋值
	{
		if(t->specifictype==Var)
		{
			ExpType tp=t->child[0]->type;
			TreeNode* temp=t->child[1];
			if(temp->child[0]!=NULL)//此时idExpr
			{
				ids[temp->child[0]->val].type=tp;
			}
			else ids[temp->val].type=tp;
			while(temp->brother!=NULL)
			{
				if(temp->brother->child[0]!=NULL)//此时idExpr
				{
					ids[temp->brother->child[0]->val].type=tp;
				}
				else ids[temp->brother->val].type=tp;
				temp=temp->brother;
			}
		}
	}
}
int main(void)
{
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}
void myparser::display(struct TreeNode*node)
{
	for(int i=0;i<MAX;i++)
 	{
   		if(node->child[i]!=NULL)
     	display(node->child[i]);//递归直到叶节点
 	}
	checkNode(node);
 	shownode(node);
	
 	if(node->brother!=NULL)
 	{
   		display(node->brother);
 	}
 return;
}
void myparser::output1(string str)
{
	cout.setf(ios::left);
	cout<<setw(25)<<str;
	
}

void myparser::shownode(struct TreeNode*node)
{
	node->lineno=NUM++;
	cout<<node->lineno<<":";
	switch (node->nodetype)
	{
		case Stmt:
		{
			string names[6]={"If_statement,",  "While_statement," , "For_statement," ,"Input_statement,","Output_statement,","Complex_statement,"};
			output1(names[node->specifictype]);
			cout<<"			    ";
			break;
		}
		case Expr:
		{
			string names[4]={"Expr," , "Const Declaration,", "ID Declaration,","Type Specifier,"};
			string types[4]={"Int, ","Char","Void","Bool"};
			output1(names[node->specifictype]);
			switch (node->specifictype)
			{
				
				case Op:
				{
					switch (node->val)
					{
						case PLUS:
						{
							output1("op:+");
							
							break;
						}
						case MINUS:
    				    {
        		 	    	output1("op:-");
     	 	            	break;
    	 	            }
          				case MUL:
          		   	    {
            				output1("op:*");
            				break;
					    }
          				case DIV:
         				{
           					output1("op:/");
            				break;
          				}
          				case REMI:
          				{
            				output1("op:%");
            				break;
          				}
          				case DPLUS:
          				{
            				output1("op:++");
            				break;
          				}
          				case DMINUS:
          				{
            				output1("op:--");
            				break;
          				}
          				case LT:
          				{
              				output1("op:<");
              				break;
            			}
            			case GT:
            			{
              				output1("op:>");
              				break;
            			}
            			case LE:
          				{
            				output1("op:<=");
            				break;
          				}
          				case GE:
          				{
            				output1("op:>=");
            				break;
          				}
          				case EQ:
          				{
            				output1("op:==");
            				break;
          				}
           				case ASSIGN:
          				{
            				output1("op:=");
            				break;
          				}
          				case NEQ:
          				{
            				output1("op:!=");
            				break;
          				}
          				case LM:
          				{
            				output1("op:<<");
            				break;
          				}
           				case RM:
          				{
            				output1("op:>>");
            				break;
          				}
          				case NOT:
          				{
            				output1("op:!");
            				break;
          				}
          				case OR:
          				{
            				output1("op:||");
            				break;
          				}
          				case AND:
          				{
            				output1("op:&&");
            				break;
          				}
					}
					break;
				}
				case Const:
				{
					cout.setf(ios::left);
					cout<<setw(7)<<"value:"<<setw(18)<<node->val;
       			    break;
				}
				case Idk:
				{

					cout.setf(ios::left);
					cout<<setw(8)<<"symbol:"<<setw(17)<<ids[node->val].name;
          			break;
				}
				case Type:
				{
					cout.setf(ios::left);
					cout<<setw(25)<<types[node->type];
          			break;

				}
			}
			outtype(node);
			break;
		}
		case Decl:
		{
			string names[1]={"Var Declaration,"};
			cout.setf(ios::left);
       		cout<<setw(25)<<names[node->specifictype];
       		cout<<"			    ";
			   
       		break;
		}
	}
	
	cout<<"children:";
	for(int i=0;i<MAX;i++)
   {
     if(node->child[i]!=NULL)
     {
       cout<<node->child[i]->lineno<<" ";
       struct TreeNode*temp=node->child[i]->brother;
       while(temp!=NULL)
       {
        cout<<temp->lineno<<" ";
        temp=temp->brother; 
       }
     }
   }
   cout<<endl;
   return;
}
void myparser::outtype(struct TreeNode*node)
{
	ExpType tp=node->type;
	switch(tp)
	{
		case Int:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Int";
			break;
		}
		case Char:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Char";
			break;
		}
		case Void:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Void";
			break;
		}
		case Bool:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Bool";
			break;
		}
		default:
		break;
	}


}
