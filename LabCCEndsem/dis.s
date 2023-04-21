AREA    Display_Hexadecimal, CODE, READONLY

        ENTRY

start   MOV     R0, #0x1         @it to display
        LDR     R1, =0x3F00      @ment display data register into R1
        LDR     R2, =0x7000      @ment display control register into R2

        @ to 7-segment display data
        CMP     R0, #0x0
        BEQ     digit_0
        CMP     R0, #0x1
        BEQ     digit_1
        CMP     R0, #0x2
        BEQ     digit_2
        CMP     R0, #0x3
        BEQ     digit_3
        CMP     R0, #0x4
        BEQ     digit_4
        CMP     R0, #0x5
        BEQ     digit_5
        CMP     R0, #0x6
        BEQ     digit_6
        CMP     R0, #0x7
        BEQ     digit_7
        CMP     R0, #0x8
        BEQ     digit_8
        CMP     R0, #0x9
        BEQ     digit_9
        CMP     R0, #0xA
        BEQ     digit_A
        CMP     R0, #0xB
        BEQ     digit_B
        CMP     R0, #0xC
        BEQ     digit_C
        CMP     R0, #0xD
        BEQ     digit_D
        CMP     R0, #0xE
        BEQ     digit_E
        CMP     R0, #0xF
        BEQ     digit_F

digit_0 MOV     R3, #0x3F        @ay data for the digit '0'
        B       display_digit

digit_1 MOV     R3, #0x06        @ay data for the digit '1'
        B       display_digit

digit_2 MOV     R3, #0x5B        @ay data for the digit '2'
        B       display_digit

digit_3 MOV     R3, #0x4F        @ay data for the digit '3'
        B       display_digit

digit_4 MOV     R3, #0x66        @ay data for the digit '4'
        B       display_digit

digit_5 MOV     R3, #0x6D        @ay data for the digit '5'
        B       display_digit

digit_6 MOV     R3, #0x7D        @ay data for the digit '6'
        B       display_digit

digit_7 MOV     R3, #0x07        @ay data for the digit '7'
        B       display_digit

digit_8 MOV     R3, #0x7F        @ay data for the digit '8'
        B       display_digit

digit_9 MOV R3, #0x6F @ay data for the digit '9'
B display_digit

digit_A MOV R3, #0x77 @ay data for the digit 'A'
B display_digit

digit_B MOV R3, #0x7C @ay data for the digit 'B'
B display_digit

digit_C MOV R3, #0x39 @ay data for the digit 'C'
B display_digit

digit_D MOV R3, #0x5E @ay data for the digit 'D'
B display_digit

digit_E MOV R3, #0x79 @ay data for the digit 'E'
B display_digit

digit_F MOV R3, #0x71 @ay data for the digit 'F'
B display_digit

display_digit
STR R3, [R1] @ata to the display data register
LDR R3, [R2] @ntrol register into R3
ORR R3, #0x01 @ to enable the display
STR R3, [R2] @isplay control register to the hardware
MOV R3, #0x1000000 @w the display to update
delay SUBS R3, #1
BNE delay
    MOV     R3, #0x00         @ata and control registers
    STR     R3, [R1]
    STR     R3, [R2]

    END
