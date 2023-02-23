.global _start
_start:
        MOV R1, #20
        MOV R2, #10

        MOV R3, R1
        MOV R1, R2
        MOV R2, R3
stop: B stop