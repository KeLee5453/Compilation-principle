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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/25/19
* Time: 15:27:20
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


#line 62 "mylexer.cpp"
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
#line 37 ".\\mylexer.l"

	// place any extra initialisation code here

#line 86 "mylexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 42 ".\\mylexer.l"

	// place any extra cleanup code here

#line 98 "mylexer.cpp"
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
#line 62 ".\\mylexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 169 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 68 ".\\mylexer.l"
/* do nothing */
#line 176 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 72 ".\\mylexer.l"
print_token(INT, yytext); return INT;
#line 183 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 73 ".\\mylexer.l"
print_token(CHAR, yytext); return CHAR;
#line 190 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 74 ".\\mylexer.l"
print_token(DOUBLE, yytext); return DOUBLE;
#line 197 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 76 ".\\mylexer.l"
print_token(INPUT,yytext);return INPUT;
#line 204 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 77 ".\\mylexer.l"
print_token(PRINT,yytext);return PRINT;
#line 211 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 79 ".\\mylexer.l"
print_token(MAIN, yytext); return MAIN;
#line 218 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 80 ".\\mylexer.l"
print_token(IF, yytext); return IF;
#line 225 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 81 ".\\mylexer.l"
print_token(ELSE, yytext); return ELSE;
#line 232 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 83 ".\\mylexer.l"
print_token(FOR, yytext); return FOR;
#line 239 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 84 ".\\mylexer.l"
print_token(WHILE, yytext); return WHILE;
#line 246 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 85 ".\\mylexer.l"
print_token(DO, yytext); return DO;
#line 253 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 87 ".\\mylexer.l"
print_token(SWITCH, yytext); return SWITCH;
#line 260 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 88 ".\\mylexer.l"
print_token(CASE, yytext); return CASE;
#line 267 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 89 ".\\mylexer.l"
print_token(DEFAULT, yytext); return DEFAULT;
#line 274 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 91 ".\\mylexer.l"
print_token(BREAK, yytext); return BREAK;
#line 281 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 92 ".\\mylexer.l"
print_token(CONTINUE, yytext); return CONTINUE;
#line 288 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 94 ".\\mylexer.l"
int offset;
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
			
#line 320 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 121 ".\\mylexer.l"

				yylval=&transmitter;
				yylval->attr.vald=atof(yytext);
				print_double(DOUBLE_NUM,yytext,atof(yytext));
				return DOUBLE_NUM;
#line 331 "mylexer.cpp"
		}
		break;
#line 126 ".\\mylexer.l"
				
#line 336 "mylexer.cpp"
	case 20:
		{
#line 127 ".\\mylexer.l"

			yylval=&transmitter;
			yylval->attr.vali=atoi(yytext);
			print_token(INT_NUM,yytext,atoi(yytext));
			return INT_NUM;
#line 345 "mylexer.cpp"
		}
		break;
#line 132 ".\\mylexer.l"
			
#line 350 "mylexer.cpp"
	case 21:
		{
#line 133 ".\\mylexer.l"

				yylval = &transmitter;
				yylval->attr.valc = yytext[1];
				print_token(CONSTCHAR, yytext);
				return CONSTCHAR;
#line 359 "mylexer.cpp"
		}
		break;
#line 138 ".\\mylexer.l"
				
