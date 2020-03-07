#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 115 of your 30 day trial period.
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
# Date: 12/25/19
# Time: 15:27:20
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : MAIN LPAREN RPAREN compound_statement

    2  id : ID

    3  constant : INT_NUM
    4           | DOUBLE_NUM
    5           | CONSTCHAR

    6  var_declaration : type_specifier init_declarator_list SEMICOLON

    7  init_declarator_list : init_declarator
    8                       | init_declarator_list COMMA init_declarator

    9  init_declarator : id
   10                  | id ASSIGN assignment_expression

   11  type_specifier : INT
   12                 | CHAR
   13                 | DOUBLE

   14  var : ID

   15  primary_expression : var
   16                     | constant
   17                     | LPAREN expression RPAREN

   18  postfix_expression : primary_expression
   19                     | postfix_expression PLUS2
   20                     | postfix_expression MINUS2

   21  unary_expression : postfix_expression
   22                   | PLUS2 unary_expression
   23                   | MINUS2 unary_expression
   24                   | MINUS unary_expression
   25                   | PLUS unary_expression
   26                   | NOT unary_expression

   27  cast_expression : unary_expression
   28                  | LPAREN type_specifier RPAREN cast_expression

   29  multi_expression : cast_expression
   30                   | multi_expression TIMES cast_expression
   31                   | multi_expression OVER cast_expression
   32                   | multi_expression MOD cast_expression

   33  additive_expression : multi_expression
   34                      | additive_expression PLUS multi_expression
   35                      | additive_expression MINUS multi_expression

   36  shift_expression : additive_expression
   37                   | shift_expression LSHIFT additive_expression
   38                   | shift_expression RSHIFT additive_expression

   39  relational_expression : shift_expression
   40                        | relational_expression LT shift_expression
   41                        | relational_expression GT shift_expression
   42                        | relational_expression LE shift_expression
   43                        | relational_expression GE shift_expression

   44  equality_expression : relational_expression
   45                      | equality_expression EQ relational_expression
   46                      | equality_expression NE relational_expression

   47  AND_expression : equality_expression
   48                 | AND_expression BIT_AND equality_expression

   49  XOR_expression : AND_expression
   50                 | XOR_expression BIT_XOR AND_expression

   51  OR_expression : XOR_expression
   52                | OR_expression BIT_OR XOR_expression

   53  logical_AND_expression : OR_expression
   54                         | logical_AND_expression AND OR_expression

   55  logical_OR_expression : logical_AND_expression
   56                        | logical_OR_expression OR logical_AND_expression

   57  conditional_expression : logical_OR_expression
   58                         | logical_OR_expression QMARK expression COLON conditional_expression

   59  assignment_expression : conditional_expression
   60                        | unary_expression ASSIGN assignment_expression
   61                        | unary_expression PLUSA assignment_expression
   62                        | unary_expression MINUSA assignment_expression
   63                        | unary_expression TIMESA assignment_expression
   64                        | unary_expression OVERA assignment_expression
   65                        | unary_expression MODA assignment_expression

   66  expression : assignment_expression
   67             | expression COMMA assignment_expression

   68  statement : compound_statement
   69            | expression_statement
   70            | selection_statement
   71            | iteration_statement
   72            | jump_statement
   73            | input_statement
   74            | print_statement

   75  compound_statement : LBRACE RBRACE
   76                     | LBRACE block_item_list RBRACE

   77  block_item_list : block_item
   78                  | block_item_list block_item

   79  block_item : var_declaration
   80             | statement

   81  expression_statement : SEMICOLON
   82                       | expression SEMICOLON

   83  selection_statement : if_statement
   84                      | switch_statement

   85  if_statement : IF LPAREN expression RPAREN statement ELSE statement
   86               | IF LPAREN expression RPAREN statement

   87  switch_statement : SWITCH LPAREN expression RPAREN statement

   88  iteration_statement : while_statement
   89                      | do_while_statment
   90                      | for_statement

   91  while_statement : WHILE LPAREN expression RPAREN statement

   92  do_while_statment : DO statement WHILE LPAREN expression RPAREN SEMICOLON

   93  for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement
   94                | FOR LPAREN expression SEMICOLON expression SEMICOLON RPAREN statement
   95                | FOR LPAREN expression SEMICOLON SEMICOLON expression RPAREN statement
   96                | FOR LPAREN expression SEMICOLON SEMICOLON RPAREN statement
   97                | FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement
   98                | FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement
   99                | FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement
  100                | FOR LPAREN SEMICOLON SEMICOLON RPAREN statement
  101                | FOR LPAREN var_declaration expression SEMICOLON expression RPAREN statement
  102                | FOR LPAREN var_declaration expression SEMICOLON RPAREN statement
  103                | FOR LPAREN var_declaration SEMICOLON expression RPAREN statement
  104                | FOR LPAREN var_declaration SEMICOLON RPAREN statement

  105  jump_statement : CONTINUE SEMICOLON
  106                 | BREAK SEMICOLON

  107  input_statement : INPUT LPAREN expression RPAREN SEMICOLON

  108  print_statement : PRINT LPAREN expression RPAREN SEMICOLON


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	MAIN  shift 1

	program  goto 2


