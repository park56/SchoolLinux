cal : add.o calc.c
	gcc -o cal add.o calc.c
add.o : add.h add.c
	gcc -c add.h add.c

clean:
	rm cal *.o *.h.gch
