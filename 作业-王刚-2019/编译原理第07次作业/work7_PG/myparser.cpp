/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 115 of your 30 day trial period.
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
* Date: 12/25/19
* Time: 15:27:20
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

#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "mylexer.h"
#include "grammer_tree.h"
#include "symbol.h"

#include <set>

extern GrammerTree parse_tree;
extern symbol_table_type symtbl;


set<int> id_pos;
int decl_var_cnt=0;
	
#line 60 "myparser.cpp"
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
#line 35 ".\\myparser.y"

	// place any extra initialisation code here

#line 84 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 40 ".\\myparser.y"

	// place any extra cleanup code here

#line 98 "myparser.cpp"
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
#line 71 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(4 - 4);
#line 208 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 75 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, ID_LEAF, yyattribute(1 - 1)->attr.symtbl_seq, Notype);
			(*(YYSTYPE YYFAR*)yyvalptr)->output();
			parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
		
#line 225 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 83 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, CONST_LEAF, yyattribute(1 - 1)->attr.vali, Integer);
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
                      
#line 241 "myparser.cpp"
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
#line 88 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, CONST_LEAF, yyattribute(1 - 1)->attr.vald,Double);
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
                      
#line 257 "myparser.cpp"
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
#line 93 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, CONST_LEAF, yyattribute(1 - 1)->attr.valc, Char);
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
                   	  
