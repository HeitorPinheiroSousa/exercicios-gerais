#include "data.h"
#include <stdio.h>

int main(){
    int d1,m1,a1,d2,m2,a2;

    scanf("%d/%d/%d\n%d/%d/%d",&d1,&m1,&a1,&d2,&m2,&a2);

    if(!verificaDataValida(d1,m1,a1)||!verificaDataValida(d2,m2,a2)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data: "); imprimeDataExtenso(d1,m1,a1);
    printf("Segunda data: "); imprimeDataExtenso(d2,m2,a2);

    if(comparaData(d1,m1,a1,d2,m2,a2)==1) printf("A segunda data eh mais antiga\n");
    else if(comparaData(d1,m1,a1,d2,m2,a2)==-1) printf("A primeira data eh mais antiga\n");
    else printf("As datas sao iguais\n");

    printf("A diferenca em dias entre as datas eh: %02d dias\n",calculaDiferencaDias(d1,m1,a1,d2,m2,a2));

return 0;
}