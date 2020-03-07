#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 80 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 11/20/19
# Time: 14:40:15
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : start $end

    1  start : MAIN LP RP complex

    2  complex : LFP stmts RFP

    3  stmts : stmt stmts
    4        | stmt

    5  stmt : expr_stmt
    6       | var_stmt
    7       | if_stmt
    8       | while_stmt
    9       | for_stmt
   10       | complex
   11       | input_stmt
   12       | output_stmt

   13  type_var : INT
   14           | CHAR
   15           | BOOL
   16           | VOID

   17  id_list : id_expr COMMA id_list
   18          | id_expr

   19  id_expr : ID ASSIGN expr
   20          | ID

   21  var_stmt : type_var id_list SEMI

   22  expr_stmt : expr SEMI
   23            | SEMI

   24  expr : expr ASSIGN expr
   25       | or_expr

   26  or_expr : or_expr OR and_expr
   27          | and_expr

   28  and_expr : and_expr AND eq_expr
   29           | eq_expr

   30  eq_expr : eq_expr EQ simple_expr
   31          | eq_expr GE simple_expr
   32          | eq_expr LE simple_expr
   33          | eq_expr GT simple_expr
   34          | eq_expr LT simple_expr
   35          | eq_expr NEQ simple_expr
   36          | eq_expr LM simple_expr
   37          | eq_expr RM simple_expr
   38          | simple_expr

   39  simple_expr : simple_expr PLUS term
   40              | simple_expr MINUS term
   41              | simple_expr MUL term
   42              | simple_expr DIV term
   43              | simple_expr REMI term
   44              | simple_expr DPLUS
   45              | simple_expr DMINUS
   46              | term

   47  term : LP expr RP
   48       | ID
   49       | NUMBER
   50       | NOT term

   51  if_stmt : IF LP expr RP stmt
   52          | IF LP expr RP stmt ELSE stmt

   53  for_stmt : FOR LP expr SEMI expr SEMI expr RP stmt
   54           | FOR LP SEMI expr SEMI expr RP stmt
   55           | FOR LP expr SEMI SEMI expr RP stmt
   56           | FOR LP expr SEMI expr SEMI RP stmt
   57           | FOR LP SEMI SEMI expr RP stmt
   58           | FOR LP SEMI expr SEMI RP stmt
   59           | FOR LP expr SEMI SEMI RP stmt
   60           | FOR LP SEMI SEMI RP stmt

   61  while_stmt : WHILE LP expr RP stmt

   62  input_stmt : CIN RM ID SEMI

   63  output_stmt : COUT LM ID SEMI

   64  Grammar :


##############################################################################
# States
##############################################################################

state 0
	$accept : . start $end

	MAIN  shift 1

	start  goto 2


state 1
	start : MAIN . LP RP complex

	LP  shift 3


state 2
	$accept : start . $end  (0)

	$end  accept


state 3
	start : MAIN LP . RP complex

	RP  shift 4


state 4
	start : MAIN LP RP . complex

	LFP  shift 5

	complex  goto 6


state 5
	complex : LFP . stmts RFP

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmts  goto 29
	stmt  goto 30
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 6
	start : MAIN LP RP complex .  (1)

	.  reduce 1


state 7
	if_stmt : IF . LP expr RP stmt ELSE stmt
	if_stmt : IF . LP expr RP stmt

	LP  shift 38


state 8
	for_stmt : FOR . LP SEMI expr SEMI RP stmt
	for_stmt : FOR . LP SEMI SEMI expr RP stmt
	for_stmt : FOR . LP SEMI SEMI RP stmt
	for_stmt : FOR . LP expr SEMI expr SEMI expr RP stmt
	for_stmt : FOR . LP expr SEMI SEMI expr RP stmt
	for_stmt : FOR . LP expr SEMI expr SEMI RP stmt
	for_stmt : FOR . LP expr SEMI SEMI RP stmt
	for_stmt : FOR . LP SEMI expr SEMI expr RP stmt

	LP  shift 39


