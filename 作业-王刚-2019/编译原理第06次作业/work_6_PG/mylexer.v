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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 12/05/19
# Time: 18:37:01
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  \n

    2  [ \t]+

    3  ("/*"([^*"]*|".*"|\*+[^/])*\**"*/")|("//".*\n)

    4  ","

    5  ";"

    6  "("

    7  ")"

    8  "{"

    9  "}"

   10  "["

   11  "]"

   12  "if"

   13  "else"

   14  "while"

   15  "for"

   16  "cin"

   17  "cout"

   18  "void"

   19  "int"

   20  "char"

   21  "bool"

   22  "="

   23  "main"

   24  "+"

   25  "-"

   26  "*"

   27  "/"

   28  "%"

   29  "++"

   30  "--"

   31  "=="

   32  ">"

   33  "<"

   34  ">="

   35  "<="

   36  "!="

   37  "&&"

   38  "||"

   39  "!"

   40  "<<"

   41  ">>"

   42  [0-9]+(\.[0-9]+)?(E[+-]?[0-9]+)?

   43  \'.\'

   44  [A-Za-z_]([A-Za-z_]|[0-9])*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30 - 0x39 (10)   goto 16
	0x3b               goto 17
	0x3c               goto 18
	0x3d               goto 19
	0x3e               goto 20
	0x41 - 0x5a (26)   goto 21
	0x5b               goto 22
	0x5d               goto 23
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 24
	0x63               goto 25
	0x64               goto 21
	0x65               goto 26
	0x66               goto 27
	0x67 - 0x68 (2)    goto 21
	0x69               goto 28
	0x6a - 0x6c (3)    goto 21
	0x6d               goto 29
	0x6e - 0x75 (8)    goto 21
	0x76               goto 30
	0x77               goto 31
	0x78 - 0x7a (3)    goto 21
	0x7b               goto 32
	0x7c               goto 33
	0x7d               goto 34


state 2
	^INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30 - 0x39 (10)   goto 16
	0x3b               goto 17
	0x3c               goto 18
	0x3d               goto 19
	0x3e               goto 20
	0x41 - 0x5a (26)   goto 21
	0x5b               goto 22
	0x5d               goto 23
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 24
	0x63               goto 25
	0x64               goto 21
	0x65               goto 26
	0x66               goto 27
	0x67 - 0x68 (2)    goto 21
	0x69               goto 28
	0x6a - 0x6c (3)    goto 21
	0x6d               goto 29
	0x6e - 0x75 (8)    goto 21
	0x76               goto 30
	0x77               goto 31
	0x78 - 0x7a (3)    goto 21
	0x7b               goto 32
	0x7c               goto 33
	0x7d               goto 34


state 3
	0x09               goto 3
	0x20               goto 3

	match 2


state 4
	match 1


state 5
	0x3d               goto 35

	match 39


state 6
	match 28


state 7
	0x26               goto 36


state 8
	0x00 - 0x09 (10)   goto 37
	0x0b - 0xff (245)  goto 37


state 9
	match 6


state 10
	match 7


state 11
	match 26


state 12
	0x2b               goto 38

	match 24


state 13
	match 4


state 14
	0x2d               goto 39

	match 25


state 15
	0x2a               goto 40
	0x2f               goto 41

	match 27


state 16
	0x2e               goto 42
	0x30 - 0x39 (10)   goto 16
	0x45               goto 43

	match 42


state 17
	match 5


state 18
	0x3c               goto 44
	0x3d               goto 45

	match 33


state 19
	0x3d               goto 46

	match 22


state 20
	0x3d               goto 47
	0x3e               goto 48

	match 32


state 21
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 44


state 22
	match 10


state 23
	match 11


state 24
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 49
	0x70 - 0x7a (11)   goto 21

	match 44


state 25
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 50
	0x69               goto 51
	0x6a - 0x6e (5)    goto 21
	0x6f               goto 52
	0x70 - 0x7a (11)   goto 21

	match 44


state 26
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 53
	0x6d - 0x7a (14)   goto 21

	match 44


state 27
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 54
	0x70 - 0x7a (11)   goto 21

	match 44


state 28
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x65 (5)    goto 21
	0x66               goto 55
	0x67 - 0x6d (7)    goto 21
	0x6e               goto 56
	0x6f - 0x7a (12)   goto 21

	match 44


state 29
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 57
	0x62 - 0x7a (25)   goto 21

	match 44


state 30
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 58
	0x70 - 0x7a (11)   goto 21

	match 44


state 31
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 59
	0x69 - 0x7a (18)   goto 21

	match 44


state 32
	match 8


state 33
	0x7c               goto 60


state 34
	match 9


state 35
	match 36


state 36
	match 37


state 37
	0x27               goto 61


state 38
	match 29


state 39
	match 30


state 40
	0x00 - 0x21 (34)   goto 40
	0x23 - 0x29 (7)    goto 40
	0x2a               goto 62
	0x2b - 0x2d (3)    goto 40
	0x2e               goto 63
	0x2f - 0xff (209)  goto 40


state 41
	0x00 - 0x09 (10)   goto 41
	0x0a               goto 64
	0x0b - 0xff (245)  goto 41


state 42
	0x30 - 0x39 (10)   goto 65


state 43
	0x2b               goto 66
	0x2d               goto 66
	0x30 - 0x39 (10)   goto 67


state 44
	match 40


state 45
	match 35


state 46
	match 31


state 47
	match 34


state 48
	match 41


state 49
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 68
	0x70 - 0x7a (11)   goto 21

	match 44


state 50
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 69
	0x62 - 0x7a (25)   goto 21

	match 44


state 51
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 70
	0x6f - 0x7a (12)   goto 21

	match 44


state 52
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x74 (20)   goto 21
	0x75               goto 71
	0x76 - 0x7a (5)    goto 21

	match 44


state 53
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 72
	0x74 - 0x7a (7)    goto 21

	match 44


state 54
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 73
	0x73 - 0x7a (8)    goto 21

	match 44


state 55
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 12


state 56
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 74
	0x75 - 0x7a (6)    goto 21

	match 44


state 57
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 75
	0x6a - 0x7a (17)   goto 21

	match 44


state 58
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 76
	0x6a - 0x7a (17)   goto 21

	match 44


state 59
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 77
	0x6a - 0x7a (17)   goto 21

	match 44


state 60
	match 38


state 61
	match 43


state 62
	0x00 - 0x29 (42)   goto 40
	0x2a               goto 78
	0x2b - 0x2e (4)    goto 40
	0x2f               goto 64
	0x30 - 0xff (208)  goto 40


state 63
	0x00 - 0x21 (34)   goto 40
	0x23 - 0x29 (7)    goto 40
	0x2a               goto 78
	0x2b - 0x2d (3)    goto 40
	0x2e               goto 63
	0x2f - 0xff (209)  goto 40


state 64
	match 3


state 65
	0x30 - 0x39 (10)   goto 65
	0x45               goto 43

	match 42


state 66
	0x30 - 0x39 (10)   goto 67


state 67
	0x30 - 0x39 (10)   goto 67

	match 42


state 68
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 79
	0x6d - 0x7a (14)   goto 21

	match 44


state 69
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 80
	0x73 - 0x7a (8)    goto 21

	match 44


state 70
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 16


state 71
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 81
	0x75 - 0x7a (6)    goto 21

	match 44


state 72
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 82
	0x66 - 0x7a (21)   goto 21

	match 44


state 73
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 15


state 74
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 19


state 75
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 83
	0x6f - 0x7a (12)   goto 21

	match 44


state 76
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x63 (3)    goto 21
	0x64               goto 84
	0x65 - 0x7a (22)   goto 21

	match 44


state 77
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 85
	0x6d - 0x7a (14)   goto 21

	match 44


state 78
	0x00 - 0x21 (34)   goto 40
	0x22               goto 40
	0x23 - 0x29 (7)    goto 40
	0x2a               goto 78
	0x2b - 0x2d (3)    goto 40
	0x2e               goto 63
	0x2f               goto 86
	0x30 - 0xff (208)  goto 40


state 79
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 21


state 80
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 20


state 81
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 17


state 82
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 13


state 83
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 23


state 84
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 18


state 85
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 87
	0x66 - 0x7a (21)   goto 21

	match 44


state 86
	0x00 - 0x21 (34)   goto 40
	0x23 - 0x29 (7)    goto 40
	0x2a               goto 62
	0x2b - 0x2d (3)    goto 40
	0x2e               goto 63
	0x2f - 0xff (209)  goto 40

	match 3


state 87
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 14


#############################################################################
# Summary
#############################################################################

1 start state(s)
44 expression(s), 87 state(s)


#############################################################################
# End of File
#############################################################################
