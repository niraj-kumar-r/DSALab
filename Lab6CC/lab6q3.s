.data
.LC0:
  .word 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9

.text
.global _start

_start:
  ldr r1, =0x5

  mov r2, #0
  ldr r3, =.LC0

loop:
  
  cmp r2, #10
  beq not_found

  ldr r4, [r3, r2, lsl #2]

  cmp r4, r1
  beq found

  add r2, r2, #1
  b loop

found:
  add r0, r3, r2, lsl #2
  b end

not_found:
  mov r0, #0

end:
  stop: b stop
