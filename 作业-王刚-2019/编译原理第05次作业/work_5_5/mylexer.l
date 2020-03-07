%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019??11??12??
****************************************************************************/

#include "myparser.h"
#include<unordered_map>
#include<iostream>
#include<string>
#include<iomanip>
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
	Void
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
extern YYSTYPE yylval;
extern int line;
unordered_map<string,int> ids;
int idcount =0;
int lines_num=0;

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
public:
int getId(string);
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}


newline     \n
whitespace  [ \t]+
digit [0-9]
letter_	[A-Za-z_]
id	{letter_}({letter_}|{digit})*
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
comment	("/*"([^*"]*|".*"|\*+[^/])*\**"*/")|("//".*\n)
// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}
{newline}       {lines_num++;}
{whitespace}    {/* skip whitespace */}
{comment}		{/* skip whitespace */}
","				        {return COMMA;}
";"					    {return SEMI;}
"("					    {return LP;}
")"					    {return RP;}
"{"					    {return LFP;}
"}"					    {return RFP;}
"["					    {return LSP;}//数组时候使用
"]"				     	{return RSP;}
/*关键字*/
"if"					{return IF;}
"else"					{return ELSE;}
"while"					{return WHILE;}
"for"					{return FOR;}
"cin"					{return CIN;}
"cout"					{return COUT;}
"void"					{return VOID;}
"int"					{return INT;}
"char"					{return CHAR;}
"bool"					{return BOOL;}
"="				    	{return ASSIGN;}
"main"                  {return MAIN;}
/*操作符*/
"+"				    	{return PLUS;}
"-"				    	{return MINUS;}
"*"				    	{return MUL;}
"/"				    	{return DIV;}
"%"				    	{return REMI;}
"++"				    {return DPLUS;}
"--"				   	{return DMINUS;}
"=="				   	{return EQ;}
/*逻辑运算符*/
">"				    	{return GT;}
"<"				    	{return LT;}
">="				   	{return GE;}
"<="				    {return LE;}
"!="				   	{return NEQ;}
"&&"				   	{return AND;}
"||"				   	{return OR;}
"!"				    	{return NOT;}
"<<"                    {return LM;}
">>"                    {return RM;}

{number}		{
					struct TreeNode *node = (struct TreeNode*)malloc (sizeof(struct TreeNode));
					for(int i=0;i<MAX;i++)
                    {
                        node->child[i]=NULL;
                    }
					node->brother=NULL;
					node->nodetype=Expr;
					node->specifictype=Const;
					node->val=atoi(yytext);					
					node->type=Int;
					node->lineno=line++;
					yylval = node;
					return NUMBER;
				}

{id}			{
					struct TreeNode *node = (struct TreeNode*)malloc (sizeof(struct TreeNode));
					for(int i=0;i<MAX;i++)
                    {
                        node->child[i]=NULL;
                    }
					node->brother=NULL;
					node->nodetype=Expr;
					node->specifictype=Idk;	
					node->val=getId(yytext);
					node->type=Void;
					node->lineno=line++;
					yylval = node;
					return ID;
				}
// place your Lex rules here

%%
int mylexer::getId(string word)
{
	if(ids.find(yytext)==ids.end())
	{
		ids[yytext]=idcount;
		idcount++;
		return idcount-1;
	}
	return ids[yytext];
}
/////////////////////////////////////////////////////////////////////////////
// programs section