state 9
	while_stmt : WHILE . LP expr RP stmt

	LP  shift 40


state 10
	input_stmt : CIN . RM ID SEMI

	RM  shift 41


state 11
	output_stmt : COUT . LM ID SEMI

	LM  shift 42


state 12
	type_var : INT .  (13)

	.  reduce 13


state 13
	type_var : CHAR .  (14)

	.  reduce 14


state 14
	type_var : VOID .  (16)

	.  reduce 16


state 15
	type_var : BOOL .  (15)

	.  reduce 15


state 16
	term : ID .  (48)

	.  reduce 48


state 17
	term : NUMBER .  (49)

	.  reduce 49


state 18
	term : NOT . term

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 43


state 19
	expr_stmt : SEMI .  (23)

	.  reduce 23


state 20
	term : LP . expr RP

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 44
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 21
	stmt : var_stmt .  (6)

	.  reduce 6


state 22
	stmt : if_stmt .  (7)

	.  reduce 7


state 23
	stmt : complex .  (10)

	.  reduce 10


state 24
	stmt : while_stmt .  (8)

	.  reduce 8


state 25
	stmt : expr_stmt .  (5)

	.  reduce 5


state 26
	stmt : for_stmt .  (9)

	.  reduce 9


state 27
	stmt : input_stmt .  (11)

	.  reduce 11


state 28
	var_stmt : type_var . id_list SEMI

	ID  shift 45

	id_list  goto 46
	id_expr  goto 47


state 29
	complex : LFP stmts . RFP

	RFP  shift 48


state 30
	stmts : stmt . stmts
	stmts : stmt .  (4)

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20
	.  reduce 4

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmts  goto 49
	stmt  goto 30
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 31
	stmt : output_stmt .  (12)

	.  reduce 12


state 32
	simple_expr : simple_expr . MUL term
	eq_expr : simple_expr .  (38)
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 38


state 33
	eq_expr : eq_expr . GT simple_expr
	eq_expr : eq_expr . EQ simple_expr
	and_expr : eq_expr .  (29)
	eq_expr : eq_expr . GE simple_expr
	eq_expr : eq_expr . LE simple_expr
	eq_expr : eq_expr . RM simple_expr
	eq_expr : eq_expr . LT simple_expr
	eq_expr : eq_expr . NEQ simple_expr
	eq_expr : eq_expr . LM simple_expr

	GT  shift 57
	LT  shift 58
	GE  shift 59
	LE  shift 60
	NEQ  shift 61
	LM  shift 62
	RM  shift 63
	EQ  shift 64
	.  reduce 29


state 34
	expr_stmt : expr . SEMI
	expr : expr . ASSIGN expr

	ASSIGN  shift 65
	SEMI  shift 66


state 35
	or_expr : or_expr . OR and_expr
	expr : or_expr .  (25)

	OR  shift 67
	.  reduce 25


state 36
	or_expr : and_expr .  (27)
	and_expr : and_expr . AND eq_expr

	AND  shift 68
	.  reduce 27


state 37
	simple_expr : term .  (46)

	.  reduce 46


state 38
	if_stmt : IF LP . expr RP stmt ELSE stmt
	if_stmt : IF LP . expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 69
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 39
	for_stmt : FOR LP . SEMI expr SEMI RP stmt
	for_stmt : FOR LP . SEMI SEMI expr RP stmt
	for_stmt : FOR LP . SEMI SEMI RP stmt
	for_stmt : FOR LP . expr SEMI expr SEMI expr RP stmt
	for_stmt : FOR LP . expr SEMI SEMI expr RP stmt
	for_stmt : FOR LP . expr SEMI expr SEMI RP stmt
	for_stmt : FOR LP . expr SEMI SEMI RP stmt
	for_stmt : FOR LP . SEMI expr SEMI expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	SEMI  shift 70
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 71
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 40
	while_stmt : WHILE LP . expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 72
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 41
	input_stmt : CIN RM . ID SEMI

	ID  shift 73


state 42
	output_stmt : COUT LM . ID SEMI

	ID  shift 74