state 1
	program : MAIN . LPAREN RPAREN compound_statement

	LPAREN  shift 3


state 2
	$accept : program . $end  (0)

	$end  accept


state 3
	program : MAIN LPAREN . RPAREN compound_statement

	RPAREN  shift 4


state 4
	program : MAIN LPAREN RPAREN . compound_statement

	LBRACE  shift 5

	compound_statement  goto 6


state 5
	compound_statement : LBRACE . block_item_list RBRACE
	compound_statement : LBRACE . RBRACE

	INT  shift 7
	CHAR  shift 8
	DOUBLE  shift 9
	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	RBRACE  shift 26
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	var_declaration  goto 36
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	type_specifier  goto 41
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 51
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	block_item  goto 62
	selection_statement  goto 63
	iteration_statement  goto 64
	block_item_list  goto 65
	jump_statement  goto 66


state 6
	program : MAIN LPAREN RPAREN compound_statement .  (1)

	.  reduce 1


state 7
	type_specifier : INT .  (11)

	.  reduce 11


state 8
	type_specifier : CHAR .  (12)

	.  reduce 12


state 9
	type_specifier : DOUBLE .  (13)

	.  reduce 13


state 10
	if_statement : IF . LPAREN expression RPAREN statement
	if_statement : IF . LPAREN expression RPAREN statement ELSE statement

	LPAREN  shift 67


state 11
	for_statement : FOR . LPAREN SEMICOLON SEMICOLON RPAREN statement
	for_statement : FOR . LPAREN SEMICOLON SEMICOLON expression RPAREN statement
	for_statement : FOR . LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement
	for_statement : FOR . LPAREN expression SEMICOLON SEMICOLON expression RPAREN statement
	for_statement : FOR . LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement
	for_statement : FOR . LPAREN expression SEMICOLON expression SEMICOLON RPAREN statement
	for_statement : FOR . LPAREN expression SEMICOLON SEMICOLON RPAREN statement
	for_statement : FOR . LPAREN SEMICOLON expression SEMICOLON RPAREN statement
	for_statement : FOR . LPAREN var_declaration expression SEMICOLON expression RPAREN statement
	for_statement : FOR . LPAREN var_declaration expression SEMICOLON RPAREN statement
	for_statement : FOR . LPAREN var_declaration SEMICOLON expression RPAREN statement
	for_statement : FOR . LPAREN var_declaration SEMICOLON RPAREN statement

	LPAREN  shift 68


state 12
	while_statement : WHILE . LPAREN expression RPAREN statement

	LPAREN  shift 69


state 13
	do_while_statment : DO . statement WHILE LPAREN expression RPAREN SEMICOLON

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 70
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 14
	switch_statement : SWITCH . LPAREN expression RPAREN statement

	LPAREN  shift 71


state 15
	jump_statement : BREAK . SEMICOLON

	SEMICOLON  shift 72


state 16
	jump_statement : CONTINUE . SEMICOLON

	SEMICOLON  shift 73


state 17
	var : ID .  (14)

	.  reduce 14


state 18
	constant : DOUBLE_NUM .  (4)

	.  reduce 4


state 19
	constant : INT_NUM .  (3)

	.  reduce 3


state 20
	constant : CONSTCHAR .  (5)

	.  reduce 5


state 21
	unary_expression : PLUS2 . unary_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 74
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 75
	constant  goto 45


state 22
	unary_expression : MINUS2 . unary_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 74
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 76
	constant  goto 45


state 23
	unary_expression : PLUS . unary_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 74
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 77
	constant  goto 45


state 24
	unary_expression : MINUS . unary_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 74
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 78
	constant  goto 45


state 25
	primary_expression : LPAREN . expression RPAREN
	cast_expression : LPAREN . type_specifier RPAREN cast_expression

	INT  shift 7
	CHAR  shift 8
	DOUBLE  shift 9
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 79
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	type_specifier  goto 80
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 26
	compound_statement : LBRACE RBRACE .  (75)

	.  reduce 75


state 27
	expression_statement : SEMICOLON .  (81)

	.  reduce 81


state 28
	unary_expression : NOT . unary_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 74
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 81
	constant  goto 45


state 29
	input_statement : INPUT . LPAREN expression RPAREN SEMICOLON

	LPAREN  shift 82


state 30
	print_statement : PRINT . LPAREN expression RPAREN SEMICOLON

	LPAREN  shift 83


state 31
	statement : compound_statement .  (68)

	.  reduce 68


