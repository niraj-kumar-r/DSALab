_start:
    push {r11, lr}
    add r11, sp, #4 @ initializing the frame ptr
    sub sp, sp, #16 @ creating space for four int var
    mov r3, #10 @ initializing
    str r3, [r11, #-8]
    mov r3, #20 @ initializing
    str r3, [r11, #-12]
    mov r3, #0 @
    str r3, [r11, #-16]
    ldr r0, [r11, #-8] @ parameter 1
    ldr r1, [r11, #-12] @ parameter 2
    bl 0x44 @ the relative distance of function add
    str r0, [r11, #-16]
    mov r3, #0
    mov r0, r3
    sub sp, r11, #4 @
    pop {r11, pc} @ restore the r11 and pc from the first push

add:
    push {r11} @ why not lr also?
    add r11, sp, #0
    sub sp, sp, #12
    str r0, [r11, #-8]
    str r1, [r11, #-12]
    ldr r2, [r11, #-8]
    ldr r3, [r11, #-12]
    add r3, r2, r3
    mov r0, r3
    sub sp, r11, #0
    pop {r11}
    bx lr @ restore the pc with lr back to main