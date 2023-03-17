//managing stack with
//push, pop, ldm, and stm

.global _start, instr, outstr
.data
instr:
   .ascii "forest fire\n"
   .align 1
outstr:
   .ascii "00000000000000"
   .align 1
.text
_start:
    mov r0, #0x0
    mov sp, r0 
    mov r5, #0x0 
    ldr r0, strptr1 // pointer to input string
    ldr r2, strptr2 // pointer to reverse string
loop1:
    ldrb  r1, [r0]
    push {r1} 
    add r0, r0, #0x1
    add r5, r5, #0x1
    cmp r1, #0x0
    bne loop1
    
loop2:
    pop {r1}
    strb r1, [r2]
    add r2, r2, #0x1
    cmp r5, #0x0
    sub r5, r5, #0x1
    bne loop2
end:
    b end

strptr1: 
   .word instr
strptr2:
   .word outstr