state 32
	shift_expression : shift_expression . RSHIFT additive_expression
	relational_expression : shift_expression .  (39)
	shift_expression : shift_expression . LSHIFT additive_expression

	LSHIFT  shift 84
	RSHIFT  shift 85
	.  reduce 39


state 33
	expression : expression . COMMA assignment_expression
	expression_statement : expression . SEMICOLON

	SEMICOLON  shift 86
	COMMA  shift 87


state 34
	multi_expression : multi_expression . OVER cast_expression
	multi_expression : multi_expression . MOD cast_expression
	multi_expression : multi_expression . TIMES cast_expression
	additive_expression : multi_expression .  (33)

	TIMES  shift 88
	OVER  shift 89
	MOD  shift 90
	.  reduce 33


state 35
	expression : assignment_expression .  (66)

	.  reduce 66


state 36
	block_item : var_declaration .  (79)

	.  reduce 79


state 37
	postfix_expression : primary_expression .  (18)

	.  reduce 18


state 38
	additive_expression : additive_expression . PLUS multi_expression
	additive_expression : additive_expression . MINUS multi_expression
	shift_expression : additive_expression .  (36)

	PLUS  shift 91
	MINUS  shift 92
	.  reduce 36


state 39
	equality_expression : equality_expression . EQ relational_expression
	equality_expression : equality_expression . NE relational_expression
	AND_expression : equality_expression .  (47)

	EQ  shift 93
	NE  shift 94
	.  reduce 47


state 40
	equality_expression : relational_expression .  (44)
	relational_expression : relational_expression . LE shift_expression
	relational_expression : relational_expression . GT shift_expression
	relational_expression : relational_expression . LT shift_expression
	relational_expression : relational_expression . GE shift_expression

	LT  shift 95
	LE  shift 96
	GT  shift 97
	GE  shift 98
	.  reduce 44


state 41
	var_declaration : type_specifier . init_declarator_list SEMICOLON

	ID  shift 99

	id  goto 100
	init_declarator_list  goto 101
	init_declarator  goto 102


state 42
	unary_expression : postfix_expression .  (21)
	postfix_expression : postfix_expression . MINUS2
	postfix_expression : postfix_expression . PLUS2

	PLUS2  shift 103
	MINUS2  shift 104
	.  reduce 21


state 43
	primary_expression : var .  (15)

	.  reduce 15


state 44
	cast_expression : unary_expression .  (27)
	assignment_expression : unary_expression . ASSIGN assignment_expression
	assignment_expression : unary_expression . PLUSA assignment_expression
	assignment_expression : unary_expression . MINUSA assignment_expression
	assignment_expression : unary_expression . TIMESA assignment_expression
	assignment_expression : unary_expression . OVERA assignment_expression
	assignment_expression : unary_expression . MODA assignment_expression

	ASSIGN  shift 105
	PLUSA  shift 106
	MINUSA  shift 107
	TIMESA  shift 108
	OVERA  shift 109
	MODA  shift 110
	.  reduce 27


state 45
	primary_expression : constant .  (16)

	.  reduce 16


state 46
	multi_expression : cast_expression .  (29)

	.  reduce 29


state 47
	logical_AND_expression : OR_expression .  (53)
	OR_expression : OR_expression . BIT_OR XOR_expression

	BIT_OR  shift 111
	.  reduce 53


state 48
	XOR_expression : XOR_expression . BIT_XOR AND_expression
	OR_expression : XOR_expression .  (51)

	BIT_XOR  shift 112
	.  reduce 51


state 49
	logical_OR_expression : logical_AND_expression .  (55)
	logical_AND_expression : logical_AND_expression . AND OR_expression

	AND  shift 113
	.  reduce 55


state 50
	logical_OR_expression : logical_OR_expression . OR logical_AND_expression
	conditional_expression : logical_OR_expression .  (57)
	conditional_expression : logical_OR_expression . QMARK expression COLON conditional_expression

	OR  shift 114
	QMARK  shift 115
	.  reduce 57


state 51
	block_item : statement .  (80)

	.  reduce 80


state 52
	XOR_expression : AND_expression .  (49)
	AND_expression : AND_expression . BIT_AND equality_expression

	BIT_AND  shift 116
	.  reduce 49


state 53
	statement : expression_statement .  (69)

	.  reduce 69


state 54
	assignment_expression : conditional_expression .  (59)

	.  reduce 59


state 55
	iteration_statement : do_while_statment .  (89)

	.  reduce 89


state 56
	iteration_statement : for_statement .  (90)

	.  reduce 90


state 57
	statement : input_statement .  (73)

	.  reduce 73


state 58
	selection_statement : switch_statement .  (84)

	.  reduce 84


state 59
	statement : print_statement .  (74)

	.  reduce 74


state 60
	selection_statement : if_statement .  (83)

	.  reduce 83


state 61
	iteration_statement : while_statement .  (88)

	.  reduce 88


state 62
	block_item_list : block_item .  (77)

	.  reduce 77


