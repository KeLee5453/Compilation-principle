%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2019年10月16日
****************************************************************************/

#include "mylexer.h"
#include <iostream>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int lineno = 1;
int tokenval ;


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
%token NUM
//%token ZERO ONE TWO THREE FORE FIVE SIX SEVEN EIGHT NINE
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
	|	NUM {$$=$1;}
	;


/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)


%%

////////////////////////dx/////////////////////////////////////////////////////
// programs section
//string.c
static struct string {
	char *str;
	int len;
	struct string *link;
} *buckets[1024];
char *stringn(const char *str, int len) {
	int i;
	unsigned int h;
	const char *end;
	struct string *p;
	assert(str);
	for (h = 0, i = len, end = str; i > 0; i--)	// Hash
		h = (h<<1) + scatter[*(unsigned char *)end++];
	h &= NELEMS(buckets)-1;
	for (p = buckets[h]; p; p = p->link)		//搜索
		if (len == p->len) {
			const char *s1 = str;
			char *s2 = p->str;
			do {
				if (s1 == end)
					return p->str;
			} while (*s1++ == *s2++);
		}
	{
	static char *next, *strlimit;		//创建
	if (len + 1 >= strlimit - next) {		//现有空间不够
			int n = len + 4*1024;
			next = allocate(n, PERM);	//分配空间
			strlimit = next + n;
		}	

	p->len = len;
		for (p->str = next; str < end; )
			*next++ = *str++;		 //复制字符串
		*next++ = 0;
		p->link = buckets[h];			 //放入Hash表
		buckets[h] = p;
		return p->str;
	}
}


//sym.c
struct table {
	int level;
	Table previous;
	struct entry {
		struct symbol sym;
		struct entry *link;
	} *buckets[256];
	Symbol all;
};
Symbol lookup(const char *name, Table tp) {
	struct entry *p;
	unsigned h = (unsigned long)name&(HASHSIZE-1);

	assert(tp);
	do
		for (p = tp->buckets[h]; p; p = p->link)
			if (name == p->sym.name)
				return &p->sym;
	while ((tp = tp->previous) != NULL);
	return NULL;
}
Symbol install(const char *name, Table *tpp, int level, int arena) {
	Table tp = *tpp;
	struct entry *p;
	unsigned h = (unsigned long)name&(HASHSIZE-1);

	assert(level == 0 || level >= tp->level);
	if (level > 0 && tp->level < level)
		tp = *tpp = table(tp, level);	 //新作用域
	NEW0(p, arena);
	p->sym.name = (char *)name;
	p->sym.scope = level;
	p->sym.up = tp->all;
	tp->all = &p->sym;
	p->link = tp->buckets[h];		//放入Hash表
	tp->buckets[h] = p;
	return &p->sym;
}






int lexan()
{

	char lexbuf[100];
	char c;

	while (1) {
		c = getchar();
		if (c == ‘ ‘ || c == ‘\t’) ;//过滤了空白符
		else if (c == ‘\n’)//回车就行号加一（为了报错显示行号）
			lineno++;
		else if (isdigit(c)) {//识别无符号整数
			tokenval = 0;
			while (isdigit(t)) {
				tokenval = tokenval * 10 + c - ‘0’;
				c = getchar();
			}
			ungetc(c, stdin);//ungetchar：退回去，把下一个加号识别出来，为下一个单词
			return NUM;
		}
		else if (isalpha(c)) {
			while(isalpha(c))
			{
				strcat(lexbuf,c);
				c=getchar();
			}
			ungetc(c,stdin);
			p = lookup(lexbuf);
			if (p = 0) 
				p = insert(lexbuf, ID);
			tokenval = p;
			return 符号表项p的token值;
		} else {
			tokenval = NONE;
			return 字符c对应的整数;
		}
	}
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


