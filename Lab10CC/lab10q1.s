.global _start

.equ LEDS, 0xFF200000
.equ DELAY_COUNT, 1

_start:
  ldr r0, =LEDS
  mov r1, #0b1000000000

inner_loop:
  str r1, [r0]
  bl delay
  lsr r1, r1, #1
  cmp r1, #1
  bne inner_loop

reverse_start:
	str r1, [r0]
	bl delay

reverse_loop:
  lsl r1, r1, #1
  str r1, [r0]
  bl delay
  cmp r1, #512
  bne reverse_loop

  b _start

delay:
  mov r3, #DELAY_COUNT
delay_loop:
  subs r3, r3, #1
  bne delay_loop
  bx lr

.end
