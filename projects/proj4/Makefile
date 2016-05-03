test : grades 
	./grades <test.txt

grades: grades.c
	gcc -m32 -g -o grades grades.c

grades.objd.txt : grades
	objdump -d grades >grades.objd.txt

gdb : grades 
	gdb -x dbg_cmds.txt grades	

makeHex : makeHex.c
	gcc -g -Wall -m32 -o makeHex makeHex.c

test.txt : input.txt makeHex
	./makeHex <input.txt >test.txt	

clean:  
	-rm grades grades.objd.txt
