#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 47 of your 30 day trial period.
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
# Date: 10/18/19
# Time: 11:24:16
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : lines $end

    1  lines : lines expr ';'
    2        | lines ';'
    3        |

    4  expr : expr AND expr
    5       | expr MIN expr
    6       | expr MUL expr
    7       | expr DIV expr
    8       | BL expr BR
    9       | MIN expr
   10       | DIGIT

   11  DIGIT : NUMBER
   12        | DIGIT NUMBER

   13  NUMBER : ZERO
   14         | ONE
   15         | TWO
   16         | THREE
   17         | FORE
   18         | FIVE
   19         | SIX
   20         | SEVEN
   21         | EIGHT
   22         | NINE


##############################################################################
# States
##############################################################################

state 0
	$accept : . lines $end
	lines : .  (3)

	.  reduce 3

	lines  goto 1


state 1
	$accept : lines . $end  (0)
	lines : lines . expr ';'
	lines : lines . ';'

	$end  accept
	';'  shift 2
	MIN  shift 3
	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	BL  shift 14

	expr  goto 15
	DIGIT  goto 16
	NUMBER  goto 17


state 2
	lines : lines ';' .  (2)

	.  reduce 2


state 3
	expr : MIN . expr

	MIN  shift 3
	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	BL  shift 14

	expr  goto 18
	DIGIT  goto 16
	NUMBER  goto 17


state 4
	NUMBER : ZERO .  (13)

	.  reduce 13


state 5
	NUMBER : ONE .  (14)

	.  reduce 14


state 6
	NUMBER : TWO .  (15)

	.  reduce 15


state 7
	NUMBER : THREE .  (16)

	.  reduce 16


state 8
	NUMBER : FORE .  (17)

	.  reduce 17


state 9
	NUMBER : FIVE .  (18)

	.  reduce 18


state 10
	NUMBER : SIX .  (19)

	.  reduce 19


state 11
	NUMBER : SEVEN .  (20)

	.  reduce 20


state 12
	NUMBER : EIGHT .  (21)

	.  reduce 21


state 13
	NUMBER : NINE .  (22)

	.  reduce 22


state 14
	expr : BL . expr BR

	MIN  shift 3
	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	BL  shift 14

	expr  goto 19
	DIGIT  goto 16
	NUMBER  goto 17


state 15
	lines : lines expr . ';'
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	';'  shift 20
	AND  shift 21
	MIN  shift 22
	MUL  shift 23
	DIV  shift 24


state 16
	expr : DIGIT .  (10)
	DIGIT : DIGIT . NUMBER

	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	.  reduce 10

	NUMBER  goto 25


state 17
	DIGIT : NUMBER .  (11)

	.  reduce 11


state 18
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : MIN expr .  (9)

	.  reduce 9


state 19
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : BL expr . BR

	AND  shift 21
	MIN  shift 22
	MUL  shift 23
	DIV  shift 24
	BR  shift 26


state 20
	lines : lines expr ';' .  (1)

	.  reduce 1


state 21
	expr : expr AND . expr

	MIN  shift 3
	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	BL  shift 14

	expr  goto 27
	DIGIT  goto 16
	NUMBER  goto 17


state 22
	expr : expr MIN . expr

	MIN  shift 3
	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	BL  shift 14

	expr  goto 28
	DIGIT  goto 16
	NUMBER  goto 17


state 23
	expr : expr MUL . expr

	MIN  shift 3
	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	BL  shift 14

	expr  goto 29
	DIGIT  goto 16
	NUMBER  goto 17


state 24
	expr : expr DIV . expr

	MIN  shift 3
	ZERO  shift 4
	ONE  shift 5
	TWO  shift 6
	THREE  shift 7
	FORE  shift 8
	FIVE  shift 9
	SIX  shift 10
	SEVEN  shift 11
	EIGHT  shift 12
	NINE  shift 13
	BL  shift 14

	expr  goto 30
	DIGIT  goto 16
	NUMBER  goto 17


state 25
	DIGIT : DIGIT NUMBER .  (12)

	.  reduce 12


state 26
	expr : BL expr BR .  (8)

	.  reduce 8


state 27
	expr : expr AND expr .  (4)
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 23
	DIV  shift 24
	.  reduce 4


state 28
	expr : expr . AND expr
	expr : expr MIN expr .  (5)
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 23
	DIV  shift 24
	.  reduce 5


state 29
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr MUL expr .  (6)
	expr : expr . MUL expr
	expr : expr . DIV expr

	.  reduce 6


state 30
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr DIV expr .  (7)
	expr : expr . DIV expr

	.  reduce 7


##############################################################################
# Summary
##############################################################################

20 token(s), 5 nonterminal(s)
23 grammar rule(s), 31 state(s)


##############################################################################
# End of File
##############################################################################
