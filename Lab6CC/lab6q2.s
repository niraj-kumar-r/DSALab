.LC0:
    .word 1,2,3,4,5,6,7,8,9
    .align 4

.text
.global _start

_start:

    ldr r1, =.LC0
    ldr r2, [r1, #0x0]
    ldr r3, [r1, #0x4]
    add r4, r2, r3
    ldr r2, [r1, #0x8]
    ldr r3, [r1, #0xc]
    add r5, r2, r3
    ldr r2, [r1, #0x10]
    ldr r3, [r1, #0x14]
    add r6, r2, r3

stop: b stop
