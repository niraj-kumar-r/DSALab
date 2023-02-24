.global main
    
main:
    MOV r0, #5      @ m = 5
    MOV r1, #3      @ n = 3
    MOV r2, #0
    

    LOOP:
        CMP r1, #0
        BEQ ENDLOOP
        
        ADD r2, r2, r0
        
        SUB r1, r1, #1
        
        B LOOP
        
    ENDLOOP:
        MOV r3, r2
        
	stop: B stop