state 63
	statement : selection_statement .  (70)

	.  reduce 70


state 64
	statement : iteration_statement .  (71)

	.  reduce 71


state 65
	compound_statement : LBRACE block_item_list . RBRACE
	block_item_list : block_item_list . block_item

	INT  shift 7
	CHAR  shift 8
	DOUBLE  shift 9
	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	RBRACE  shift 117
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	var_declaration  goto 36
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	type_specifier  goto 41
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 51
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	block_item  goto 118
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 66
	statement : jump_statement .  (72)

	.  reduce 72


state 67
	if_statement : IF LPAREN . expression RPAREN statement
	if_statement : IF LPAREN . expression RPAREN statement ELSE statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 119
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 68
	for_statement : FOR LPAREN . SEMICOLON SEMICOLON RPAREN statement
	for_statement : FOR LPAREN . SEMICOLON SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN . expression SEMICOLON expression SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN . expression SEMICOLON SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN . SEMICOLON expression SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN . expression SEMICOLON expression SEMICOLON RPAREN statement
	for_statement : FOR LPAREN . expression SEMICOLON SEMICOLON RPAREN statement
	for_statement : FOR LPAREN . SEMICOLON expression SEMICOLON RPAREN statement
	for_statement : FOR LPAREN . var_declaration expression SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN . var_declaration expression SEMICOLON RPAREN statement
	for_statement : FOR LPAREN . var_declaration SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN . var_declaration SEMICOLON RPAREN statement

	INT  shift 7
	CHAR  shift 8
	DOUBLE  shift 9
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	SEMICOLON  shift 120
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 121
	multi_expression  goto 34
	assignment_expression  goto 35
	var_declaration  goto 122
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	type_specifier  goto 41
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 69
	while_statement : WHILE LPAREN . expression RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 123
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 70
	do_while_statment : DO statement . WHILE LPAREN expression RPAREN SEMICOLON

	WHILE  shift 124


state 71
	switch_statement : SWITCH LPAREN . expression RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 125
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 72
	jump_statement : BREAK SEMICOLON .  (106)

	.  reduce 106


state 73
	jump_statement : CONTINUE SEMICOLON .  (105)

	.  reduce 105


state 74
	primary_expression : LPAREN . expression RPAREN

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 79
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 75
	unary_expression : PLUS2 unary_expression .  (22)

	.  reduce 22


state 76
	unary_expression : MINUS2 unary_expression .  (23)

	.  reduce 23


state 77
	unary_expression : PLUS unary_expression .  (25)

	.  reduce 25


state 78
	unary_expression : MINUS unary_expression .  (24)

	.  reduce 24


state 79
	primary_expression : LPAREN expression . RPAREN
	expression : expression . COMMA assignment_expression

	RPAREN  shift 126
	COMMA  shift 87


state 80
	cast_expression : LPAREN type_specifier . RPAREN cast_expression

	RPAREN  shift 127


state 81
	unary_expression : NOT unary_expression .  (26)

	.  reduce 26


state 82
	input_statement : INPUT LPAREN . expression RPAREN SEMICOLON

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 128
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 83
	print_statement : PRINT LPAREN . expression RPAREN SEMICOLON

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 129
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 84
	shift_expression : shift_expression LSHIFT . additive_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 130
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 85
	shift_expression : shift_expression RSHIFT . additive_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 132
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 86
	expression_statement : expression SEMICOLON .  (82)

	.  reduce 82


state 87
	expression : expression COMMA . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 133
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 88
	multi_expression : multi_expression TIMES . cast_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 134


state 89
	multi_expression : multi_expression OVER . cast_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 135


state 90
	multi_expression : multi_expression MOD . cast_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 136


state 91
	additive_expression : additive_expression PLUS . multi_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	multi_expression  goto 137
	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 92
	additive_expression : additive_expression MINUS . multi_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	multi_expression  goto 138
	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 93
	equality_expression : equality_expression EQ . relational_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	relational_expression  goto 139
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 94
	equality_expression : equality_expression NE . relational_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	relational_expression  goto 140
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 95
	relational_expression : relational_expression LT . shift_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 141
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 96
	relational_expression : relational_expression LE . shift_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 142
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 97
	relational_expression : relational_expression GT . shift_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 143
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 98
	relational_expression : relational_expression GE . shift_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 144
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 99
	id : ID .  (2)

	.  reduce 2


state 100
	init_declarator : id .  (9)
	init_declarator : id . ASSIGN assignment_expression

	ASSIGN  shift 145
	.  reduce 9


state 101
	var_declaration : type_specifier init_declarator_list . SEMICOLON
	init_declarator_list : init_declarator_list . COMMA init_declarator

	SEMICOLON  shift 146
	COMMA  shift 147


state 102
	init_declarator_list : init_declarator .  (7)

	.  reduce 7


state 103
	postfix_expression : postfix_expression PLUS2 .  (19)

	.  reduce 19


