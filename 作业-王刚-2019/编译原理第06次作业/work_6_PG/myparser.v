#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 95 of your 30 day trial period.
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
# Date: 12/05/19
# Time: 18:37:02
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
   50       | CHARACTER
   51       | NOT term

   52  if_stmt : IF LP expr RP stmt
   53          | IF LP expr RP stmt ELSE stmt

   54  for_stmt : FOR LP expr SEMI expr SEMI expr RP stmt
   55           | FOR LP SEMI expr SEMI expr RP stmt
   56           | FOR LP expr SEMI SEMI expr RP stmt
   57           | FOR LP expr SEMI expr SEMI RP stmt
   58           | FOR LP SEMI SEMI expr RP stmt
   59           | FOR LP SEMI expr SEMI RP stmt
   60           | FOR LP expr SEMI SEMI RP stmt
   61           | FOR LP SEMI SEMI RP stmt

   62  while_stmt : WHILE LP expr RP stmt

   63  input_stmt : CIN RM term SEMI

   64  output_stmt : COUT LM term SEMI

   65  Grammar :


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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	stmts  goto 28
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 33
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 6
	start : MAIN LP RP complex .  (1)

	.  reduce 1


state 7
	if_stmt : IF . LP expr RP stmt ELSE stmt
	if_stmt : IF . LP expr RP stmt

	LP  shift 39


state 8
	for_stmt : FOR . LP SEMI expr SEMI expr RP stmt
	for_stmt : FOR . LP expr SEMI expr SEMI RP stmt
	for_stmt : FOR . LP expr SEMI expr SEMI expr RP stmt
	for_stmt : FOR . LP SEMI SEMI expr RP stmt
	for_stmt : FOR . LP expr SEMI SEMI RP stmt
	for_stmt : FOR . LP SEMI expr SEMI RP stmt
	for_stmt : FOR . LP SEMI SEMI RP stmt
	for_stmt : FOR . LP expr SEMI SEMI expr RP stmt

	LP  shift 40


state 9
	while_stmt : WHILE . LP expr RP stmt

	LP  shift 41


state 10
	input_stmt : CIN . RM term SEMI

	RM  shift 42


state 11
	output_stmt : COUT . LM term SEMI

	LM  shift 43


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
	term : CHARACTER .  (50)

	.  reduce 50


state 19
	term : NOT . term

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 44


state 20
	expr_stmt : SEMI .  (23)

	.  reduce 23


state 21
	term : LP . expr RP

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 45
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 22
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	eq_expr : simple_expr .  (38)
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 38


state 23
	simple_expr : term .  (46)

	.  reduce 46


state 24
	expr : expr . ASSIGN expr
	expr_stmt : expr . SEMI

	ASSIGN  shift 53
	SEMI  shift 54


state 25
	and_expr : eq_expr .  (29)
	eq_expr : eq_expr . LE simple_expr
	eq_expr : eq_expr . EQ simple_expr
	eq_expr : eq_expr . GE simple_expr
	eq_expr : eq_expr . GT simple_expr
	eq_expr : eq_expr . RM simple_expr
	eq_expr : eq_expr . LM simple_expr
	eq_expr : eq_expr . NEQ simple_expr
	eq_expr : eq_expr . LT simple_expr

	GT  shift 55
	LT  shift 56
	GE  shift 57
	LE  shift 58
	NEQ  shift 59
	LM  shift 60
	RM  shift 61
	EQ  shift 62
	.  reduce 29


state 26
	or_expr : and_expr .  (27)
	and_expr : and_expr . AND eq_expr

	AND  shift 63
	.  reduce 27


state 27
	expr : or_expr .  (25)
	or_expr : or_expr . OR and_expr

	OR  shift 64
	.  reduce 25


state 28
	complex : LFP stmts . RFP

	RFP  shift 65


state 29
	var_stmt : type_var . id_list SEMI

	ID  shift 66

	id_expr  goto 67
	id_list  goto 68


state 30
	stmt : input_stmt .  (11)

	.  reduce 11


state 31
	stmt : expr_stmt .  (5)

	.  reduce 5


state 32
	stmt : complex .  (10)

	.  reduce 10


state 33
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21
	.  reduce 4

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	stmts  goto 69
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 33
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 34
	stmt : var_stmt .  (6)

	.  reduce 6


state 35
	stmt : if_stmt .  (7)

	.  reduce 7


