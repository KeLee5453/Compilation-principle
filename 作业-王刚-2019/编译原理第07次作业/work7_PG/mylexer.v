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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 12/25/19
# Time: 15:27:20
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ \t]+

    2  "int"

    3  "char"

    4  "double"

    5  "input"

    6  "print"

    7  "main"

    8  "if"

    9  "else"

   10  for

   11  while

   12  do

   13  switch

   14  case

   15  default

   16  break

   17  continue

   18  [_A-Za-z]([_A-Za-z]|[0-9])*

   19  [0-9]+\.[0-9]+

   20  ([1-9]+[0-9]*)|([1-9])|0

   21  \'.\'

   22  "++"

   23  "--"

   24  "+"

   25  "-"

   26  "*"

   27  "/"

   28  "%"

   29  "<<"

   30  ">>"

   31  "<"

   32  "<="

   33  ">"

   34  ">="

   35  "=="

   36  "!="

   37  "&"

   38  "^"

   39  "|"

   40  "&&"

   41  "||"

   42  "?"

   43  ":"

   44  "="

   45  "+="

   46  "-="

   47  "*="

   48  "/="

   49  "%="

   50  "("

   51  ")"

   52  "{"

   53  "}"

   54  ";"

   55  ","

   56  "!"

   57  "//"[^\n]*

   58  "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"

   59  \n

   60  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 6
	0x22 - 0x24 (3)    goto 3
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2e               goto 3
	0x2f               goto 16
	0x30               goto 17
	0x31 - 0x39 (9)    goto 18
	0x3a               goto 19
	0x3b               goto 20
	0x3c               goto 21
	0x3d               goto 22
	0x3e               goto 23
	0x3f               goto 24
	0x40               goto 3
	0x41 - 0x5a (26)   goto 25
	0x5b - 0x5d (3)    goto 3
	0x5e               goto 26
	0x5f               goto 25
	0x60               goto 3
	0x61               goto 25
	0x62               goto 27
	0x63               goto 28
	0x64               goto 29
	0x65               goto 30
	0x66               goto 31
	0x67 - 0x68 (2)    goto 25
	0x69               goto 32
	0x6a - 0x6c (3)    goto 25
	0x6d               goto 33
	0x6e - 0x6f (2)    goto 25
	0x70               goto 34
	0x71 - 0x72 (2)    goto 25
	0x73               goto 35
	0x74 - 0x76 (3)    goto 25
	0x77               goto 36
	0x78 - 0x7a (3)    goto 25
	0x7b               goto 37
	0x7c               goto 38
	0x7d               goto 39
	0x7e - 0xff (130)  goto 3


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 5
	0x0b - 0x1f (21)   goto 3
	0x20               goto 4
	0x21               goto 6
	0x22 - 0x24 (3)    goto 3
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2e               goto 3
	0x2f               goto 16
	0x30               goto 17
	0x31 - 0x39 (9)    goto 18
	0x3a               goto 19
	0x3b               goto 20
	0x3c               goto 21
	0x3d               goto 22
	0x3e               goto 23
	0x3f               goto 24
	0x40               goto 3
	0x41 - 0x5a (26)   goto 25
	0x5b - 0x5d (3)    goto 3
	0x5e               goto 26
	0x5f               goto 25
	0x60               goto 3
	0x61               goto 25
	0x62               goto 27
	0x63               goto 28
	0x64               goto 29
	0x65               goto 30
	0x66               goto 31
	0x67 - 0x68 (2)    goto 25
	0x69               goto 32
	0x6a - 0x6c (3)    goto 25
	0x6d               goto 33
	0x6e - 0x6f (2)    goto 25
	0x70               goto 34
	0x71 - 0x72 (2)    goto 25
	0x73               goto 35
	0x74 - 0x76 (3)    goto 25
	0x77               goto 36
	0x78 - 0x7a (3)    goto 25
	0x7b               goto 37
	0x7c               goto 38
	0x7d               goto 39
	0x7e - 0xff (130)  goto 3


state 3
	match 60


state 4
	0x09               goto 4
	0x20               goto 4

	match 1


state 5
	match 59


state 6
	0x3d               goto 40

	match 56


state 7
	0x3d               goto 41

	match 28


state 8
	0x26               goto 42

	match 37


state 9
	0x00 - 0x09 (10)   goto 43
	0x0b - 0xff (245)  goto 43

	match 60


state 10
	match 50


state 11
	match 51


state 12
	0x3d               goto 44

	match 26


state 13
	0x2b               goto 45
	0x3d               goto 46

	match 24


state 14
	match 55


state 15
	0x2d               goto 47
	0x3d               goto 48

	match 25


