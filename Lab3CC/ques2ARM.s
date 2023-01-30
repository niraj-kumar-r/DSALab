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
	.file	"ques2.c"
	.text
	.global	__aeabi_dadd
	.section	.rodata
	.align	3
.LC0:
	.word	0
	.word	1076232192
	.word	0
	.word	1076363264
	.word	0
	.word	1076494336
	.word	0
	.word	1076625408
	.word	0
	.word	1076756480
	.word	0
	.word	1076887552
	.word	0
	.word	1076953088
	.word	0
	.word	1077018624
	.word	0
	.word	1077084160
	.align	3
.LC1:
	.word	0
	.word	1072693248
	.word	0
	.word	1073741824
	.word	0
	.word	1074266112
	.word	0
	.word	1074790400
	.word	0
	.word	1075052544
	.word	0
	.word	1075314688
	.word	0
	.word	1075576832
	.word	0
	.word	1075838976
	.word	0
	.word	1075970048
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 224
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #224
	ldr	r2, .L5
	sub	r3, fp, #84
	mov	r1, r2
	mov	r2, #72
	mov	r0, r3
	bl	memcpy
	sub	r3, fp, #156
	mov	r2, #72
	mov	r1, #0
	mov	r0, r3
	bl	memset
	ldr	r2, .L5+4
	sub	r3, fp, #228
	mov	r1, r2
	mov	r2, #72
	mov	r0, r3
	bl	memcpy
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L3:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #3
	sub	r3, r3, #4
	add	r3, r3, fp
	sub	r3, r3, #224
	ldmia	r3, {r0-r1}
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #3
	sub	r3, r3, #4
	add	r3, r3, fp
	sub	r3, r3, #80
	ldmia	r3, {r2-r3}
	bl	__aeabi_dadd
	mov	r2, r0
	mov	r3, r1
	ldr	r1, [fp, #-8]
	lsl	r1, r1, #3
	sub	r1, r1, #4
	add	r1, r1, fp
	sub	r1, r1, #152
	stm	r1, {r2-r3}
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #8
	ble	.L3
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L6:
	.align	2
.L5:
	.word	.LC0
	.word	.LC1
	.size	main, .-main
	.ident	"GCC: (Fedora 12.2.0-1.fc37) 12.2.0"