state 104
	postfix_expression : postfix_expression MINUS2 .  (20)

	.  reduce 20


state 105
	assignment_expression : unary_expression ASSIGN . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 148
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 106
	assignment_expression : unary_expression PLUSA . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 149
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 107
	assignment_expression : unary_expression MINUSA . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 150
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 108
	assignment_expression : unary_expression TIMESA . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 151
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 109
	assignment_expression : unary_expression OVERA . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 152
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 110
	assignment_expression : unary_expression MODA . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 153
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 111
	OR_expression : OR_expression BIT_OR . XOR_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46
	XOR_expression  goto 154
	AND_expression  goto 52


state 112
	XOR_expression : XOR_expression BIT_XOR . AND_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46
	AND_expression  goto 155


state 113
	logical_AND_expression : logical_AND_expression AND . OR_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 156
	XOR_expression  goto 48
	AND_expression  goto 52


state 114
	logical_OR_expression : logical_OR_expression OR . logical_AND_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 157
	AND_expression  goto 52


state 115
	conditional_expression : logical_OR_expression QMARK . expression COLON conditional_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 158
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 116
	AND_expression : AND_expression BIT_AND . equality_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 159
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46


state 117
	compound_statement : LBRACE block_item_list RBRACE .  (76)

	.  reduce 76


state 118
	block_item_list : block_item_list block_item .  (78)

	.  reduce 78


state 119
	expression : expression . COMMA assignment_expression
	if_statement : IF LPAREN expression . RPAREN statement
	if_statement : IF LPAREN expression . RPAREN statement ELSE statement

	RPAREN  shift 160
	COMMA  shift 87


state 120
	for_statement : FOR LPAREN SEMICOLON . SEMICOLON RPAREN statement
	for_statement : FOR LPAREN SEMICOLON . SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN SEMICOLON . expression SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN SEMICOLON . expression SEMICOLON RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	SEMICOLON  shift 161
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 162
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 121
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN expression . SEMICOLON expression SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN expression . SEMICOLON SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN expression . SEMICOLON expression SEMICOLON RPAREN statement
	for_statement : FOR LPAREN expression . SEMICOLON SEMICOLON RPAREN statement

	SEMICOLON  shift 163
	COMMA  shift 87


state 122
	for_statement : FOR LPAREN var_declaration . expression SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN var_declaration . expression SEMICOLON RPAREN statement
	for_statement : FOR LPAREN var_declaration . SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN var_declaration . SEMICOLON RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	SEMICOLON  shift 164
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 165
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 123
	expression : expression . COMMA assignment_expression
	while_statement : WHILE LPAREN expression . RPAREN statement

	RPAREN  shift 166
	COMMA  shift 87


state 124
	do_while_statment : DO statement WHILE . LPAREN expression RPAREN SEMICOLON

	LPAREN  shift 167


state 125
	expression : expression . COMMA assignment_expression
	switch_statement : SWITCH LPAREN expression . RPAREN statement

	RPAREN  shift 168
	COMMA  shift 87


state 126
	primary_expression : LPAREN expression RPAREN .  (17)

	.  reduce 17


state 127
	cast_expression : LPAREN type_specifier RPAREN . cast_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	primary_expression  goto 37
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 169


state 128
	expression : expression . COMMA assignment_expression
	input_statement : INPUT LPAREN expression . RPAREN SEMICOLON

	RPAREN  shift 170
	COMMA  shift 87


state 129
	expression : expression . COMMA assignment_expression
	print_statement : PRINT LPAREN expression . RPAREN SEMICOLON

	RPAREN  shift 171
	COMMA  shift 87


state 130
	additive_expression : additive_expression . PLUS multi_expression
	additive_expression : additive_expression . MINUS multi_expression
	shift_expression : shift_expression LSHIFT additive_expression .  (37)

	PLUS  shift 91
	MINUS  shift 92
	.  reduce 37


state 131
	cast_expression : unary_expression .  (27)

	.  reduce 27


state 132
	shift_expression : shift_expression RSHIFT additive_expression .  (38)
	additive_expression : additive_expression . PLUS multi_expression
	additive_expression : additive_expression . MINUS multi_expression

	PLUS  shift 91
	MINUS  shift 92
	.  reduce 38


state 133
	expression : expression COMMA assignment_expression .  (67)

	.  reduce 67


state 134
	multi_expression : multi_expression TIMES cast_expression .  (30)

	.  reduce 30


state 135
	multi_expression : multi_expression OVER cast_expression .  (31)

	.  reduce 31


state 136
	multi_expression : multi_expression MOD cast_expression .  (32)

	.  reduce 32


state 137
	multi_expression : multi_expression . OVER cast_expression
	multi_expression : multi_expression . MOD cast_expression
	multi_expression : multi_expression . TIMES cast_expression
	additive_expression : additive_expression PLUS multi_expression .  (34)

	TIMES  shift 88
	OVER  shift 89
	MOD  shift 90
	.  reduce 34


