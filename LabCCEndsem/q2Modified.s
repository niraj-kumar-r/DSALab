.global _start
.data
haha:
	.word 10,9,8,7,6,5,4,3,2,1

.text

_start:
ldr r0, =haha
ldr r1, =10
mov r2, #0


L0:
	mov r3, #0

L1:

	ldr r4, [r0, r3, lsl #2]
	add r7, r3, #1
	ldr r5, [r0, r7, lsl #2]
	cmp r4, r5
	blgt hehe @1
	add r3, r3, #1
	cmp r3, r1
	blt L1

	cmp r2, r1
	sub r1, r1, #1
	blt L0
	b huhu


hehe:
	str r5, [r0, r3, lsl #2]
	str r4, [r0, r7, lsl #2]
	bx lr


huhu:
	.end
	