state 36
	stmt : for_stmt .  (9)

	.  reduce 9


state 37
	stmt : output_stmt .  (12)

	.  reduce 12


state 38
	stmt : while_stmt .  (8)

	.  reduce 8


state 39
	if_stmt : IF LP . expr RP stmt ELSE stmt
	if_stmt : IF LP . expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 70
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 40
	for_stmt : FOR LP . SEMI expr SEMI expr RP stmt
	for_stmt : FOR LP . expr SEMI expr SEMI RP stmt
	for_stmt : FOR LP . expr SEMI expr SEMI expr RP stmt
	for_stmt : FOR LP . SEMI SEMI expr RP stmt
	for_stmt : FOR LP . expr SEMI SEMI RP stmt
	for_stmt : FOR LP . SEMI expr SEMI RP stmt
	for_stmt : FOR LP . SEMI SEMI RP stmt
	for_stmt : FOR LP . expr SEMI SEMI expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	SEMI  shift 71
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 72
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 41
	while_stmt : WHILE LP . expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 73
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 42
	input_stmt : CIN RM . term SEMI

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 74


state 43
	output_stmt : COUT LM . term SEMI

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 75


state 44
	term : NOT term .  (51)

	.  reduce 51


state 45
	expr : expr . ASSIGN expr
	term : LP expr . RP

	ASSIGN  shift 53
	RP  shift 76


state 46
	simple_expr : simple_expr PLUS . term

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 77


state 47
	simple_expr : simple_expr MINUS . term

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 78


state 48
	simple_expr : simple_expr MUL . term

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 79


state 49
	simple_expr : simple_expr DIV . term

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 80


state 50
	simple_expr : simple_expr REMI . term

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	term  goto 81


state 51
	simple_expr : simple_expr DPLUS .  (44)

	.  reduce 44


state 52
	simple_expr : simple_expr DMINUS .  (45)

	.  reduce 45


state 53
	expr : expr ASSIGN . expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 82
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 54
	expr_stmt : expr SEMI .  (22)

	.  reduce 22


state 55
	eq_expr : eq_expr GT . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 83
	term  goto 23


state 56
	eq_expr : eq_expr LT . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 84
	term  goto 23


state 57
	eq_expr : eq_expr GE . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 85
	term  goto 23


state 58
	eq_expr : eq_expr LE . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 86
	term  goto 23


state 59
	eq_expr : eq_expr NEQ . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 87
	term  goto 23


state 60
	eq_expr : eq_expr LM . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 88
	term  goto 23


state 61
	eq_expr : eq_expr RM . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 89
	term  goto 23


state 62
	eq_expr : eq_expr EQ . simple_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 90
	term  goto 23


state 63
	and_expr : and_expr AND . eq_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	eq_expr  goto 91


state 64
	or_expr : or_expr OR . and_expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	eq_expr  goto 25
	and_expr  goto 92


state 65
	complex : LFP stmts RFP .  (2)

	.  reduce 2


state 66
	id_expr : ID . ASSIGN expr
	id_expr : ID .  (20)

	ASSIGN  shift 93
	.  reduce 20


state 67
	id_list : id_expr .  (18)
	id_list : id_expr . COMMA id_list

	COMMA  shift 94
	.  reduce 18


state 68
	var_stmt : type_var id_list . SEMI

	SEMI  shift 95


state 69
	stmts : stmt stmts .  (3)

	.  reduce 3


state 70
	expr : expr . ASSIGN expr
	if_stmt : IF LP expr . RP stmt ELSE stmt
	if_stmt : IF LP expr . RP stmt

	ASSIGN  shift 53
	RP  shift 96


state 71
	for_stmt : FOR LP SEMI . expr SEMI expr RP stmt
	for_stmt : FOR LP SEMI . SEMI expr RP stmt
	for_stmt : FOR LP SEMI . expr SEMI RP stmt
	for_stmt : FOR LP SEMI . SEMI RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	SEMI  shift 97
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 98
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 72
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr . SEMI expr SEMI RP stmt
	for_stmt : FOR LP expr . SEMI expr SEMI expr RP stmt
	for_stmt : FOR LP expr . SEMI SEMI RP stmt
	for_stmt : FOR LP expr . SEMI SEMI expr RP stmt

	ASSIGN  shift 53
	SEMI  shift 99