state 138
	multi_expression : multi_expression . OVER cast_expression
	multi_expression : multi_expression . MOD cast_expression
	multi_expression : multi_expression . TIMES cast_expression
	additive_expression : additive_expression MINUS multi_expression .  (35)

	TIMES  shift 88
	OVER  shift 89
	MOD  shift 90
	.  reduce 35


state 139
	relational_expression : relational_expression . LE shift_expression
	equality_expression : equality_expression EQ relational_expression .  (45)
	relational_expression : relational_expression . GT shift_expression
	relational_expression : relational_expression . LT shift_expression
	relational_expression : relational_expression . GE shift_expression

	LT  shift 95
	LE  shift 96
	GT  shift 97
	GE  shift 98
	.  reduce 45


state 140
	relational_expression : relational_expression . LE shift_expression
	equality_expression : equality_expression NE relational_expression .  (46)
	relational_expression : relational_expression . GT shift_expression
	relational_expression : relational_expression . LT shift_expression
	relational_expression : relational_expression . GE shift_expression

	LT  shift 95
	LE  shift 96
	GT  shift 97
	GE  shift 98
	.  reduce 46


state 141
	shift_expression : shift_expression . RSHIFT additive_expression
	shift_expression : shift_expression . LSHIFT additive_expression
	relational_expression : relational_expression LT shift_expression .  (40)

	LSHIFT  shift 84
	RSHIFT  shift 85
	.  reduce 40


state 142
	relational_expression : relational_expression LE shift_expression .  (42)
	shift_expression : shift_expression . RSHIFT additive_expression
	shift_expression : shift_expression . LSHIFT additive_expression

	LSHIFT  shift 84
	RSHIFT  shift 85
	.  reduce 42


state 143
	shift_expression : shift_expression . RSHIFT additive_expression
	relational_expression : relational_expression GT shift_expression .  (41)
	shift_expression : shift_expression . LSHIFT additive_expression

	LSHIFT  shift 84
	RSHIFT  shift 85
	.  reduce 41


state 144
	shift_expression : shift_expression . RSHIFT additive_expression
	shift_expression : shift_expression . LSHIFT additive_expression
	relational_expression : relational_expression GE shift_expression .  (43)

	LSHIFT  shift 84
	RSHIFT  shift 85
	.  reduce 43


state 145
	init_declarator : id ASSIGN . assignment_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	assignment_expression  goto 172
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 146
	var_declaration : type_specifier init_declarator_list SEMICOLON .  (6)

	.  reduce 6


state 147
	init_declarator_list : init_declarator_list COMMA . init_declarator

	ID  shift 99

	id  goto 100
	init_declarator  goto 173


state 148
	assignment_expression : unary_expression ASSIGN assignment_expression .  (60)

	.  reduce 60


state 149
	assignment_expression : unary_expression PLUSA assignment_expression .  (61)

	.  reduce 61


state 150
	assignment_expression : unary_expression MINUSA assignment_expression .  (62)

	.  reduce 62


state 151
	assignment_expression : unary_expression TIMESA assignment_expression .  (63)

	.  reduce 63


state 152
	assignment_expression : unary_expression OVERA assignment_expression .  (64)

	.  reduce 64


state 153
	assignment_expression : unary_expression MODA assignment_expression .  (65)

	.  reduce 65


state 154
	XOR_expression : XOR_expression . BIT_XOR AND_expression
	OR_expression : OR_expression BIT_OR XOR_expression .  (52)

	BIT_XOR  shift 112
	.  reduce 52


state 155
	XOR_expression : XOR_expression BIT_XOR AND_expression .  (50)
	AND_expression : AND_expression . BIT_AND equality_expression

	BIT_AND  shift 116
	.  reduce 50


state 156
	OR_expression : OR_expression . BIT_OR XOR_expression
	logical_AND_expression : logical_AND_expression AND OR_expression .  (54)

	BIT_OR  shift 111
	.  reduce 54


state 157
	logical_OR_expression : logical_OR_expression OR logical_AND_expression .  (56)
	logical_AND_expression : logical_AND_expression . AND OR_expression

	AND  shift 113
	.  reduce 56


state 158
	conditional_expression : logical_OR_expression QMARK expression . COLON conditional_expression
	expression : expression . COMMA assignment_expression

	COLON  shift 174
	COMMA  shift 87


state 159
	equality_expression : equality_expression . EQ relational_expression
	equality_expression : equality_expression . NE relational_expression
	AND_expression : AND_expression BIT_AND equality_expression .  (48)

	EQ  shift 93
	NE  shift 94
	.  reduce 48


