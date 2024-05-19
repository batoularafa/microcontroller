		    SW_inc		BIT     P3.2
			SW_dec      BIT     P3.3	
		    ORG 	000H
		    MOV		DPTR, #CC_PATTERNS
					
			
START:  
            setb	SW_inc
            JB 		SW_inc, HERE

            MOV 	A,#00H 	; A=0
            MOV 	B,A      ; B=A=0
		    MOV 	R0,#0AH  ;R0 =10
	
Loop:	
    	    setb	SW_inc
increase:   JB 		SW_inc, increase 
			
    	    ACALL   Delay
            MOVC	A,@A+DPTR
								
		    MOV 	P2,A			
							
		    MOV 	A,B
		    INC 	A
	        MOV 	B,A
			
			djnz	R0,	Loop
			
					
HERE:		
            setb	SW_dec
            JB 		SW_dec, START


            MOV 	A,#09H 	; A=9
            MOV 	B,A      ; B=A=0
		    MOV 	R0,#0AH  ;R0 =10
	
Loop4:	
		    setb	SW_dec
decrease:   JB 		SW_dec, decrease 
			
    	    ACALL   Delay
            MOVC	A,@A+DPTR
								
		    MOV 	P2,A			
							
		    MOV 	A,B
		    DEC 	A
	        MOV 	B,A
			djnz	R0,	Loop4
			
			
			sjmp START
				
			
			
			
Delay: 	
		MOV 	R5, #2
LOOP1: 	MOV 	R6, #255  
LOOP2: 	MOV 	R7, #255  
LOOP3:	DJNZ 	R7, LOOP3  
		DJNZ 	R6, LOOP2  
		DJNZ 	R5, LOOP1 				
		RET			
			
CC_PATTERNS: 
			DB 	~3FH, ~06H, ~5BH, ~4FH, ~66H, ~6DH, ~7DH, ~07H, ~7FH, ~6FH, ~0   
				
			END
