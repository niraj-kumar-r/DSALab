.data
.text
.global _start
.end
.word 0,0,0,0,0,0,0,0,0.0
_start:
L0:
L1:
haha:
huhu:
hehe:
ldr r0, =haha
ldr r1, =10
mov r2, #0
mov r3, #0

str r5, [r0, r3, lsl #2]
str r4, [r0, r7, lsl #2]
bx lr

ldr r4, [r0, r3, lsl #2]
add r7, r3, #1
ldr r5, [r0, r7, lsl #2]
cmp r4, r5
bllt hehe
add r3, r3, #1
cmp r3, r1
blt L1

cmp r2, r1
sub r1, r1, #1
blt L0
b huhu
	
	