state 160
	if_statement : IF LPAREN expression RPAREN . statement
	if_statement : IF LPAREN expression RPAREN . statement ELSE statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 175
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 161
	for_statement : FOR LPAREN SEMICOLON SEMICOLON . RPAREN statement
	for_statement : FOR LPAREN SEMICOLON SEMICOLON . expression RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	RPAREN  shift 176
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 177
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 162
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN SEMICOLON expression . SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN SEMICOLON expression . SEMICOLON RPAREN statement

	SEMICOLON  shift 178
	COMMA  shift 87


state 163
	for_statement : FOR LPAREN expression SEMICOLON . expression SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN expression SEMICOLON . SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN expression SEMICOLON . expression SEMICOLON RPAREN statement
	for_statement : FOR LPAREN expression SEMICOLON . SEMICOLON RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	SEMICOLON  shift 179
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 180
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 164
	for_statement : FOR LPAREN var_declaration SEMICOLON . expression RPAREN statement
	for_statement : FOR LPAREN var_declaration SEMICOLON . RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	RPAREN  shift 181
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 182
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 165
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN var_declaration expression . SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN var_declaration expression . SEMICOLON RPAREN statement

	SEMICOLON  shift 183
	COMMA  shift 87


state 166
	while_statement : WHILE LPAREN expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 184
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 167
	do_while_statment : DO statement WHILE LPAREN . expression RPAREN SEMICOLON

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 185
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 168
	switch_statement : SWITCH LPAREN expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 186
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 169
	cast_expression : LPAREN type_specifier RPAREN cast_expression .  (28)

	.  reduce 28


state 170
	input_statement : INPUT LPAREN expression RPAREN . SEMICOLON

	SEMICOLON  shift 187


state 171
	print_statement : PRINT LPAREN expression RPAREN . SEMICOLON

	SEMICOLON  shift 188


state 172
	init_declarator : id ASSIGN assignment_expression .  (10)

	.  reduce 10


state 173
	init_declarator_list : init_declarator_list COMMA init_declarator .  (8)

	.  reduce 8


state 174
	conditional_expression : logical_OR_expression QMARK expression COLON . conditional_expression

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	NOT  shift 28

	shift_expression  goto 32
	multi_expression  goto 34
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 131
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 189


175: shift-reduce conflict (shift 190, reduce 86) on ELSE
state 175
	if_statement : IF LPAREN expression RPAREN statement .  (86)
	if_statement : IF LPAREN expression RPAREN statement . ELSE statement

	ELSE  shift 190
	.  reduce 86


state 176
	for_statement : FOR LPAREN SEMICOLON SEMICOLON RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 191
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 177
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN SEMICOLON SEMICOLON expression . RPAREN statement

	RPAREN  shift 192
	COMMA  shift 87


state 178
	for_statement : FOR LPAREN SEMICOLON expression SEMICOLON . expression RPAREN statement
	for_statement : FOR LPAREN SEMICOLON expression SEMICOLON . RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	RPAREN  shift 193
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 194
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 179
	for_statement : FOR LPAREN expression SEMICOLON SEMICOLON . expression RPAREN statement
	for_statement : FOR LPAREN expression SEMICOLON SEMICOLON . RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	RPAREN  shift 195
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 196
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 180
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN expression SEMICOLON expression . SEMICOLON expression RPAREN statement
	for_statement : FOR LPAREN expression SEMICOLON expression . SEMICOLON RPAREN statement

	SEMICOLON  shift 197
	COMMA  shift 87


state 181
	for_statement : FOR LPAREN var_declaration SEMICOLON RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 198
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 182
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN var_declaration SEMICOLON expression . RPAREN statement

	RPAREN  shift 199
	COMMA  shift 87


state 183
	for_statement : FOR LPAREN var_declaration expression SEMICOLON . expression RPAREN statement
	for_statement : FOR LPAREN var_declaration expression SEMICOLON . RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	RPAREN  shift 200
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 201
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 184
	while_statement : WHILE LPAREN expression RPAREN statement .  (91)

	.  reduce 91


state 185
	expression : expression . COMMA assignment_expression
	do_while_statment : DO statement WHILE LPAREN expression . RPAREN SEMICOLON

	RPAREN  shift 202
	COMMA  shift 87


state 186
	switch_statement : SWITCH LPAREN expression RPAREN statement .  (87)

	.  reduce 87


state 187
	input_statement : INPUT LPAREN expression RPAREN SEMICOLON .  (107)

	.  reduce 107


state 188
	print_statement : PRINT LPAREN expression RPAREN SEMICOLON .  (108)

	.  reduce 108


state 189
	conditional_expression : logical_OR_expression QMARK expression COLON conditional_expression .  (58)

	.  reduce 58


state 190
	if_statement : IF LPAREN expression RPAREN statement ELSE . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 203
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 191
	for_statement : FOR LPAREN SEMICOLON SEMICOLON RPAREN statement .  (100)

	.  reduce 100


