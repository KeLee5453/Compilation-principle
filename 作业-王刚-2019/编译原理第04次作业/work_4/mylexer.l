%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2019年10月30日
****************************************************************************/
#include <iostream>
#include <fstream>
 #include <string>
static int idc=0;//计数
static int nc=0;
 double	yylval=0;
 int num_lines = 0;
 string Ids[100];//char指针类型数组,记录单词
 string Ns[100];
 int addID(string word);
 int addNUM(string name);
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
newline     \n
whitespace  [ \t]+
digit [0-9]
letter_	[A-Za-z_]
id	{letter_}({letter_}|{digit})*
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
comment	("/*"([^*"]*|".*"|\*+[^/])*\**"*/")|("//".*\n)

INT int
CHAR char
DOUBLE double
FLOAT  float

IF  if
ELSE else

FOR		for
DO		do
WHILE	while

SWITCH	switch
CASE	case
BREAK	break
DEFAULT default
CONTINUE continue

TRUE	true
FALSE	false
RETURN	return
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here
{newline}       {num_lines++;}
{whitespace}    {/* skip whitespace */}
{comment}		{}
{INT}		    {cout<<"INT\t\tint"<<endl;}
{CHAR}	    	{cout<<"CHAR\t\tchar"<<endl;}
{DOUBLE}    	{cout<<"DOUBLE\t\tdouble"<<endl;}
{FLOAT}	    	{cout<<"FLOAT\t\tfloat"<<endl;}

{IF}    		{cout<<"IF\t\tif"<<endl;}
{ELSE}  		{cout<<"ELSE\t\telse"<<endl;}	

{FOR}   		{cout<<"FOR\t\tfor"<<endl;}
{DO}    		{cout<<"DO\t\tdo"<<endl;}
{WHILE} 		{cout<<"WHILE\t\twhile"<<endl;}

{SWITCH}    	{cout<<"SWITCH\t\tswitch"<<endl;}
{CASE}	    	{cout<<"CASE\t\tcase"<<endl;}
{BREAK}		    {cout<<"BREAK\t\tbreak"<<endl;}
{DEFAULT}   	{cout<<"DEFAULT\t\tdefault"<<endl;}
{CONTINUE}  	{cout<<"CONTINUE\t\tcontinue"<<endl;}

{TRUE}  		{cout<<"TRUE\t\ttrue"<<endl;}
{FALSE}	    	{cout<<"FALSE\t\tfalse"<<endl;}
{RETURN}    	{cout<<"RETURN\t\treturn"<<endl;}

"{"             {cout<<"LBRACE\t\t"<<yytext<<endl;}
"}"             {cout<<"RBRACE\t\t"<<yytext<<endl;}
"("             {cout<<"LPAREN\t\t"<<yytext<<endl;}
")"             {cout<<"RPAREN\t\t"<<yytext<<endl;}
";"             {cout<<"SIMI\t\t"<<yytext<<endl;}
","				{cout<<"COMMA\t\t"<<yytext<<endl;}

"+"             {cout<<"PLUS\t\t"<<yytext<<endl;}
"-"             {cout<<"MINUS\t\t"<<yytext<<endl;}
"*"             {cout<<"MUL\t\t"<<yytext<<endl;}
"/"             {cout<<"DIV\t\t"<<yytext<<endl;}
"%"             {cout<<"MOD\t\t"<<yytext<<endl;}
"&"				{cout<<"bAND\t\t"<<yytext<<endl;}

"="             {cout<<"ASSIGN\t\t"<<yytext<<endl;}
"=="            {cout<<"EQ\t\t"<<yytext<<endl;}
"<="            {cout<<"LE\t\t"<<yytext<<endl;}
"<"             {cout<<"LT\t\t"<<yytext<<endl;}
"!="            {cout<<"NE\t\t"<<yytext<<endl;}
">"             {cout<<"GT\t\t"<<yytext<<endl;}
">="            {cout<<"GE\t\t"<<yytext<<endl;}

"&&"            {cout<<"AND\t\t"<<yytext<<endl;}
"||"            {cout<<"OR\t\t"<<yytext<<endl;}
"!"             {cout<<"NOT\t\t"<<yytext<<endl;}

"++"		{cout<<"DPLUS\t\t"<<yytext<<endl;}
"--"		{cout<<"DMINUS\t\t"<<yytext<<endl;}
"<<"		{cout<<"SHL\t\t"<<yytext<<endl;}
">>"		{cout<<"SHR\t\t"<<yytext<<endl;}

{number}        {string str=yytext;
           cout<<"NUMBER\t\t"<<yytext<<"\t\t"<<addNUM(str)<<endl;}
{id}		{string strin=yytext;
			cout<<"ID\t\t"<<strin<<"\t\t"<<addID(strin)<<endl;}	
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int check(string word)
{
	for(int i=0;i<idc;i++)
	{
	
		if(Ids[i]==word)//出现过
			return i;
	}
	return -1;
}

int addID(string word)
{
	int retn=check(word);
	if(retn==-1){
		retn=idc;
		Ids[idc]=word;
		idc=idc+1;
		}
	return retn;
}

int checkn(string name)
{
    for(int j=0;j<nc;j++)
	{
		if(Ns[j]==name)//出现过
			return j;
	}
	return -1;
}
int addNUM(string name)
{
    int rn=checkn(name);
    if(rn==-1){
        rn=nc;
		Ns[nc]=name;
		nc=nc+1;
		}
	return rn;
         
}
int main(void)
{
	int n = 1;
	mylexer lexer;
	if (lexer.yycreate()) {
		lexer.yyin=new std::ifstream("C:/Users/a1547/Desktop/大三上/编译原理/作业-王刚-2019/编译原理第04次作业/work_4_VS/a.txt");
		cout<<"单词\t\t词素\t\t属性"<<endl;
		if(!lexer.yyin->fail()){
		n=lexer.yylex();
		}
	}
	system("pause");
	return n;
}

