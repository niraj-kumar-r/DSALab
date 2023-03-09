.text
	.align	2
	.global	fib
	.type	fib, %function
fib:
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-16]
	cmp	r2, r3
	ble	.L2
	ldr	r3, [fp, #-8]
	b	.L3
.L2:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	ldr	r2, [fp, #-16]
	mov	r1, r3
	ldr	r0, [fp, #-12]
	bl	fib
	mov	r3, r0
.L3:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	
	
	.align	2
	.global	main
	.type	main, %function
main:
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r3, #20
	str	r3, [fp, #-8]
	ldr	r2, [fp, #-8]
	mov	r1, #1
	mov	r0, #1
	bl	fib
	str	r0, [fp, #-12]
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
