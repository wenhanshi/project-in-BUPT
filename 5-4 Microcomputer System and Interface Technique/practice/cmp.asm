; multi-segment executable file template.

data segment
    buff dw 200h
    n1 dw 0
    n2 dw 0
    n3 dw 0
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
        mov ax, data
        mov ds, ax
        mov es, ax

        mov cx  ,400          ;循环次数，每次循环cx-2，实际循环200次
        mov [0211h] , 0ffffh  ;构造一个负数，做测试用
        mov [0212h] , 01fffh  ;构造一个正数，做测试用
        
rotate: mov ax ,buff          ;主循环，从后往前逐字扫描
        mov bx ,cx
        add bx , ax
        mov ax , word ptr [bx] 
        cmp ax ,0     
        jz zero
        shl ax  ,1            ;通过左移操作来得到符号位
        jc plus
        jmp minus

zero:   inc n2
        dec cx
        loop rotate
        jmp fin

plus:   inc n1
        dec cx
        loop rotate
        jmp fin
        
minus:  inc n3
        dec cx
        loop rotate
        jmp fin

fin:
    mov ax, 4c00h 
    int 21h    
ends

end start
