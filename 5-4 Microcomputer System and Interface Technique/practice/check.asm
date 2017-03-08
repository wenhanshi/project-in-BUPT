
BUF_SIZE EQU 50

data segment
    buf db 3,7,9,1,3,2,6,11,27,25
    db 12,55,23,55,87,213,76,2,3,2
    db 29,2,99,23,23,23,111,7,8,23
    db 11,111,1,1,4,44,4,45,7,77
    db 23,32,8,7,6,5,4,3,2,1
    done db 0
data ends

stack segment
    dw   128  dup(0)
stack ends

code segment
    assume cs:code, ds:data, es: data, ss:stack
start:
    mov ax, data
    mov ds, ax
    mov es, ax
    
    call proc_print
    call proc_sort
    call proc_print
    
    mov ax, 4c00h
    int 21h
    
proc_print proc near
    push ax
    push cx
    push dx
    push si
    xor cx, cx
    xor dh, dh
    lea si, buf
next:
    mov al, [si]
    mov ch, 2
show:
    mov cl, 4
    rol al, cl
    push ax
    and al, 0fh
    add al, '0'
    cmp al, '9'
    jle print
    add al, 'A'-('9'+1)
print:
    mov dl, al
    mov ah, 2
    int 21h
    dec ch
    pop ax
    jnz show
    mov dl, 32
    mov ah, 2
    int 21h
    inc dh
    inc done
    inc si
    cmp dh, 10
    jz line
check1:
    cmp done, BUF_SIZE
    jz fin
    jmp next
line:
    mov dl, 0ah
    mov ah, 2
    int 21h
    mov dl, 0dh
    int 21h
    xor dh, dh
    jmp check1
fin:
    mov done, 0
    pop si
    pop dx
    pop cx
    pop ax
    ret
proc_print endp

proc_sort proc near
    push ax
    push cx
    push dx
    push si
    
    mov cx, BUF_SIZE-1
scan:
    lea si, buf
    mov dx, cx
comp:
    mov al, [si]
    cmp al, [si+1]
    ja exchange
    jmp check2
exchange:
    xchg al, [si+1]
    xchg al, [si]
check2:
    inc si
    dec dx
    jnz comp
    loop scan
    pop si
    pop dx
    pop cx
    pop ax
    ret
proc_sort endp
             
code ends

end start
