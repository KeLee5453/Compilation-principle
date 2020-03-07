#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 45 of your 30 day trial period.
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
# Date: 10/16/19
# Time: 12:44:05
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : lines $end

    1  lines : lines expr '\n'
    2        | lines '\n'
    3        |

    4  expr : expr AND expr
    5       | expr MIN expr
    6       | expr MUL expr
    7       | expr DIV expr
    8       | BL expr BR
    9       | MIN expr
   10       | NUMBER

   11  NUMBER : ZERO
   12         | ONE
   13         | TWO
   14         | THREE
   15         | FORE
   16         | FIVE
   17         | SIX
   18         | SEVEN
   19         | EIGHT
   20         | NINE


##############################################################################
# States
##############################################################################

state 0
	$accept : . lines $end
	lines : .  (3)

	.  reduce 3

	lines  goto 1


state 1
	lines : lines . expr '\n'
	lines : lines . '\n'
	$accept : lines . $end  (0)

	$end  accept
	'\n'  shift 2
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
	NUMBER  goto 16


state 2
	lines : lines '\n' .  (2)

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

	expr  goto 17
	NUMBER  goto 16


state 4
	NUMBER : ZERO .  (11)

	.  reduce 11


state 5
	NUMBER : ONE .  (12)

	.  reduce 12


state 6
	NUMBER : TWO .  (13)

	.  reduce 13


state 7
	NUMBER : THREE .  (14)

	.  reduce 14


state 8
	NUMBER : FORE .  (15)

	.  reduce 15


state 9
	NUMBER : FIVE .  (16)

	.  reduce 16


state 10
	NUMBER : SIX .  (17)

	.  reduce 17


state 11
	NUMBER : SEVEN .  (18)

	.  reduce 18


state 12
	NUMBER : EIGHT .  (19)

	.  reduce 19


state 13
	NUMBER : NINE .  (20)

	.  reduce 20


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

	expr  goto 18
	NUMBER  goto 16


state 15
	lines : lines expr . '\n'
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	'\n'  shift 19
	AND  shift 20
	MIN  shift 21
	MUL  shift 22
	DIV  shift 23


state 16
	expr : NUMBER .  (10)

	.  reduce 10


state 17
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : MIN expr .  (9)

	.  reduce 9


state 18
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr
	expr : BL expr . BR

	AND  shift 20
	MIN  shift 21
	MUL  shift 22
	DIV  shift 23
	BR  shift 24


state 19
	lines : lines expr '\n' .  (1)

	.  reduce 1


state 20
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

	expr  goto 25
	NUMBER  goto 16


state 21
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

	expr  goto 26
	NUMBER  goto 16


state 22
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

	expr  goto 27
	NUMBER  goto 16


state 23
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

	expr  goto 28
	NUMBER  goto 16


state 24
	expr : BL expr BR .  (8)

	.  reduce 8


state 25
	expr : expr AND expr .  (4)
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 22
	DIV  shift 23
	.  reduce 4


state 26
	expr : expr . AND expr
	expr : expr MIN expr .  (5)
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr . DIV expr

	MUL  shift 22
	DIV  shift 23
	.  reduce 5


state 27
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr MUL expr .  (6)
	expr : expr . MUL expr
	expr : expr . DIV expr

	.  reduce 6


state 28
	expr : expr . AND expr
	expr : expr . MIN expr
	expr : expr . MUL expr
	expr : expr DIV expr .  (7)
	expr : expr . DIV expr

	.  reduce 7


##############################################################################
# Summary
##############################################################################

20 token(s), 4 nonterminal(s)
21 grammar rule(s), 29 state(s)


##############################################################################
# End of File
##############################################################################
