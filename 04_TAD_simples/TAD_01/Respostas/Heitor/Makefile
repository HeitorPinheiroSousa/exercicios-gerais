all: gerabin principal clean

gerabin: jogada.c jogador.c jogo.c tabuleiro.c main.c
	gcc -c jogada.c jogador.c jogo.c tabuleiro.c main.c

principal: jogada.o jogador.o jogo.o tabuleiro.o main.o
	gcc jogada.o jogador.o jogo.o tabuleiro.o main.o -o teste

clean:
	rm -rf *.o