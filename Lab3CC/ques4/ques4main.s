	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"ques4main.c"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #32
	mov	r3, #10
	str	r3, [fp, #-8]
	mov	r3, #20
	str	r3, [fp, #-12]
	ldr	r1, [fp, #-12]
	ldr	r0, [fp, #-8]
	bl	fun_add
	str	r0, [fp, #-16]
	ldr	r1, [fp, #-12]
	ldr	r0, [fp, #-8]
	bl	fun_sub
	str	r0, [fp, #-20]
	ldr	r1, [fp, #-12]
	ldr	r0, [fp, #-8]
	bl	fun_mul
	str	r0, [fp, #-24]
	ldr	r1, [fp, #-12]
	ldr	r0, [fp, #-8]
	bl	fun_and
	str	r0, [fp, #-28]
	ldr	r1, [fp, #-12]
	ldr	r0, [fp, #-8]
	bl	fun_or
	str	r0, [fp, #-32]
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	.size	main, .-main
	.ident	"GCC: (Fedora 12.2.0-1.fc37) 12.2.0"
