.model small

print macro msg
   mov ah,09h
   lea dx,msg
   int 21h
endm

.data
   msg1 DB 10,13,'ENTER  THE STRING:$'
   msg2 DB 10,13,'SUBSTRING TO BE REPLACED IS: $'
   msg3 DB 10,13,'REPLACE WITH:$'
   msg4 DB 10,13,'OUTPUT STRING IS: $'
   str1 DB 100,0,100 dup(0)
   str2 DB 20,0,20 DUP(0)
   str3 DB 20,0,20 DUP(0)
   len1 DW 0000H
   len2 DW 0000H
   len3 DW 0000H

.code
   START:
      mov   ax, DATA
      mov   ds, ax
      mov   es, ax

      print msg1

      lea   dx, str1
      mov   ah, 0ah
      int   21h
      mov   al, [str1+1]
      mov   bx, offset len1
      mov   byte ptr [bx], al

      print msg2
      lea   dx, str2
      mov   ah, 0ah
      int   21h
      mov   al, [str2+1]
      mov   bx, offset len2
      mov   byte ptr [bx], al

      print msg3
      lea   dx, str3
      mov   ah, 0ah
      int   21h
      mov   al, [str3+1]
      mov   bx, offset len3
      mov   byte ptr [bx], al

      lea   si, str1+2
      mov   cx, len1

      print msg4

      lea   di, str2+2
      mov   bx, len2

   up:   
      mov   al, [si]
      mov   ah, [di]
      cmp   ah, al
      jz    l1

      lea   di, str2+2
      mov   bx, len2
      mov   dl, [si]
      mov   ah, 02h
      int   21h
      inc   si
      dec   cx
      cmp   cx, 0000
      jnz   up
      jz    last

   l1:   
      dec   bx
      inc   si
      inc   di
      cmp   bx, 0000
      jz    l2
   
      dec   cx
      jnz   up

   l2:   
      lea   di, str3+2
      mov   bx, len3

   l3:   
      mov   dl, [di]
      mov   ah, 02h
      int   21h
      inc   di
      dec   bx
      cmp   bx, 0000
      jnz   l3

      lea   di, str2+2
      mov   bx, len2
      jmp   up

   last: 
      mov   ah, 4ch
      int   21h

END START