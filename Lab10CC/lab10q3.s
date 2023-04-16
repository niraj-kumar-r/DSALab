
//the given code works only if we decheck the memory misaligned feature from debugger checks.. reason memory clobbering 

.equ O24, 0xFF200020
.equ F26, 0xFF200030
.set total, 86400
.global _start
_start:

mov r6, #0
ldr r0, =O24
ldr r1, =#0b00111111001111110011111100111111 // bits will cleanup first four segments
str r1, [r0] // Write to 7-seg displays

ldr r0, =F26
ldr r1, =#0b0011111100111111 // bits will cleanup first four segments
str r1, [r0] // Write to 7-seg displays

ldr r5, =0
ldr r8, =0
ldr r7, =0
bl sec_loop; // write seconds

hour:
ldr r7, =0 //min = 0
add r5, r5, #1
mov r6,r5
cmp r6, #10
blle dc_0TO10
ble skip1
cmp r6, #20
blle dc_11TO20
ble skip1
cmp r6, #24
beq _start
blle dc_21TO30

skip1:
ldr r0, =O24
ldr r12, =#0b0011111100111111
strh r12, [r0, #2]

ldr r0, =F26
str r6, [r0]
bl sec_loop


min_loop:
ldr r8, =0
add r7, r7, #1
mov r6,r7 //mins in r7
cmp r6, #10
blle dc_0TO10
ble skip2
cmp r6, #20
blle dc_11TO20
ble skip2
cmp r6, #30
blle dc_21TO30
ble skip2
cmp r6, #40
blle dc_31TO40
ble skip2
cmp r6, #50
blle dc_41TO50
ble skip2
cmp r6, #60
beq hour
blle dc_51TO60

skip2:
ldr r0, =O24

ldr r12, =#0b0011111100111111
strh r12, [r0]

strh r6, [r0, #2]
bl sec_loop

sec_loop:
mov r6,r8 //secs stored in 48 .. write the seconds

cmp r6, #10
blle dc_0TO10 //decode the files 
ble skip3
cmp r6, #20
blle dc_11TO20  //individually decoding
ble skip3
cmp r6, #30
blle dc_21TO30
ble skip3
cmp r6, #40
blle dc_31TO40
ble skip3
cmp r6, #50
blle dc_41TO50
ble skip3
cmp r6, #60
blle dc_51TO60 //decoded till 60 


skip3:
ldr r0, =O24
strh r6, [r0]
add r8, r8, #1
cmp r8, #60  
beq min_loop   //
blt sec_loop

dc_0TO10:

cmp r6,#0
beq zero
cmp r6,#1
beq one
cmp r6,#2
beq two
cmp r6,#3
beq three
cmp r6,#4
beq four
cmp r6,#5
beq five
cmp r6,#6
beq six
cmp r6,#7
beq seven
cmp r6,#8
beq eight
cmp r6,#9
beq nine
cmp r6,#10
beq zero1

dc_11TO20:

cmp r6,#11
beq one1
cmp r6,#12
beq two1
cmp r6,#13
beq three1
cmp r6,#14
beq four1
cmp r6,#15
beq five1
cmp r6,#16
beq six1
cmp r6,#17
beq seven1
cmp r6,#18
beq eight1
cmp r6,#19
beq nine1
cmp r6,#20
beq zero2

dc_21TO30:

cmp r6,#21
beq one2
cmp r6,#22
beq two2
cmp r6,#23
beq three2
cmp r6,#24
beq four2
cmp r6,#25
beq five2
cmp r6,#26
beq six2
cmp r6,#27
beq seven2
cmp r6,#28
beq eight2
cmp r6,#29
beq nine2
cmp r6,#30
beq zero3

dc_31TO40:
cmp r6,#31
beq one3
cmp r6,#32
beq two3
cmp r6,#33
beq three3
cmp r6,#34
beq four3
cmp r6,#35
beq five3
cmp r6,#36
beq six3
cmp r6,#37
beq seven3
cmp r6,#38
beq eight3
cmp r6,#39
beq nine3
cmp r6,#40
beq zero4

dc_41TO50:
cmp r6,#41
beq one4
cmp r6,#42
beq two4
cmp r6,#43
beq three4
cmp r6,#44
beq four4
cmp r6,#45
beq five4
cmp r6,#46
beq six4
cmp r6,#47
beq seven4
cmp r6,#48
beq eight4
cmp r6,#49
beq nine4
cmp r6,#50
beq zero5

dc_51TO60:

cmp r6,#51
beq one5
cmp r6,#52
beq two5
cmp r6,#53
beq three5
cmp r6,#54
beq four5
cmp r6,#55
beq five5
cmp r6,#56
beq six5
cmp r6,#57
beq seven5
cmp r6,#58
beq eight5
cmp r6,#59
beq nine5

zero:
ldr r6, =#0b0011111100111111
bx lr

one:
ldr r6, =#0b0011111100000110
bx lr

two:
ldr r6, =#0b0011111101011011
bx lr

three:
ldr r6, =#0b0011111101001111
bx lr

four:
ldr r6, =#0b0011111101100110
bx lr

five:
ldr r6, =#0b0011111101101101
bx lr

six:
ldr r6, =#0b0011111101111101
bx lr

seven:
ldr r6, =#0b0011111100000111
bx lr

eight:
ldr r6, =#0b0011111101111111
bx lr

nine:
ldr r6, =#0b0011111101101111
bx lr

zero1:
ldr r6, =#0b0000011000111111
bx lr

one1:
ldr r6, =#0b0000011000000110
bx lr

two1:
ldr r6, =#0b0000011001011011
bx lr

three1:
ldr r6, =#0b0000011001001111
bx lr

four1:
ldr r6, =#0b0000011001100110
bx lr

five1:
ldr r6, =#0b0000011001101101
bx lr

six1:
ldr r6, =#0b0000011001111101
bx lr

seven1:
ldr r6, =#0b0000011000000111
bx lr

eight1:
ldr r6, =#0b0000011001111111
bx lr

nine1:
ldr r6, =#0b0000011001101111
bx lr

zero2:
ldr r6, =#0b0101101100111111
bx lr

one2:
ldr r6, =#0b0101101100000110
bx lr

two2:
ldr r6, =#0b0101101101011011
bx lr

three2:
ldr r6, =#0b0101101101001111
bx lr

four2:
ldr r6, =#0b0101101101100110
bx lr

five2:
ldr r6, =#0b0101101101101101
bx lr

six2:
ldr r6, =#0b0101101101111101
bx lr

seven2:
ldr r6, =#0b0101101100000111
bx lr

eight2:
ldr r6, =#0b0101101101111111
bx lr

nine2:
ldr r6, =#0b0101101101101111
bx lr

zero3:
ldr r6, =#0b0100111100111111
bx lr

one3:
ldr r6, =#0b0100111100000110
bx lr

two3:
ldr r6, =#0b0100111101011011
bx lr

three3:
ldr r6, =#0b0100111101001111
bx lr

four3:
ldr r6, =#0b0100111101100110
bx lr

five3:
ldr r6, =#0b0100111101101101
bx lr

six3:
ldr r6, =#0b0100111101111101
bx lr

seven3:
ldr r6, =#0b0100111100000111
bx lr

eight3:
ldr r6, =#0b0100111101111111
bx lr

nine3:
ldr r6, =#0b0100111101101111
bx lr

zero4:
ldr r6, =#0b0110011000111111
bx lr

one4:
ldr r6, =#0b0110011000000110
bx lr

two4:
ldr r6, =#0b0110011001011011
bx lr

three4:
ldr r6, =#0b0110011001001111
bx lr

four4:
ldr r6, =#0b0110011001100110
bx lr

five4:
ldr r6, =#0b0110011001101101
bx lr

six4:
ldr r6, =#0b0110011001111101
bx lr

seven4:
ldr r6, =#0b0110011000000111
bx lr

eight4:
ldr r6, =#0b0110011001111111
bx lr

nine4:
ldr r6, =#0b0110011001101111
bx lr

zero5:
ldr r6, =#0b0110110100111111
bx lr

one5:
ldr r6, =#0b0110110100000110
bx lr

two5:
ldr r6, =#0b0110110101011011
bx lr

three5:
ldr r6, =#0b0110110101001111
bx lr

four5:
ldr r6, =#0b0110110101100110
bx lr

five5:
ldr r6, =#0b0110110101101101
bx lr

six5:
ldr r6, =#0b0110110101111101
bx lr

seven5:
ldr r6, =#0b0110110100000111
bx lr

eight5:
ldr r6, =#0b0110110101111111
bx lr

nine5:
ldr r6, =#0b0110110101101111
bx lr

