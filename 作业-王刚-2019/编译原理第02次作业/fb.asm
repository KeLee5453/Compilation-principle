
    .486 ;告诉汇编器应该生成486处理器（或更高）的伪代码。你可以使用.386，但大多数情况下用.486
    .model flat, stdcall ;使用平坦内存模式并使用stdcall调用习惯（stdcall的意思是函数的参数从右往左压入，即最后的参数最先压入，而且函数在结束时自己清栈），这对于几乎所有的Windows API函数和dll是标准
    option casemap :none ;控制字符的映射为大写。为了Windows.inc文件能正常工作，这个应该为”none”

;为了使用来自WindowsAPI的函数，你需要导入dll。这是由导入库（.lib）来完成的。这些库是必需的。因为它们使系统（Windows）能在内存的动态基地址处动态的载入dll
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


       
.data  ;定义各种变量
    n dd 0;代表第几个斐波那契数
    a dd 0
    b dd 1
    i dd 1 
.code  ;写代码的地方
start:
    invoke crt_scanf,SADD("%d"),addr n;输入n
    mov ecx,i
    cmp ecx,n
    jg @2;jg为大于时跳转
@1:
    mov eax,a
    mov ebx,b
    mov a,ebx
    add ebx,eax
    mov b,ebx
    inc i
    mov ecx,i
    cmp ecx,n
    jle @1 ;i小于等于n时跳转到@1
    invoke crt_printf,SADD("%d",13,10),b ;输出结果
@2:
    ret 
     
end start