state 43
	term : NOT term .  (50)

	.  reduce 50


state 44
	expr : expr . ASSIGN expr
	term : LP expr . RP

	ASSIGN  shift 65
	RP  shift 75


state 45
	id_expr : ID . ASSIGN expr
	id_expr : ID .  (20)

	ASSIGN  shift 76
	.  reduce 20


state 46
	var_stmt : type_var id_list . SEMI

	SEMI  shift 77


state 47
	id_list : id_expr . COMMA id_list
	id_list : id_expr .  (18)

	COMMA  shift 78
	.  reduce 18


state 48
	complex : LFP stmts RFP .  (2)

	.  reduce 2


state 49
	stmts : stmt stmts .  (3)

	.  reduce 3


state 50
	simple_expr : simple_expr PLUS . term

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 79


state 51
	simple_expr : simple_expr MINUS . term

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 80


state 52
	simple_expr : simple_expr MUL . term

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 81


state 53
	simple_expr : simple_expr DIV . term

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 82


state 54
	simple_expr : simple_expr REMI . term

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	term  goto 83


state 55
	simple_expr : simple_expr DPLUS .  (44)

	.  reduce 44


state 56
	simple_expr : simple_expr DMINUS .  (45)

	.  reduce 45


state 57
	eq_expr : eq_expr GT . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 84
	term  goto 37


state 58
	eq_expr : eq_expr LT . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 85
	term  goto 37


state 59
	eq_expr : eq_expr GE . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 86
	term  goto 37


state 60
	eq_expr : eq_expr LE . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 87
	term  goto 37


state 61
	eq_expr : eq_expr NEQ . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 88
	term  goto 37


state 62
	eq_expr : eq_expr LM . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 89
	term  goto 37


state 63
	eq_expr : eq_expr RM . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 90
	term  goto 37


state 64
	eq_expr : eq_expr EQ . simple_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 91
	term  goto 37


state 65
	expr : expr ASSIGN . expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 92
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 66
	expr_stmt : expr SEMI .  (22)

	.  reduce 22


state 67
	or_expr : or_expr OR . and_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	and_expr  goto 93
	term  goto 37


state 68
	and_expr : and_expr AND . eq_expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 94
	term  goto 37


state 69
	expr : expr . ASSIGN expr
	if_stmt : IF LP expr . RP stmt ELSE stmt
	if_stmt : IF LP expr . RP stmt

	ASSIGN  shift 65
	RP  shift 95


state 70
	for_stmt : FOR LP SEMI . expr SEMI RP stmt
	for_stmt : FOR LP SEMI . SEMI expr RP stmt
	for_stmt : FOR LP SEMI . SEMI RP stmt
	for_stmt : FOR LP SEMI . expr SEMI expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	SEMI  shift 96
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 97
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 71
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr . SEMI expr SEMI expr RP stmt
	for_stmt : FOR LP expr . SEMI SEMI expr RP stmt
	for_stmt : FOR LP expr . SEMI expr SEMI RP stmt
	for_stmt : FOR LP expr . SEMI SEMI RP stmt

	ASSIGN  shift 65
	SEMI  shift 98


state 72
	expr : expr . ASSIGN expr
	while_stmt : WHILE LP expr . RP stmt

	ASSIGN  shift 65
	RP  shift 99


state 73
	input_stmt : CIN RM ID . SEMI

	SEMI  shift 100


state 74
	output_stmt : COUT LM ID . SEMI

	SEMI  shift 101


state 75
	term : LP expr RP .  (47)

	.  reduce 47


state 76
	id_expr : ID ASSIGN . expr

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 102
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 77
	var_stmt : type_var id_list SEMI .  (21)

	.  reduce 21


state 78
	id_list : id_expr COMMA . id_list

	ID  shift 45

	id_list  goto 103
	id_expr  goto 47


state 79
	simple_expr : simple_expr PLUS term .  (39)

	.  reduce 39


state 80
	simple_expr : simple_expr MINUS term .  (40)

	.  reduce 40