state 16
	0x2a               goto 49
	0x2f               goto 50
	0x3d               goto 51

	match 27


state 17
	0x2e               goto 52
	0x30 - 0x39 (10)   goto 53

	match 20


state 18
	0x2e               goto 52
	0x30               goto 54
	0x31 - 0x39 (9)    goto 18

	match 20


state 19
	match 43


state 20
	match 54


state 21
	0x3c               goto 55
	0x3d               goto 56

	match 31


state 22
	0x3d               goto 57

	match 44


state 23
	0x3d               goto 58
	0x3e               goto 59

	match 33


state 24
	match 42


state 25
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 18


state 26
	match 38


state 27
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x71 (17)   goto 25
	0x72               goto 60
	0x73 - 0x7a (8)    goto 25

	match 18


state 28
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61               goto 61
	0x62 - 0x67 (6)    goto 25
	0x68               goto 62
	0x69 - 0x6e (6)    goto 25
	0x6f               goto 63
	0x70 - 0x7a (11)   goto 25

	match 18


state 29
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x64 (4)    goto 25
	0x65               goto 64
	0x66 - 0x6e (9)    goto 25
	0x6f               goto 65
	0x70 - 0x7a (11)   goto 25

	match 18


state 30
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6b (11)   goto 25
	0x6c               goto 66
	0x6d - 0x7a (14)   goto 25

	match 18


state 31
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6e (14)   goto 25
	0x6f               goto 67
	0x70 - 0x7a (11)   goto 25

	match 18


state 32
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x65 (5)    goto 25
	0x66               goto 68
	0x67 - 0x6d (7)    goto 25
	0x6e               goto 69
	0x6f - 0x7a (12)   goto 25

	match 18


state 33
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61               goto 70
	0x62 - 0x7a (25)   goto 25

	match 18


state 34
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x71 (17)   goto 25
	0x72               goto 71
	0x73 - 0x7a (8)    goto 25

	match 18


state 35
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x76 (22)   goto 25
	0x77               goto 72
	0x78 - 0x7a (3)    goto 25

	match 18


state 36
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x67 (7)    goto 25
	0x68               goto 73
	0x69 - 0x7a (18)   goto 25

	match 18


state 37
	match 52


state 38
	0x7c               goto 74

	match 39


state 39
	match 53


state 40
	match 36


state 41
	match 49


state 42
	match 40


state 43
	0x27               goto 75


state 44
	match 47


state 45
	match 22


state 46
	match 45


state 47
	match 23


state 48
	match 46


state 49
	0x00 - 0x29 (42)   goto 49
	0x2a               goto 76
	0x2b - 0x2e (4)    goto 49
	0x2f               goto 49
	0x30 - 0xff (208)  goto 49


state 50
	0x00 - 0x09 (10)   goto 50
	0x0b - 0xff (245)  goto 50

	match 57


state 51
	match 48


state 52
	0x30 - 0x39 (10)   goto 77


state 53
	0x2e               goto 52
	0x30 - 0x39 (10)   goto 53


state 54
	0x2e               goto 52
	0x30 - 0x39 (10)   goto 54

	match 20


state 55
	match 29


state 56
	match 32


state 57
	match 35


state 58
	match 34


state 59
	match 30


state 60
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x64 (4)    goto 25
	0x65               goto 78
	0x66 - 0x7a (21)   goto 25

	match 18


state 61
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x72 (18)   goto 25
	0x73               goto 79
	0x74 - 0x7a (7)    goto 25

	match 18


state 62
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61               goto 80
	0x62 - 0x7a (25)   goto 25

	match 18


state 63
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6d (13)   goto 25
	0x6e               goto 81
	0x6f - 0x7a (12)   goto 25

	match 18


state 64
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x65 (5)    goto 25
	0x66               goto 82
	0x67 - 0x7a (20)   goto 25

	match 18


state 65
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x74 (20)   goto 25
	0x75               goto 83
	0x76 - 0x7a (5)    goto 25

	match 12


state 66
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x72 (18)   goto 25
	0x73               goto 84
	0x74 - 0x7a (7)    goto 25

	match 18


state 67
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x71 (17)   goto 25
	0x72               goto 85
	0x73 - 0x7a (8)    goto 25

	match 18


state 68
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 8


state 69
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6f (15)   goto 25
	0x70               goto 86
	0x71 - 0x73 (3)    goto 25
	0x74               goto 87
	0x75 - 0x7a (6)    goto 25

	match 18


state 70
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x68 (8)    goto 25
	0x69               goto 88
	0x6a - 0x7a (17)   goto 25

	match 18


state 71
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x68 (8)    goto 25
	0x69               goto 89
	0x6a - 0x7a (17)   goto 25

	match 18


