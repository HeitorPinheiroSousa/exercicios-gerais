#include <stdio.h>
#include "jogo.h"

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
}

void ComecaJogo(tJogo jogo){

}

int AcabouJogo(tJogo jogo){
    return !(TemPosicaoLivreTabuleiro(jogo.tabuleiro));
}

int ContinuaJogo(){
    printf("Jogar novamente? (s,n)\n");
}