; 使用循环结构，不适用串操作

data segment
    s db 2000h dup(0)
    t db 200h dup(0)
    found db 0
    pos dw 0
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov es, ax 
    
    lea si ,s
    lea di ,t
    xor dx, dx
    
    mov byte ptr[si], 'h'
    mov byte ptr[si+1], 'e'
    mov byte ptr[si+2], 'l'
    mov byte ptr[si+3], 'l'
    mov byte ptr[si+4], 'o'
    mov byte ptr[si+5], '!'
    
    mov byte ptr[di], 'l'
    mov byte ptr[di+1], 'l'
    mov byte ptr[di+2], 'o'
    
main_loop:
    cmp [di], 00h  ; 如果比较到了子串的末尾，则一定找到了
    jz fd
    mov al, byte ptr[di]
    cmp al, byte ptr[si] ; 比较si和di指向的两个字符
    jz same
    inc dx  ; 若不相等 ，si回退至di位置 ，di回退至子串开始位置
    lea si, s
    add si, dx
    lea di, t
    cmp [si], 00h  ; 若比较到了源串末尾，则一定没有找到
    jz not_fd
    jmp main_loop
    
fd:
    mov found, 0ffh
    mov pos, dx
    jmp fin 
    
not_fd:
    mov found, 00h
    jmp fin
 
same:
    inc si  ; 若相等，继续向后扫描
    inc di
    jmp main_loop

fin:    
    mov ax, 4c00h
    int 21h    
ends

end start
