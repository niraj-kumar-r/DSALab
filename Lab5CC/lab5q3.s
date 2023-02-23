.global _start
_start:
    mov     r1, #123
	
	lsr r2, r1, #1
	lsl r2, r2, #1
	
	sub r3, r1, r2

stop: B stop
