.global _start

.equ SWITCH, 0xff200040
.equ BUTTON, 0xff200050
.equ LED, 0xff200020

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
	b switchloop
	
addBranch:
	add r3, r0, r1
	b display
	
subBranch:
	sub r3, r0, r1
	b display
	
mulBranch:
	mul r3, r0,r1
	b display
	
display:
	ldr r2, =LED
	mov r4, #0b0000000000000000000000000000000
	str r4, [r2]
	
	mov r5, #0b1111
	and r6, r3, r5
	lsr r8, r3, #4
	and r7, r8, r5
	
	
	b stop
	

	