#include <stdio.h>
#include "data.h"

int main(){
    int d,m,a;
    scanf("%d/%d/%d",&d,&m,&a);
    if(!verificaDataValida(d,m,a)){
        printf("A data informada eh invalida\n");
        return 0;
    }
    printf("Data informada: "); imprimeDataExtenso(d,m,a);
    if(verificaBissexto(a)) printf("O ano informado eh bissexto\n");
    else printf("O ano informado nao eh bissexto\n");
    printf("O mes informado possui %d dias\n",numeroDiasMes(m,a));
    printf("A data seguinte eh: "); imprimeProximaData(d,m,a);
}