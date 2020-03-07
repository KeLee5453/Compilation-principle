/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 47 of your 30 day trial period.
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
* Date: 10/18/19
* Time: 11:19:49
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// expr

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR expr : public _YL yyfparser {
public:
	expr();
	virtual ~expr();

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
#line 25 ".\\myparser.y"

	// place any extra class members here
	virtual int yygettoken();


#line 71 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME expr
#endif

#line 42 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE string
#endif

#line 84 "myparser.h"
#define AND 257
#define MIN 258
#define MUL 259
#define DIV 260
#define BL 261
#define BR 262
#define STR 263
#define UMINUS 264
#endif