#line 364 "mylexer.cpp"
	case 22:
		{
#line 139 ".\\mylexer.l"
print_token(PLUS2, yytext); return PLUS2;
#line 369 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 140 ".\\mylexer.l"
print_token(MINUS2, yytext); return MINUS2;
#line 376 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 141 ".\\mylexer.l"
print_token(PLUS, yytext); return PLUS;
#line 383 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 142 ".\\mylexer.l"
print_token(MINUS, yytext); return MINUS;
#line 390 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 144 ".\\mylexer.l"
print_token(TIMES, yytext); return TIMES;
#line 397 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 145 ".\\mylexer.l"
print_token(OVER, yytext); return OVER;
#line 404 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 146 ".\\mylexer.l"
print_token(MOD, yytext); return MOD;
#line 411 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 148 ".\\mylexer.l"
print_token(LSHIFT, yytext); return LSHIFT;
#line 418 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 149 ".\\mylexer.l"
print_token(RSHIFT, yytext); return RSHIFT;
#line 425 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 151 ".\\mylexer.l"
print_token(LT, yytext); return LT;
#line 432 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 152 ".\\mylexer.l"
print_token(LE, yytext); return LE;
#line 439 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 153 ".\\mylexer.l"
print_token(GT, yytext); return GT;
#line 446 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 154 ".\\mylexer.l"
print_token(GE, yytext); return GE;
#line 453 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 157 ".\\mylexer.l"
print_token(EQ, yytext); return EQ;
#line 460 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 158 ".\\mylexer.l"
print_token(NE, yytext); return NE;
#line 467 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 160 ".\\mylexer.l"
print_token(BIT_AND, yytext); return BIT_AND;
#line 474 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 161 ".\\mylexer.l"
print_token(BIT_XOR, yytext); return BIT_XOR;
#line 481 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 162 ".\\mylexer.l"
print_token(BIT_OR, yytext); return BIT_OR;
#line 488 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 164 ".\\mylexer.l"
print_token(AND, yytext); return AND;
#line 495 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 165 ".\\mylexer.l"
print_token(OR, yytext); return OR;
#line 502 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 167 ".\\mylexer.l"
print_token(QMARK, yytext); return QMARK;
#line 509 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 168 ".\\mylexer.l"
print_token(COLON, yytext); return COLON;
#line 516 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 170 ".\\mylexer.l"
print_token(ASSIGN, yytext); return ASSIGN;
#line 523 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 171 ".\\mylexer.l"
print_token(PLUSA, yytext); return PLUSA;
#line 530 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 172 ".\\mylexer.l"
print_token(MINUSA, yytext); return MINUSA;
#line 537 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 173 ".\\mylexer.l"
print_token(TIMESA, yytext); return TIMESA;
#line 544 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 174 ".\\mylexer.l"
print_token(OVERA, yytext); return OVERA;
#line 551 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 175 ".\\mylexer.l"
print_token(MODA, yytext); MODA;
#line 558 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 177 ".\\mylexer.l"
print_token(LPAREN, yytext); return LPAREN;
#line 565 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 178 ".\\mylexer.l"
print_token(RPAREN, yytext); return RPAREN;
#line 572 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 179 ".\\mylexer.l"
print_token(LBRACE, yytext);
		/*cur_scope++;
		cout<<"Current Scope in LBRACE: "<<cur_scope<<endl;*/
		return LBRACE;
#line 582 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 183 ".\\mylexer.l"
print_token(RBRACE, yytext);
		/*cur_scope--;
		cout<<"Current Scope out of RBRACE: "<<cur_scope<<endl;*/
		return RBRACE;
#line 592 "mylexer.cpp"
		}
		break;
#line 187 ".\\mylexer.l"
		
#line 597 "mylexer.cpp"
	case 54:
		{
#line 188 ".\\mylexer.l"
print_token(SEMICOLON, yytext); return SEMICOLON;
#line 602 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 189 ".\\mylexer.l"
print_token(COMMA, yytext); return COMMA;
#line 609 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 191 ".\\mylexer.l"
print_token(NOT, yytext); return NOT;
#line 616 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 193 ".\\mylexer.l"

#line 623 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 194 ".\\mylexer.l"

#line 630 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 196 ".\\mylexer.l"

				lineno++;
#ifdef LEX_DEBUG
				cout << "lineno: " << lineno << endl;
#endif
			
#line 642 "mylexer.cpp"
		}
		break;
#line 202 ".\\mylexer.l"
			
