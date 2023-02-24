.global _start
_start:
    MOV R0, #5
    MOV R1, #3
    CMP R0, R1
    MOVLT R2, R0
    MOVGT R2, R1
	ADD R3, R0, R1
    MOV R0, R2
	SUB R1, R3, R0

stop: B stop
