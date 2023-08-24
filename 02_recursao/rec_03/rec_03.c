#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int main(){
    int i,n;
    scanf("%d%*c",&n);

    for(i=0;i<n;i++){
        int x,qtd,j;
        scanf("%d%d%*c",&x,&qtd);
        int vet[qtd];

        for(j=0;j<qtd;j++){
            scanf("%d",&vet[j]);
        } scanf("%*c");
        int nCasos = ContaOcorrencias(vet,qtd,x);
        printf("%d\n",nCasos);
    }

return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    int count;
    if(!numElementos) return 0;
    if(vet[numElementos-1]==numeroProcurado){
        count = 1 + ContaOcorrencias(vet,numElementos-1,numeroProcurado);
    } else count = ContaOcorrencias(vet,numElementos-1,numeroProcurado);
    return count;
}