#line 647 "mylexer.cpp"
	case 60:
		{
#line 203 ".\\mylexer.l"

#ifdef LEX_DEBUG
				cout << "error!" << endl;
#endif
				return ERROR;
			
#line 657 "mylexer.cpp"
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

	yytransitionmax = 271;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 4, 4 },
		{ 49, 16 },
		{ 47, 15 },
		{ 61, 28 },
		{ 64, 29 },
		{ 68, 32 },
		{ 50, 16 },
		{ 45, 13 },
		{ 86, 69 },
		{ 66, 30 },
		{ 62, 28 },
		{ 76, 76 },
		{ 87, 69 },
		{ 69, 32 },
		{ 65, 29 },
		{ 67, 31 },
		{ 92, 76 },
		{ 63, 28 },
		{ 48, 15 },
		{ 0, 9 },
		{ 51, 16 },
		{ 4, 1 },
		{ 6, 1 },
		{ 4, 4 },
		{ 70, 33 },
		{ 46, 13 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 71, 34 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 72, 35 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 58, 23 },
		{ 59, 23 },
		{ 73, 36 },
		{ 26, 1 },
		{ 25, 1 },
		{ 74, 38 },
		{ 25, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 32, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 33, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 34, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 35, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 36, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 25, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 39, 1 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 55, 21 },
		{ 56, 21 },
		{ 75, 43 },
		{ 76, 49 },
		{ 0, 50 },
		{ 44, 12 },
		{ 57, 22 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 78, 60 },
		{ 79, 61 },
		{ 80, 62 },
		{ 81, 63 },
		{ 25, 119 },
		{ 82, 64 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 25, 119 },
		{ 52, 54 },
		{ 83, 65 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 77, 77 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 84, 66 },
		{ 85, 67 },
		{ 40, 6 },
		{ 88, 70 },
		{ 89, 71 },
		{ 90, 72 },
		{ 91, 73 },
		{ 60, 27 },
		{ 41, 7 },
		{ 93, 78 },
		{ 94, 79 },
		{ 95, 80 },
		{ 96, 81 },
		{ 97, 82 },
		{ 98, 83 },
		{ 99, 84 },
		{ 100, 86 },
		{ 101, 88 },
		{ 102, 89 },
		{ 103, 90 },
		{ 104, 91 },
		{ 105, 93 },
		{ 106, 96 },
		{ 107, 97 },
		{ 108, 98 },
		{ 109, 100 },
		{ 110, 102 },
		{ 111, 103 },
		{ 112, 104 },
		{ 113, 106 },
		{ 114, 107 },
		{ 115, 108 },
		{ 116, 111 },
		{ 117, 113 },
		{ 118, 114 },
		{ 119, 117 },
		{ 42, 8 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 60 },
		{ 0, -6, 1 },
		{ 0, 0, 59 },
		{ 0, 175, 56 },
		{ 0, 181, 28 },
		{ 0, 232, 37 },
		{ -43, 12, 60 },
		{ 0, 0, 50 },
		{ 0, 0, 51 },
		{ 0, 72, 26 },
		{ 0, -33, 24 },
		{ 0, 0, 55 },
		{ 0, -40, 25 },
		{ 0, -38, 27 },
		{ 53, 0, 20 },
		{ 54, 176, 20 },
		{ 0, 0, 43 },
		{ 0, 0, 54 },
		{ 0, 68, 31 },
		{ 0, 73, 44 },
		{ 0, 22, 33 },
		{ 0, 0, 42 },
		{ 119, 0, 18 },
		{ 0, 0, 38 },
		{ 119, 127, 18 },
		{ 119, -91, 18 },
		{ 119, -94, 18 },
		{ 119, -96, 18 },
		{ 119, -93, 18 },
		{ 119, -94, 18 },
		{ 119, -70, 18 },
		{ 119, -76, 18 },
		{ 119, -63, 18 },
		{ 119, -19, 18 },
		{ 0, 0, 52 },
		{ 0, -36, 39 },
		{ 0, 0, 53 },
		{ 0, 0, 36 },
		{ 0, 0, 49 },
		{ 0, 0, 40 },
		{ 0, 91, 0 },
		{ 0, 0, 47 },
		{ 0, 0, 22 },
		{ 0, 0, 45 },
		{ 0, 0, 23 },
		{ 0, 0, 46 },
		{ -49, 89, 0 },
		{ -50, 122, 57 },
		{ 0, 0, 48 },
		{ 77, 0, 0 },
		{ 54, 167, 0 },
		{ 0, 147, 20 },
		{ 0, 0, 29 },
		{ 0, 0, 32 },
		{ 0, 0, 35 },
		{ 0, 0, 34 },
		{ 0, 0, 30 },
		{ 119, 60, 18 },
		{ 119, 47, 18 },
		{ 119, 66, 18 },
		{ 119, 54, 18 },
		{ 119, 64, 18 },
		{ 119, 77, 12 },
		{ 119, 119, 18 },
		{ 119, 121, 18 },
		{ 119, 0, 8 },
		{ 119, -101, 18 },
		{ 119, 132, 18 },
		{ 119, 133, 18 },
		{ 119, 134, 18 },
		{ 119, 135, 18 },
		{ 0, 0, 41 },
		{ 0, 0, 21 },
		{ -49, -28, 0 },
		{ 0, 157, 19 },
		{ 119, 146, 18 },
		{ 119, 143, 18 },
		{ 119, 131, 18 },
		{ 119, 130, 18 },
		{ 119, 150, 18 },
		{ 119, 150, 18 },
		{ 119, 148, 18 },
		{ 119, 0, 10 },
		{ 119, 133, 18 },
		{ 119, 0, 2 },
		{ 119, 141, 18 },
		{ 119, 142, 18 },
		{ 119, 137, 18 },
		{ 119, 146, 18 },
		{ 0, 0, 58 },
		{ 119, 148, 18 },
		{ 119, 0, 14 },
		{ 119, 0, 3 },
		{ 119, 151, 18 },
		{ 119, 140, 18 },
		{ 119, 150, 18 },
		{ 119, 0, 9 },
		{ 119, 143, 18 },
		{ 119, 0, 7 },
		{ 119, 144, 18 },
		{ 119, 162, 18 },
		{ 119, 161, 18 },
		{ 119, 0, 16 },
		{ 119, 153, 18 },
		{ 119, 156, 18 },
		{ 119, 164, 18 },
		{ 119, 0, 5 },
		{ 119, 0, 6 },
		{ 119, 162, 18 },
		{ 119, 0, 11 },
		{ 119, 150, 18 },
		{ 119, 152, 18 },
		{ 119, 0, 4 },
		{ 119, 0, 13 },
		{ 119, 168, 18 },
		{ 119, 0, 15 },
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
#line 210 ".\\mylexer.l"


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


