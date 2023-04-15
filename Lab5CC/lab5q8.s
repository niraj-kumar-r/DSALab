.global main
    
main:
    
    MOV r0, #5      @ m = 5
    MOV r1, #3      @ n = 3
    MOV r2, #0      @ result = 0
    
    LOOP:
        CMP r1, #0
        BEQ ENDLOOP
        
        
        AND r3, r1, #1
        BEQ SHIFT
        
        ADD r2, r2, r0
        
    SHIFT:
        
        MOV r3, r0
        LSL r3, r3, #1
        
        
        MOV r1, r1, LSR #1
        
        
        MOV r0, r3
        
        
        B LOOP
        
    ENDLOOP:
        
        MOV r3, r2
        
    stop: B stop
