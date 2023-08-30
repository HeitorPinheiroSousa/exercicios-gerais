all: gerabin principal

gerabin: Includes/matrix_utils.c bibli_02.c
	gcc -c Includes/matrix_utils.c bibli_02.c

principal: Includes/matrix_utils.o bibli_02.o
	gcc Includes/matrix_utils.o bibli_02.o -o teste

clean:
	rm -rf *.o Includes/*.o