state 81
	simple_expr : simple_expr MUL term .  (41)

	.  reduce 41


state 82
	simple_expr : simple_expr DIV term .  (42)

	.  reduce 42


state 83
	simple_expr : simple_expr REMI term .  (43)

	.  reduce 43


state 84
	eq_expr : eq_expr GT simple_expr .  (33)
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 33


state 85
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	eq_expr : eq_expr LT simple_expr .  (34)
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 34


state 86
	eq_expr : eq_expr GE simple_expr .  (31)
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 31


state 87
	eq_expr : eq_expr LE simple_expr .  (32)
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 32


state 88
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	eq_expr : eq_expr NEQ simple_expr .  (35)
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 35


state 89
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	eq_expr : eq_expr LM simple_expr .  (36)
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 36


state 90
	eq_expr : eq_expr RM simple_expr .  (37)
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 37


state 91
	eq_expr : eq_expr EQ simple_expr .  (30)
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . DIV term

	PLUS  shift 50
	MINUS  shift 51
	MUL  shift 52
	DIV  shift 53
	REMI  shift 54
	DPLUS  shift 55
	DMINUS  shift 56
	.  reduce 30


state 92
	expr : expr ASSIGN expr .  (24)
	expr : expr . ASSIGN expr

	ASSIGN  shift 65
	.  reduce 24


state 93
	or_expr : or_expr OR and_expr .  (26)
	and_expr : and_expr . AND eq_expr

	AND  shift 68
	.  reduce 26


state 94
	eq_expr : eq_expr . GT simple_expr
	eq_expr : eq_expr . EQ simple_expr
	eq_expr : eq_expr . GE simple_expr
	eq_expr : eq_expr . LE simple_expr
	and_expr : and_expr AND eq_expr .  (28)
	eq_expr : eq_expr . RM simple_expr
	eq_expr : eq_expr . LT simple_expr
	eq_expr : eq_expr . NEQ simple_expr
	eq_expr : eq_expr . LM simple_expr

	GT  shift 57
	LT  shift 58
	GE  shift 59
	LE  shift 60
	NEQ  shift 61
	LM  shift 62
	RM  shift 63
	EQ  shift 64
	.  reduce 28


state 95
	if_stmt : IF LP expr RP . stmt ELSE stmt
	if_stmt : IF LP expr RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 104
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 96
	for_stmt : FOR LP SEMI SEMI . expr RP stmt
	for_stmt : FOR LP SEMI SEMI . RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 105

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 106
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 97
	expr : expr . ASSIGN expr
	for_stmt : FOR LP SEMI expr . SEMI RP stmt
	for_stmt : FOR LP SEMI expr . SEMI expr RP stmt

	ASSIGN  shift 65
	SEMI  shift 107


state 98
	for_stmt : FOR LP expr SEMI . expr SEMI expr RP stmt
	for_stmt : FOR LP expr SEMI . SEMI expr RP stmt
	for_stmt : FOR LP expr SEMI . expr SEMI RP stmt
	for_stmt : FOR LP expr SEMI . SEMI RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	SEMI  shift 108
	LP  shift 20

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 109
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 99
	while_stmt : WHILE LP expr RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 110
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 100
	input_stmt : CIN RM ID SEMI .  (62)

	.  reduce 62


state 101
	output_stmt : COUT LM ID SEMI .  (63)

	.  reduce 63


state 102
	expr : expr . ASSIGN expr
	id_expr : ID ASSIGN expr .  (19)

	ASSIGN  shift 65
	.  reduce 19


state 103
	id_list : id_expr COMMA id_list .  (17)

	.  reduce 17


state 104
	if_stmt : IF LP expr RP stmt . ELSE stmt
	if_stmt : IF LP expr RP stmt .  (51)

	ELSE  shift 111
	.  reduce 51


state 105
	for_stmt : FOR LP SEMI SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 112
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 106
	expr : expr . ASSIGN expr
	for_stmt : FOR LP SEMI SEMI expr . RP stmt

	ASSIGN  shift 65
	RP  shift 113


