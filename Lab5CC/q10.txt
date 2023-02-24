.global _start
_start:
    mov R0,#10
    mov R1,#20
    eor R2, R1, R0

    @if R2 is 0 then R0 is equal to R1
    stop: b stop


