.equ heapBottom, 0x50000
.equ heapTop, 0xf0000

.data
ptr1: .word 0

.text
.global _start

_start:
   mov r5, #heapBottom
   mov r6, #heapTop
   mov r7, r5 // start from bottom

   // Allocate 4 bytes and store a value in allocate1
    mov r0, #4
    bl alloc
    mov r9, r3
    mov r4, #0xf
    str r4, [r9, #0]

     // Allocate 8 bytes and store a value in allocate2
    mov r0, #8
    bl alloc
    mov r10, r3
    mov r4, #0xf2
    str r4, [r10, #0]

    // Allocate 16 bytes and store a value in allocate3
    mov r0, #16
    bl alloc
    mov r11, r3
    mov r4, #0xff
    str r4, [r11, #0]

    // Free 16 bytes (allocate3)
    mov r0, r10
    mov r1, #16
    bl free

     // Free 8 bytes (allocate2)
    mov r0, r9
    mov r1, #8
    bl free

    // Free 4 bytes (allocate1)
    mov r0, r5
    mov r1, #4
    bl free

    // Exit program
    mov r7, #1
    mov r0, #0x18

stop:
	B stop


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
   add r2, r0, r1
   cmp r2,r7
   bne free_exit
   mov r7, r0
   mov r3, #1
   
free_exit:
   pop {lr} // restore lr
   bx lr // return

freeStart: .word 0
freeEnd: .word 0 
allocStart: .word 0
allocEnd: .word 0
.end