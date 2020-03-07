/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 80 of your 30 day trial period.
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
* Date: 11/20/19
* Time: 14:40:15
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
unordered_map<string,int> ids;
int idcount =0;
int lines_num=0;


#line 104 "mylexer.cpp"
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
#line 81 ".\\mylexer.l"

	// place any extra initialisation code here

#line 128 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 86 ".\\mylexer.l"

	// place any extra cleanup code here

#line 140 "mylexer.cpp"
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
#line 105 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 211 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 109 ".\\mylexer.l"
lines_num++;
#line 218 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 110 ".\\mylexer.l"
/* skip whitespace */
#line 225 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 111 ".\\mylexer.l"
/* skip whitespace */
#line 232 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 112 ".\\mylexer.l"
return COMMA;
#line 239 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 113 ".\\mylexer.l"
return SEMI;
#line 246 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 114 ".\\mylexer.l"
return LP;
#line 253 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 115 ".\\mylexer.l"
return RP;
#line 260 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 116 ".\\mylexer.l"
return LFP;
#line 267 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 117 ".\\mylexer.l"
return RFP;
#line 274 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 118 ".\\mylexer.l"
return LSP;
#line 281 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 119 ".\\mylexer.l"
return RSP;
#line 288 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 121 ".\\mylexer.l"
return IF;
#line 295 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 122 ".\\mylexer.l"
return ELSE;
#line 302 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 123 ".\\mylexer.l"
return WHILE;
#line 309 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 124 ".\\mylexer.l"
return FOR;
#line 316 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 125 ".\\mylexer.l"
return CIN;
#line 323 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 126 ".\\mylexer.l"
return COUT;
#line 330 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 127 ".\\mylexer.l"
return VOID;
#line 337 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 128 ".\\mylexer.l"
return INT;
#line 344 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 129 ".\\mylexer.l"
return CHAR;
#line 351 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 130 ".\\mylexer.l"
return BOOL;
#line 358 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 131 ".\\mylexer.l"
return ASSIGN;
#line 365 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 132 ".\\mylexer.l"
return MAIN;
#line 372 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 134 ".\\mylexer.l"
return PLUS;
#line 379 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 135 ".\\mylexer.l"
return MINUS;
#line 386 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 136 ".\\mylexer.l"
return MUL;
#line 393 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 137 ".\\mylexer.l"
return DIV;
#line 400 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 138 ".\\mylexer.l"
return REMI;
#line 407 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 139 ".\\mylexer.l"
return DPLUS;
#line 414 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 140 ".\\mylexer.l"
return DMINUS;
#line 421 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 141 ".\\mylexer.l"
return EQ;
#line 428 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 143 ".\\mylexer.l"
return GT;
#line 435 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 144 ".\\mylexer.l"
return LT;
#line 442 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 145 ".\\mylexer.l"
return GE;
#line 449 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 146 ".\\mylexer.l"
return LE;
#line 456 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 147 ".\\mylexer.l"
return NEQ;
#line 463 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 148 ".\\mylexer.l"
return AND;
#line 470 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 149 ".\\mylexer.l"
return OR;
#line 477 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 150 ".\\mylexer.l"
return NOT;
#line 484 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 151 ".\\mylexer.l"
return LM;
#line 491 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 152 ".\\mylexer.l"
return RM;
#line 498 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 154 ".\\mylexer.l"

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
				
#line 519 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 170 ".\\mylexer.l"

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
				
