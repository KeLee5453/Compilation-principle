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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 11/20/19
# Time: 14:40:15
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

   43  [A-Za-z_]([A-Za-z_]|[0-9])*


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
	0x28               goto 8
	0x29               goto 9
	0x2a               goto 10
	0x2b               goto 11
	0x2c               goto 12
	0x2d               goto 13
	0x2f               goto 14
	0x30 - 0x39 (10)   goto 15
	0x3b               goto 16
	0x3c               goto 17
	0x3d               goto 18
	0x3e               goto 19
	0x41 - 0x5a (26)   goto 20
	0x5b               goto 21
	0x5d               goto 22
	0x5f               goto 20
	0x61               goto 20
	0x62               goto 23
	0x63               goto 24
	0x64               goto 20
	0x65               goto 25
	0x66               goto 26
	0x67 - 0x68 (2)    goto 20
	0x69               goto 27
	0x6a - 0x6c (3)    goto 20
	0x6d               goto 28
	0x6e - 0x75 (8)    goto 20
	0x76               goto 29
	0x77               goto 30
	0x78 - 0x7a (3)    goto 20
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33


state 2
	^INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x25               goto 6
	0x26               goto 7
	0x28               goto 8
	0x29               goto 9
	0x2a               goto 10
	0x2b               goto 11
	0x2c               goto 12
	0x2d               goto 13
	0x2f               goto 14
	0x30 - 0x39 (10)   goto 15
	0x3b               goto 16
	0x3c               goto 17
	0x3d               goto 18
	0x3e               goto 19
	0x41 - 0x5a (26)   goto 20
	0x5b               goto 21
	0x5d               goto 22
	0x5f               goto 20
	0x61               goto 20
	0x62               goto 23
	0x63               goto 24
	0x64               goto 20
	0x65               goto 25
	0x66               goto 26
	0x67 - 0x68 (2)    goto 20
	0x69               goto 27
	0x6a - 0x6c (3)    goto 20
	0x6d               goto 28
	0x6e - 0x75 (8)    goto 20
	0x76               goto 29
	0x77               goto 30
	0x78 - 0x7a (3)    goto 20
	0x7b               goto 31
	0x7c               goto 32
	0x7d               goto 33


state 3
	0x09               goto 3
	0x20               goto 3

	match 2


state 4
	match 1


state 5
	0x3d               goto 34

	match 39


state 6
	match 28


state 7
	0x26               goto 35


state 8
	match 6


state 9
	match 7


state 10
	match 26


state 11
	0x2b               goto 36

	match 24


state 12
	match 4


state 13
	0x2d               goto 37

	match 25


state 14
	0x2a               goto 38
	0x2f               goto 39

	match 27


state 15
	0x2e               goto 40
	0x30 - 0x39 (10)   goto 15
	0x45               goto 41

	match 42


state 16
	match 5


state 17
	0x3c               goto 42
	0x3d               goto 43

	match 33


state 18
	0x3d               goto 44

	match 22


state 19
	0x3d               goto 45
	0x3e               goto 46

	match 32


state 20
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 43


state 21
	match 10


state 22
	match 11


state 23
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 47
	0x70 - 0x7a (11)   goto 20

	match 43


state 24
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x67 (7)    goto 20
	0x68               goto 48
	0x69               goto 49
	0x6a - 0x6e (5)    goto 20
	0x6f               goto 50
	0x70 - 0x7a (11)   goto 20

	match 43


state 25
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 51
	0x6d - 0x7a (14)   goto 20

	match 43


state 26
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 52
	0x70 - 0x7a (11)   goto 20

	match 43


state 27
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x65 (5)    goto 20
	0x66               goto 53
	0x67 - 0x6d (7)    goto 20
	0x6e               goto 54
	0x6f - 0x7a (12)   goto 20

	match 43


state 28
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 55
	0x62 - 0x7a (25)   goto 20

	match 43


state 29
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 56
	0x70 - 0x7a (11)   goto 20

	match 43


state 30
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x67 (7)    goto 20
	0x68               goto 57
	0x69 - 0x7a (18)   goto 20

	match 43


state 31
	match 8


state 32
	0x7c               goto 58


