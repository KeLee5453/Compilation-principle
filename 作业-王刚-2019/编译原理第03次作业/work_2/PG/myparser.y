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
lines	:	lines expr ';'	{ cout << $2 << endl; }
	|	lines ';'
	|
	;

expr	:	expr AND expr	{ $$ = $1 + $3; }
	|	expr MIN expr	{ $$ = $1 - $3; }
	|	expr MUL expr	{ $$ = $1 * $3; }
	|	expr DIV expr	{ $$ = $1 / $3; }
	|	BL expr BR	{ $$ = $2; }
	|	MIN expr %prec UMINUS	{ $$ = -$2; }
	|	DIGIT {$$=$1;}
	;
DIGIT :NUMBER {$$=$1;}
	|DIGIT NUMBER {$$=$1*10+$2;}
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

////////////////////////dx/////////////////////////////////////////////////////
// programs section

int YYPARSERNAME::yygettoken()
{
	char c;
	c=getchar();
	while(c == ' ' || c == '\n' || c == '\t' )
		c = getchar();
	switch(c){
	case '+': return AND;
	case '-':return MIN;
	case '*':return MUL;
	case '/':return DIV;
	case '(':return BL;
	case ')' :return BR ;
	case '0' :return ZERO ;
	case '1' :return ONE ;
	case '2' :return TWO ;
	case '3' :return THREE ;
	case  '4':return FORE ;
	case '5' :return FIVE ;
	case '6' :return SIX ;
	case '7' :return SEVEN ;
	case '8' :return EIGHT ;
	case '9' :return NINE ;
	default: return c;		
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


