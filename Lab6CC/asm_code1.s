.section .data
//data type supported in ARM: .byte, .hword, .word, .dword
.align 2
.LC0:
    .word 2, 3, 5, 7
.text 	
.global _start
.type _start %function
_start:     
     //to access the integer array
	  ldr r2, .L1
	  ldr r3, [r2, #0x0]
	  ldr r4, [r2, #0x4]
	  add r5, r3, r4
          str r5 [r2, #0x10] 
	  
stop: 
      b stop

.L1:
    .word .LC0	

