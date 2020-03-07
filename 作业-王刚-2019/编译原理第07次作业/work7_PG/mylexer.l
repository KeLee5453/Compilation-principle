%{
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

#include "myparser.h"
#include "symbol.h"
#include "grammer_tree.h"

//#define LEX_DEBUG

extern symbol_table_type symtbl;
extern int cur_scope;

GrammerTreeNode transmitter;

int lineno=1;

static void print_token(int token,char *lexeme,int attr=0);
static void print_double(int token,char *lexeme,double attr);

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
letter	[A-Za-z]
_letter	[_A-Za-z]
digit	[0-9]
id {_letter}({_letter}|{digit})*
double_num	{digit}+\.{digit}+
int_num ([1-9]+[0-9]*)|([1-9])|0
constchar	\'.\'
newline     \n
whitespace	[ \t]+

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
{whitespace} {/* do nothing */}

/*通常动作会将控制返回给语法分析器。
  词法分析器只向语法分析器返回一个值，即词法单元名*/
"int"       {print_token(INT, yytext); return INT;}
"char"       {print_token(CHAR, yytext); return CHAR;}
"double"       {print_token(DOUBLE, yytext); return DOUBLE;}

"input"		{print_token(INPUT,yytext);return INPUT;}
"print"		{print_token(PRINT,yytext);return PRINT;}

"main"        {print_token(MAIN, yytext); return MAIN;}
"if"        {print_token(IF, yytext); return IF;}
"else"        {print_token(ELSE, yytext); return ELSE;}

for		{print_token(FOR, yytext); return FOR;}
while	{print_token(WHILE, yytext); return WHILE;}
do		{print_token(DO, yytext); return DO;}

switch	{print_token(SWITCH, yytext); return SWITCH;}
case	{print_token(CASE, yytext); return CASE;}
default	{print_token(DEFAULT, yytext); return DEFAULT;}

break	{print_token(BREAK, yytext); return BREAK;}
continue	{print_token(CONTINUE, yytext); return CONTINUE;}

{id}		{int offset;
			offset=symtbl.findItem(yytext);
			/*
			cout<<"******************"<<endl;
			cout<<"For Debug"<<endl;
			cout<<offset<<endl;
			cout<<"******************"<<endl;
			*/
			if(offset==-1){
				offset=symtbl.insert(yytext,Identifier);
			}
			else{
				transmitter.type = symtbl.getType(offset);
			}
			/*
			cout<<"******************"<<endl;
			cout<<"For Debug"<<endl;
			cout<<symtbl.symbol_table[offset].name<<"\t"<<symtbl.symbol_table[offset].scope<<endl;
			cout<<"******************"<<endl;
			*/
			yylval=&transmitter;
			yylval->attr.symtbl_seq=offset;
			
			print_token(ID,yytext,offset);
			return ID;
			}

{double_num}	{
				yylval=&transmitter;
				yylval->attr.vald=atof(yytext);
				print_double(DOUBLE_NUM,yytext,atof(yytext));
				return DOUBLE_NUM;}
				
{int_num}	{
			yylval=&transmitter;
			yylval->attr.vali=atoi(yytext);
			print_token(INT_NUM,yytext,atoi(yytext));
			return INT_NUM;}
			
{constchar}	{
				yylval = &transmitter;
				yylval->attr.valc = yytext[1];
				print_token(CONSTCHAR, yytext);
				return CONSTCHAR;}
				
"++"		{print_token(PLUS2, yytext); return PLUS2;}
"--"		{print_token(MINUS2, yytext); return MINUS2;}
"+"		{print_token(PLUS, yytext); return PLUS;}
"-"		{print_token(MINUS, yytext); return MINUS;}

"*"		{print_token(TIMES, yytext); return TIMES;}
"/"		{print_token(OVER, yytext); return OVER;}
"%"		{print_token(MOD, yytext); return MOD;}

"<<"		{print_token(LSHIFT, yytext); return LSHIFT;}
">>"		{print_token(RSHIFT, yytext); return RSHIFT;}

"<"		{print_token(LT, yytext); return LT;}
"<="	{print_token(LE, yytext); return LE;}
">"		{print_token(GT, yytext); return GT;}
">="	{print_token(GE, yytext); return GE;}


"=="	{print_token(EQ, yytext); return EQ;}
"!="	{print_token(NE, yytext); return NE;}

"&"        {print_token(BIT_AND, yytext); return BIT_AND;}
"^"        {print_token(BIT_XOR, yytext); return BIT_XOR;}
"|"        {print_token(BIT_OR, yytext); return BIT_OR;}

"&&"        {print_token(AND, yytext); return AND;}
"||"        {print_token(OR, yytext); return OR;}

"?"		{print_token(QMARK, yytext); return QMARK;}
":"		{print_token(COLON, yytext); return COLON;}

"="		{print_token(ASSIGN, yytext); return ASSIGN;}
"+="		{print_token(PLUSA, yytext); return PLUSA;}
"-="		{print_token(MINUSA, yytext); return MINUSA;}
"*="		{print_token(TIMESA, yytext); return TIMESA;}
"/="		{print_token(OVERA, yytext); return OVERA;}
"%="		{print_token(MODA, yytext); MODA;}

"("		{print_token(LPAREN, yytext); return LPAREN;}
")"		{print_token(RPAREN, yytext); return RPAREN;}
"{"		{print_token(LBRACE, yytext);
		/*cur_scope++;
		cout<<"Current Scope in LBRACE: "<<cur_scope<<endl;*/
		return LBRACE;}
"}"		{print_token(RBRACE, yytext);
		/*cur_scope--;
		cout<<"Current Scope out of RBRACE: "<<cur_scope<<endl;*/
		return RBRACE;}
		
";"		{print_token(SEMICOLON, yytext); return SEMICOLON;}
","		{print_token(COMMA, yytext); return COMMA;}

"!"         {print_token(NOT, yytext); return NOT;}

"//"[^\n]*	{}
"/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"	{}

{newline}   {
				lineno++;
#ifdef LEX_DEBUG
				cout << "lineno: " << lineno << endl;
#endif
			}
			
.			{
#ifdef LEX_DEBUG
				cout << "error!" << endl;
#endif
				return ERROR;
			}

%%

/////////////////////////////////////////////////////////////////////////////
// programs section
static void print_token(int token,char *lexeme,int attr){
#ifdef LEX_DEBUG
	cout<<"token: "<<token<<",\tlexeme: "<<lexeme;
	if(token==ID)
		cout<<",\tsymbol table pos: "<<attr;
	else if(token==INT_NUM)
		cout<<",\tvalue: "<<attr;
	cout<<endl;
#endif
}

static void print_double(int token,char *lexeme,double attr){
#ifdef LEX_DEBUG
	cout<<"token: "<<token<<",\tlexeme: "<<lexeme;
	if(token==DOUBLE_NUM)
		cout<<",\tvalue: "<<attr;
	cout<<endl;
#endif
}