state 33
	match 9


state 34
	match 36


state 35
	match 37


state 36
	match 29


state 37
	match 30


state 38
	0x00 - 0x21 (34)   goto 38
	0x23 - 0x29 (7)    goto 38
	0x2a               goto 59
	0x2b - 0x2d (3)    goto 38
	0x2e               goto 60
	0x2f - 0xff (209)  goto 38


state 39
	0x00 - 0x09 (10)   goto 39
	0x0a               goto 61
	0x0b - 0xff (245)  goto 39


state 40
	0x30 - 0x39 (10)   goto 62


state 41
	0x2b               goto 63
	0x2d               goto 63
	0x30 - 0x39 (10)   goto 64


state 42
	match 40


state 43
	match 35


state 44
	match 31


state 45
	match 34


state 46
	match 41


state 47
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 65
	0x70 - 0x7a (11)   goto 20

	match 43


state 48
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61               goto 66
	0x62 - 0x7a (25)   goto 20

	match 43


state 49
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6d (13)   goto 20
	0x6e               goto 67
	0x6f - 0x7a (12)   goto 20

	match 43


state 50
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 68
	0x76 - 0x7a (5)    goto 20

	match 43


state 51
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 69
	0x74 - 0x7a (7)    goto 20

	match 43


state 52
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 70
	0x73 - 0x7a (8)    goto 20

	match 43


state 53
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 12


state 54
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 71
	0x75 - 0x7a (6)    goto 20

	match 43


state 55
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 72
	0x6a - 0x7a (17)   goto 20

	match 43


state 56
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 73
	0x6a - 0x7a (17)   goto 20

	match 43


state 57
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 74
	0x6a - 0x7a (17)   goto 20

	match 43


state 58
	match 38


state 59
	0x00 - 0x29 (42)   goto 38
	0x2a               goto 75
	0x2b - 0x2e (4)    goto 38
	0x2f               goto 61
	0x30 - 0xff (208)  goto 38


state 60
	0x00 - 0x21 (34)   goto 38
	0x23 - 0x29 (7)    goto 38
	0x2a               goto 75
	0x2b - 0x2d (3)    goto 38
	0x2e               goto 60
	0x2f - 0xff (209)  goto 38


state 61
	match 3


state 62
	0x30 - 0x39 (10)   goto 62
	0x45               goto 41

	match 42


state 63
	0x30 - 0x39 (10)   goto 64


state 64
	0x30 - 0x39 (10)   goto 64

	match 42


state 65
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 76
	0x6d - 0x7a (14)   goto 20

	match 43


state 66
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 77
	0x73 - 0x7a (8)    goto 20

	match 43


state 67
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 16


state 68
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 78
	0x75 - 0x7a (6)    goto 20

	match 43


state 69
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 79
	0x66 - 0x7a (21)   goto 20

	match 43


state 70
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 15


state 71
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 19


state 72
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6d (13)   goto 20
	0x6e               goto 80
	0x6f - 0x7a (12)   goto 20

	match 43


state 73
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x63 (3)    goto 20
	0x64               goto 81
	0x65 - 0x7a (22)   goto 20

	match 43


state 74
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 82
	0x6d - 0x7a (14)   goto 20

	match 43


state 75
	0x00 - 0x21 (34)   goto 38
	0x22               goto 38
	0x23 - 0x29 (7)    goto 38
	0x2a               goto 75
	0x2b - 0x2d (3)    goto 38
	0x2e               goto 60
	0x2f               goto 83
	0x30 - 0xff (208)  goto 38


state 76
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 21


state 77
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 20


state 78
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 17


state 79
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 13


state 80
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 23


state 81
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 18


state 82
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 84
	0x66 - 0x7a (21)   goto 20

	match 43


state 83
	0x00 - 0x21 (34)   goto 38
	0x23 - 0x29 (7)    goto 38
	0x2a               goto 59
	0x2b - 0x2d (3)    goto 38
	0x2e               goto 60
	0x2f - 0xff (209)  goto 38

	match 3


state 84
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 14


#############################################################################
# Summary
#############################################################################

1 start state(s)
43 expression(s), 84 state(s)


#############################################################################
# End of File
#############################################################################
