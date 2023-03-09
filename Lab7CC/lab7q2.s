.global var1, var2

var1:
	.word 10
	.align 4
var2:
	.word 20
	.align 4

add:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r3, .L0
	ldr	r2, [r3]
	ldr	r3, .L0+4
	ldr	r3, [r3]
	add	r3, r2, r3
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	
.L0:
	.word	var1
	.word	var2
	
main:
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r3, #0
	str	r3, [fp, #-8]
	bl	add
	str	r0, [fp, #-8]
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
