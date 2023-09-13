#include "jogada.h"
#include <stdio.h>
#include "tabuleiro.h"

tJogada LeJogada(){
    tJogada jogada;
    scanf("%d %d%*c",&jogada.x,&jogada.y);
    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}