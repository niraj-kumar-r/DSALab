/* 
Program: Memory mapped I/O experiment with LEDs and Switches.
LEDs: as output devices, Switches: as input devices
Writing using STR instruction and Reading using LD instruction

Date: 13th April, 2023 | IITT 
 */

.global _start
.equ ADDR_LEDS, 0xFF200000
.equ ADDR_SWITCH, 0xFF200040
_start:
  ldr  r0, =ADDR_SWITCH
  ldr  r1, =ADDR_LEDS
  ldr  r2, [r0]  // Reading from Switches
  str  r2, [r1]  // Write to LEDs
.end










