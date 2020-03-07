/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 59 of your 30 day trial period.
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
* Date: 10/30/19
* Time: 18:16:50
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

#line 58 "mylexer.cpp"
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
#line 33 ".\\mylexer.l"

	// place any extra initialisation code here

#line 82 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 38 ".\\mylexer.l"

	// place any extra cleanup code here

#line 94 "mylexer.cpp"
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
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 78 ".\\mylexer.l"
num_lines++;
#line 166 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 79 ".\\mylexer.l"
/* skip whitespace */
#line 173 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 80 ".\\mylexer.l"

#line 180 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 81 ".\\mylexer.l"
cout<<"INT\t\tint"<<endl;
#line 187 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 82 ".\\mylexer.l"
cout<<"CHAR\t\tchar"<<endl;
#line 194 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 83 ".\\mylexer.l"
cout<<"DOUBLE\t\tdouble"<<endl;
#line 201 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 84 ".\\mylexer.l"
cout<<"FLOAT\t\tfloat"<<endl;
#line 208 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 86 ".\\mylexer.l"
cout<<"IF\t\tif"<<endl;
#line 215 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 87 ".\\mylexer.l"
cout<<"ELSE\t\telse"<<endl;
#line 222 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 89 ".\\mylexer.l"
cout<<"FOR\t\tfor"<<endl;
#line 229 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 90 ".\\mylexer.l"
cout<<"DO\t\tdo"<<endl;
#line 236 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 91 ".\\mylexer.l"
cout<<"WHILE\t\twhile"<<endl;
#line 243 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 93 ".\\mylexer.l"
cout<<"SWITCH\t\tswitch"<<endl;
#line 250 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 94 ".\\mylexer.l"
cout<<"CASE\t\tcase"<<endl;
#line 257 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 95 ".\\mylexer.l"
cout<<"BREAK\t\tbreak"<<endl;
#line 264 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 96 ".\\mylexer.l"
cout<<"DEFAULT\t\tdefault"<<endl;
#line 271 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 97 ".\\mylexer.l"
cout<<"CONTINUE\t\tcontinue"<<endl;
#line 278 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 99 ".\\mylexer.l"
cout<<"TRUE\t\ttrue"<<endl;
#line 285 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 100 ".\\mylexer.l"
cout<<"FALSE\t\tfalse"<<endl;
#line 292 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 101 ".\\mylexer.l"
cout<<"RETURN\t\treturn"<<endl;
#line 299 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 103 ".\\mylexer.l"
cout<<"LBRACE\t\t"<<yytext<<endl;
#line 306 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 104 ".\\mylexer.l"
cout<<"RBRACE\t\t"<<yytext<<endl;
#line 313 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 105 ".\\mylexer.l"
cout<<"LPAREN\t\t"<<yytext<<endl;
#line 320 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 106 ".\\mylexer.l"
cout<<"RPAREN\t\t"<<yytext<<endl;
#line 327 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 107 ".\\mylexer.l"
cout<<"SIMI\t\t"<<yytext<<endl;
#line 334 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 108 ".\\mylexer.l"
cout<<"COMMA\t\t"<<yytext<<endl;
#line 341 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 110 ".\\mylexer.l"
cout<<"PLUS\t\t"<<yytext<<endl;
#line 348 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 111 ".\\mylexer.l"
cout<<"MINUS\t\t"<<yytext<<endl;
#line 355 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 112 ".\\mylexer.l"
cout<<"MUL\t\t"<<yytext<<endl;
#line 362 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 113 ".\\mylexer.l"
cout<<"DIV\t\t"<<yytext<<endl;
#line 369 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 114 ".\\mylexer.l"
cout<<"MOD\t\t"<<yytext<<endl;
#line 376 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 115 ".\\mylexer.l"
cout<<"bAND\t\t"<<yytext<<endl;
#line 383 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 117 ".\\mylexer.l"
cout<<"ASSIGN\t\t"<<yytext<<endl;
#line 390 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 118 ".\\mylexer.l"
cout<<"EQ\t\t"<<yytext<<endl;
#line 397 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 119 ".\\mylexer.l"
cout<<"LE\t\t"<<yytext<<endl;
#line 404 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 120 ".\\mylexer.l"
cout<<"LT\t\t"<<yytext<<endl;
#line 411 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 121 ".\\mylexer.l"
cout<<"NE\t\t"<<yytext<<endl;
#line 418 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 122 ".\\mylexer.l"
cout<<"GT\t\t"<<yytext<<endl;
#line 425 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 123 ".\\mylexer.l"
cout<<"GE\t\t"<<yytext<<endl;
#line 432 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 125 ".\\mylexer.l"
cout<<"AND\t\t"<<yytext<<endl;
#line 439 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 126 ".\\mylexer.l"
cout<<"OR\t\t"<<yytext<<endl;
#line 446 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 127 ".\\mylexer.l"
cout<<"NOT\t\t"<<yytext<<endl;
#line 453 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 129 ".\\mylexer.l"
cout<<"DPLUS\t\t"<<yytext<<endl;
#line 460 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 130 ".\\mylexer.l"
cout<<"DMINUS\t\t"<<yytext<<endl;
#line 467 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 131 ".\\mylexer.l"
cout<<"SHL\t\t"<<yytext<<endl;
#line 474 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 132 ".\\mylexer.l"
cout<<"SHR\t\t"<<yytext<<endl;
#line 481 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 134 ".\\mylexer.l"
string str=yytext;
           cout<<"NUMBER\t\t"<<yytext<<"\t\t"<<addNUM(str)<<endl;
