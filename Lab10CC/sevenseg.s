.equ ADDR_7SEG1TO4, 0xFF200020
.equ ADDR_7SEG5TO6, 0xFF200030

.global _start
_start:
  ldr r0, =ADDR_7SEG1TO4
  ldr r1, =#0b0000000000000000000000000000000 // bits will cleanup first four segments
  str r1, [r0]     // Write to 7-seg displays

  ldr r0, =ADDR_7SEG1TO4
  ldr r1, =#0b0000001
  str r1, [r0]
  
  ldr r0, =ADDR_7SEG5TO6
  ldr r1, =#0b1111000011110000 // bits  will activate last two segment
  str r1, [r0]                 // Write to 7-seg display 
  
  ldr r0, =ADDR_7SEG5TO6
  ldr r1, =#0b0000000   	// bits 0b0000110 will cleanup last two segments
  str r1, [r0]              // Write to 7-seg display
  
  b _start
  
.end






