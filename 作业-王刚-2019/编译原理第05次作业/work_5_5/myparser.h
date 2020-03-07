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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 11/20/19
* Time: 14:40:15
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

#line 82 ".\\myparser.y"

  class mylexer;
 
#line 37 "myparser.h"
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
#line 89 ".\\myparser.y"

	// place any extra class members here
	void display(struct TreeNode*node);
	void shownode(struct TreeNode*node);
	void output1(string str);
	string find_key(int val);

#line 78 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 108 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE struct TreeNode*
#endif

#line 91 "myparser.h"
#define IF 257
#define MAIN 258
#define FOR 259
#define WHILE 260
#define CIN 261
#define COUT 262
#define INT 263
#define CHAR 264
#define VOID 265
#define BOOL 266
#define ID 267
#define NUMBER 268
#define PLUS 269
#define MINUS 270
#define MUL 271
#define DIV 272
#define REMI 273
#define DPLUS 274
#define DMINUS 275
#define GT 276
#define LT 277
#define GE 278
#define LE 279
#define NEQ 280
#define AND 281
#define OR 282
#define NOT 283
#define ASSIGN 284
#define LFP 285
#define RFP 286
#define COMMA 287
#define SEMI 288
#define LP 289
#define RP 290
#define LM 291
#define RM 292
#define EQ 293
#define LSP 294
#define RSP 295
#define ELSE 296
#endif
