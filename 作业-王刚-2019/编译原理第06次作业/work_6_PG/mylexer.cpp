/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 95 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/05/19
* Time: 18:37:01
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

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
struct idNameType
{
	string name;
	ExpType type;
};
idNameType ids[1000];
int idcount =0;
int lines_num=0;


#line 109 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 87 ".\\mylexer.l"

	// place any extra initialisation code here

#line 133 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 92 ".\\mylexer.l"

	// place any extra cleanup code here

#line 145 "mylexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 112 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 216 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 116 ".\\mylexer.l"
lines_num++;
#line 223 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 117 ".\\mylexer.l"
/* skip whitespace */
#line 230 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 118 ".\\mylexer.l"
/* skip whitespace */
#line 237 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 119 ".\\mylexer.l"
return COMMA;
#line 244 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 120 ".\\mylexer.l"
return SEMI;
#line 251 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 121 ".\\mylexer.l"
return LP;
#line 258 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 122 ".\\mylexer.l"
return RP;
#line 265 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 123 ".\\mylexer.l"
return LFP;
#line 272 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 124 ".\\mylexer.l"
return RFP;
#line 279 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 125 ".\\mylexer.l"
return LSP;
#line 286 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 126 ".\\mylexer.l"
return RSP;
#line 293 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 128 ".\\mylexer.l"
return IF;
#line 300 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 129 ".\\mylexer.l"
return ELSE;
#line 307 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 130 ".\\mylexer.l"
return WHILE;
#line 314 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 131 ".\\mylexer.l"
return FOR;
#line 321 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 132 ".\\mylexer.l"
return CIN;
#line 328 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 133 ".\\mylexer.l"
return COUT;
#line 335 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 134 ".\\mylexer.l"
return VOID;
#line 342 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 135 ".\\mylexer.l"
return INT;
#line 349 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 136 ".\\mylexer.l"
return CHAR;
#line 356 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 137 ".\\mylexer.l"
return BOOL;
#line 363 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 138 ".\\mylexer.l"
return ASSIGN;
#line 370 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 139 ".\\mylexer.l"
return MAIN;
#line 377 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 141 ".\\mylexer.l"
return PLUS;
#line 384 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 142 ".\\mylexer.l"
return MINUS;
#line 391 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 143 ".\\mylexer.l"
return MUL;
#line 398 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 144 ".\\mylexer.l"
return DIV;
#line 405 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 145 ".\\mylexer.l"
return REMI;
#line 412 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 146 ".\\mylexer.l"
return DPLUS;
#line 419 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 147 ".\\mylexer.l"
return DMINUS;
#line 426 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 148 ".\\mylexer.l"
return EQ;
#line 433 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 150 ".\\mylexer.l"
return GT;
#line 440 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 151 ".\\mylexer.l"
return LT;
#line 447 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 152 ".\\mylexer.l"
return GE;
#line 454 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 153 ".\\mylexer.l"
return LE;
#line 461 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 154 ".\\mylexer.l"
return NEQ;
#line 468 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 155 ".\\mylexer.l"
return AND;
#line 475 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 156 ".\\mylexer.l"
return OR;
#line 482 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 157 ".\\mylexer.l"
return NOT;
#line 489 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 158 ".\\mylexer.l"
return LM;
#line 496 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 159 ".\\mylexer.l"
return RM;
#line 503 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 161 ".\\mylexer.l"

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
				
#line 524 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 176 ".\\mylexer.l"

					struct TreeNode *node = (struct TreeNode*)malloc (sizeof(struct TreeNode));
					for(int i=0;i<MAX;i++)
                    {
                        node->child[i]=NULL;
                    }
					node->brother=NULL;
					node->nodetype=Expr;
					node->specifictype=Const;
					node->val=getCh(yytext);					
					node->type=Char;
					node->lineno=line++;
					yylval = node;
					return CHARACTER;
				
#line 545 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 191 ".\\mylexer.l"

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
				
