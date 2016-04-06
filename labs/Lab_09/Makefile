
prog.s : prog.c
	gcc -m32 -O0 -S prog.c
	
prog : prog.c
	gcc -m32 -O0 -o prog prog.c
	
progG : prog.c	
	gcc -m32 -g -O0 -o progG prog.c
	
progIf.s : progIf.c
	gcc -m32 -O0 -S progIf.c
	
progWhile.s : progWhile.c
	gcc -m32 -O0 -S progWhile.c	

progFor.s : progFor.c
	gcc -m32 -O0 -S progFor.c
	
progSwitch.s : progSwitch.c
	gcc -m32 -O0 -S progSwitch.c	
	
clean :
	-rm prog.s progIf.s progWhile.s progFor.s progSwitch.s prog progG
