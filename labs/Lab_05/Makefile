fact : fact.c
	gcc -Wall -g -o fact fact.c

test : fact ackerman
	./fact 10
	./ackerman 3 2
	
ackerman : ackerman.c
	gcc -Wall -g -o ackerman ackerman.c	
	
clean :
	-rm fact ackerman 
