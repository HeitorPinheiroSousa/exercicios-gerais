all: gerabin principal

gerabin: Includes/esfera_utils.c bibli_01.c
	gcc -c Includes/esfera_utils.c bibli_01.c

principal: Includes/esfera_utils.o bibli_01.o
	gcc Includes/esfera_utils.o bibli_01.o -o teste

clean:
	rm -rf *.o Includes/*.o