#line 566 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 194;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 1 },
		{ 3, 3 },
		{ 40, 78 },
		{ 54, 27 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 65, 65 },
		{ 78, 62 },
		{ 86, 78 },
		{ 40, 15 },
		{ 35, 5 },
		{ 55, 28 },
		{ 64, 62 },
		{ 57, 29 },
		{ 41, 15 },
		{ 3, 1 },
		{ 5, 1 },
		{ 3, 3 },
		{ 43, 65 },
		{ 56, 28 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 58, 30 },
		{ 15, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 0, 86 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 66, 43 },
		{ 59, 31 },
		{ 66, 43 },
		{ 62, 86 },
		{ 47, 20 },
		{ 48, 20 },
		{ 42, 16 },
		{ 63, 86 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 67, 67 },
		{ 22, 1 },
		{ 60, 33 },
		{ 23, 1 },
		{ 44, 18 },
		{ 45, 18 },
		{ 50, 25 },
		{ 51, 25 },
		{ 24, 1 },
		{ 25, 1 },
		{ 61, 37 },
		{ 26, 1 },
		{ 27, 1 },
		{ 52, 25 },
		{ 64, 41 },
		{ 28, 1 },
		{ 0, 42 },
		{ 36, 7 },
		{ 68, 49 },
		{ 29, 1 },
		{ 69, 50 },
		{ 70, 51 },
		{ 71, 52 },
		{ 72, 53 },
		{ 73, 54 },
		{ 74, 56 },
		{ 75, 57 },
		{ 76, 58 },
		{ 30, 1 },
		{ 31, 1 },
		{ 77, 59 },
		{ 0, 8 },
		{ 78, 63 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 46, 19 },
		{ 38, 12 },
		{ 79, 68 },
		{ 80, 69 },
		{ 81, 71 },
		{ 82, 72 },
		{ 83, 75 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 84, 76 },
		{ 85, 77 },
		{ 49, 24 },
		{ 87, 85 },
		{ 21, 87 },
		{ 39, 14 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 21, 87 },
		{ 53, 26 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 87, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 2 },
		{ 0, 0, 1 },
		{ 0, -42, 39 },
		{ 0, 0, 28 },
		{ 0, 61, 0 },
		{ -37, 103, 0 },
		{ 0, 0, 6 },
		{ 0, 0, 7 },
		{ 0, 0, 26 },
		{ 0, 86, 24 },
		{ 0, 0, 4 },
		{ 0, 121, 25 },
		{ 0, -24, 27 },
		{ 65, 15, 42 },
		{ 0, 0, 5 },
		{ 0, 26, 33 },
		{ 0, 67, 22 },
		{ 0, -2, 32 },
		{ 87, 0, 44 },
		{ 0, 0, 10 },
		{ 0, 0, 11 },
		{ 87, 52, 44 },
		{ 87, -16, 44 },
		{ 87, 85, 44 },
		{ 87, -106, 44 },
		{ 87, -82, 44 },
		{ 87, -75, 44 },
		{ 87, -73, 44 },
		{ 87, -48, 44 },
		{ 0, 0, 8 },
		{ 0, -40, 0 },
		{ 0, 0, 9 },
		{ 0, 0, 36 },
		{ 0, 0, 37 },
		{ 0, 53, 0 },
		{ 0, 0, 29 },
		{ 0, 0, 30 },
		{ 86, 0, 0 },
		{ -41, 86, 0 },
		{ 65, 29, 0 },
		{ 67, 12, 0 },
		{ 0, 0, 40 },
		{ 0, 0, 35 },
		{ 0, 0, 31 },
		{ 0, 0, 34 },
		{ 0, 0, 41 },
		{ 87, -11, 44 },
		{ 87, 5, 44 },
		{ 87, -7, 44 },
		{ 87, -13, 44 },
		{ 87, -10, 44 },
		{ 87, -8, 44 },
		{ 87, 0, 12 },
		{ 87, -9, 44 },
		{ 87, 3, 44 },
		{ 87, 4, 44 },
		{ 87, 7, 44 },
		{ 0, 0, 38 },
		{ 0, 0, 43 },
		{ -40, -26, 0 },
		{ 86, 72, 0 },
		{ 0, 0, 3 },
		{ 0, -42, 42 },
		{ 67, 0, 0 },
		{ 0, 25, 42 },
		{ 87, 22, 44 },
		{ 87, 17, 44 },
		{ 87, 0, 16 },
		{ 87, 16, 44 },
		{ 87, 32, 44 },
		{ 87, 0, 15 },
		{ 87, 0, 19 },
		{ 87, 24, 44 },
		{ 87, 61, 44 },
		{ 87, 54, 44 },
		{ 63, -30, 0 },
		{ 87, 0, 21 },
		{ 87, 0, 20 },
		{ 87, 0, 17 },
		{ 87, 0, 13 },
		{ 87, 0, 23 },
		{ 87, 0, 18 },
		{ 87, 63, 44 },
		{ -40, 16, 3 },
		{ 0, 70, 14 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 208 ".\\mylexer.l"

int mylexer::getId(string word)
{
for(int i=0;i<idcount;i++)
	{
		if(ids[i].name==word)return i;
	}
	ids[idcount].name=word;
	ids[idcount].type=Void;
	idcount++;
	return idcount-1;
}
int mylexer::getCh(string word)
{
	char c;
	c=word[0];
	return int(c);
}
/////////////////////////////////////////////////////////////////////////////
// programs section


