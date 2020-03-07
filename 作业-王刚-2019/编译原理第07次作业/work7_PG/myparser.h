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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/25/19
* Time: 15:27:20
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 30 ".\\myparser.y"

	// place any extra class members here

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 45 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE GrammerTreeNode *
#endif

#line 82 "myparser.h"
#define MAIN 257
#define INT 258
#define CHAR 259
#define DOUBLE 260
#define IF 261
#define ELSE 262
#define FOR 263
#define WHILE 264
#define DO 265
#define SWITCH 266
#define CASE 267
#define DEFAULT 268
#define BREAK 269
#define CONTINUE 270
#define ID 271
#define DOUBLE_NUM 272
#define INT_NUM 273
#define CONSTCHAR 274
#define PLUS2 275
#define MINUS2 276
#define PLUS 277
#define MINUS 278
#define TIMES 279
#define OVER 280
#define MOD 281
#define LSHIFT 282
#define RSHIFT 283
#define LT 284
#define LE 285
#define GT 286
#define GE 287
#define EQ 288
#define NE 289
#define BIT_AND 290
#define BIT_XOR 291
#define BIT_OR 292
#define AND 293
#define OR 294
#define QMARK 295
#define COLON 296
#define ASSIGN 297
#define PLUSA 298
#define MINUSA 299
#define TIMESA 300
#define OVERA 301
#define MODA 302
#define LPAREN 303
#define RPAREN 304
#define LBRACE 305
#define RBRACE 306
#define SEMICOLON 307
#define COMMA 308
#define NOT 309
#define INPUT 310
#define PRINT 311
#define ERROR 312
#endif
