#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    tabuleiro.peca1='X';
    tabuleiro.peca2='0';
    tabuleiro.pecaVazio='-';
    int i,j;
    for(i=0;i<TAM_TABULEIRO;i++){
        for(j=0;j<TAM_TABULEIRO;j++){
            tabuleiro.posicoes[i][j]=tabuleiro.pecaVazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    tabuleiro.posicoes[x][y] = peca==1 ? tabuleiro.peca1 : tabuleiro.peca2;
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i,j;
    for(i=0;i<TAM_TABULEIRO;i++){
        for(j=0;j<TAM_TABULEIRO;j++){
            if(tabuleiro.posicoes[i][j]==tabuleiro.pecaVazio)
            return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    return peca==1 ? tabuleiro.posicoes[x][y]==tabuleiro.peca1
                   : tabuleiro.posicoes[x][y]==tabuleiro.peca2;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    return (tabuleiro.posicoes[x][y]==tabuleiro.pecaVazio);
}

int EhPosicaoValidaTabuleiro(int x, int y){
    return(x>=0 && y>=0 && x<TAM_TABULEIRO && y<TAM_TABULEIRO);
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i,j;
    for(i=0;i<TAM_TABULEIRO;i++){
        for(j=0;j<TAM_TABULEIRO;j++){
            printf("%c",tabuleiro.posicoes[i][j]);
        }printf("\n");
    }
}