#line 273 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 100 ".\\myparser.y"

								GrammerTreeNode * p;
								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(DECL_NODE, VAR_DECL, 0, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
								
								for (p = yyattribute(2 - 3); p; p = p->sibling)
								{
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(p);
									(p->children[0])->type = yyattribute(1 - 3)->type;
									symtbl.setType((p->children[0])->attr.symtbl_seq, (p->children[0])->type);
									
									id_pos.insert((p->children[0])->attr.symtbl_seq);
									decl_var_cnt++;
									
									if(decl_var_cnt!=id_pos.size()){
										cerr<<"Symbol \""<<symtbl.symbol_table[(p->children[0])->attr.symtbl_seq].name<<"\" duplicate definited!"<<endl;
										freopen("CON", "r", stdin);
										system("pause");
									}
								}// end for
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
						  
#line 307 "myparser.cpp"
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
#line 125 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
									
#line 322 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 129 ".\\myparser.y"

										GrammerTreeNode * t = yyattribute(1 - 3);
										if (t!=NULL){
											while (t->sibling!=NULL)
												t=t->sibling;
											t->sibling = yyattribute(3 - 3);
											(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3);
										}
										else 
											(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(3 - 3);
									
#line 345 "myparser.cpp"
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
#line 143 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(DECL_NODE, DECLARATOR, 0, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 1));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
							
#line 362 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 149 ".\\myparser.y"

								//这里为了体现int a=1这类的变量声明，创建了新种类的结点
								//主要还是想不太好怎样理解这个过程
								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(DECL_NODE, DECLARATOR, 0, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
							
#line 382 "myparser.cpp"
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
#line 160 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, TYPE_LEAF, 0, Integer);
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
                      
#line 398 "myparser.cpp"
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
#line 165 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, TYPE_LEAF, 0, Char);
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
                      
#line 414 "myparser.cpp"
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
#line 170 ".\\myparser.y"
 
						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, TYPE_LEAF, 0, Double);
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
                      
#line 430 "myparser.cpp"
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
#line 225 ".\\myparser.y"

			(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(LEAF_NODE, ID_LEAF, yyattribute(1 - 1)->attr.symtbl_seq, Notype);
			(*(YYSTYPE YYFAR*)yyvalptr)->output();
			parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
		
#line 447 "myparser.cpp"
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
#line 233 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
									if(((*(YYSTYPE YYFAR*)yyvalptr)->attr.symtbl_seq!=0)&&(symtbl.getType((*(YYSTYPE YYFAR*)yyvalptr)->attr.symtbl_seq)==Notype)){
										cout<<"Undeclared identifier!"<<endl;
									}
								
#line 465 "myparser.cpp"
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
#line 240 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
								
#line 480 "myparser.cpp"
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
#line 244 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
								
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
#line 250 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
								
#line 510 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 254 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, POSTFIX_EXPR, PLUS2, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 2));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
									parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
								
#line 528 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 261 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, POSTFIX_EXPR, MINUS2, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 2));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
									parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
								
#line 546 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 270 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
								
#line 561 "myparser.cpp"
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
#line 274 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, PLUS2, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(2 - 2));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
									parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
								
#line 579 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 281 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, MINUS2, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(2 - 2));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
									parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
								
#line 597 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 288 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, MINUS, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(2 - 2));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
								
#line 614 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 294 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, PLUS, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(2 - 2));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
								
#line 631 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 300 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, NOT, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(2 - 2));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
								
#line 648 "myparser.cpp"
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
#line 308 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
							
#line 663 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 312 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, CAST_EXPR, 0, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(2 - 4));
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(4 - 4));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
							
#line 681 "myparser.cpp"
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
#line 321 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
								
#line 696 "myparser.cpp"
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
#line 325 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, TIMES, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
									parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
								
#line 715 "myparser.cpp"
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
#line 333 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, OVER, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
									parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
								
#line 734 "myparser.cpp"
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
#line 341 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MOD, Notype);
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
									((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
									parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
								
#line 753 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 351 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
									
#line 768 "myparser.cpp"
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
#line 355 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, PLUS, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
										parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
									
#line 787 "myparser.cpp"
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
#line 363 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MINUS, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
										parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
									
#line 806 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 373 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
							
#line 821 "myparser.cpp"
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
#line 377 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, LSHIFT, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
								parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
							
#line 840 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 385 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, RSHIFT, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
								parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
							
#line 859 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 395 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
									
#line 874 "myparser.cpp"
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
#line 399 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, LT, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 892 "myparser.cpp"
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
#line 406 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, GT, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 910 "myparser.cpp"
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
#line 413 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, LE, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 928 "myparser.cpp"
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
#line 420 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, GE, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 946 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 429 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
									
#line 961 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 433 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, EQ, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 979 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 440 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, NE, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 997 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 449 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
							
#line 1012 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 453 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, BIT_AND, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
								parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
							
#line 1031 "myparser.cpp"
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
#line 463 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
							
#line 1046 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 467 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, BIT_XOR, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
								parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
							
#line 1065 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 477 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
							
#line 1080 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 481 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, BIT_OR, Notype);
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
								((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
								(*(YYSTYPE YYFAR*)yyvalptr)->output();
								parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
							
#line 1099 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 491 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
										
#line 1114 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 495 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, AND, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1132 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 504 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
										
#line 1147 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 508 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, OR, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1165 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 517 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
										
#line 1180 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 521 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, COND_EXPR, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 5));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 5));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 5));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1199 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 531 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
										
#line 1214 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 535 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, ASSIGN, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
											parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
										
#line 1233 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 543 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, PLUSA, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
											parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
										
#line 1252 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 551 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MINUSA, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
											parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
										
#line 1271 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 559 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, TIMESA, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
											parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
										
#line 1290 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 567 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, OVERA, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
											parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
										
#line 1309 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 575 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MODA, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 3));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 3));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
											parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
										
#line 1328 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 585 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1343 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 589 ".\\myparser.y"
	
						GrammerTreeNode * t=yyattribute(1 - 3);
						if(t!=NULL){
							while(t->sibling!=NULL)
								t=t->sibling;
							t->sibling=yyattribute(3 - 3);
							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3);
						}
						else
							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(3 - 3);
					
#line 1366 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 603 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1381 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 607 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1396 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 611 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1411 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 615 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1426 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 619 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1441 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 623 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1456 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 627 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
					
#line 1471 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 633 ".\\myparser.y"

										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, COMP_STMT, 0, Notype);
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 1487 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 638 ".\\myparser.y"

										GrammerTreeNode * t=yyattribute(2 - 3);
										(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, COMP_STMT, 0, Notype);
										((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(t);
										//这里需不需要判断t为NULL还需考虑
										while (t->sibling != NULL){
											t = t->sibling;
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(t);
										}
										(*(YYSTYPE YYFAR*)yyvalptr)->output();
									
#line 1510 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 652 ".\\myparser.y"

								(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
							
#line 1525 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 656 ".\\myparser.y"

								GrammerTreeNode * t=yyattribute(1 - 2);
								if (t!=NULL){
								
									while (t->sibling!=NULL)
										t=t->sibling;
										
									t->sibling = yyattribute(2 - 2);
									(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
								}
								else 
									(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2);
							
#line 1550 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 672 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
						
#line 1565 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 676 ".\\myparser.y"

							(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
						
#line 1580 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 682 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, EXPR_STMT, 0, Notype);
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
											parse_tree.GetTempVar((*(YYSTYPE YYFAR*)yyvalptr));
										
#line 1597 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 688 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, EXPR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(1 - 2));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1614 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 696 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1627 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 698 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1640 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 701 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, IF_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(7 - 7));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1659 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 709 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, IF_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 5));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 5));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1677 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 717 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, SWITCH_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 5));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 5));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1695 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 726 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1708 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 728 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1721 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 730 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1734 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 733 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, WHILE_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 5));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 5));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1752 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 741 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, DO_WHILE_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(2 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 7));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1770 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 749 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 9));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 9));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(7 - 9));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(9 - 9));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1790 "myparser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 758 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(8 - 8));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1809 "myparser.cpp"
			}
		}
		break;
	case 94:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 766 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(6 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(8 - 8));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1828 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 774 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(7 - 7));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1846 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 781 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(4 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(6 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(8 - 8));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1865 "myparser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 789 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(4 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(7 - 7));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1883 "myparser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 796 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(7 - 7));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1901 "myparser.cpp"
			}
		}
		break;
	case 99:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 803 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(6 - 6));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1918 "myparser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 809 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(4 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(6 - 8));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(8 - 8));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1938 "myparser.cpp"
			}
		}
		break;
	case 101:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 818 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(4 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(7 - 7));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1957 "myparser.cpp"
			}
		}
		break;
	case 102:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 826 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(5 - 7));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(7 - 7));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1976 "myparser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 834 ".\\myparser.y"

											(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 6));
											((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(6 - 6));
											(*(YYSTYPE YYFAR*)yyvalptr)->output();
										
#line 1994 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 843 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, JUMP_STMT, 0, Notype);
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
								
#line 2010 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 848 ".\\myparser.y"

									(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, JUMP_STMT, 0, Notype);
									(*(YYSTYPE YYFAR*)yyvalptr)->output();
								
#line 2026 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 855 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, INPUT_STMT, 0, Notype);
						((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 5));
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
					
#line 2043 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 863 ".\\myparser.y"

						(*(YYSTYPE YYFAR*)yyvalptr) = parse_tree.MakeNode(STMT_NODE, PRINT_STMT, 0, Notype);
						((*(YYSTYPE YYFAR*)yyvalptr)->children).push_back(yyattribute(3 - 5));
						(*(YYSTYPE YYFAR*)yyvalptr)->output();
					
#line 2060 "myparser.cpp"
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
		{ "MAIN", 257 },
		{ "INT", 258 },
		{ "CHAR", 259 },
		{ "DOUBLE", 260 },
		{ "IF", 261 },
		{ "ELSE", 262 },
		{ "FOR", 263 },
		{ "WHILE", 264 },
		{ "DO", 265 },
		{ "SWITCH", 266 },
		{ "BREAK", 269 },
		{ "CONTINUE", 270 },
		{ "ID", 271 },
		{ "DOUBLE_NUM", 272 },
		{ "INT_NUM", 273 },
		{ "CONSTCHAR", 274 },
		{ "PLUS2", 275 },
		{ "MINUS2", 276 },
		{ "PLUS", 277 },
		{ "MINUS", 278 },
		{ "TIMES", 279 },
		{ "OVER", 280 },
		{ "MOD", 281 },
		{ "LSHIFT", 282 },
		{ "RSHIFT", 283 },
		{ "LT", 284 },
		{ "LE", 285 },
		{ "GT", 286 },
		{ "GE", 287 },
		{ "EQ", 288 },
		{ "NE", 289 },
		{ "BIT_AND", 290 },
		{ "BIT_XOR", 291 },
		{ "BIT_OR", 292 },
		{ "AND", 293 },
		{ "OR", 294 },
		{ "QMARK", 295 },
		{ "COLON", 296 },
		{ "ASSIGN", 297 },
		{ "PLUSA", 298 },
		{ "MINUSA", 299 },
		{ "TIMESA", 300 },
		{ "OVERA", 301 },
		{ "MODA", 302 },
		{ "LPAREN", 303 },
		{ "RPAREN", 304 },
		{ "LBRACE", 305 },
		{ "RBRACE", 306 },
		{ "SEMICOLON", 307 },
		{ "COMMA", 308 },
		{ "NOT", 309 },
		{ "INPUT", 310 },
		{ "PRINT", 311 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: MAIN LPAREN RPAREN compound_statement",
		"id: ID",
		"constant: INT_NUM",
		"constant: DOUBLE_NUM",
		"constant: CONSTCHAR",
		"var_declaration: type_specifier init_declarator_list SEMICOLON",
		"init_declarator_list: init_declarator",
		"init_declarator_list: init_declarator_list COMMA init_declarator",
		"init_declarator: id",
		"init_declarator: id ASSIGN assignment_expression",
		"type_specifier: INT",
		"type_specifier: CHAR",
		"type_specifier: DOUBLE",
		"var: ID",
		"primary_expression: var",
		"primary_expression: constant",
		"primary_expression: LPAREN expression RPAREN",
		"postfix_expression: primary_expression",
		"postfix_expression: postfix_expression PLUS2",
		"postfix_expression: postfix_expression MINUS2",
		"unary_expression: postfix_expression",
		"unary_expression: PLUS2 unary_expression",
		"unary_expression: MINUS2 unary_expression",
		"unary_expression: MINUS unary_expression",
		"unary_expression: PLUS unary_expression",
		"unary_expression: NOT unary_expression",
		"cast_expression: unary_expression",
		"cast_expression: LPAREN type_specifier RPAREN cast_expression",
		"multi_expression: cast_expression",
		"multi_expression: multi_expression TIMES cast_expression",
		"multi_expression: multi_expression OVER cast_expression",
		"multi_expression: multi_expression MOD cast_expression",
		"additive_expression: multi_expression",
		"additive_expression: additive_expression PLUS multi_expression",
		"additive_expression: additive_expression MINUS multi_expression",
		"shift_expression: additive_expression",
		"shift_expression: shift_expression LSHIFT additive_expression",
		"shift_expression: shift_expression RSHIFT additive_expression",
		"relational_expression: shift_expression",
		"relational_expression: relational_expression LT shift_expression",
		"relational_expression: relational_expression GT shift_expression",
		"relational_expression: relational_expression LE shift_expression",
		"relational_expression: relational_expression GE shift_expression",
		"equality_expression: relational_expression",
		"equality_expression: equality_expression EQ relational_expression",
		"equality_expression: equality_expression NE relational_expression",
		"AND_expression: equality_expression",
		"AND_expression: AND_expression BIT_AND equality_expression",
		"XOR_expression: AND_expression",
		"XOR_expression: XOR_expression BIT_XOR AND_expression",
		"OR_expression: XOR_expression",
		"OR_expression: OR_expression BIT_OR XOR_expression",
		"logical_AND_expression: OR_expression",
		"logical_AND_expression: logical_AND_expression AND OR_expression",
		"logical_OR_expression: logical_AND_expression",
		"logical_OR_expression: logical_OR_expression OR logical_AND_expression",
		"conditional_expression: logical_OR_expression",
		"conditional_expression: logical_OR_expression QMARK expression COLON conditional_expression",
		"assignment_expression: conditional_expression",
		"assignment_expression: unary_expression ASSIGN assignment_expression",
		"assignment_expression: unary_expression PLUSA assignment_expression",
		"assignment_expression: unary_expression MINUSA assignment_expression",
		"assignment_expression: unary_expression TIMESA assignment_expression",
		"assignment_expression: unary_expression OVERA assignment_expression",
		"assignment_expression: unary_expression MODA assignment_expression",
		"expression: assignment_expression",
		"expression: expression COMMA assignment_expression",
		"statement: compound_statement",
		"statement: expression_statement",
		"statement: selection_statement",
		"statement: iteration_statement",
		"statement: jump_statement",
		"statement: input_statement",
		"statement: print_statement",
		"compound_statement: LBRACE RBRACE",
		"compound_statement: LBRACE block_item_list RBRACE",
		"block_item_list: block_item",
		"block_item_list: block_item_list block_item",
		"block_item: var_declaration",
		"block_item: statement",
		"expression_statement: SEMICOLON",
		"expression_statement: expression SEMICOLON",
		"selection_statement: if_statement",
		"selection_statement: switch_statement",
		"if_statement: IF LPAREN expression RPAREN statement ELSE statement",
		"if_statement: IF LPAREN expression RPAREN statement",
		"switch_statement: SWITCH LPAREN expression RPAREN statement",
		"iteration_statement: while_statement",
		"iteration_statement: do_while_statment",
		"iteration_statement: for_statement",
		"while_statement: WHILE LPAREN expression RPAREN statement",
		"do_while_statment: DO statement WHILE LPAREN expression RPAREN SEMICOLON",
		"for_statement: FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement",
		"for_statement: FOR LPAREN expression SEMICOLON expression SEMICOLON RPAREN statement",
		"for_statement: FOR LPAREN expression SEMICOLON SEMICOLON expression RPAREN statement",
		"for_statement: FOR LPAREN expression SEMICOLON SEMICOLON RPAREN statement",
		"for_statement: FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement",
		"for_statement: FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement",
		"for_statement: FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement",
		"for_statement: FOR LPAREN SEMICOLON SEMICOLON RPAREN statement",
		"for_statement: FOR LPAREN var_declaration expression SEMICOLON expression RPAREN statement",
		"for_statement: FOR LPAREN var_declaration expression SEMICOLON RPAREN statement",
		"for_statement: FOR LPAREN var_declaration SEMICOLON expression RPAREN statement",
		"for_statement: FOR LPAREN var_declaration SEMICOLON RPAREN statement",
		"jump_statement: CONTINUE SEMICOLON",
		"jump_statement: BREAK SEMICOLON",
		"input_statement: INPUT LPAREN expression RPAREN SEMICOLON",
		"print_statement: PRINT LPAREN expression RPAREN SEMICOLON"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 4, 0 },
		{ 2, 1, 1 },
		{ 3, 1, 2 },
		{ 3, 1, 3 },
		{ 3, 1, 4 },
		{ 4, 3, 5 },
		{ 5, 1, 6 },
		{ 5, 3, 7 },
		{ 6, 1, 8 },
		{ 6, 3, 9 },
		{ 7, 1, 10 },
		{ 7, 1, 11 },
		{ 7, 1, 12 },
		{ 8, 1, 13 },
		{ 9, 1, 14 },
		{ 9, 1, 15 },
		{ 9, 3, 16 },
		{ 10, 1, 17 },
		{ 10, 2, 18 },
		{ 10, 2, 19 },
		{ 11, 1, 20 },
		{ 11, 2, 21 },
		{ 11, 2, 22 },
		{ 11, 2, 23 },
		{ 11, 2, 24 },
		{ 11, 2, 25 },
		{ 12, 1, 26 },
		{ 12, 4, 27 },
		{ 13, 1, 28 },
		{ 13, 3, 29 },
		{ 13, 3, 30 },
		{ 13, 3, 31 },
		{ 14, 1, 32 },
		{ 14, 3, 33 },
		{ 14, 3, 34 },
		{ 15, 1, 35 },
		{ 15, 3, 36 },
		{ 15, 3, 37 },
		{ 16, 1, 38 },
		{ 16, 3, 39 },
		{ 16, 3, 40 },
		{ 16, 3, 41 },
		{ 16, 3, 42 },
		{ 17, 1, 43 },
		{ 17, 3, 44 },
		{ 17, 3, 45 },
		{ 18, 1, 46 },
		{ 18, 3, 47 },
		{ 19, 1, 48 },
		{ 19, 3, 49 },
		{ 20, 1, 50 },
		{ 20, 3, 51 },
		{ 21, 1, 52 },
		{ 21, 3, 53 },
		{ 22, 1, 54 },
		{ 22, 3, 55 },
		{ 23, 1, 56 },
		{ 23, 5, 57 },
		{ 24, 1, 58 },
		{ 24, 3, 59 },
		{ 24, 3, 60 },
		{ 24, 3, 61 },
		{ 24, 3, 62 },
		{ 24, 3, 63 },
		{ 24, 3, 64 },
		{ 25, 1, 65 },
		{ 25, 3, 66 },
		{ 26, 1, 67 },
		{ 26, 1, 68 },
		{ 26, 1, 69 },
		{ 26, 1, 70 },
		{ 26, 1, 71 },
		{ 26, 1, 72 },
		{ 26, 1, 73 },
		{ 27, 2, 74 },
		{ 27, 3, 75 },
		{ 28, 1, 76 },
		{ 28, 2, 77 },
		{ 29, 1, 78 },
		{ 29, 1, 79 },
		{ 30, 1, 80 },
		{ 30, 2, 81 },
		{ 31, 1, 82 },
		{ 31, 1, 83 },
		{ 32, 7, 84 },
		{ 32, 5, 85 },
		{ 33, 5, 86 },
		{ 34, 1, 87 },
		{ 34, 1, 88 },
		{ 34, 1, 89 },
		{ 35, 5, 90 },
		{ 36, 7, 91 },
		{ 37, 9, 92 },
		{ 37, 8, 93 },
		{ 37, 8, 94 },
		{ 37, 7, 95 },
		{ 37, 8, 96 },
		{ 37, 7, 97 },
		{ 37, 7, 98 },
		{ 37, 6, 99 },
		{ 37, 8, 100 },
		{ 37, 7, 101 },
		{ 37, 7, 102 },
		{ 37, 6, 103 },
		{ 38, 2, 104 },
		{ 38, 2, 105 },
		{ 39, 5, 106 },
		{ 40, 5, 107 }
	};
	yyreduction = reduction;

	yytokenaction_size = 147;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 218, YYAT_SHIFT, 10 },
		{ 202, YYAT_SHIFT, 214 },
		{ 218, YYAT_SHIFT, 11 },
		{ 218, YYAT_SHIFT, 12 },
		{ 218, YYAT_SHIFT, 13 },
		{ 218, YYAT_SHIFT, 14 },
		{ 180, YYAT_SHIFT, 197 },
		{ 180, YYAT_SHIFT, 87 },
		{ 218, YYAT_SHIFT, 15 },
		{ 218, YYAT_SHIFT, 16 },
		{ 197, YYAT_SHIFT, 17 },
		{ 197, YYAT_SHIFT, 18 },
		{ 197, YYAT_SHIFT, 19 },
		{ 197, YYAT_SHIFT, 20 },
		{ 197, YYAT_SHIFT, 21 },
		{ 197, YYAT_SHIFT, 22 },
		{ 197, YYAT_SHIFT, 23 },
		{ 197, YYAT_SHIFT, 24 },
		{ 68, YYAT_SHIFT, 7 },
		{ 68, YYAT_SHIFT, 8 },
		{ 68, YYAT_SHIFT, 9 },
		{ 65, YYAT_SHIFT, 7 },
		{ 65, YYAT_SHIFT, 8 },
		{ 65, YYAT_SHIFT, 9 },
		{ 44, YYAT_SHIFT, 105 },
		{ 44, YYAT_SHIFT, 106 },
		{ 44, YYAT_SHIFT, 107 },
		{ 44, YYAT_SHIFT, 108 },
		{ 44, YYAT_SHIFT, 109 },
		{ 44, YYAT_SHIFT, 110 },
		{ 138, YYAT_SHIFT, 88 },
		{ 138, YYAT_SHIFT, 89 },
		{ 138, YYAT_SHIFT, 90 },
		{ 158, YYAT_SHIFT, 174 },
		{ 140, YYAT_SHIFT, 95 },
		{ 140, YYAT_SHIFT, 96 },
		{ 140, YYAT_SHIFT, 97 },
		{ 140, YYAT_SHIFT, 98 },
		{ 139, YYAT_SHIFT, 95 },
		{ 139, YYAT_SHIFT, 96 },
		{ 139, YYAT_SHIFT, 97 },
		{ 139, YYAT_SHIFT, 98 },
		{ 197, YYAT_SHIFT, 25 },
		{ 197, YYAT_SHIFT, 209 },
		{ 218, YYAT_SHIFT, 5 },
		{ 158, YYAT_SHIFT, 87 },
		{ 218, YYAT_SHIFT, 27 },
		{ 201, YYAT_SHIFT, 213 },
		{ 197, YYAT_SHIFT, 28 },
		{ 218, YYAT_SHIFT, 29 },
		{ 218, YYAT_SHIFT, 30 },
		{ 40, YYAT_SHIFT, 95 },
		{ 40, YYAT_SHIFT, 96 },
		{ 40, YYAT_SHIFT, 97 },
		{ 40, YYAT_SHIFT, 98 },
		{ 137, YYAT_SHIFT, 88 },
		{ 137, YYAT_SHIFT, 89 },
		{ 137, YYAT_SHIFT, 90 },
		{ 34, YYAT_SHIFT, 88 },
		{ 34, YYAT_SHIFT, 89 },
		{ 34, YYAT_SHIFT, 90 },
		{ 210, YYAT_SHIFT, 218 },
		{ 159, YYAT_SHIFT, 93 },
		{ 159, YYAT_SHIFT, 94 },
		{ 196, YYAT_SHIFT, 208 },
		{ 210, YYAT_SHIFT, 87 },
		{ 194, YYAT_SHIFT, 206 },
		{ 68, YYAT_SHIFT, 120 },
		{ 185, YYAT_SHIFT, 202 },
		{ 65, YYAT_SHIFT, 117 },
		{ 144, YYAT_SHIFT, 84 },
		{ 144, YYAT_SHIFT, 85 },
		{ 143, YYAT_SHIFT, 84 },
		{ 143, YYAT_SHIFT, 85 },
		{ 142, YYAT_SHIFT, 84 },
		{ 142, YYAT_SHIFT, 85 },
		{ 141, YYAT_SHIFT, 84 },
		{ 141, YYAT_SHIFT, 85 },
		{ 132, YYAT_SHIFT, 91 },
		{ 132, YYAT_SHIFT, 92 },
		{ 130, YYAT_SHIFT, 91 },
		{ 130, YYAT_SHIFT, 92 },
		{ 101, YYAT_SHIFT, 146 },
		{ 101, YYAT_SHIFT, 147 },
		{ 50, YYAT_SHIFT, 114 },
		{ 50, YYAT_SHIFT, 115 },
		{ 42, YYAT_SHIFT, 103 },
		{ 42, YYAT_SHIFT, 104 },
		{ 39, YYAT_SHIFT, 93 },
		{ 39, YYAT_SHIFT, 94 },
		{ 38, YYAT_SHIFT, 91 },
		{ 38, YYAT_SHIFT, 92 },
		{ 32, YYAT_SHIFT, 84 },
		{ 32, YYAT_SHIFT, 85 },
		{ 183, YYAT_SHIFT, 200 },
		{ 182, YYAT_SHIFT, 199 },
		{ 179, YYAT_SHIFT, 195 },
		{ 178, YYAT_SHIFT, 193 },
		{ 177, YYAT_SHIFT, 192 },
		{ 175, YYAT_SHIFT, 190 },
		{ 174, YYAT_ERROR, 0 },
		{ 171, YYAT_SHIFT, 188 },
		{ 170, YYAT_SHIFT, 187 },
		{ 165, YYAT_SHIFT, 183 },
		{ 164, YYAT_SHIFT, 181 },
		{ 163, YYAT_SHIFT, 179 },
		{ 162, YYAT_SHIFT, 178 },
		{ 161, YYAT_SHIFT, 176 },
		{ 157, YYAT_SHIFT, 113 },
		{ 156, YYAT_SHIFT, 111 },
		{ 155, YYAT_SHIFT, 116 },
		{ 154, YYAT_SHIFT, 112 },
		{ 147, YYAT_SHIFT, 99 },
		{ 129, YYAT_SHIFT, 171 },
		{ 128, YYAT_SHIFT, 170 },
		{ 125, YYAT_SHIFT, 168 },
		{ 124, YYAT_SHIFT, 167 },
		{ 123, YYAT_SHIFT, 166 },
		{ 122, YYAT_SHIFT, 164 },
		{ 121, YYAT_SHIFT, 163 },
		{ 120, YYAT_SHIFT, 161 },
		{ 119, YYAT_SHIFT, 160 },
		{ 100, YYAT_SHIFT, 145 },
		{ 80, YYAT_SHIFT, 127 },
		{ 79, YYAT_SHIFT, 126 },
		{ 70, YYAT_SHIFT, 124 },
		{ 52, YYAT_SHIFT, 116 },
		{ 49, YYAT_SHIFT, 113 },
		{ 48, YYAT_SHIFT, 112 },
		{ 47, YYAT_SHIFT, 111 },
		{ 33, YYAT_SHIFT, 86 },
		{ 30, YYAT_SHIFT, 83 },
		{ 29, YYAT_SHIFT, 82 },
		{ 28, YYAT_SHIFT, 74 },
		{ 25, YYAT_ERROR, 0 },
		{ 16, YYAT_SHIFT, 73 },
		{ 15, YYAT_SHIFT, 72 },
		{ 14, YYAT_SHIFT, 71 },
		{ 12, YYAT_SHIFT, 69 },
		{ 11, YYAT_SHIFT, 68 },
		{ 10, YYAT_SHIFT, 67 },
		{ 5, YYAT_SHIFT, 26 },
		{ 4, YYAT_SHIFT, 5 },
		{ 3, YYAT_SHIFT, 4 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -111, 1, YYAT_ERROR, 0 },
		{ -158, 1, YYAT_ERROR, 0 },
		{ 144, 1, YYAT_ERROR, 0 },
		{ -161, 1, YYAT_ERROR, 0 },
		{ -163, 1, YYAT_ERROR, 0 },
		{ -165, 1, YYAT_DEFAULT, 65 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -163, 1, YYAT_ERROR, 0 },
		{ -164, 1, YYAT_ERROR, 0 },
		{ -165, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -166, 1, YYAT_ERROR, 0 },
		{ -171, 1, YYAT_ERROR, 0 },
		{ -172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_DEFAULT, 28 },
		{ 0, 0, YYAT_DEFAULT, 28 },
		{ 0, 0, YYAT_DEFAULT, 28 },
		{ 0, 0, YYAT_DEFAULT, 28 },
		{ -173, 1, YYAT_DEFAULT, 68 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ -170, 1, YYAT_DEFAULT, 174 },
		{ -171, 1, YYAT_ERROR, 0 },
		{ -172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ -190, 1, YYAT_REDUCE, 39 },
		{ -177, 1, YYAT_DEFAULT, 180 },
		{ -221, 1, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ -187, 1, YYAT_REDUCE, 36 },
		{ -200, 1, YYAT_REDUCE, 47 },
		{ -233, 1, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ -189, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -273, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -163, 1, YYAT_REDUCE, 53 },
		{ -163, 1, YYAT_REDUCE, 51 },
		{ -166, 1, YYAT_REDUCE, 55 },
		{ -210, 1, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ -164, 1, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ -237, 1, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ -240, 1, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ -139, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ -180, 1, YYAT_DEFAULT, 210 },
		{ -181, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -175, 1, YYAT_REDUCE, 9 },
		{ -225, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ -183, 1, YYAT_DEFAULT, 210 },
		{ -187, 1, YYAT_DEFAULT, 174 },
		{ -188, 1, YYAT_DEFAULT, 180 },
		{ -189, 1, YYAT_DEFAULT, 174 },
		{ -187, 1, YYAT_DEFAULT, 210 },
		{ -187, 1, YYAT_ERROR, 0 },
		{ -189, 1, YYAT_DEFAULT, 210 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ -190, 1, YYAT_DEFAULT, 210 },
		{ -191, 1, YYAT_DEFAULT, 210 },
		{ -197, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ -199, 1, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ -224, 1, YYAT_REDUCE, 34 },
		{ -249, 1, YYAT_REDUCE, 35 },
		{ -246, 1, YYAT_REDUCE, 45 },
		{ -250, 1, YYAT_REDUCE, 46 },
		{ -206, 1, YYAT_REDUCE, 40 },
		{ -208, 1, YYAT_REDUCE, 42 },
		{ -210, 1, YYAT_REDUCE, 41 },
		{ -212, 1, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ -180, 1, YYAT_REDUCE, 52 },
		{ -180, 1, YYAT_REDUCE, 50 },
		{ -183, 1, YYAT_REDUCE, 54 },
		{ -185, 1, YYAT_REDUCE, 56 },
		{ -263, 1, YYAT_ERROR, 0 },
		{ -226, 1, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -197, 1, YYAT_DEFAULT, 197 },
		{ -201, 1, YYAT_DEFAULT, 180 },
		{ -202, 1, YYAT_DEFAULT, 174 },
		{ -200, 1, YYAT_DEFAULT, 197 },
		{ -204, 1, YYAT_DEFAULT, 180 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -205, 1, YYAT_ERROR, 0 },
		{ -206, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -204, 1, YYAT_DEFAULT, 197 },
		{ -163, 1, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -206, 1, YYAT_DEFAULT, 210 },
		{ -207, 1, YYAT_DEFAULT, 197 },
		{ -208, 1, YYAT_DEFAULT, 197 },
		{ -301, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -209, 1, YYAT_DEFAULT, 210 },
		{ -210, 1, YYAT_DEFAULT, 197 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ -236, 1, YYAT_DEFAULT, 210 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -238, 1, YYAT_DEFAULT, 210 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -240, 1, YYAT_DEFAULT, 210 },
		{ -261, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -257, 1, YYAT_DEFAULT, 210 },
		{ -306, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ -243, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 0, 0, YYAT_DEFAULT, 218 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ -261, 1, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 93 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 144;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 218, 45 },
		{ 127, 169 },
		{ 127, -1 },
		{ 127, -1 },
		{ 213, 219 },
		{ 218, 43 },
		{ 218, 37 },
		{ 218, 42 },
		{ 218, 44 },
		{ 218, 46 },
		{ 218, 34 },
		{ 218, 38 },
		{ 218, 32 },
		{ 218, 40 },
		{ 218, 39 },
		{ 218, 52 },
		{ 218, 48 },
		{ 218, 47 },
		{ 218, 49 },
		{ 218, 50 },
		{ 218, 54 },
		{ 218, 35 },
		{ 218, 33 },
		{ 218, 220 },
		{ 218, 31 },
		{ 145, 172 },
		{ 145, -1 },
		{ 218, 53 },
		{ 218, 63 },
		{ 218, 60 },
		{ 218, 58 },
		{ 218, 64 },
		{ 218, 61 },
		{ 218, 55 },
		{ 218, 56 },
		{ 218, 66 },
		{ 218, 57 },
		{ 218, 59 },
		{ 197, 210 },
		{ 197, -1 },
		{ 197, -1 },
		{ 113, 156 },
		{ 113, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 197, -1 },
		{ 65, 36 },
		{ 174, 131 },
		{ 68, 122 },
		{ 65, 41 },
		{ 209, 217 },
		{ 68, 41 },
		{ 116, 159 },
		{ 116, -1 },
		{ 116, -1 },
		{ 114, 157 },
		{ 114, -1 },
		{ 114, -1 },
		{ 147, 100 },
		{ 174, 189 },
		{ 174, -1 },
		{ 208, 216 },
		{ 147, 173 },
		{ 112, 39 },
		{ 112, 155 },
		{ 111, 154 },
		{ 111, -1 },
		{ 206, 215 },
		{ 65, 51 },
		{ 68, 121 },
		{ 200, 212 },
		{ 65, 118 },
		{ 98, 144 },
		{ 98, -1 },
		{ 94, 140 },
		{ 94, -1 },
		{ 92, 46 },
		{ 92, 138 },
		{ 85, 132 },
		{ 85, -1 },
		{ 41, 101 },
		{ 41, 102 },
		{ 28, 81 },
		{ 28, -1 },
		{ 5, 65 },
		{ 5, 62 },
		{ 199, 211 },
		{ 195, 207 },
		{ 193, 205 },
		{ 192, 204 },
		{ 190, 203 },
		{ 183, 201 },
		{ 181, 198 },
		{ 179, 196 },
		{ 178, 194 },
		{ 176, 191 },
		{ 168, 186 },
		{ 167, 185 },
		{ 166, 184 },
		{ 164, 182 },
		{ 163, 180 },
		{ 161, 177 },
		{ 160, 175 },
		{ 122, 165 },
		{ 120, 162 },
		{ 115, 158 },
		{ 110, 153 },
		{ 109, 152 },
		{ 108, 151 },
		{ 107, 150 },
		{ 106, 149 },
		{ 105, 148 },
		{ 97, 143 },
		{ 96, 142 },
		{ 95, 141 },
		{ 93, 139 },
		{ 91, 137 },
		{ 90, 136 },
		{ 89, 135 },
		{ 88, 134 },
		{ 87, 133 },
		{ 84, 130 },
		{ 83, 129 },
		{ 82, 128 },
		{ 74, 79 },
		{ 71, 125 },
		{ 69, 123 },
		{ 67, 119 },
		{ 25, 80 },
		{ 24, 78 },
		{ 23, 77 },
		{ 22, 76 },
		{ 21, 75 },
		{ 13, 70 },
		{ 4, 6 },
		{ 0, 2 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 142, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 115, -1 },
		{ 64, 65 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 115, 218 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 129, 28 },
		{ 128, 28 },
		{ 127, 28 },
		{ 126, 28 },
		{ 129, 74 },
		{ 0, -1 },
		{ 0, -1 },
		{ 79, 127 },
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
		{ 83, 147 },
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
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 218 },
		{ 0, -1 },
		{ 110, 197 },
		{ 52, 197 },
		{ 109, 197 },
		{ 0, -1 },
		{ 108, 197 },
		{ 0, -1 },
		{ 0, -1 },
		{ 107, 197 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 106, 197 },
		{ 105, 197 },
		{ 115, 85 },
		{ 72, 98 },
		{ 0, -1 },
		{ 104, 145 },
		{ 115, 127 },
		{ 114, 127 },
		{ 113, 127 },
		{ 111, 92 },
		{ 72, 127 },
		{ 107, 94 },
		{ 66, 116 },
		{ 107, 98 },
		{ 106, 98 },
		{ 105, 98 },
		{ 65, 94 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 95, 145 },
		{ 94, 145 },
		{ 93, 145 },
		{ 92, 145 },
		{ 91, 145 },
		{ 90, 145 },
		{ 54, 113 },
		{ 54, 116 },
		{ 21, 114 },
		{ 42, 174 },
		{ 88, 197 },
		{ 43, 111 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 87, 197 },
		{ 0, -1 },
		{ 86, 197 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -11, 85 },
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
		{ 1, 197 },
		{ 0, -1 },
		{ 64, -1 },
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
		{ 84, 218 },
		{ 84, 197 },
		{ 0, -1 },
		{ 83, 197 },
		{ 82, 197 },
		{ 0, -1 },
		{ 80, 218 },
		{ 80, 197 },
		{ 78, 218 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 44, 145 },
		{ 0, -1 },
		{ 77, 218 },
		{ 0, -1 },
		{ 77, 197 },
		{ 76, 197 },
		{ 0, -1 },
		{ 74, 218 },
		{ 0, -1 },
		{ 74, 197 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 72, 218 },
		{ 0, -1 },
		{ 71, 218 },
		{ 70, 218 },
		{ 0, -1 },
		{ 69, 218 },
		{ 0, -1 },
		{ 13, 218 },
		{ 0, -1 },
		{ 68, 218 },
		{ 52, 218 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 218 },
		{ 0, -1 },
		{ 43, 218 },
		{ 32, 218 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -22, 218 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 870 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section