#line 489 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 136 ".\\mylexer.l"
string strin=yytext;
			cout<<"ID\t\t"<<strin<<"\t\t"<<addID(strin)<<endl;
#line 497 "mylexer.cpp"
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

	yytransitionmax = 223;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 1 },
		{ 3, 3 },
		{ 38, 85 },
		{ 54, 25 },
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
		{ 55, 25 },
		{ 99, 85 },
		{ 51, 23 },
		{ 56, 25 },
		{ 68, 41 },
		{ 59, 27 },
		{ 68, 41 },
		{ 57, 26 },
		{ 3, 1 },
		{ 5, 1 },
		{ 3, 3 },
		{ 41, 67 },
		{ 52, 23 },
		{ 6, 1 },
		{ 7, 1 },
		{ 58, 26 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 60, 28 },
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
		{ 48, 22 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 0, 99 },
		{ 85, 64 },
		{ 49, 22 },
		{ 45, 19 },
		{ 46, 19 },
		{ 38, 14 },
		{ 66, 64 },
		{ 61, 29 },
		{ 64, 99 },
		{ 50, 22 },
		{ 39, 14 },
		{ 40, 15 },
		{ 65, 99 },
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
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 69, 69 },
		{ 42, 17 },
		{ 43, 17 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 62, 30 },
		{ 63, 32 },
		{ 26, 1 },
		{ 66, 39 },
		{ 0, 40 },
		{ 37, 13 },
		{ 71, 48 },
		{ 70, 47 },
		{ 72, 49 },
		{ 73, 50 },
		{ 74, 51 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 75, 52 },
		{ 76, 53 },
		{ 30, 1 },
		{ 77, 54 },
		{ 78, 55 },
		{ 80, 58 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 79, 56 },
		{ 81, 59 },
		{ 82, 60 },
		{ 83, 61 },
		{ 84, 62 },
		{ 47, 21 },
		{ 85, 65 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 34, 5 },
		{ 35, 7 },
		{ 86, 70 },
		{ 87, 71 },
		{ 20, 116 },
		{ 88, 72 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 20, 116 },
		{ 89, 73 },
		{ 90, 74 },
		{ 91, 75 },
		{ 92, 76 },
		{ 93, 77 },
		{ 94, 78 },
		{ 95, 81 },
		{ 96, 82 },
		{ 97, 83 },
		{ 98, 84 },
		{ 53, 24 },
		{ 100, 86 },
		{ 101, 89 },
		{ 102, 90 },
		{ 103, 91 },
		{ 104, 93 },
		{ 105, 94 },
		{ 106, 95 },
		{ 107, 96 },
		{ 108, 98 },
		{ 36, 11 },
		{ 109, 101 },
		{ 110, 102 },
		{ 111, 103 },
		{ 112, 106 },
		{ 113, 107 },
		{ 114, 109 },
		{ 115, 110 },
		{ 116, 114 },
		{ 44, 18 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 116, -8, 0 },
		{ 1, 0, 0 },
		{ 0, -6, 2 },
		{ 0, 0, 1 },
		{ 0, 100, 42 },
		{ 0, 0, 31 },
		{ 0, 124, 32 },
		{ 0, 0, 23 },
		{ 0, 0, 24 },
		{ 0, 0, 29 },
		{ 0, 170, 27 },
		{ 0, 0, 26 },
		{ 0, 55, 28 },
		{ 0, 18, 30 },
		{ 67, 20, 47 },
		{ 0, 0, 25 },
		{ 0, 28, 36 },
		{ 0, 161, 33 },
		{ 0, -3, 38 },
		{ 116, 0, 48 },
		{ 116, 19, 48 },
		{ 116, -47, 48 },
		{ 116, -83, 48 },
		{ 116, 95, 48 },
		{ 116, -92, 48 },
		{ 116, -79, 48 },
		{ 116, -80, 48 },
		{ 116, -81, 48 },
		{ 116, -52, 48 },
		{ 116, -9, 48 },
		{ 0, 0, 21 },
		{ 0, -28, 0 },
		{ 0, 0, 22 },
		{ 0, 0, 37 },
		{ 0, 0, 40 },
		{ 0, 0, 43 },
		{ 0, 0, 44 },
		{ 99, 0, 0 },
		{ -39, 88, 0 },
		{ 67, 30, 0 },
		{ 69, -23, 0 },
		{ 0, 0, 45 },
		{ 0, 0, 35 },
		{ 0, 0, 34 },
		{ 0, 0, 39 },
		{ 0, 0, 46 },
		{ 116, 1, 48 },
		{ 116, -14, 48 },
		{ 116, 6, 48 },
		{ 116, -6, 48 },
		{ 116, 3, 48 },
		{ 116, -8, 11 },
		{ 116, -5, 48 },
		{ 116, 4, 48 },
		{ 116, 2, 48 },
		{ 116, 14, 48 },
		{ 116, 0, 8 },
		{ 116, -2, 48 },
		{ 116, 13, 48 },
		{ 116, 25, 48 },
		{ 116, 14, 48 },
		{ 116, 27, 48 },
		{ 0, 0, 41 },
		{ -38, 14, 0 },
		{ 99, 92, 0 },
		{ 0, 0, 3 },
		{ 0, -42, 47 },
		{ 69, 0, 0 },
		{ 0, 30, 47 },
		{ 116, 66, 48 },
		{ 116, 63, 48 },
		{ 116, 52, 48 },
		{ 116, 77, 48 },
		{ 116, 97, 48 },
		{ 116, 97, 48 },
		{ 116, 95, 48 },
		{ 116, 82, 48 },
		{ 116, 101, 48 },
		{ 116, 0, 10 },
		{ 116, 0, 4 },
		{ 116, 82, 48 },
		{ 116, 84, 48 },
		{ 116, 100, 48 },
		{ 116, 94, 48 },
		{ 65, -30, 0 },
		{ 116, 97, 48 },
		{ 116, 0, 14 },
		{ 116, 0, 5 },
		{ 116, 100, 48 },
		{ 116, 89, 48 },
		{ 116, 99, 48 },
		{ 116, 0, 9 },
		{ 116, 107, 48 },
		{ 116, 93, 48 },
		{ 116, 96, 48 },
		{ 116, 112, 48 },
		{ 116, 0, 18 },
		{ 116, 111, 48 },
		{ -38, 21, 3 },
		{ 116, 0, 15 },
		{ 116, 104, 48 },
		{ 116, 107, 48 },
		{ 116, 115, 48 },
		{ 116, 0, 19 },
		{ 116, 0, 7 },
		{ 116, 107, 48 },
		{ 116, 114, 48 },
		{ 116, 0, 12 },
		{ 116, 102, 48 },
		{ 116, 104, 48 },
		{ 116, 0, 6 },
		{ 116, 0, 20 },
		{ 116, 0, 13 },
		{ 116, 120, 48 },
		{ 116, 0, 16 },
		{ 0, 70, 17 }
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
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 138 ".\\mylexer.l"


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


