	.586
	.model flat, stdcall
	option casemap : none

	include \masm32\macros\macros.asm

	include    \masm32\include\msvcrt.inc
	includelib \masm32\lib\msvcrt.lib

	main PROTO
	WaitKeyCrt PROTO


	.data
		_a DWORD ?
		_b DWORD ?
		_c DWORD ?
		_d DWORD ?
		_D BYTE ?
		_t_0 DWORD ?
		_t_1 DWORD ?
		_t_2 DWORD ?
		_t_3 DWORD ?
		_t_4 DWORD ?
		_t_5 DWORD ?
		_t_6 DWORD ?
		newline BYTE 13, 10, 0


	.code
start:

	invoke main
	invoke WaitKeyCrt
	invoke crt__exit, 0

main PROC
	mov eax,5
	mov _a,eax
	mov eax,7
	mov _c,eax
	invoke crt_scanf, SADD("%d",0), addr _b
	invoke crt_scanf, SADD("%c",0), addr _D
	invoke crt_printf, addr _D
	invoke crt_printf, OFFSET newline
	mov al,'P'
	mov _D,al
	invoke crt_printf, addr _D
	invoke crt_printf, OFFSET newline
@0:
	mov eax,_a
	add eax,3
	mov _t_0,eax
	mov eax,_b
	add eax,1
	mov _t_1,eax
	mov eax,_t_1
	add eax,2
	mov _t_1,eax
	mov eax,_t_0
	cmp eax,_t_1
	jl @4
	jmp @3
@4:
	mov eax,_a
	cmp eax,_b
	je @3
	jmp @1
@3:
	mov eax,1
	cmp eax,1
	jne @1
	jmp @2
@1:
	mov eax,_a
	add eax,1
	mov _t_2,eax
	mov eax,_t_2
	mov _a,eax
	jmp @0
@2:
	mov eax,_c
	add eax,1
	mov _t_3,eax
	mov eax,_t_3
	mov _c,eax
@6:
	mov eax,_a
	cmp eax,_b
	jge @7
	jmp @5
@7:
	invoke crt_printf, SADD("%d",13,10), _b
	mov eax,_b
	add eax,1
	mov _t_4,eax
	mov eax,_t_4
	mov _b,eax
	jmp @6
@5:
	invoke crt_printf, SADD("%d",13,10), _a
	invoke crt_printf, SADD("%d",13,10), _b
	mov eax,_a
	cmp eax,_c
	je @10
	jmp @8
@8:
	mov eax,10
	mov _b,eax
	invoke crt_printf, SADD("%d",13,10), _c
	jmp @9
@10:
	mov eax,100
	mov _a,eax
	invoke crt_printf, SADD("%d",13,10), _c
	jmp @9
@9:
	mov eax,_c
	sub eax,1
	mov _t_5,eax
	mov eax,_t_5
	mov _c,eax
	invoke crt_printf, SADD("%d",13,10), _a
	invoke crt_printf, SADD("%d",13,10), _b
	invoke crt_printf, SADD("%d",13,10), _c
	mov eax,_b
	imul eax,_c
	mov _t_6,eax
	mov eax,_a
	add eax,_t_6
	mov _t_6,eax
	mov eax,_t_6
	mov _d,eax
	invoke crt_printf, SADD("%d",13,10), _d
@11:
	mov eax,_a
	cmp eax,0
	je @12
	jmp @13
@12:
	invoke crt_printf, addr _D
	invoke crt_printf, OFFSET newline
	jmp @11
@13:
	ret
main ENDP

WaitKeyCrt PROC
	invoke crt_printf, SADD(13,10,"Press any key to continue...")
	invoke crt__getch
	.if (eax == 0) || (eax == 0E0h)
		invoke crt__getch
	.endif
	invoke crt_printf, OFFSET newline
	ret
WaitKeyCrt ENDP

END start
