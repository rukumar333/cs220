test : grades 
	./grades <test.txt

grades: grades.c
	gcc -m32 -g -o grades grades.c

grades.objd.txt : grades
	objdump -d grades >grades.objd.txt

gdb : grades 
	gdb -x dbg_cmds.txt grades	

makeHex: makeHex.cpp
	g++ -std=c++11 -g makeHex.cpp -o makeHex
	./makeHex

hackasm: hack.s
	gcc -m32 -c -o hack.o hack.s
	objdump -d hack.o > hack.objd.txt

clean:  
	-rm grades grades.objd.txt makeHex a.out
