
    .486 ;���߻����Ӧ������486������������ߣ���α���롣�����ʹ��.386����������������.486
    .model flat, stdcall ;ʹ��ƽ̹�ڴ�ģʽ��ʹ��stdcall����ϰ�ߣ�stdcall����˼�Ǻ����Ĳ�����������ѹ�룬�����Ĳ�������ѹ�룬���Һ����ڽ���ʱ�Լ���ջ��������ڼ������е�Windows API������dll�Ǳ�׼
    option casemap :none ;�����ַ���ӳ��Ϊ��д��Ϊ��Windows.inc�ļ����������������Ӧ��Ϊ��none��

;Ϊ��ʹ������WindowsAPI�ĺ���������Ҫ����dll�������ɵ���⣨.lib������ɵġ���Щ���Ǳ���ġ���Ϊ����ʹϵͳ��Windows�������ڴ�Ķ�̬����ַ����̬������dll
    includelib \masm32\lib\kernel32.lib
    includelib \masm32\lib\user32.lib
    includelib \masm32\lib\gdi32.lib
    includelib \masm32\lib\msvcrt.lib
    includelib \masm32\lib\masm32.lib


    include \masm32\include\kernel32.inc
    include \masm32\include\user32.inc
    include \masm32\include\gdi32.inc
    include \masm32\include\windows.inc
    include \masm32\include\msvcrt.inc
    include \masm32\include\masm32.inc
    include \masm32\macros\macros.asm


       
.data  ;������ֱ���
    n dd 0;����ڼ���쳲�������
    a dd 0
    b dd 1
    i dd 1 
.code  ;д����ĵط�
start:
    invoke crt_scanf,SADD("%d"),addr n;����n
    mov ecx,i
    cmp ecx,n
    jg @2;jgΪ����ʱ��ת
@1:
    mov eax,a
    mov ebx,b
    mov a,ebx
    add ebx,eax
    mov b,ebx
    inc i
    mov ecx,i
    cmp ecx,n
    jle @1 ;iС�ڵ���nʱ��ת��@1
    invoke crt_printf,SADD("%d",13,10),b ;������
@2:
    ret 
     
end start