state 72
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x68 (8)    goto 25
	0x69               goto 90
	0x6a - 0x7a (17)   goto 25

	match 18


state 73
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x68 (8)    goto 25
	0x69               goto 91
	0x6a - 0x7a (17)   goto 25

	match 18


state 74
	match 41


state 75
	match 21


state 76
	0x00 - 0x29 (42)   goto 49
	0x2a               goto 76
	0x2b - 0x2e (4)    goto 49
	0x2f               goto 92
	0x30 - 0xff (208)  goto 49


state 77
	0x30 - 0x39 (10)   goto 77

	match 19


state 78
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61               goto 93
	0x62 - 0x7a (25)   goto 25

	match 18


state 79
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x64 (4)    goto 25
	0x65               goto 94
	0x66 - 0x7a (21)   goto 25

	match 18


state 80
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x71 (17)   goto 25
	0x72               goto 95
	0x73 - 0x7a (8)    goto 25

	match 18


state 81
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x73 (19)   goto 25
	0x74               goto 96
	0x75 - 0x7a (6)    goto 25

	match 18


state 82
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61               goto 97
	0x62 - 0x7a (25)   goto 25

	match 18


state 83
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61               goto 25
	0x62               goto 98
	0x63 - 0x7a (24)   goto 25

	match 18


state 84
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x64 (4)    goto 25
	0x65               goto 99
	0x66 - 0x7a (21)   goto 25

	match 18


state 85
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 10


state 86
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x74 (20)   goto 25
	0x75               goto 100
	0x76 - 0x7a (5)    goto 25

	match 18


state 87
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 2


state 88
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6d (13)   goto 25
	0x6e               goto 101
	0x6f - 0x7a (12)   goto 25

	match 18


state 89
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6d (13)   goto 25
	0x6e               goto 102
	0x6f - 0x7a (12)   goto 25

	match 18


state 90
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x73 (19)   goto 25
	0x74               goto 103
	0x75 - 0x7a (6)    goto 25

	match 18


state 91
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6b (11)   goto 25
	0x6c               goto 104
	0x6d - 0x7a (14)   goto 25

	match 18


state 92
	match 58


state 93
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6a (10)   goto 25
	0x6b               goto 105
	0x6c - 0x7a (15)   goto 25

	match 18


state 94
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 14


state 95
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 3


state 96
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x68 (8)    goto 25
	0x69               goto 106
	0x6a - 0x7a (17)   goto 25

	match 18


state 97
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x74 (20)   goto 25
	0x75               goto 107
	0x76 - 0x7a (5)    goto 25

	match 18


state 98
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6b (11)   goto 25
	0x6c               goto 108
	0x6d - 0x7a (14)   goto 25

	match 18


state 99
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 9


state 100
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x73 (19)   goto 25
	0x74               goto 109
	0x75 - 0x7a (6)    goto 25

	match 18


state 101
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 7


state 102
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x73 (19)   goto 25
	0x74               goto 110
	0x75 - 0x7a (6)    goto 25

	match 18


state 103
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x62 (2)    goto 25
	0x63               goto 111
	0x64 - 0x7a (23)   goto 25

	match 18


state 104
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x64 (4)    goto 25
	0x65               goto 112
	0x66 - 0x7a (21)   goto 25

	match 18


state 105
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 16


state 106
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6d (13)   goto 25
	0x6e               goto 113
	0x6f - 0x7a (12)   goto 25

	match 18


state 107
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x6b (11)   goto 25
	0x6c               goto 114
	0x6d - 0x7a (14)   goto 25

	match 18


state 108
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x64 (4)    goto 25
	0x65               goto 115
	0x66 - 0x7a (21)   goto 25

	match 18


state 109
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 5


state 110
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 6


state 111
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x67 (7)    goto 25
	0x68               goto 116
	0x69 - 0x7a (18)   goto 25

	match 18


state 112
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 11


state 113
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x74 (20)   goto 25
	0x75               goto 117
	0x76 - 0x7a (5)    goto 25

	match 18


state 114
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x73 (19)   goto 25
	0x74               goto 118
	0x75 - 0x7a (6)    goto 25

	match 18


state 115
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 4


state 116
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 13


state 117
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x64 (4)    goto 25
	0x65               goto 119
	0x66 - 0x7a (21)   goto 25

	match 18


state 118
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 15


state 119
	0x30 - 0x39 (10)   goto 25
	0x41 - 0x5a (26)   goto 25
	0x5f               goto 25
	0x61 - 0x7a (26)   goto 25

	match 17


#############################################################################
# Summary
#############################################################################

1 start state(s)
60 expression(s), 119 state(s)


#############################################################################
# End of File
#############################################################################
