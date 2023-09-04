#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    if(dia<1 || dia>numeroDiasMes(mes,ano) || mes<1 || mes >12) return 0;
    else return 1;
}

void imprimeMesExtenso(int mes){
    switch (mes)
    {
    case 1:printf("Janeiro");break;
    case 2:printf("Fevereiro");break;
    case 3:printf("Marco");break;
    case 4:printf("Abril");break;
    case 5:printf("Maio");break;
    case 6:printf("Junho");break;
    case 7:printf("Julho");break;
    case 8:printf("Agosto");break;
    case 9:printf("Setembro");break;
    case 10:printf("Outubro");break;
    case 11:printf("Novembro");break;
    case 12:printf("Dezembro");break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ",dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n",ano);
}

void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%d\n",dia,mes,ano);
}

int verificaBissexto(int ano){
    if(!(ano%400) || (!(ano%4) && ano%100)) return 1;
    else return 0;
}

int numeroDiasMes(int mes, int ano){
    if(mes == 2){
        if(verificaBissexto(ano)) return 29;
        else return 28;
    }
    if(mes==4||mes==6||mes==9||mes==11) return 30;
    else return 31;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    //Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda e 0 se as datas são iguais.
    if(ano1>ano2 || (ano1==ano2&&mes1>mes2) || (ano1==ano2 && mes1==mes2 && dia1>dia2)) return 1;
    if(ano1<ano2 || (ano1==ano2&&mes1<mes2) || (ano1==ano2 && mes1==mes2 && dia1<dia2)) return -1;
    else return 0;
}

int calculaDiasAteMes(int mes, int ano){
    int i=0,dias=0;
    for(i=1;i<mes;i++) dias += numeroDiasMes(i,ano);
    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(!comparaData(dia1,mes1,ano1,dia2,mes2,ano2)) return 0;
    int d,m,a,dif=0;
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2)==1){
        d=dia2;m=mes2;a=ano2;

        while(!(d==dia1 && m==mes1 && a==ano1)){
            d++; dif++;
            if(d>numeroDiasMes(m,a)){
                d=1; m++;
                if(m>12){
                    m=1; a++;
                }
            }
        }
    }
    else if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2)==-1){
        d=dia1;m=mes1;a=ano1;

        while(!(d==dia2 && m==mes2 && a==ano2)){
            d++; dif++;
            if(d>numeroDiasMes(m,a)){
                d=1; m++;
                if(m>12){
                    m=1; a++;
                }
            }
        }
    }
    return dif;
}

void imprimeProximaData(int dia, int mes, int ano){
    int d=dia,m=mes,a=ano;
    d++;
    if(d>numeroDiasMes(m,a)){
        d=1; m++;
        if(m>12){
            m=1; a++;
        }
    }
    printf("%02d/%02d/%d",d,m,a);
}