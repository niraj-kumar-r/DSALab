.global _start
.equ ADDR_REDLEDS, 0xFF200000
_start:
  ldr  r0, =ADDR_REDLEDS
  mov  r1, #-1
  str  r1, [r0]   // Write to LEDs 
.end
