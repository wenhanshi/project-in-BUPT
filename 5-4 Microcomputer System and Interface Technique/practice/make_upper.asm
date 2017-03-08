
data segment
    string db '***2016:i_love_wei_ji_jie_kou_!!!***do_you_believe_me!#hehe$'
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov es, ax
    lea si, string ; 得到string首地址
    
comp:
    mov al, byte ptr [si]
    cmp al, '$' ; 若遇到结束符，则跳出，显示结果
    jz fin
    cmp al, 'a' ; 若遇到比'a'小的字符，则被归为其他
    jb others
    cmp al, 'z' ; 在此基础上若遇到小于等于'z'的，就是小写字母
    jbe islower
    jmp others  ; 比'z'大的被归为其他
    
others:
    inc si      ; 如果是其他字符，继续搜索即可
    jmp comp
    
islower:
    sub al, 32  ; 减去32变为大写字母
    mov [si], al
    inc si
    jmp comp
    
fin:
    mov dx, offset string  ; 添加显示功能，方便验收程序...
    mov ax, 0900h
    int 21h
    mov ax, 4c00h  ; 返回操作系统
    int 21h    
ends

end start
