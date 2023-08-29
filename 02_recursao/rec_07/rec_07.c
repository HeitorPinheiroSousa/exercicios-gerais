#include <stdio.h>

int somaDigitos(int n){
    if(!n) return 0;
    int soma=0;
    soma = n%10 + somaDigitos(n/10);
    return soma;
}

int main(){
    int n; scanf("%d",&n);
    n = somaDigitos(n);
    printf("%d\n",n);
return 0;
}