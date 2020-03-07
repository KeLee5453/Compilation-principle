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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/05/19
* Time: 18:37:02
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
struct idNameType
{
	string name;
	ExpType type;
};
extern idNameType ids[1000];
struct res
{
	int resLine;
	string resStr;
};
res checkRes[100];
int resKount=0;

#line 129 "myparser.cpp"
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
#line 113 ".\\myparser.y"

	// place any extra initialisation code here

#line 153 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 118 ".\\myparser.y"

	// place any extra cleanup code here

#line 167 "myparser.cpp"
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
#line 151 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(4 - 4);root=yyattribute(4 - 4);display(root);showCheckRes();
#line 277 "myparser.cpp"
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
#line 153 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,Complex);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(2 - 3);
#line 290 "myparser.cpp"
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
#line 155 ".\\myparser.y"

							if(yyattribute(1 - 2)!=NULL)
							{
							while(yyattribute(1 - 2)->brother!=NULL)
							yyattribute(1 - 2)=yyattribute(1 - 2)->brother;
							yyattribute(1 - 2)->brother=yyattribute(2 - 2);
							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
							}
							else 
							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
							
#line 313 "myparser.cpp"
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
#line 166 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 326 "myparser.cpp"
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
#line 168 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 339 "myparser.cpp"
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
#line 169 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 352 "myparser.cpp"
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
#line 170 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 365 "myparser.cpp"
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
#line 171 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 378 "myparser.cpp"
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
#line 172 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 391 "myparser.cpp"
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
#line 173 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 404 "myparser.cpp"
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
#line 174 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 417 "myparser.cpp"
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
#line 175 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 430 "myparser.cpp"
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
#line 177 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Int;
#line 443 "myparser.cpp"
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
#line 178 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Char;
#line 456 "myparser.cpp"
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
#line 179 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Bool;
#line 469 "myparser.cpp"
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
#line 180 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Type);(*(YYSTYPE YYFAR*)yyvalptr)->type=Void;
#line 482 "myparser.cpp"
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
#line 182 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->brother=yyattribute(3 - 3);
#line 495 "myparser.cpp"
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
#line 183 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 508 "myparser.cpp"
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
#line 185 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=ASSIGN;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 521 "myparser.cpp"
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
#line 186 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 534 "myparser.cpp"
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
#line 188 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Decl,Var);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(2 - 3);
#line 547 "myparser.cpp"
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
#line 190 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2);
#line 560 "myparser.cpp"
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
#line 191 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=NULL;
#line 573 "myparser.cpp"
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
#line 194 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=ASSIGN;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 586 "myparser.cpp"
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
#line 195 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 599 "myparser.cpp"
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
#line 197 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=OR;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 612 "myparser.cpp"
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
#line 198 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 625 "myparser.cpp"
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
#line 200 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=AND;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 638 "myparser.cpp"
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
#line 201 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 651 "myparser.cpp"
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
#line 204 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=EQ;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 664 "myparser.cpp"
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
#line 205 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=GE;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 677 "myparser.cpp"
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
#line 206 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=LE;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 690 "myparser.cpp"
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
#line 207 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=GT;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 703 "myparser.cpp"
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
#line 208 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=LT;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 716 "myparser.cpp"
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
#line 209 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=NEQ;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 729 "myparser.cpp"
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
#line 210 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=LM;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 742 "myparser.cpp"
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
#line 211 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=RM;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 755 "myparser.cpp"
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
#line 212 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 768 "myparser.cpp"
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
#line 215 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=PLUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 781 "myparser.cpp"
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
#line 216 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=MINUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 794 "myparser.cpp"
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
#line 217 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=MUL;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 807 "myparser.cpp"
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
#line 218 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=DIV;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 820 "myparser.cpp"
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
#line 219 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=REMI;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 3);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(3 - 3);
#line 833 "myparser.cpp"
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
#line 220 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=DPLUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 2);
#line 846 "myparser.cpp"
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
#line 221 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=DMINUS;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(1 - 2);
#line 859 "myparser.cpp"
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
#line 222 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 872 "myparser.cpp"
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
#line 224 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
#line 885 "myparser.cpp"
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
#line 225 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 898 "myparser.cpp"
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
#line 226 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 911 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 227 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 924 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 228 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Expr,Op);(*(YYSTYPE YYFAR*)yyvalptr)->val=NOT;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(2 - 2);
#line 937 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 231 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,If);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 5);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 5);
#line 950 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 232 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,If);yyattribute(3 - 7)->type=Bool;(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(7 - 7);
#line 963 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 235 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 9);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 9);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(7 - 9);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(9 - 9);
#line 976 "myparser.cpp"
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
#line 236 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(4 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(6 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(8 - 8);
#line 989 "myparser.cpp"
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
#line 237 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(6 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(8 - 8);
#line 1002 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 238 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 8);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(8 - 8);
#line 1015 "myparser.cpp"
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
#line 239 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[2]=yyattribute(5 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(7 - 7);
#line 1028 "myparser.cpp"
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
#line 240 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(4 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(7 - 7);
#line 1041 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 241 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 7);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(7 - 7);
#line 1054 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 242 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,For);(*(YYSTYPE YYFAR*)yyvalptr)->child[3]=yyattribute(6 - 6);
#line 1067 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 245 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,While);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 5);(*(YYSTYPE YYFAR*)yyvalptr)->child[1]=yyattribute(5 - 5);
#line 1080 "myparser.cpp"
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
#line 248 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,Input);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 4);
#line 1093 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 250 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=createNode(Stmt,Output);(*(YYSTYPE YYFAR*)yyvalptr)->child[0]=yyattribute(3 - 4);
#line 1106 "myparser.cpp"
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
		{ "CHARACTER", 269 },
		{ "PLUS", 270 },
		{ "MINUS", 271 },
		{ "MUL", 272 },
		{ "DIV", 273 },
		{ "REMI", 274 },
		{ "DPLUS", 275 },
		{ "DMINUS", 276 },
		{ "GT", 277 },
		{ "LT", 278 },
		{ "GE", 279 },
		{ "LE", 280 },
		{ "NEQ", 281 },
		{ "AND", 282 },
		{ "OR", 283 },
		{ "NOT", 284 },
		{ "ASSIGN", 285 },
		{ "LFP", 286 },
		{ "RFP", 287 },
		{ "COMMA", 288 },
		{ "SEMI", 289 },
		{ "LP", 290 },
		{ "RP", 291 },
		{ "LM", 292 },
		{ "RM", 293 },
		{ "EQ", 294 },
		{ "ELSE", 297 },
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
		"term: CHARACTER",
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
		"input_stmt: CIN RM term SEMI",
		"output_stmt: COUT LM term SEMI",
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
		{ 15, 1, 49 },
		{ 15, 2, 50 },
		{ 16, 5, 51 },
		{ 16, 7, 52 },
		{ 17, 9, 53 },
		{ 17, 8, 54 },
		{ 17, 8, 55 },
		{ 17, 8, 56 },
		{ 17, 7, 57 },
		{ 17, 7, 58 },
		{ 17, 7, 59 },
		{ 17, 6, 60 },
		{ 18, 5, 61 },
		{ 19, 4, 62 },
		{ 20, 4, 63 },
		{ 21, 0, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 155;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 33, YYAT_SHIFT, 7 },
		{ 118, YYAT_SHIFT, 125 },
		{ 33, YYAT_SHIFT, 8 },
		{ 33, YYAT_SHIFT, 9 },
		{ 33, YYAT_SHIFT, 10 },
		{ 33, YYAT_SHIFT, 11 },
		{ 33, YYAT_SHIFT, 12 },
		{ 33, YYAT_SHIFT, 13 },
		{ 33, YYAT_SHIFT, 14 },
		{ 33, YYAT_SHIFT, 15 },
		{ 33, YYAT_SHIFT, 16 },
		{ 33, YYAT_SHIFT, 17 },
		{ 33, YYAT_SHIFT, 18 },
		{ 131, YYAT_SHIFT, 7 },
		{ 116, YYAT_SHIFT, 123 },
		{ 131, YYAT_SHIFT, 8 },
		{ 131, YYAT_SHIFT, 9 },
		{ 131, YYAT_SHIFT, 10 },
		{ 131, YYAT_SHIFT, 11 },
		{ 131, YYAT_SHIFT, 12 },
		{ 131, YYAT_SHIFT, 13 },
		{ 131, YYAT_SHIFT, 14 },
		{ 131, YYAT_SHIFT, 15 },
		{ 119, YYAT_SHIFT, 16 },
		{ 119, YYAT_SHIFT, 17 },
		{ 119, YYAT_SHIFT, 18 },
		{ 110, YYAT_SHIFT, 53 },
		{ 33, YYAT_SHIFT, 19 },
		{ 109, YYAT_SHIFT, 117 },
		{ 33, YYAT_SHIFT, 5 },
		{ 110, YYAT_SHIFT, 119 },
		{ 108, YYAT_SHIFT, 115 },
		{ 33, YYAT_SHIFT, 20 },
		{ 33, YYAT_SHIFT, 21 },
		{ 91, YYAT_SHIFT, 55 },
		{ 91, YYAT_SHIFT, 56 },
		{ 91, YYAT_SHIFT, 57 },
		{ 91, YYAT_SHIFT, 58 },
		{ 91, YYAT_SHIFT, 59 },
		{ 107, YYAT_SHIFT, 114 },
		{ 119, YYAT_SHIFT, 19 },
		{ 105, YYAT_SHIFT, 112 },
		{ 131, YYAT_SHIFT, 5 },
		{ 103, YYAT_SHIFT, 53 },
		{ 99, YYAT_SHIFT, 109 },
		{ 131, YYAT_SHIFT, 20 },
		{ 119, YYAT_SHIFT, 21 },
		{ 119, YYAT_SHIFT, 126 },
		{ 98, YYAT_SHIFT, 108 },
		{ 91, YYAT_SHIFT, 60 },
		{ 91, YYAT_SHIFT, 61 },
		{ 91, YYAT_SHIFT, 62 },
		{ 25, YYAT_SHIFT, 55 },
		{ 25, YYAT_SHIFT, 56 },
		{ 25, YYAT_SHIFT, 57 },
		{ 25, YYAT_SHIFT, 58 },
		{ 25, YYAT_SHIFT, 59 },
		{ 90, YYAT_SHIFT, 46 },
		{ 90, YYAT_SHIFT, 47 },
		{ 90, YYAT_SHIFT, 48 },
		{ 90, YYAT_SHIFT, 49 },
		{ 90, YYAT_SHIFT, 50 },
		{ 90, YYAT_SHIFT, 51 },
		{ 90, YYAT_SHIFT, 52 },
		{ 97, YYAT_SHIFT, 106 },
		{ 94, YYAT_SHIFT, 66 },
		{ 93, YYAT_ERROR, 0 },
		{ 25, YYAT_SHIFT, 60 },
		{ 25, YYAT_SHIFT, 61 },
		{ 25, YYAT_SHIFT, 62 },
		{ 89, YYAT_SHIFT, 46 },
		{ 89, YYAT_SHIFT, 47 },
		{ 89, YYAT_SHIFT, 48 },
		{ 89, YYAT_SHIFT, 49 },
		{ 89, YYAT_SHIFT, 50 },
		{ 89, YYAT_SHIFT, 51 },
		{ 89, YYAT_SHIFT, 52 },
		{ 88, YYAT_SHIFT, 46 },
		{ 88, YYAT_SHIFT, 47 },
		{ 88, YYAT_SHIFT, 48 },
		{ 88, YYAT_SHIFT, 49 },
		{ 88, YYAT_SHIFT, 50 },
		{ 88, YYAT_SHIFT, 51 },
		{ 88, YYAT_SHIFT, 52 },
		{ 87, YYAT_SHIFT, 46 },
		{ 87, YYAT_SHIFT, 47 },
		{ 87, YYAT_SHIFT, 48 },
		{ 87, YYAT_SHIFT, 49 },
		{ 87, YYAT_SHIFT, 50 },
		{ 87, YYAT_SHIFT, 51 },
		{ 87, YYAT_SHIFT, 52 },
		{ 86, YYAT_SHIFT, 46 },
		{ 86, YYAT_SHIFT, 47 },
		{ 86, YYAT_SHIFT, 48 },
		{ 86, YYAT_SHIFT, 49 },
		{ 86, YYAT_SHIFT, 50 },
		{ 86, YYAT_SHIFT, 51 },
		{ 86, YYAT_SHIFT, 52 },
		{ 85, YYAT_SHIFT, 46 },
		{ 85, YYAT_SHIFT, 47 },
		{ 85, YYAT_SHIFT, 48 },
		{ 85, YYAT_SHIFT, 49 },
		{ 85, YYAT_SHIFT, 50 },
		{ 85, YYAT_SHIFT, 51 },
		{ 85, YYAT_SHIFT, 52 },
		{ 84, YYAT_SHIFT, 46 },
		{ 84, YYAT_SHIFT, 47 },
		{ 84, YYAT_SHIFT, 48 },
		{ 84, YYAT_SHIFT, 49 },
		{ 84, YYAT_SHIFT, 50 },
		{ 84, YYAT_SHIFT, 51 },
		{ 84, YYAT_SHIFT, 52 },
		{ 83, YYAT_SHIFT, 46 },
		{ 83, YYAT_SHIFT, 47 },
		{ 83, YYAT_SHIFT, 48 },
		{ 83, YYAT_SHIFT, 49 },
		{ 83, YYAT_SHIFT, 50 },
		{ 83, YYAT_SHIFT, 51 },
		{ 83, YYAT_SHIFT, 52 },
		{ 22, YYAT_SHIFT, 46 },
		{ 22, YYAT_SHIFT, 47 },
		{ 22, YYAT_SHIFT, 48 },
		{ 22, YYAT_SHIFT, 49 },
		{ 22, YYAT_SHIFT, 50 },
		{ 22, YYAT_SHIFT, 51 },
		{ 22, YYAT_SHIFT, 52 },
		{ 127, YYAT_SHIFT, 53 },
		{ 92, YYAT_SHIFT, 63 },
		{ 82, YYAT_SHIFT, 53 },
		{ 75, YYAT_SHIFT, 102 },
		{ 74, YYAT_SHIFT, 101 },
		{ 73, YYAT_SHIFT, 100 },
		{ 127, YYAT_SHIFT, 131 },
		{ 72, YYAT_SHIFT, 99 },
		{ 71, YYAT_SHIFT, 97 },
		{ 70, YYAT_SHIFT, 96 },
		{ 68, YYAT_SHIFT, 95 },
		{ 67, YYAT_SHIFT, 94 },
		{ 66, YYAT_SHIFT, 93 },
		{ 45, YYAT_SHIFT, 76 },
		{ 40, YYAT_SHIFT, 71 },
		{ 28, YYAT_SHIFT, 65 },
		{ 27, YYAT_SHIFT, 64 },
		{ 26, YYAT_SHIFT, 63 },
		{ 24, YYAT_SHIFT, 54 },
		{ 11, YYAT_SHIFT, 43 },
		{ 10, YYAT_SHIFT, 42 },
		{ 9, YYAT_SHIFT, 41 },
		{ 8, YYAT_SHIFT, 40 },
		{ 7, YYAT_SHIFT, 39 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -104, 1, YYAT_ERROR, 0 },
		{ -137, 1, YYAT_ERROR, 0 },
		{ 152, 1, YYAT_ERROR, 0 },
		{ -140, 1, YYAT_ERROR, 0 },
		{ -136, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -141, 1, YYAT_ERROR, 0 },
		{ -142, 1, YYAT_ERROR, 0 },
		{ -143, 1, YYAT_ERROR, 0 },
		{ -147, 1, YYAT_ERROR, 0 },
		{ -147, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ -151, 1, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ -145, 1, YYAT_DEFAULT, 110 },
		{ -225, 1, YYAT_REDUCE, 29 },
		{ -139, 1, YYAT_REDUCE, 27 },
		{ -141, 1, YYAT_REDUCE, 25 },
		{ -146, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 94 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -257, 1, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ -149, 1, YYAT_DEFAULT, 99 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ -152, 1, YYAT_DEFAULT, 127 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -147, 1, YYAT_REDUCE, 20 },
		{ -151, 1, YYAT_REDUCE, 18 },
		{ -153, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -156, 1, YYAT_DEFAULT, 127 },
		{ -155, 1, YYAT_DEFAULT, 99 },
		{ -156, 1, YYAT_DEFAULT, 110 },
		{ -160, 1, YYAT_DEFAULT, 127 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ -160, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ -157, 1, YYAT_REDUCE, 24 },
		{ -158, 1, YYAT_REDUCE, 33 },
		{ -165, 1, YYAT_REDUCE, 34 },
		{ -172, 1, YYAT_REDUCE, 31 },
		{ -179, 1, YYAT_REDUCE, 32 },
		{ -186, 1, YYAT_REDUCE, 35 },
		{ -193, 1, YYAT_REDUCE, 36 },
		{ -200, 1, YYAT_REDUCE, 37 },
		{ -213, 1, YYAT_REDUCE, 30 },
		{ -243, 1, YYAT_REDUCE, 28 },
		{ -155, 1, YYAT_REDUCE, 26 },
		{ -225, 1, YYAT_DEFAULT, 119 },
		{ -202, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ -227, 1, YYAT_DEFAULT, 119 },
		{ -241, 1, YYAT_DEFAULT, 110 },
		{ -245, 1, YYAT_DEFAULT, 93 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ -242, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -256, 1, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ -252, 1, YYAT_DEFAULT, 127 },
		{ -260, 1, YYAT_DEFAULT, 119 },
		{ -263, 1, YYAT_DEFAULT, 119 },
		{ -259, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ -277, 1, YYAT_DEFAULT, 127 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ -290, 1, YYAT_DEFAULT, 127 },
		{ -244, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ 0, 0, YYAT_DEFAULT, 131 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ -244, 1, YYAT_DEFAULT, 99 },
		{ 0, 0, YYAT_REDUCE, 54 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 67;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 131, 32 },
		{ 126, 130 },
		{ 131, 132 },
		{ 131, 29 },
		{ 94, 104 },
		{ 94, 67 },
		{ 131, 34 },
		{ 131, 31 },
		{ 131, 24 },
		{ 119, 127 },
		{ 119, 27 },
		{ 119, 26 },
		{ 119, 25 },
		{ 119, 22 },
		{ 131, 35 },
		{ 131, 36 },
		{ 131, 38 },
		{ 131, 30 },
		{ 131, 37 },
		{ 64, -1 },
		{ 64, -1 },
		{ 64, 92 },
		{ 63, -1 },
		{ 63, 91 },
		{ 62, 90 },
		{ 62, 23 },
		{ 33, 69 },
		{ 33, 33 },
		{ 125, 129 },
		{ 123, 128 },
		{ 117, 124 },
		{ 115, 122 },
		{ 114, 121 },
		{ 112, 120 },
		{ 109, 118 },
		{ 108, 116 },
		{ 106, 113 },
		{ 100, 111 },
		{ 99, 110 },
		{ 97, 107 },
		{ 96, 105 },
		{ 93, 103 },
		{ 71, 98 },
		{ 61, 89 },
		{ 60, 88 },
		{ 59, 87 },
		{ 58, 86 },
		{ 57, 85 },
		{ 56, 84 },
		{ 55, 83 },
		{ 53, 82 },
		{ 50, 81 },
		{ 49, 80 },
		{ 48, 79 },
		{ 47, 78 },
		{ 46, 77 },
		{ 43, 75 },
		{ 42, 74 },
		{ 41, 73 },
		{ 40, 72 },
		{ 39, 70 },
		{ 29, 68 },
		{ 21, 45 },
		{ 19, 44 },
		{ 5, 28 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 65, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 63, -1 },
		{ 61, 33 },
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
		{ 48, -1 },
		{ 0, -1 },
		{ 52, 119 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 55, 94 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, 131 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 119 },
		{ 49, 119 },
		{ 48, 119 },
		{ 42, -1 },
		{ 41, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, -1 },
		{ 39, -1 },
		{ 38, -1 },
		{ 37, -1 },
		{ 36, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 40, 119 },
		{ 0, -1 },
		{ 35, 62 },
		{ 34, 62 },
		{ 33, 62 },
		{ 32, 62 },
		{ 31, 62 },
		{ 30, 62 },
		{ 29, 62 },
		{ 10, -1 },
		{ 10, 64 },
		{ 9, 119 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 32, 119 },
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
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 31, 119 },
		{ -2, -1 },
		{ 0, -1 },
		{ 36, 131 },
		{ 29, 119 },
		{ 0, -1 },
		{ 28, 119 },
		{ 33, 131 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 32, 131 },
		{ 0, -1 },
		{ 25, 119 },
		{ 24, 119 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 131 },
		{ 0, -1 },
		{ 28, 131 },
		{ 27, 131 },
		{ 0, -1 },
		{ 26, 131 },
		{ 0, -1 },
		{ -1, 62 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 25, 131 },
		{ 0, -1 },
		{ 24, 131 },
		{ -3, 131 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 119 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 258 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section
void myparser::showCheckRes()
{
	cout<<"---------------------------------------------------"<<endl;
	for(int i=0;i<resKount;i++)
	{
		cout<<checkRes[i].resLine<<":"<<checkRes[i].resStr<<endl;
	}
}
void myparser::typeError(TreeNode* t,string str)
{
	checkRes[resKount].resLine=t->lineno;
	checkRes[resKount].resStr=str;
	resKount++;
}
void myparser::checkNode(TreeNode * t)
{ 
	if(t->nodetype==Expr)
	{
      switch (t->specifictype)
      { 
		case Op:
			if (t->val==ASSIGN)
			{
				//cout<<ids[t->child[0]->val].type<<endl;
				//cout<<t->child[1]->type<<endl<<endl;
				if(ids[t->child[0]->val].type==Void)
				{
					typeError(t,"未定义标识符"+ids[t->child[0]->val].name);
				}
				else if(ids[t->child[0]->val].type!=t->child[1]->type)
				{
					
					typeError(t,"赋值类型不符");
				}
				t->type=t->child[0]->type;
			}
			else if(t->val==AND||t->val==OR)
			{
				if((t->child[0]->type!=Bool&&t->child[0]->type!=Int&&t->child[0]->type!=Char)||
				(t->child[1]->type!=Bool&&t->child[1]->type!=Int&&t->child[1]->type!=Char)){
					typeError(t,"AND OR -- Operand is not Bool/Int/Char  ");
				}
				t->type=t->child[0]->type;
			}
			else if(t->val==NOT)
			{
				if((t->child[0]->type!=Bool&&t->child[0]->type!=Int&&t->child[0]->type!=Char))
					typeError(t,"NOT -- Operand is not Bool/Int/Char ");
				t->type=t->child[0]->type;
			}
			else if(t->val==PLUS||(t->val==MUL||t->val==REMI||t->val==DIV))
			{
				if((t->child[0]->type!=Int&&t->child[0]->type!=Char)||(t->child [1]->type!=Int&&t->child[1]->type!=Char))
					typeError(t,"PLUS MUL REMI DIV -- Operand is not Int/Char");
				if(t->child[0]->type!=t->child [1]->type )
					typeError(t,"Operand different type" );
					t->type=t->child[0]->type;
			}
			else if(t->val==MINUS)//减或负号
			{
				if(t->child[1]!=NULL)
				{  
					if((t->child[0]->type!=Int&&t->child[0]->type!=Char)||(t->child [1]->type!=Int&&t->child[1]->type!=Char))
						typeError(t,"MINUS -- Operand is not Int/Char ");
					if(t->child[0]->type !=t->child [1]->type )
						typeError(t,"Operand different type");
				}
				else 
				{
					if(t->child[0]->type!=Int&&t->child [0]->type!=Char)
						typeError(t,"MINUS -- Operand is not Int/Char ");
				}	
				t->type=t->child[0]->type;
			}
			else if(t->val==DPLUS||t->val ==DMINUS)
			{
				if(t->child[0]->type!=Int&&t->child[0]->type!=Char)
					typeError(t,"DPLUS DMINUS -- Operand is not Int/Char ");
				t->type=t->child[0]->type;
			}
			else if(t->val==EQ||t->val==GT||t->val==LT||t->val==GE||t->val==LE||t->val==NEQ)    //关系运算运算左右是integer或char
			{
				if((t->child[0]->type!=Int&&t->child[0]->type!=Char)||(t->child [1]->type!=Int&&t->child[1]->type!=Char))
					typeError(t,"关系运算符--Operand is not Int/Char");
				if(t->child[0]->type!=t->child [1]->type )
					typeError(t,"Operand different type");
				t->type=Bool;
			}	
          break;
		case Idk:
			if(ids[t->val].type!=Void)t->type=ids[t->val].type;
			break;
        default:
          break;
      }
	}
    else if(t->nodetype==Stmt)
	{
      switch (t->specifictype)
      { case If:
          if (t->child[0]->type != Bool)
            typeError(t->child[0],"IF --expr not Bool");
          break;
        case While:
          if (t->child[0]->type != Bool)
            typeError(t->child[0],"WHILE --expr not Bool");
          break;
        case For:
          if (t->child[0]!= NULL)
		  {
            if(t->child[0]->type!=Int)
				typeError(t->child[0],"FOR --child[0] is not Int");
		  }
		  if(t->child[1]!= NULL)
		  {
			if(t->child[1]->type!=Bool)
				typeError(t->child[1],"FOR --child[1] is not Bool");
	      }
		  if(t->child[2]!= NULL)
		  {
			if(t->child[2]->type!=Int)
				typeError(t->child[2],"FOR --child[2] is not Int");
		  }
		  break;
		case Output:
		{
			if(t->child[0]!=NULL)
			{
				if(t->child[0]->type==Bool)
				{
					typeError(t->child[0],"OUTPUT --expr should not be Bool");
				}
			}

		}
        default:
          break;
      }
    }
	else if(t->nodetype==Decl)//主要为了给声明语句中id的type赋值
	{
		if(t->specifictype==Var)
		{
			ExpType tp=t->child[0]->type;
			TreeNode* temp=t->child[1];
			if(temp->child[0]!=NULL)//此时idExpr
			{
				ids[temp->child[0]->val].type=tp;
			}
			else ids[temp->val].type=tp;
			while(temp->brother!=NULL)
			{
				if(temp->brother->child[0]!=NULL)//此时idExpr
				{
					ids[temp->brother->child[0]->val].type=tp;
				}
				else ids[temp->brother->val].type=tp;
				temp=temp->brother;
			}
		}
	}
}
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
	checkNode(node);
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
					cout<<setw(8)<<"symbol:"<<setw(17)<<ids[node->val].name;
          			break;
				}
				case Type:
				{
					cout.setf(ios::left);
					cout<<setw(25)<<types[node->type];
          			break;

				}
			}
			outtype(node);
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
void myparser::outtype(struct TreeNode*node)
{
	ExpType tp=node->type;
	switch(tp)
	{
		case Int:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Int";
			break;
		}
		case Char:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Char";
			break;
		}
		case Void:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Void";
			break;
		}
		case Bool:
		{
			cout.setf(ios::left);
			cout<<setw(25)<<"Type:Bool";
			break;
		}
		default:
		break;
	}


}

