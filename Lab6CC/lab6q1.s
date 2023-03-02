.LC0:
    .align 4
.text
.global _start
_start:
    mov r1, #0x2
    mov r2, #0x3
    ldr r3, .L1
    str r1, [r3, #0x0]
    str r2, [r3, #0x4]
//here you do swapping code
    ldr r1, [r3, #0x4]
	ldr r2, [r3, #0x0]
stop:
    b stop
.L1:
    .word .LC0