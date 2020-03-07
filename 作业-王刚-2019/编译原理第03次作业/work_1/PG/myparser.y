%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年10月16日
****************************************************************************/

#include "mylexer.h"
#include <iostream>
#include <cctype>
using namespace std;

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
#define YYSTYPE double
#endif
}

//%token NUMBER 
//运算符
%token AND MIN MUL DIV
//数
%token ZERO ONE TWO THREE FORE FIVE SIX SEVEN EIGHT NINE
//括号
%token BL BR

%left AND MIN
%left MUL DIV
%left BL BR
%right UMINUS 
 
// place any declarations here

%%
lines	:	lines expr '\n'	{ cout << $2 << endl; }
	|	lines '\n'
	|
	;

expr	:	expr AND expr	{ $$ = $1 + $3; }
	|	expr MIN expr	{ $$ = $1 - $3; }
	|	expr MUL expr	{ $$ = $1 * $3; }
	|	expr DIV expr	{ $$ = $1 / $3; }
	|	BL expr BR	{ $$ = $2; }
	|	MIN expr %prec UMINUS	{ $$ = -$2; }
	|	NUMBER
	;

NUMBER	:	ZERO			{ $$ = 0.0; }
	|	ONE				{ $$ = 1.0; }
	|	TWO				{ $$ = 2.0; }
	|	THREE				{ $$ = 3.0; }
	|	FORE				{ $$ = 4.0; }
	|	FIVE				{ $$ = 5.0; }
	|	SIX				{ $$ = 6.0; }
	|	SEVEN				{ $$ = 7.0; }
	|	EIGHT				{ $$ = 8.0; }
	|	NINE				{ $$ = 9.0; }
	;


/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)


%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int YYPARSERNAME::yygettoken()
{
	char c;
	c=getchar();
	switch(c){
	case '+': return AND;
		break;
	case '-':return MIN;
		break;
	case '*':return MUL;
		break;
	case '/':return DIV;
		break;
	case '(':return BL;
	    break;
	case ')' :return BR ;
		break;
	case '0' :return ZERO ;
		break;
	case '1' :return ONE ;
		break;
	case '2' :return TWO ;
		break;
	case '3' :return THREE ;
		break;
	case  '4':return FORE ;
		break;
	case '5' :return FIVE ;
		break;
	case '6' :return SIX ;
		break;
	case '7' :return SEVEN ;
		break;
	case '8' :return EIGHT ;
		break;
	case '9' :return NINE ;
		break;
	default: return c;
		break;
		
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