state 192
	for_statement : FOR LPAREN SEMICOLON SEMICOLON expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 204
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 193
	for_statement : FOR LPAREN SEMICOLON expression SEMICOLON RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 205
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 194
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN SEMICOLON expression SEMICOLON expression . RPAREN statement

	RPAREN  shift 206
	COMMA  shift 87


state 195
	for_statement : FOR LPAREN expression SEMICOLON SEMICOLON RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 207
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 196
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN expression SEMICOLON SEMICOLON expression . RPAREN statement

	RPAREN  shift 208
	COMMA  shift 87


state 197
	for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON . expression RPAREN statement
	for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON . RPAREN statement

	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	RPAREN  shift 209
	NOT  shift 28

	shift_expression  goto 32
	expression  goto 210
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	AND_expression  goto 52
	conditional_expression  goto 54


state 198
	for_statement : FOR LPAREN var_declaration SEMICOLON RPAREN statement .  (104)

	.  reduce 104


state 199
	for_statement : FOR LPAREN var_declaration SEMICOLON expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 211
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 200
	for_statement : FOR LPAREN var_declaration expression SEMICOLON RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 212
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 201
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN var_declaration expression SEMICOLON expression . RPAREN statement

	RPAREN  shift 213
	COMMA  shift 87


state 202
	do_while_statment : DO statement WHILE LPAREN expression RPAREN . SEMICOLON

	SEMICOLON  shift 214


state 203
	if_statement : IF LPAREN expression RPAREN statement ELSE statement .  (85)

	.  reduce 85


state 204
	for_statement : FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement .  (99)

	.  reduce 99


state 205
	for_statement : FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement .  (98)

	.  reduce 98


state 206
	for_statement : FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 215
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 207
	for_statement : FOR LPAREN expression SEMICOLON SEMICOLON RPAREN statement .  (96)

	.  reduce 96


state 208
	for_statement : FOR LPAREN expression SEMICOLON SEMICOLON expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 216
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 209
	for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 217
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 210
	expression : expression . COMMA assignment_expression
	for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON expression . RPAREN statement

	RPAREN  shift 218
	COMMA  shift 87


state 211
	for_statement : FOR LPAREN var_declaration SEMICOLON expression RPAREN statement .  (103)

	.  reduce 103


state 212
	for_statement : FOR LPAREN var_declaration expression SEMICOLON RPAREN statement .  (102)

	.  reduce 102


state 213
	for_statement : FOR LPAREN var_declaration expression SEMICOLON expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 219
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 214
	do_while_statment : DO statement WHILE LPAREN expression RPAREN SEMICOLON .  (92)

	.  reduce 92


state 215
	for_statement : FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement .  (97)

	.  reduce 97


state 216
	for_statement : FOR LPAREN expression SEMICOLON SEMICOLON expression RPAREN statement .  (95)

	.  reduce 95


state 217
	for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON RPAREN statement .  (94)

	.  reduce 94


state 218
	for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN . statement

	IF  shift 10
	FOR  shift 11
	WHILE  shift 12
	DO  shift 13
	SWITCH  shift 14
	BREAK  shift 15
	CONTINUE  shift 16
	ID  shift 17
	DOUBLE_NUM  shift 18
	INT_NUM  shift 19
	CONSTCHAR  shift 20
	PLUS2  shift 21
	MINUS2  shift 22
	PLUS  shift 23
	MINUS  shift 24
	LPAREN  shift 25
	LBRACE  shift 5
	SEMICOLON  shift 27
	NOT  shift 28
	INPUT  shift 29
	PRINT  shift 30

	compound_statement  goto 31
	shift_expression  goto 32
	expression  goto 33
	multi_expression  goto 34
	assignment_expression  goto 35
	primary_expression  goto 37
	additive_expression  goto 38
	equality_expression  goto 39
	relational_expression  goto 40
	postfix_expression  goto 42
	var  goto 43
	unary_expression  goto 44
	constant  goto 45
	cast_expression  goto 46
	OR_expression  goto 47
	XOR_expression  goto 48
	logical_AND_expression  goto 49
	logical_OR_expression  goto 50
	statement  goto 220
	AND_expression  goto 52
	expression_statement  goto 53
	conditional_expression  goto 54
	do_while_statment  goto 55
	for_statement  goto 56
	input_statement  goto 57
	switch_statement  goto 58
	print_statement  goto 59
	if_statement  goto 60
	while_statement  goto 61
	selection_statement  goto 63
	iteration_statement  goto 64
	jump_statement  goto 66


state 219
	for_statement : FOR LPAREN var_declaration expression SEMICOLON expression RPAREN statement .  (101)

	.  reduce 101


state 220
	for_statement : FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement .  (93)

	.  reduce 93


##############################################################################
# Summary
##############################################################################

State 175 contains 1 shift-reduce conflict(s)


55 token(s), 41 nonterminal(s)
109 grammar rule(s), 221 state(s)


##############################################################################
# End of File
##############################################################################
