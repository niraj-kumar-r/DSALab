.global _start

_start:
    
	MOV R1, #1
	MOV R2, #10
	
	ADD R1, R1, R2
	SUB R2, R1, R2
	SUB R1, R1, R2
	
	
stop: B stop