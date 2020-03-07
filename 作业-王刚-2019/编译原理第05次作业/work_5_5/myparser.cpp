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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 11/20/19
* Time: 14:40:15
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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
extern unordered_map<string,int> ids;

#line 117 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 98 ".\\myparser.y"

	// place any extra initialisation code here

#line 141 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 103 ".\\myparser.y"

	// place any extra cleanup code here

#line 155 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 136 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(4 - 4);root=yyattribute(4 - 4);display(root);
#line 265 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 138 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,Complex);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(2 - 3);
#line 278 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 140 ".\\myparser.y"

							if(yyattribute(1 - 2)!=NULL)
							{
							while(yyattribute(1 - 2)->brother!=NULL)
							yyattribute(1 - 2)=yyattribute(1 - 2)->brother;
							yyattribute(1 - 2)->brother=yyattribute(2 - 2);
							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
							}
							else 
							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
							
#line 301 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 151 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 314 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 153 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 327 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 154 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 340 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 155 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 353 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 156 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 366 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 157 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 379 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 158 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 392 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 159 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 405 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 160 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 418 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 162 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Int;
#line 431 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 163 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Char;
#line 444 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 164 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Bool;
#line 457 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 165 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Void;
#line 470 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 167 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->brother=yyattribute(3 - 3);
#line 483 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 168 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 496 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 170 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=ASSIGN;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 509 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 171 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 522 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 173 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Decl,Var);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(2 - 3);
#line 535 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 175 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
#line 548 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 176 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=NULL;
#line 561 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 179 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=ASSIGN;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 574 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 180 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 587 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 182 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=OR;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 600 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 183 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 613 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 185 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=AND;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 626 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 186 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 639 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 189 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=EQ;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 652 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 190 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=GE;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 665 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 191 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=LE;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 678 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 192 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=GT;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 691 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 193 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=LT;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 704 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 194 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=NEQ;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 717 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 195 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=LM;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 730 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 196 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=RM;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 743 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 197 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 756 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 200 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=PLUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 769 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 201 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=MINUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 782 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 202 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=MUL;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 795 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 203 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=DIV;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 808 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 204 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=REMI;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 821 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 205 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=DPLUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 2);
#line 834 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 206 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=DMINUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 2);
#line 847 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 207 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 860 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 209 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
#line 873 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 210 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 886 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 211 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 899 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 212 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=NOT;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(2 - 2);
#line 912 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 215 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,If);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 5);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 5);
#line 925 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 216 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,If);yyattribute(3 - 7)->type=Bool;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(7 - 7);
#line 938 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 219 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 9);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 9);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(7 - 9);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(9 - 9);
#line 951 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 220 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(4 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(6 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(8 - 8);
#line 964 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 221 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(6 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(8 - 8);
#line 977 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 222 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(8 - 8);
#line 990 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 223 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(5 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(7 - 7);
#line 1003 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 224 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(4 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(7 - 7);
#line 1016 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 225 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(7 - 7);
#line 1029 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 226 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(6 - 6);
#line 1042 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 229 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,While);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 5);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 5);
#line 1055 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 232 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,Input);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 4);
#line 1068 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 234 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,Output);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 4);
#line 1081 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "IF", 257 },
		{ "MAIN", 258 },
		{ "FOR", 259 },
		{ "WHILE", 260 },
		{ "CIN", 261 },
		{ "COUT", 262 },
		{ "INT", 263 },
		{ "CHAR", 264 },
		{ "VOID", 265 },
		{ "BOOL", 266 },
		{ "ID", 267 },
		{ "NUMBER", 268 },
		{ "PLUS", 269 },
		{ "MINUS", 270 },
		{ "MUL", 271 },
		{ "DIV", 272 },
		{ "REMI", 273 },
		{ "DPLUS", 274 },
		{ "DMINUS", 275 },
		{ "GT", 276 },
		{ "LT", 277 },
		{ "GE", 278 },
		{ "LE", 279 },
		{ "NEQ", 280 },
		{ "AND", 281 },
		{ "OR", 282 },
		{ "NOT", 283 },
		{ "ASSIGN", 284 },
		{ "LFP", 285 },
		{ "RFP", 286 },
		{ "COMMA", 287 },
		{ "SEMI", 288 },
		{ "LP", 289 },
		{ "RP", 290 },
		{ "LM", 291 },
		{ "RM", 292 },
		{ "EQ", 293 },
		{ "ELSE", 296 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: start",
		"start: MAIN LP RP complex",
		"complex: LFP stmts RFP",
		"stmts: stmt stmts",
		"stmts: stmt",
		"stmt: expr_stmt",
		"stmt: var_stmt",
		"stmt: if_stmt",
		"stmt: while_stmt",
		"stmt: for_stmt",
		"stmt: complex",
		"stmt: input_stmt",
		"stmt: output_stmt",
		"type_var: INT",
		"type_var: CHAR",
		"type_var: BOOL",
		"type_var: VOID",
		"id_list: id_expr COMMA id_list",
		"id_list: id_expr",
		"id_expr: ID ASSIGN expr",
		"id_expr: ID",
		"var_stmt: type_var id_list SEMI",
		"expr_stmt: expr SEMI",
		"expr_stmt: SEMI",
		"expr: expr ASSIGN expr",
		"expr: or_expr",
		"or_expr: or_expr OR and_expr",
		"or_expr: and_expr",
		"and_expr: and_expr AND eq_expr",
		"and_expr: eq_expr",
		"eq_expr: eq_expr EQ simple_expr",
		"eq_expr: eq_expr GE simple_expr",
		"eq_expr: eq_expr LE simple_expr",
		"eq_expr: eq_expr GT simple_expr",
		"eq_expr: eq_expr LT simple_expr",
		"eq_expr: eq_expr NEQ simple_expr",
		"eq_expr: eq_expr LM simple_expr",
		"eq_expr: eq_expr RM simple_expr",
		"eq_expr: simple_expr",
		"simple_expr: simple_expr PLUS term",
		"simple_expr: simple_expr MINUS term",
		"simple_expr: simple_expr MUL term",
		"simple_expr: simple_expr DIV term",
		"simple_expr: simple_expr REMI term",
		"simple_expr: simple_expr DPLUS",
		"simple_expr: simple_expr DMINUS",
		"simple_expr: term",
		"term: LP expr RP",
		"term: ID",
		"term: NUMBER",
		"term: NOT term",
		"if_stmt: IF LP expr RP stmt",
		"if_stmt: IF LP expr RP stmt ELSE stmt",
		"for_stmt: FOR LP expr SEMI expr SEMI expr RP stmt",
		"for_stmt: FOR LP SEMI expr SEMI expr RP stmt",
		"for_stmt: FOR LP expr SEMI SEMI expr RP stmt",
		"for_stmt: FOR LP expr SEMI expr SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI expr RP stmt",
		"for_stmt: FOR LP SEMI expr SEMI RP stmt",
		"for_stmt: FOR LP expr SEMI SEMI RP stmt",
		"for_stmt: FOR LP SEMI SEMI RP stmt",
		"while_stmt: WHILE LP expr RP stmt",
		"input_stmt: CIN RM ID SEMI",
		"output_stmt: COUT LM ID SEMI",
		"Grammar:"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 3, 1 },
		{ 3, 2, 2 },
		{ 3, 1, 3 },
		{ 4, 1, 4 },
		{ 4, 1, 5 },
		{ 4, 1, 6 },
		{ 4, 1, 7 },
		{ 4, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 5, 1, 12 },
		{ 5, 1, 13 },
		{ 5, 1, 14 },
		{ 5, 1, 15 },
		{ 6, 3, 16 },
		{ 6, 1, 17 },
		{ 7, 3, 18 },
		{ 7, 1, 19 },
		{ 8, 3, 20 },
		{ 9, 2, 21 },
		{ 9, 1, 22 },
		{ 10, 3, 23 },
		{ 10, 1, 24 },
		{ 11, 3, 25 },
		{ 11, 1, 26 },
		{ 12, 3, 27 },
		{ 12, 1, 28 },
		{ 13, 3, 29 },
		{ 13, 3, 30 },
		{ 13, 3, 31 },
		{ 13, 3, 32 },
		{ 13, 3, 33 },
		{ 13, 3, 34 },
		{ 13, 3, 35 },
		{ 13, 3, 36 },
		{ 13, 1, 37 },
		{ 14, 3, 38 },
		{ 14, 3, 39 },
		{ 14, 3, 40 },
		{ 14, 3, 41 },
		{ 14, 3, 42 },
		{ 14, 2, 43 },
		{ 14, 2, 44 },
		{ 14, 1, 45 },
		{ 15, 3, 46 },
		{ 15, 1, 47 },
		{ 15, 1, 48 },
		{ 15, 2, 49 },
		{ 16, 5, 50 },
		{ 16, 7, 51 },
		{ 17, 9, 52 },
		{ 17, 8, 53 },
		{ 17, 8, 54 },
		{ 17, 8, 55 },
		{ 17, 7, 56 },
		{ 17, 7, 57 },
		{ 17, 7, 58 },
		{ 17, 6, 59 },
		{ 18, 5, 60 },
		{ 19, 4, 61 },
		{ 20, 4, 62 },
		{ 21, 0, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 155;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 30, YYAT_SHIFT, 7 },
		{ 117, YYAT_SHIFT, 124 },
		{ 30, YYAT_SHIFT, 8 },
		{ 30, YYAT_SHIFT, 9 },
		{ 30, YYAT_SHIFT, 10 },
		{ 30, YYAT_SHIFT, 11 },
		{ 30, YYAT_SHIFT, 12 },
		{ 30, YYAT_SHIFT, 13 },
		{ 30, YYAT_SHIFT, 14 },
		{ 30, YYAT_SHIFT, 15 },
		{ 30, YYAT_SHIFT, 16 },
		{ 30, YYAT_SHIFT, 17 },
		{ 130, YYAT_SHIFT, 7 },
		{ 115, YYAT_SHIFT, 122 },
		{ 130, YYAT_SHIFT, 8 },
		{ 130, YYAT_SHIFT, 9 },
		{ 130, YYAT_SHIFT, 10 },
		{ 130, YYAT_SHIFT, 11 },
		{ 130, YYAT_SHIFT, 12 },
		{ 130, YYAT_SHIFT, 13 },
		{ 130, YYAT_SHIFT, 14 },
		{ 130, YYAT_SHIFT, 15 },
		{ 118, YYAT_SHIFT, 16 },
		{ 118, YYAT_SHIFT, 17 },
		{ 126, YYAT_SHIFT, 65 },
		{ 109, YYAT_SHIFT, 65 },
		{ 30, YYAT_SHIFT, 18 },
		{ 108, YYAT_SHIFT, 116 },
		{ 30, YYAT_SHIFT, 5 },
		{ 109, YYAT_SHIFT, 118 },
		{ 126, YYAT_SHIFT, 130 },
		{ 30, YYAT_SHIFT, 19 },
		{ 30, YYAT_SHIFT, 20 },
		{ 94, YYAT_SHIFT, 57 },
		{ 94, YYAT_SHIFT, 58 },
		{ 94, YYAT_SHIFT, 59 },
		{ 94, YYAT_SHIFT, 60 },
		{ 94, YYAT_SHIFT, 61 },
		{ 118, YYAT_SHIFT, 18 },
		{ 107, YYAT_SHIFT, 114 },
		{ 130, YYAT_SHIFT, 5 },
		{ 106, YYAT_SHIFT, 113 },
		{ 104, YYAT_SHIFT, 111 },
		{ 130, YYAT_SHIFT, 19 },
		{ 118, YYAT_SHIFT, 20 },
		{ 118, YYAT_SHIFT, 125 },
		{ 102, YYAT_SHIFT, 65 },
		{ 98, YYAT_SHIFT, 108 },
		{ 94, YYAT_SHIFT, 62 },
		{ 94, YYAT_SHIFT, 63 },
		{ 94, YYAT_SHIFT, 64 },
		{ 33, YYAT_SHIFT, 57 },
		{ 33, YYAT_SHIFT, 58 },
		{ 33, YYAT_SHIFT, 59 },
		{ 33, YYAT_SHIFT, 60 },
		{ 33, YYAT_SHIFT, 61 },
		{ 91, YYAT_SHIFT, 50 },
		{ 91, YYAT_SHIFT, 51 },
		{ 91, YYAT_SHIFT, 52 },
		{ 91, YYAT_SHIFT, 53 },
		{ 91, YYAT_SHIFT, 54 },
		{ 91, YYAT_SHIFT, 55 },
		{ 91, YYAT_SHIFT, 56 },
		{ 97, YYAT_SHIFT, 107 },
		{ 96, YYAT_SHIFT, 105 },
		{ 93, YYAT_SHIFT, 68 },
		{ 33, YYAT_SHIFT, 62 },
		{ 33, YYAT_SHIFT, 63 },
		{ 33, YYAT_SHIFT, 64 },
		{ 90, YYAT_SHIFT, 50 },
		{ 90, YYAT_SHIFT, 51 },
		{ 90, YYAT_SHIFT, 52 },
		{ 90, YYAT_SHIFT, 53 },
		{ 90, YYAT_SHIFT, 54 },
		{ 90, YYAT_SHIFT, 55 },
		{ 90, YYAT_SHIFT, 56 },
		{ 89, YYAT_SHIFT, 50 },
		{ 89, YYAT_SHIFT, 51 },
		{ 89, YYAT_SHIFT, 52 },
		{ 89, YYAT_SHIFT, 53 },
		{ 89, YYAT_SHIFT, 54 },
		{ 89, YYAT_SHIFT, 55 },
		{ 89, YYAT_SHIFT, 56 },
		{ 88, YYAT_SHIFT, 50 },
		{ 88, YYAT_SHIFT, 51 },
		{ 88, YYAT_SHIFT, 52 },
		{ 88, YYAT_SHIFT, 53 },
		{ 88, YYAT_SHIFT, 54 },
		{ 88, YYAT_SHIFT, 55 },
		{ 88, YYAT_SHIFT, 56 },
		{ 87, YYAT_SHIFT, 50 },
		{ 87, YYAT_SHIFT, 51 },
		{ 87, YYAT_SHIFT, 52 },
		{ 87, YYAT_SHIFT, 53 },
		{ 87, YYAT_SHIFT, 54 },
		{ 87, YYAT_SHIFT, 55 },
		{ 87, YYAT_SHIFT, 56 },
		{ 86, YYAT_SHIFT, 50 },
		{ 86, YYAT_SHIFT, 51 },
		{ 86, YYAT_SHIFT, 52 },
		{ 86, YYAT_SHIFT, 53 },
		{ 86, YYAT_SHIFT, 54 },
		{ 86, YYAT_SHIFT, 55 },
		{ 86, YYAT_SHIFT, 56 },
		{ 85, YYAT_SHIFT, 50 },
		{ 85, YYAT_SHIFT, 51 },
		{ 85, YYAT_SHIFT, 52 },
		{ 85, YYAT_SHIFT, 53 },
		{ 85, YYAT_SHIFT, 54 },
		{ 85, YYAT_SHIFT, 55 },
		{ 85, YYAT_SHIFT, 56 },
		{ 84, YYAT_SHIFT, 50 },
		{ 84, YYAT_SHIFT, 51 },
		{ 84, YYAT_SHIFT, 52 },
		{ 84, YYAT_SHIFT, 53 },
		{ 84, YYAT_SHIFT, 54 },
		{ 84, YYAT_SHIFT, 55 },
		{ 84, YYAT_SHIFT, 56 },
		{ 32, YYAT_SHIFT, 50 },
		{ 32, YYAT_SHIFT, 51 },
		{ 32, YYAT_SHIFT, 52 },
		{ 32, YYAT_SHIFT, 53 },
		{ 32, YYAT_SHIFT, 54 },
		{ 32, YYAT_SHIFT, 55 },
		{ 32, YYAT_SHIFT, 56 },
		{ 92, YYAT_SHIFT, 65 },
		{ 78, YYAT_SHIFT, 45 },
		{ 76, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 101 },
		{ 73, YYAT_SHIFT, 100 },
		{ 72, YYAT_SHIFT, 99 },
		{ 71, YYAT_SHIFT, 98 },
		{ 70, YYAT_SHIFT, 96 },
		{ 69, YYAT_SHIFT, 95 },
		{ 47, YYAT_SHIFT, 78 },
		{ 46, YYAT_SHIFT, 77 },
		{ 45, YYAT_SHIFT, 76 },
		{ 44, YYAT_SHIFT, 75 },
		{ 42, YYAT_SHIFT, 74 },
		{ 41, YYAT_SHIFT, 73 },
		{ 39, YYAT_SHIFT, 70 },
		{ 36, YYAT_SHIFT, 68 },
		{ 35, YYAT_SHIFT, 67 },
		{ 34, YYAT_SHIFT, 66 },
		{ 29, YYAT_SHIFT, 48 },
		{ 11, YYAT_SHIFT, 42 },
		{ 10, YYAT_SHIFT, 41 },
		{ 9, YYAT_SHIFT, 40 },
		{ 8, YYAT_SHIFT, 39 },
		{ 7, YYAT_SHIFT, 38 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -104, 1, YYAT_ERROR, 0 },
		{ -136, 1, YYAT_ERROR, 0 },
		{ 152, 1, YYAT_ERROR, 0 },
		{ -139, 1, YYAT_ERROR, 0 },
		{ -135, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -140, 1, YYAT_ERROR, 0 },
		{ -141, 1, YYAT_ERROR, 0 },
		{ -142, 1, YYAT_ERROR, 0 },
		{ -146, 1, YYAT_ERROR, 0 },
		{ -146, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 78 },
		{ -142, 1, YYAT_ERROR, 0 },
		{ -257, 1, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ -151, 1, YYAT_REDUCE, 38 },
		{ -225, 1, YYAT_REDUCE, 29 },
		{ -145, 1, YYAT_DEFAULT, 109 },
		{ -140, 1, YYAT_REDUCE, 25 },
		{ -140, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ -148, 1, YYAT_DEFAULT, 98 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ -128, 1, YYAT_ERROR, 0 },
		{ -129, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ -153, 1, YYAT_DEFAULT, 126 },
		{ -148, 1, YYAT_REDUCE, 20 },
		{ -153, 1, YYAT_ERROR, 0 },
		{ -153, 1, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 76 },
		{ -157, 1, YYAT_DEFAULT, 126 },
		{ -156, 1, YYAT_DEFAULT, 98 },
		{ -157, 1, YYAT_DEFAULT, 109 },
		{ -160, 1, YYAT_DEFAULT, 126 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ -160, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ -163, 1, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ -141, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ -158, 1, YYAT_REDUCE, 33 },
		{ -165, 1, YYAT_REDUCE, 34 },
		{ -172, 1, YYAT_REDUCE, 31 },
		{ -179, 1, YYAT_REDUCE, 32 },
		{ -186, 1, YYAT_REDUCE, 35 },
		{ -193, 1, YYAT_REDUCE, 36 },
		{ -200, 1, YYAT_REDUCE, 37 },
		{ -213, 1, YYAT_REDUCE, 30 },
		{ -159, 1, YYAT_REDUCE, 24 },
		{ -216, 1, YYAT_REDUCE, 26 },
		{ -243, 1, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -226, 1, YYAT_DEFAULT, 118 },
		{ -225, 1, YYAT_DEFAULT, 109 },
		{ -241, 1, YYAT_DEFAULT, 76 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ -238, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -254, 1, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -249, 1, YYAT_DEFAULT, 126 },
		{ -251, 1, YYAT_DEFAULT, 118 },
		{ -263, 1, YYAT_DEFAULT, 118 },
		{ -259, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -277, 1, YYAT_DEFAULT, 126 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -289, 1, YYAT_DEFAULT, 126 },
		{ -245, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ 0, 0, YYAT_DEFAULT, 130 },
		{ -260, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ -245, 1, YYAT_DEFAULT, 98 },
		{ 0, 0, YYAT_REDUCE, 53 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 62;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 130, 23 },
		{ 125, 129 },
		{ 130, 131 },
		{ 130, 28 },
		{ 78, 103 },
		{ 78, 47 },
		{ 130, 21 },
		{ 130, 25 },
		{ 130, 34 },
		{ 118, 126 },
		{ 118, 35 },
		{ 118, 36 },
		{ 68, 94 },
		{ 68, 32 },
		{ 130, 22 },
		{ 130, 26 },
		{ 130, 24 },
		{ 130, 27 },
		{ 130, 31 },
		{ 67, 93 },
		{ 67, 33 },
		{ 64, 91 },
		{ 64, 37 },
		{ 30, 49 },
		{ 30, 30 },
		{ 124, 128 },
		{ 122, 127 },
		{ 116, 123 },
		{ 114, 121 },
		{ 113, 120 },
		{ 111, 119 },
		{ 108, 117 },
		{ 107, 115 },
		{ 105, 112 },
		{ 99, 110 },
		{ 98, 109 },
		{ 96, 106 },
		{ 95, 104 },
		{ 76, 102 },
		{ 70, 97 },
		{ 65, 92 },
		{ 63, 90 },
		{ 62, 89 },
		{ 61, 88 },
		{ 60, 87 },
		{ 59, 86 },
		{ 58, 85 },
		{ 57, 84 },
		{ 54, 83 },
		{ 53, 82 },
		{ 52, 81 },
		{ 51, 80 },
		{ 50, 79 },
		{ 40, 72 },
		{ 39, 71 },
		{ 38, 69 },
		{ 28, 46 },
		{ 20, 44 },
		{ 18, 43 },
		{ 5, 29 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 60, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 58, -1 },
		{ 56, 30 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 43, -1 },
		{ 0, -1 },
		{ 47, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 78 },
		{ 0, -1 },
		{ 20, 130 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, 118 },
		{ 44, 118 },
		{ 43, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, -1 },
		{ 36, -1 },
		{ 35, -1 },
		{ 34, -1 },
		{ 33, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 64 },
		{ 32, 64 },
		{ 31, 64 },
		{ 30, 64 },
		{ 29, 64 },
		{ 28, 64 },
		{ 27, 64 },
		{ 7, -1 },
		{ 30, 118 },
		{ 0, -1 },
		{ 7, 68 },
		{ -1, 64 },
		{ 0, -1 },
		{ 29, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 28, 118 },
		{ 0, -1 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 33, 130 },
		{ 26, 118 },
		{ 0, -1 },
		{ 25, 118 },
		{ 30, 130 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 130 },
		{ 0, -1 },
		{ 22, 118 },
		{ 21, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 26, 130 },
		{ 0, -1 },
		{ 25, 130 },
		{ 24, 130 },
		{ 0, -1 },
		{ 23, 130 },
		{ 0, -1 },
		{ -1, 67 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 22, 130 },
		{ 0, -1 },
		{ 21, 130 },
		{ -3, 130 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 118 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 242 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

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
					cout<<setw(8)<<"symbol:"<<setw(17)<<find_key(node->val);
          			break;
				}
				case Type:
				{
					cout.setf(ios::left);
					cout<<setw(25)<<types[node->type];
          			break;

				}
			}
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
string myparser::find_key(int val)
{
auto x=ids.begin();
while (x!=ids.end())
{
if(x->second==val)
{

return x->first;
}
x++;
}

}
