#include "matrix_utils.h"
#include <stdio.h>

int main(){
    int lin1,col1,lin2,col2;
    scanf("%d%d%*c",&lin1,&col1);
    
    int matriz1[lin1][col1];
    matrix_read(lin1,col1,matriz1);

    scanf("%d%d%*c",&lin2,&col2);
    
    int matriz2[lin2][col2];
    matrix_read(lin2,col2,matriz2);

    int x=0;
    while(x!=6){
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:");
        scanf("%d",&x);
        printf("\n");
        switch (x)
        {
        case 1:
            if(possible_matrix_sum(lin1,col1,lin2,col2)){
                int resultadoSoma[lin1][col1];
                matrix_add(lin1,col1,matriz1,lin2,col2,matriz2,resultadoSoma);
                matrix_print(lin1,col1,resultadoSoma);
            }
            else printf("Erro: as dimensoes da matriz nao correspondem\n");
            break;
        
        case 2:
            if(possible_matrix_sub(lin1,col1,lin2,col2)){
                int resultadoSub[lin1][col1];
                matrix_sub(lin1,col1,matriz1,lin2,col2,matriz2,resultadoSub);
                matrix_print(lin1,col1,resultadoSub);
            }
            else printf("Erro: as dimensoes da matriz nao correspondem\n");
            break;
        
        case 3:
            if(possible_matrix_multiply(col1,lin2)){
                int resultadoMult[lin1][col2];
                matrix_multiply(lin1,col1,matriz1,lin2,col2,matriz2,resultadoMult);
                matrix_print(lin1,col2,resultadoMult);
            }
            else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            break;
        
        case 4:{
            int scalar,opcao;
            scanf("%d %d",&scalar,&opcao);
            switch(opcao){
                case 1:
                    scalar_multiply(lin1,col1,matriz1,scalar);
                    matrix_print(lin1,col1,matriz1);
                    break;

                case 2:
                    scalar_multiply(lin2,col2,matriz2,scalar);
                    matrix_print(lin2,col2,matriz2);
                    break;
            }
            break;}
        
        case 5:
            {
            int resultado1[col1][lin1];
            transpose_matrix(lin1,col1,matriz1,resultado1);
            matrix_print(col1,lin1,resultado1);

            printf("\n");

            int resultado2[col2][lin2];
            transpose_matrix(lin2,col2,matriz2,resultado2);
            matrix_print(col2,lin2,resultado2);
            break;
            }
        case 6: break;
        }
    if(x!=6) printf("\n");
    }
return 0;
}