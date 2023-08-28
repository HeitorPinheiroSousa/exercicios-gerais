#include <stdio.h>

int palindromo(char *string, int tamanho);

int main(){
    char palavra[1001];

    while(scanf("%1000s%*c",palavra)==1){
        int i=0; while(palavra[i])i++;

        if(palindromo(palavra,i)) printf("SIM\n");
        else printf("NAO\n");
    }


return 0;
}

int palindromo(char *string, int tamanho){
    if(tamanho<=1) return 1;
    
    else{
        int i=0;
        while(!string[i])i++;
        if(i>= tamanho-1) return 1;

        if(string[i] != string[tamanho-1]) return 0;
        else{
            string[i]=0; string[tamanho-1]=0;
            return palindromo(string,tamanho-1);
        }
    }
    
}