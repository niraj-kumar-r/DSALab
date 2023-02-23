.global main

    main:
        
        MOV R5, #0
        MOV R4, #1
        MOV R0, #3
        CMP R0, #0
        BEQ done

    loop:
        ADD R5, R5, R4
        ADD R4, R4, #1    
        SUB R0, R0, #1
        CMP R0, #0
        BNE loop
		
	done:
		stop: B stop