state 107
	for_stmt : FOR LP SEMI expr SEMI . RP stmt
	for_stmt : FOR LP SEMI expr SEMI . expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 114

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 115
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 108
	for_stmt : FOR LP expr SEMI SEMI . expr RP stmt
	for_stmt : FOR LP expr SEMI SEMI . RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 116

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 117
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 109
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr SEMI expr . SEMI expr RP stmt
	for_stmt : FOR LP expr SEMI expr . SEMI RP stmt

	ASSIGN  shift 65
	SEMI  shift 118


state 110
	while_stmt : WHILE LP expr RP stmt .  (61)

	.  reduce 61


state 111
	if_stmt : IF LP expr RP stmt ELSE . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 119
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 112
	for_stmt : FOR LP SEMI SEMI RP stmt .  (60)

	.  reduce 60


state 113
	for_stmt : FOR LP SEMI SEMI expr RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 120
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 114
	for_stmt : FOR LP SEMI expr SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 121
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 115
	expr : expr . ASSIGN expr
	for_stmt : FOR LP SEMI expr SEMI expr . RP stmt

	ASSIGN  shift 65
	RP  shift 122


state 116
	for_stmt : FOR LP expr SEMI SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 123
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 117
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr SEMI SEMI expr . RP stmt

	ASSIGN  shift 65
	RP  shift 124


state 118
	for_stmt : FOR LP expr SEMI expr SEMI . expr RP stmt
	for_stmt : FOR LP expr SEMI expr SEMI . RP stmt

	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LP  shift 20
	RP  shift 125

	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 126
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 119
	if_stmt : IF LP expr RP stmt ELSE stmt .  (52)

	.  reduce 52


state 120
	for_stmt : FOR LP SEMI SEMI expr RP stmt .  (57)

	.  reduce 57


state 121
	for_stmt : FOR LP SEMI expr SEMI RP stmt .  (58)

	.  reduce 58


state 122
	for_stmt : FOR LP SEMI expr SEMI expr RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 127
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 123
	for_stmt : FOR LP expr SEMI SEMI RP stmt .  (59)

	.  reduce 59


state 124
	for_stmt : FOR LP expr SEMI SEMI expr RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 128
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 125
	for_stmt : FOR LP expr SEMI expr SEMI RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 129
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 126
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr SEMI expr SEMI expr . RP stmt

	ASSIGN  shift 65
	RP  shift 130


state 127
	for_stmt : FOR LP SEMI expr SEMI expr RP stmt .  (54)

	.  reduce 54


state 128
	for_stmt : FOR LP expr SEMI SEMI expr RP stmt .  (55)

	.  reduce 55


state 129
	for_stmt : FOR LP expr SEMI expr SEMI RP stmt .  (56)

	.  reduce 56


state 130
	for_stmt : FOR LP expr SEMI expr SEMI expr RP . stmt

	IF  shift 7
	FOR  shift 8
	WHILE  shift 9
	CIN  shift 10
	COUT  shift 11
	INT  shift 12
	CHAR  shift 13
	VOID  shift 14
	BOOL  shift 15
	ID  shift 16
	NUMBER  shift 17
	NOT  shift 18
	LFP  shift 5
	SEMI  shift 19
	LP  shift 20

	var_stmt  goto 21
	if_stmt  goto 22
	complex  goto 23
	while_stmt  goto 24
	expr_stmt  goto 25
	for_stmt  goto 26
	input_stmt  goto 27
	type_var  goto 28
	stmt  goto 131
	output_stmt  goto 31
	simple_expr  goto 32
	eq_expr  goto 33
	expr  goto 34
	or_expr  goto 35
	and_expr  goto 36
	term  goto 37


state 131
	for_stmt : FOR LP expr SEMI expr SEMI expr RP stmt .  (53)

	.  reduce 53


Rules never reduced
	Grammar :  (64)


##############################################################################
# Summary
##############################################################################

40 token(s), 22 nonterminal(s)
65 grammar rule(s), 132 state(s)


##############################################################################
# End of File
##############################################################################
