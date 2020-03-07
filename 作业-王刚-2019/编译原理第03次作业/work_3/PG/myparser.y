%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年10月16日
****************************************************************************/

#include "mylexer.h"
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;
string ch;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name expr

// class definition
{
	// place any extra class members here
	virtual int yygettoken();

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
#define YYSTYPE string
#endif
}

//%token NUMBER 
//运算符
%token AND MIN MUL DIV
//数
//%token ZERO ONE TWO THREE FORE FIVE SIX SEVEN EIGHT NINE
//括号
%token BL BR
//符号串
%token STR

%left AND MIN
%left MUL DIV
%left BL BR
%right UMINUS 
 
// place any declarations here

%%
lines	:	lines expr ';'	{ cout << $2 << endl; }
	|	lines ';'
	|
	;

expr	:	expr AND expr	{ $$ = $1 + ' '+ $3+ " +"; }
	|	expr MIN expr	{ $$ = $1 + ' '+ $3+ " -"; }
	|	expr MUL expr	{ $$ = $1 + ' '+ $3+ " *"; }
	|	expr DIV expr	{ $$ = $1 + ' '+ $3+ " /"; }
	|	BL expr BR	{ $$ = $2; }
	|	MIN expr %prec UMINUS	{ $$ = '-'+$2; }
	|	STR {$$=ch;}
	;



/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)


%%

////////////////////////dx/////////////////////////////////////////////////////
// programs section

int YYPARSERNAME::yygettoken()
{
	char c;
	c=getchar();
	while(c == ' ' || c == '\n' || c == '\t')
		c = getchar();
	
	switch(c){
	case '+': return AND;
	case '-':return MIN;
	case '*':return MUL;
	case '/':return DIV;
	case '(':return BL;
	case ')' :return BR ;
	case ';':
		return c;
	default: 
		ch="";
		while((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||(c=='_'))
		{
			ch=ch+c;c=getchar();
		}
		
		ungetc(c,stdin);
		return STR;
		
		
			} 
	// place your token retrieving code here
	
}

int main(void)
{
	int n = 1;
	expr parser;
	if (parser.yycreate()) {
		n = parser.yyparse();
	}
	return n;
}


