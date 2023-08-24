#include <stdio.h>

void ImprimeInvertido(char* string);

int main(){
    char palavra[1001];

    while (scanf("%1000s",palavra)==1)
    {
        ImprimeInvertido(palavra);
        printf(" ");
    }
    

return 0;
}

void ImprimeInvertido(char* string){
    int i=0;
    while(string[i+1])i++;
    printf("%c",string[i]);
    string[i]=0;
    if(string[0]){
        ImprimeInvertido(string);
    }
}