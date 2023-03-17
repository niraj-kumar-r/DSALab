
	.text
	.global	array
	.bss
	.align	2
	.type	array, %object
	.size	array, 80
array:
	.space	80
	.global	i
	.align	2
	.type	i, %object
	.size	i, 4
i:
	.space	4
	.text
	.align	2
	.global	fibs
	.syntax unified
	.arm
	.type	fibs, %function
fibs:

	push	{r4, fp, lr}
	add	fp, sp, #8
	sub	sp, sp, #20
	str	r0, [fp, #-24]
	ldr	r3, [fp, #-24]
	cmp	r3, #0
	bne	.L2
	mov	r3, #0
	b	.L3
.L2:
	ldr	r3, [fp, #-24]
	cmp	r3, #1
	bgt	.L4
	ldr	r3, [fp, #-24]
	sub	r3, r3, #1
	ldr	r2, .L5
	mov	r1, #1
	str	r1, [r2, r3, lsl #2]
	mov	r3, #1
	b	.L3
.L4:
	ldr	r3, [fp, #-24]
	sub	r3, r3, #1
	mov	r0, r3
	bl	fibs
	mov	r4, r0
	ldr	r3, [fp, #-24]
	sub	r3, r3, #2
	mov	r0, r3
	bl	fibs
	mov	r3, r0
	add	r3, r4, r3
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-24]
	sub	r3, r3, #1
	ldr	r1, .L5
	ldr	r2, [fp, #-16]
	str	r2, [r1, r3, lsl #2]
	ldr	r3, [fp, #-16]
.L3:
	mov	r0, r3
	sub	sp, fp, #8
	@ sp needed
	pop	{r4, fp, lr}
	bx	lr
.L6:
	.align	2
.L5:
	.word	array
	.size	fibs, .-fibs
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:

	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r3, #8
	str	r3, [fp, #-8]
	ldr	r0, [fp, #-8]
	bl	fibs
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr

