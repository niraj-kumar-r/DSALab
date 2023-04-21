.global _start

.equ SWITCH, 0xff200040
.equ BUTTON, 0xff200050

_start:

	mov r0, #0x-1
	mov r1, #0x-1
	ldr r3, =SWITCH
	ldr r4, [r3]
	mov r5, #0x1
	mov r7, #-1

switchloop:
	add r7, r7, #0x1
	and r6, r4, r5
	lsr r4, #0x1
	cmp r6, #0x1
	beq transfer
	cmp r4 ,#0x0
	bne switchloop
	
operator:
	ldr r4, =BUTTON
	ldr r5, [r4]
	cmp r5, #0x1
	beq addBranch
	cmp r5, #0x2
	beq subBranch
	cmp r5, #0x4
	beq mulBranch

stop:
	b stop
	
transfer:
	cmp r1, #0x-1
	moveq r1,r7
	movne r0,r7
	add r7, r7, #0x1
	bx lr
	
addBranch:
	add r3, r0, r1
	b stop
	
subBranch:
	sub r3, r0, r1
	b stop
	
mulBranch:
	mul r3, r0,r1
	b stop
	
	