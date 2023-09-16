#include "empresa.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    tEmpresa empresas[n];
    for(int i=0;i<n;i++){
        empresas[i]=leEmpresa();
    }
    for(int i=0;i<n;i++){
        imprimeEmpresa(empresas[i]);
    }
    return 0;
}