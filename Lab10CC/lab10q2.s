.global _start
.equ ADDR_LEDS, 0xFF200000
.equ ADDR_SWITCH, 0xFF200040

_start:
  ldr r0, =ADDR_SWITCH
  ldr r1, =ADDR_LEDS
loop:
  ldr r2, [r0]
  str r2, [r1]
  b loop
