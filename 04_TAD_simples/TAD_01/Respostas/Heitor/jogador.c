#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    jogada = LeJogada();

    if(jogador.id==ID_JOGADOR_1) printf("Jogador 1\nDigite uma posicao (x e y):\n");
    else if(jogador.id==ID_JOGADOR_2) printf("Jogador 2\nDigite uma posicao (x e y):\n");

    if(!EhPosicaoValidaTabuleiro(jogada.x,jogada.y)){
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",jogada.x,jogada.y);
        jogada.sucesso=0;
    } else
    if(!EstaLivrePosicaoTabuleiro(tabuleiro,jogada.x,jogada.y)){
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",jogada.x,jogada.y);
        jogada.sucesso=0;
    } else{
        jogada.sucesso=1;
        tabuleiro.posicoes[jogada.x][jogada.y] =
        jogador.id==ID_JOGADOR_1 ? tabuleiro.peca1 : tabuleiro.peca2;

        printf("Jogada [%d,%d]!\n",jogada.x,jogada.y);
    }

    if(FoiJogadaBemSucedida(jogada)) return tabuleiro;
    else return JogaJogador(jogador,tabuleiro);
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char c = jogador.id==ID_JOGADOR_1 ? tabuleiro.peca1 : tabuleiro.peca2;
    int i,j;
    for(i=0;i<TAM_TABULEIRO;i++){
        int ganhouLinha = 1;
        for(j=0;j<TAM_TABULEIRO;j++){
            if(tabuleiro.posicoes[i][j]!=c) ganhouLinha=0;
        }
        if(ganhouLinha) return 1;
    }
    for(j=0;j<TAM_TABULEIRO;j++){
        int ganhouColuna = 1;
        for(i=0;i<TAM_TABULEIRO;i++){
            if(tabuleiro.posicoes[i][j]!=c) ganhouColuna=0;
        }
        if(ganhouColuna) return 1;
    }
    
    int ganhouDiag1=1,ganhouDiag2=1;
    for(i=0,j=TAM_TABULEIRO-1;i<TAM_TABULEIRO;i++,j--){
        if(tabuleiro.posicoes[i][i]!=c) ganhouDiag1=0;
        if(tabuleiro.posicoes[j][j]!=c) ganhouDiag2=0;
    }
    if(ganhouDiag1 || ganhouDiag2) return 1;
    
    return 0;
}