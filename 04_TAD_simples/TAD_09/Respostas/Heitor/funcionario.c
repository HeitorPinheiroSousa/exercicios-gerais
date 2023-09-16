#include "funcionario.h"
#include <stdio.h>

tFuncionario criaFuncionario(int id, float salario){
    tFuncionario f;
    f.id=id;    f.salario=salario;
    return f;
}

tFuncionario leFuncionario(){
    tFuncionario f;
    scanf("%d %f\n",&f.id,&f.salario);
    return f;
}

int getIdFuncionario(tFuncionario funcionario){
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n",funcionario.id,funcionario.salario);
}