state 73
	expr : expr . ASSIGN expr
	while_stmt : WHILE LP expr . RP stmt

	ASSIGN  shift 53
	RP  shift 100


state 74
	input_stmt : CIN RM term . SEMI

	SEMI  shift 101


state 75
	output_stmt : COUT LM term . SEMI

	SEMI  shift 102


state 76
	term : LP expr RP .  (47)

	.  reduce 47


state 77
	simple_expr : simple_expr PLUS term .  (39)

	.  reduce 39


state 78
	simple_expr : simple_expr MINUS term .  (40)

	.  reduce 40


state 79
	simple_expr : simple_expr MUL term .  (41)

	.  reduce 41


state 80
	simple_expr : simple_expr DIV term .  (42)

	.  reduce 42


state 81
	simple_expr : simple_expr REMI term .  (43)

	.  reduce 43


state 82
	expr : expr ASSIGN expr .  (24)
	expr : expr . ASSIGN expr

	ASSIGN  shift 53
	.  reduce 24


state 83
	eq_expr : eq_expr GT simple_expr .  (33)
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 33


state 84
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	eq_expr : eq_expr LT simple_expr .  (34)
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 34


state 85
	eq_expr : eq_expr GE simple_expr .  (31)
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 31


state 86
	eq_expr : eq_expr LE simple_expr .  (32)
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 32


state 87
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	eq_expr : eq_expr NEQ simple_expr .  (35)
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 35


state 88
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	eq_expr : eq_expr LM simple_expr .  (36)
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 36


state 89
	simple_expr : simple_expr . MINUS term
	eq_expr : eq_expr RM simple_expr .  (37)
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 37


state 90
	eq_expr : eq_expr EQ simple_expr .  (30)
	simple_expr : simple_expr . MINUS term
	simple_expr : simple_expr . DPLUS
	simple_expr : simple_expr . REMI term
	simple_expr : simple_expr . DMINUS
	simple_expr : simple_expr . PLUS term
	simple_expr : simple_expr . MUL term
	simple_expr : simple_expr . DIV term

	PLUS  shift 46
	MINUS  shift 47
	MUL  shift 48
	DIV  shift 49
	REMI  shift 50
	DPLUS  shift 51
	DMINUS  shift 52
	.  reduce 30


state 91
	eq_expr : eq_expr . LE simple_expr
	eq_expr : eq_expr . EQ simple_expr
	eq_expr : eq_expr . GE simple_expr
	eq_expr : eq_expr . GT simple_expr
	and_expr : and_expr AND eq_expr .  (28)
	eq_expr : eq_expr . RM simple_expr
	eq_expr : eq_expr . LM simple_expr
	eq_expr : eq_expr . NEQ simple_expr
	eq_expr : eq_expr . LT simple_expr

	GT  shift 55
	LT  shift 56
	GE  shift 57
	LE  shift 58
	NEQ  shift 59
	LM  shift 60
	RM  shift 61
	EQ  shift 62
	.  reduce 28


state 92
	or_expr : or_expr OR and_expr .  (26)
	and_expr : and_expr . AND eq_expr

	AND  shift 63
	.  reduce 26


state 93
	id_expr : ID ASSIGN . expr

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 103
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 94
	id_list : id_expr COMMA . id_list

	ID  shift 66

	id_expr  goto 67
	id_list  goto 104


state 95
	var_stmt : type_var id_list SEMI .  (21)

	.  reduce 21


state 96
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 105
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 97
	for_stmt : FOR LP SEMI SEMI . expr RP stmt
	for_stmt : FOR LP SEMI SEMI . RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21
	RP  shift 106

	simple_expr  goto 22
	term  goto 23
	expr  goto 107
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 98
	expr : expr . ASSIGN expr
	for_stmt : FOR LP SEMI expr . SEMI expr RP stmt
	for_stmt : FOR LP SEMI expr . SEMI RP stmt

	ASSIGN  shift 53
	SEMI  shift 108


state 99
	for_stmt : FOR LP expr SEMI . expr SEMI RP stmt
	for_stmt : FOR LP expr SEMI . expr SEMI expr RP stmt
	for_stmt : FOR LP expr SEMI . SEMI RP stmt
	for_stmt : FOR LP expr SEMI . SEMI expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	SEMI  shift 109
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 110
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 100
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 111
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 101
	input_stmt : CIN RM term SEMI .  (63)

	.  reduce 63


state 102
	output_stmt : COUT LM term SEMI .  (64)

	.  reduce 64


