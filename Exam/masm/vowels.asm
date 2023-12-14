.model small
.data
    string db ?
    msg db 10,13,"enter the string:$"
    msg1 db 10,13, "no of vowels:$"
    count db 0 
    
.code
        mov ax,@data
        mov ds,ax
        mov es,ax

        lea dx,msg
        mov ah,09
        int 21h
        
        lea si,string
        mov bl,0

    input:
        mov ah,01
        int 21h
        mov [si],al
        inc si
        inc bl
        cmp al,13
        jz t1
        jnz input

    t1:
        mov al,'$'
        mov [si],al
        dec bl
        lea si,string
        mov cl,bl

    find:
        mov al,[si]
        inc si
        cmp al,'a'
        jz increase
        cmp al,'e'
        jz increase
        cmp al,'i'
        jz increase
        cmp al,'o'
        jz increase
        cmp al,'u'
        jz increase
        dec cl
        cmp cl,0
        jnz find
        jmp toend

    increase:
        inc count
        dec cl
        cmp cl,0
        jnz find

    toend:
        lea dx,msg1
        mov ah,09
        int 21h

        mov dl,count
        add dl,30h
        mov ah,02
        int 21h

        mov ah,4ch
        int 21h

    end 