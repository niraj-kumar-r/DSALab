	.file	"addTwoNumbers.cpp"
	.text
.lcomm _ZStL8__ioinit,1,1
	.section	.text$_ZN8ListNodeC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8ListNodeC1Ei
	.def	_ZN8ListNodeC1Ei;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8ListNodeC1Ei
_ZN8ListNodeC1Ei:
.LFB1814:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, (%rax)
	movq	16(%rbp), %rax
	movq	$0, 8(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.text
	.globl	_Z13addTwoNumbersP8ListNodeS0_
	.def	_Z13addTwoNumbersP8ListNodeS0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z13addTwoNumbersP8ListNodeS0_
_Z13addTwoNumbersP8ListNodeS0_:
.LFB1818:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	64(%rsp), %rbp
	.seh_setframe	%rbp, 64
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	$0, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L3
.L7:
	movq	32(%rbp), %rax
	movl	(%rax), %edx
	movq	40(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -20(%rbp)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	-24(%rbp), %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	sarl	$2, %eax
	movl	%ecx, %r8d
	sarl	$31, %r8d
	subl	%r8d, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movq	%rbx, %rcx
	call	_ZN8ListNodeC1Ei
	movq	%rbx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L4
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L5
.L4:
	movq	-16(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L5:
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, 32(%rbp)
	movq	40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, 40(%rbp)
.L3:
	cmpq	$0, 32(%rbp)
	je	.L8
	cmpq	$0, 40(%rbp)
	jne	.L7
	jmp	.L8
.L10:
	cmpl	$0, -20(%rbp)
	jne	.L9
	movq	-16(%rbp), %rax
	movq	32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	$0, 32(%rbp)
	jmp	.L8
.L9:
	movq	32(%rbp), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	sarl	$2, %eax
	movl	%edx, %r8d
	sarl	$31, %r8d
	subl	%r8d, %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	addl	%eax, %eax
	subl	%eax, %edx
	movl	%edx, -24(%rbp)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movq	%rbx, %rcx
	call	_ZN8ListNodeC1Ei
	movq	-16(%rbp), %rax
	movq	%rbx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, 32(%rbp)
.L8:
	cmpq	$0, 32(%rbp)
	jne	.L10
	jmp	.L11
.L13:
	cmpl	$0, -20(%rbp)
	jne	.L12
	movq	-16(%rbp), %rax
	movq	40(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	$0, 40(%rbp)
	jmp	.L11
.L12:
	movq	40(%rbp), %rax
	movl	(%rax), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	sarl	$2, %eax
	movl	%edx, %r8d
	sarl	$31, %r8d
	subl	%r8d, %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	addl	%eax, %eax
	subl	%eax, %edx
	movl	%edx, -24(%rbp)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movq	%rbx, %rcx
	call	_ZN8ListNodeC1Ei
	movq	-16(%rbp), %rax
	movq	%rbx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, 40(%rbp)
.L11:
	cmpq	$0, 40(%rbp)
	jne	.L13
	jmp	.L14
.L15:
	movl	-20(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	sarl	$2, %eax
	movl	%edx, %r8d
	sarl	$31, %r8d
	subl	%r8d, %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	addl	%eax, %eax
	subl	%eax, %edx
	movl	%edx, -24(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$2, %edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -20(%rbp)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	movq	%rbx, %rcx
	call	_ZN8ListNodeC1Ei
	movq	-16(%rbp), %rax
	movq	%rbx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L14:
	cmpl	$0, -20(%rbp)
	jne	.L15
	movq	-8(%rbp), %rax
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii " \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1819:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	64(%rsp), %rbp
	.seh_setframe	%rbp, 64
	.seh_endprologue
	call	__main
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	$1, %edx
	movq	%rbx, %rcx
	call	_ZN8ListNodeC1Ei
	movq	%rbx, -16(%rbp)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	$8, %edx
	movq	%rbx, %rcx
	call	_ZN8ListNodeC1Ei
	movq	-16(%rbp), %rax
	movq	%rbx, 8(%rax)
	movl	$16, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	$0, %edx
	movq	%rbx, %rcx
	call	_ZN8ListNodeC1Ei
	movq	%rbx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_Z13addTwoNumbersP8ListNodeS0_
	movq	%rax, -8(%rbp)
	jmp	.L18
.L19:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L18:
	cmpq	$0, -8(%rbp)
	jne	.L19
	movl	$0, %eax
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2318:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2317:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L24
	cmpl	$65535, 24(%rbp)
	jne	.L24
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rax
	movq	%rax, %rcx
	call	atexit
.L24:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__Z13addTwoNumbersP8ListNodeS0_;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z13addTwoNumbersP8ListNodeS0_
_GLOBAL__sub_I__Z13addTwoNumbersP8ListNodeS0_:
.LFB2319:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z13addTwoNumbersP8ListNodeS0_
	.ident	"GCC: (Rev1, Built by MSYS2 project) 11.3.0"
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
