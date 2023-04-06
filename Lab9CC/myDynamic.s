.equ heapBottom, 0xffff0000
.equ heapTop, 0xfffffff0

.data
ptr1: .word 0

.text
.global _start

_start:
   mov r5, heapBottom
   mov r6, heapTop
   mov r7, r5 // start from bottom
   
   // Allocate memory
   mov r0, #4 // allocate 4 bytes
   bl alloc
   mov r1, r3 // save pointer to ptr1
   
   // Do something with the allocated space
   str r1, ptr1
loop1:
   str [ptr1], #0x10   
   b loop1
   
   // Free memory
   mov r0, r1 // pass pointer to free
   mov r1, #4 // free 4 bytes
   bl free
   
   // End program
   mov r7, #1 // set return value
   mov r0, #0 // set exit status
   mov r1, #0 // set exit status
   mov r2, #0 // set exit status
   mov r3, #0 // set exit status
   mov r4, #0 // set exit status
   mov r5, #0 // set exit status
   mov r6, #0 // set exit status
   mov r8, #0 // set exit status
   mov r9, #0 // set exit status
   mov r10, #0 // set exit status
   mov r11, #0 // set exit status
   mov r12, #0 // set exit status
   svc 0x00000000 // exit

alloc:
   push {lr} // save lr on stack
   sub sp, sp, #8 // allocate space for temp and result
   sub r4, r6, r7 // calculate available space
   cmp r0, r4 // compare requested size with available space
   ble alloc_space // if available space is greater than or equal to requested size, allocate memory
   mov r3, #0 // otherwise, return NULL
   b alloc_exit
   
alloc_space:
   mov r2, r7 // store current freeptr in temp
   add r7, r7, r0 // increment freeptr
   mov r3, r7 // store new freeptr in result
   
alloc_exit:
   add sp, sp, #8 // deallocate space for temp and result
   pop {lr} // restore lr
   bx lr // return

free:
   push {lr} // save lr on stack
   cmp r0, r7 // compare base_ptr with freeptr
   bne free_exit // if not equal, return failure
   add r2, r0, r1 // calculate end address of block to free
   cmp r2, r7 // compare end address with freeptr
   bne free_exit // if not equal, return failure
   mov r7, r0 // otherwise, update freeptr to base_ptr
   mov r3, #1 // return success
   
free_exit:
   pop {lr} // restore lr
   bx lr // return

freeStart: .word 0
freeEnd: .word 0 
allocStart: .word 0
allocEnd: .word 0
.end