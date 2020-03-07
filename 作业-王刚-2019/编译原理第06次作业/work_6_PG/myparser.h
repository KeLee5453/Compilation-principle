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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/05/19
* Time: 18:37:02
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

#line 94 ".\\myparser.y"

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
#line 101 ".\\myparser.y"

	// place any extra class members here
	void showCheckRes();
void typeError(struct TreeNode* t,string str);
void checkNode(struct TreeNode * t);
	void display(struct TreeNode*node);
	void shownode(struct TreeNode*node);
	void output1(string str);
	void outtype(struct TreeNode * t);

#line 81 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 123 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE struct TreeNode*
#endif

#line 94 "myparser.h"
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
#define CHARACTER 269
#define PLUS 270
#define MINUS 271
#define MUL 272
#define DIV 273
#define REMI 274
#define DPLUS 275
#define DMINUS 276
#define GT 277
#define LT 278
#define GE 279
#define LE 280
#define NEQ 281
#define AND 282
#define OR 283
#define NOT 284
#define ASSIGN 285
#define LFP 286
#define RFP 287
#define COMMA 288
#define SEMI 289
#define LP 290
#define RP 291
#define LM 292
#define RM 293
#define EQ 294
#define LSP 295
#define RSP 296
#define ELSE 297
#endif
