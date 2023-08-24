#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);

int main(){
    int i=0,n;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        int j,qtd;
        scanf("%d",&qtd);
        int vet[qtd];

        for (j=0;j<qtd;j++){
            scanf("%d",&vet[j]);
        }
        scanf("\n");
        int soma = SomaElementosPares(vet,qtd);
        printf("%d\n",soma);
    }

return 0;
}

int SomaElementosPares(int* vet, int numElementos){
    int soma;
    if (!numElementos) return 0;
    if(!(vet[numElementos-1]%2)){
        soma = (vet[numElementos-1] + SomaElementosPares(vet,numElementos-1));
        return soma;
    } else{
        soma = SomaElementosPares(vet,numElementos-1);
        return soma;
    }
}