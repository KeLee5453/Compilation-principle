.486
.model flat, stdcall
option casemap :none

	include \masm32\macros\macros.asm
	include \masm32\include\msvcrt.inc
	includelib \masm32\lib\msvcrt.lib


	.data
		_a DWORD 0
		_b DWORD 0
		_c DWORD 0
		_d DWORD 0
		_D BYTE 0
		t0 DWORD 0
		t1 DWORD 0
		t2 DWORD 0
		t3 DWORD 0
		t4 DWORD 0
		buffer BYTE 128 dup(0)
		LF BYTE 13, 10, 0


	.code
	 _start:
	MOV eax,5
	MOV _a,eax
	MOV eax,7
	MOV _c,eax
	 invoke crt_scanf, SADD("%d",0), addr _b
	 invoke crt_printf,SADD('%d',13,10),_D
	 invoke crt_printf,SADD('%d',13,10),_D
	MOV eax,39
	MOV _D,eax
	 invoke crt_printf,SADD('%d',13,10),_D
L0:
	MOV eax,_a
	ADD eax,3
	MOV t0,eax
	MOV eax,_b
	ADD eax,1
	MOV t1,eax
	MOV eax,t1
	ADD eax,2
	MOV t1,eax
	MOV eax,t0
	CMP eax,t1
	 jl L4
	 jmp L3
L4:
	MOV eax,_a
	CMP eax,_b
	 je L1
	 jmp L3
L1:
	MOV eax,1
	CMP eax,1
	 jne L1
	 jmp L2
L1:
	MOV eax,_a
	ADD eax,1
	MOV t2,eax
	MOV eax,t2
	MOV _a,eax
	jmp L0
L2:
	 invoke crt_printf,SADD('%d',13,10),_a
	 invoke crt_printf,SADD('%d',13,10),_b
L5:
	MOV eax,_a
	CMP eax,_c
	 je L6
	 jmp L7
L6:
	MOV eax,10
	MOV _b,eax
	 invoke crt_printf,SADD('%d',13,10),_c
	jmp L8
L7:
	MOV eax,100
	MOV _a,eax
	 invoke crt_printf,SADD('%d',13,10),_c
	jmp L8
L8:
	MOV eax,_c
	SUB eax,1
	MOV t3,eax
	MOV eax,t3
	MOV _c,eax
	 invoke crt_printf,SADD('%d',13,10),_a
	 invoke crt_printf,SADD('%d',13,10),_b
	 invoke crt_printf,SADD('%d',13,10),_c
	MOV eax,_a
	ADD eax,_b
	MOV t4,eax
	MOV eax,t4
	MUL _c
	MOV t4,eax
	MOV eax,t4
	MOV _d,eax
	 invoke crt_printf,SADD('%d',13,10),_d
L9:
	MOV eax,_a
	CMP eax,0
	 je L10
	 jmp L11
L10:
	 invoke crt_printf,SADD('%d',13,10),_D
	jmp L9
L11:
		invoke crt_printf, SADD("print any key to continue...")
		invoke crt__getch
		invoke crt__exit, 0
	end _start
