.global _start

_start:
    MOV R1, #1
    MOV R2, #10
    
	EOR R1, R1, R2
	EOR R2, R1, R2
	EOR R1, R1, R2

stop: B stop