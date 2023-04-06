//This code is incomplete
// You may get some error wile assembling and running

.equ heapBottom 0xffff0000
.equ heapTop 0xfffffff00
//.equ stackStart 0xffffffff
.data .word ptr1

.text
.global _start
_start:
   mov r5, heapBottom
   mov r6, heapTop
   mov r7, r5 // start from bottom
   bl alloc
   //do something with the allocated space
   str r3, ptr1
loop1:   // doing some initilization
   str [ptr1], 0x10   
   b loop1
   
   bl free
   //end program 


alloc: 
   //code for alloc


free: 
   // code for free

freeStart: .word 0
freeEnd: .word 0 
allocStart: .word 0
allocEnd: .word 0
.end

