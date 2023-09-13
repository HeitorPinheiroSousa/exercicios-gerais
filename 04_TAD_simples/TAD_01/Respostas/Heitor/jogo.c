#include <stdio.h>
#include "jogo.h"

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
}

void ComecaJogo(tJogo jogo){
    while(1){
        ImprimeTabuleiro(jogo.tabuleiro);
        JogaJogador(jogo.jogador1,jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(AcabouJogo(jogo)) break;
        JogaJogador(jogo.jogador2,jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(AcabouJogo(jogo)); break;
    }
}

int AcabouJogo(tJogo jogo){
    if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro) &&
    !VenceuJogador(jogo.jogador1,jogo.tabuleiro) &&
    !VenceuJogador(jogo.jogador2,jogo.tabuleiro)){
        printf("Sem vencedor!\n"); return 1;
    } else
    if(VenceuJogador(jogo.jogador1,jogo.tabuleiro)){
        printf("JOGADOR 1 Venceu!\n"); return 1;
    } else
    if(VenceuJogador(jogo.jogador2,jogo.tabuleiro)){
        printf("JOGADOR 2 Venceu!\n"); return 1;
    } else return 0;
}

int ContinuaJogo(){
    char c;
    printf("Jogar novamente? (s,n)\n");
    scanf("%c\n",&c);
    if(c=='s') return 1;
    else return 0;
}