#line 540 "mylexer.cpp"
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

	yytransitionmax = 193;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 1 },
		{ 3, 3 },
		{ 38, 75 },
		{ 35, 7 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 62, 62 },
		{ 75, 59 },
		{ 83, 75 },
		{ 38, 14 },
		{ 55, 28 },
		{ 53, 27 },
		{ 61, 59 },
		{ 56, 29 },
		{ 39, 14 },
		{ 3, 1 },
		{ 5, 1 },
		{ 3, 3 },
		{ 41, 62 },
		{ 54, 27 },
		{ 6, 1 },
		{ 7, 1 },
		{ 57, 30 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 58, 32 },
		{ 14, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 15, 1 },
		{ 0, 83 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 63, 41 },
		{ 61, 39 },
		{ 63, 41 },
		{ 59, 83 },
		{ 45, 19 },
		{ 46, 19 },
		{ 40, 15 },
		{ 60, 83 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 15, 15 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 64, 64 },
		{ 21, 1 },
		{ 0, 40 },
		{ 22, 1 },
		{ 42, 17 },
		{ 43, 17 },
		{ 48, 24 },
		{ 49, 24 },
		{ 23, 1 },
		{ 24, 1 },
		{ 36, 11 },
		{ 25, 1 },
		{ 26, 1 },
		{ 50, 24 },
		{ 65, 47 },
		{ 27, 1 },
		{ 66, 48 },
		{ 67, 49 },
		{ 68, 50 },
		{ 28, 1 },
		{ 69, 51 },
		{ 70, 52 },
		{ 71, 54 },
		{ 44, 18 },
		{ 72, 55 },
		{ 73, 56 },
		{ 74, 57 },
		{ 75, 60 },
		{ 29, 1 },
		{ 30, 1 },
		{ 37, 13 },
		{ 47, 23 },
		{ 76, 65 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 77, 66 },
		{ 78, 68 },
		{ 79, 69 },
		{ 80, 72 },
		{ 81, 73 },
		{ 82, 74 },
		{ 34, 5 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 84, 82 },
		{ 51, 25 },
		{ 52, 26 },
		{ 0, 0 },
		{ 20, 84 },
		{ 0, 0 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 },
		{ 20, 84 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 84, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 2 },
		{ 0, 0, 1 },
		{ 0, 73, 39 },
		{ 0, 0, 28 },
		{ 0, -33, 0 },
		{ 0, 0, 6 },
		{ 0, 0, 7 },
		{ 0, 0, 26 },
		{ 0, 49, 24 },
		{ 0, 0, 4 },
		{ 0, 67, 25 },
		{ 0, -24, 27 },
		{ 62, 15, 42 },
		{ 0, 0, 5 },
		{ 0, 26, 33 },
		{ 0, 44, 22 },
		{ 0, -2, 32 },
		{ 84, 0, 43 },
		{ 0, 0, 10 },
		{ 0, 0, 11 },
		{ 84, 2, 43 },
		{ 84, -16, 43 },
		{ 84, 54, 43 },
		{ 84, 52, 43 },
		{ 84, -82, 43 },
		{ 84, -78, 43 },
		{ 84, -89, 43 },
		{ 84, -73, 43 },
		{ 0, 0, 8 },
		{ 0, -86, 0 },
		{ 0, 0, 9 },
		{ 0, 0, 36 },
		{ 0, 0, 37 },
		{ 0, 0, 29 },
		{ 0, 0, 30 },
		{ 83, 0, 0 },
		{ -39, 46, 0 },
		{ 62, 15, 0 },
		{ 64, 12, 0 },
		{ 0, 0, 40 },
		{ 0, 0, 35 },
		{ 0, 0, 31 },
		{ 0, 0, 34 },
		{ 0, 0, 41 },
		{ 84, -15, 43 },
		{ 84, 1, 43 },
		{ 84, -11, 43 },
		{ 84, -17, 43 },
		{ 84, -13, 43 },
		{ 84, -11, 43 },
		{ 84, 0, 12 },
		{ 84, -12, 43 },
		{ 84, 1, 43 },
		{ 84, 2, 43 },
		{ 84, 3, 43 },
		{ 0, 0, 38 },
		{ -38, -26, 0 },
		{ 83, 67, 0 },
		{ 0, 0, 3 },
		{ 0, -42, 42 },
		{ 64, 0, 0 },
		{ 0, 25, 42 },
		{ 84, 6, 43 },
		{ 84, 14, 43 },
		{ 84, 0, 16 },
		{ 84, 13, 43 },
		{ 84, 29, 43 },
		{ 84, 0, 15 },
		{ 84, 0, 19 },
		{ 84, 21, 43 },
		{ 84, 32, 43 },
		{ 84, 25, 43 },
		{ 60, -30, 0 },
		{ 84, 0, 21 },
		{ 84, 0, 20 },
		{ 84, 0, 17 },
		{ 84, 0, 13 },
		{ 84, 0, 23 },
		{ 84, 0, 18 },
		{ 84, 60, 43 },
		{ -38, 16, 3 },
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
		0
	};
	yybackup = backup;
}
#line 187 ".\\mylexer.l"

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


