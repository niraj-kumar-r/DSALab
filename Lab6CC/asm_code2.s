.section .data
//data type supported in ARM: .byte, .hword, .word, .dword
.align 2
.LC0:
        .ascii "i   i   t   t   i   r   u   p   a   t   i"
        //try with the following way of storing the character string
        //.ascii "iit   tirupati"
	.byte 'a' 
	.align 2
.text 	
.global _start
.type _start %function
_start:
	 //to access the character array
	  ldr r6, .L1
	  ldr r7, [r6, #0]
	  ldr r8, [r6, #4]
	  ldr r9, [r6, #8]
	  str r9, [r6, #0] 
	  str r8, [r6, #4]
	  str r7, [r6, #8]
stop: 
      b stop

.L1:
    .word .LC0	

