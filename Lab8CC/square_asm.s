.global _start
_start:
    mov r0, #4 // input
	mov r4, #0 // initilization
	mov r1, #0x00000000 // to set the stack location
    mov sp, r1
    bl sqr // call the recursive sqr
        //other instructions
end:
	B end // you will return here from sqr
		
sqr:	
	push {r4, lr} //save the return address and local variables/registers
	cmp r0,#1  // recursion terminating condition
	ble ret // return from recursion
	mov r4, r0
	sub r0, r0, #1 
	bl sqr  // recursive calling
	add r0, r0, r4 // computation within function
	add r0, r0, r4 
	sub r0, r0, #1
ret:
	pop {r4, lr} // restore the return address and locals
	bx lr // return to last call
//end of the program