state 103
	expr : expr . ASSIGN expr
	id_expr : ID ASSIGN expr .  (19)

	ASSIGN  shift 53
	.  reduce 19


state 104
	id_list : id_expr COMMA id_list .  (17)

	.  reduce 17


state 105
	if_stmt : IF LP expr RP stmt . ELSE stmt
	if_stmt : IF LP expr RP stmt .  (52)

	ELSE  shift 112
	.  reduce 52


state 106
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 113
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 107
	expr : expr . ASSIGN expr
	for_stmt : FOR LP SEMI SEMI expr . RP stmt

	ASSIGN  shift 53
	RP  shift 114


state 108
	for_stmt : FOR LP SEMI expr SEMI . expr RP stmt
	for_stmt : FOR LP SEMI expr SEMI . RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21
	RP  shift 115

	simple_expr  goto 22
	term  goto 23
	expr  goto 116
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 109
	for_stmt : FOR LP expr SEMI SEMI . RP stmt
	for_stmt : FOR LP expr SEMI SEMI . expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21
	RP  shift 117

	simple_expr  goto 22
	term  goto 23
	expr  goto 118
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 110
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr SEMI expr . SEMI RP stmt
	for_stmt : FOR LP expr SEMI expr . SEMI expr RP stmt

	ASSIGN  shift 53
	SEMI  shift 119


state 111
	while_stmt : WHILE LP expr RP stmt .  (62)

	.  reduce 62


state 112
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 120
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 113
	for_stmt : FOR LP SEMI SEMI RP stmt .  (61)

	.  reduce 61


state 114
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 121
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 115
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 122
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 116
	expr : expr . ASSIGN expr
	for_stmt : FOR LP SEMI expr SEMI expr . RP stmt

	ASSIGN  shift 53
	RP  shift 123


state 117
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 124
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 118
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr SEMI SEMI expr . RP stmt

	ASSIGN  shift 53
	RP  shift 125


state 119
	for_stmt : FOR LP expr SEMI expr SEMI . RP stmt
	for_stmt : FOR LP expr SEMI expr SEMI . expr RP stmt

	ID  shift 16
	NUMBER  shift 17
	CHARACTER  shift 18
	NOT  shift 19
	LP  shift 21
	RP  shift 126

	simple_expr  goto 22
	term  goto 23
	expr  goto 127
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27


state 120
	if_stmt : IF LP expr RP stmt ELSE stmt .  (53)

	.  reduce 53


state 121
	for_stmt : FOR LP SEMI SEMI expr RP stmt .  (58)

	.  reduce 58


state 122
	for_stmt : FOR LP SEMI expr SEMI RP stmt .  (59)

	.  reduce 59


state 123
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 128
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 124
	for_stmt : FOR LP expr SEMI SEMI RP stmt .  (60)

	.  reduce 60


state 125
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 129
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 126
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 130
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 127
	expr : expr . ASSIGN expr
	for_stmt : FOR LP expr SEMI expr SEMI expr . RP stmt

	ASSIGN  shift 53
	RP  shift 131


state 128
	for_stmt : FOR LP SEMI expr SEMI expr RP stmt .  (55)

	.  reduce 55


state 129
	for_stmt : FOR LP expr SEMI SEMI expr RP stmt .  (56)

	.  reduce 56


state 130
	for_stmt : FOR LP expr SEMI expr SEMI RP stmt .  (57)

	.  reduce 57


state 131
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
	CHARACTER  shift 18
	NOT  shift 19
	LFP  shift 5
	SEMI  shift 20
	LP  shift 21

	simple_expr  goto 22
	term  goto 23
	expr  goto 24
	eq_expr  goto 25
	and_expr  goto 26
	or_expr  goto 27
	type_var  goto 29
	input_stmt  goto 30
	expr_stmt  goto 31
	complex  goto 32
	stmt  goto 132
	var_stmt  goto 34
	if_stmt  goto 35
	for_stmt  goto 36
	output_stmt  goto 37
	while_stmt  goto 38


state 132
	for_stmt : FOR LP expr SEMI expr SEMI expr RP stmt .  (54)

	.  reduce 54


Rules never reduced
	Grammar :  (65)


##############################################################################
# Summary
##############################################################################

41 token(s), 22 nonterminal(s)
66 grammar rule(s), 133 state(s)


##############################################################################
# End of File
##############################################################################
