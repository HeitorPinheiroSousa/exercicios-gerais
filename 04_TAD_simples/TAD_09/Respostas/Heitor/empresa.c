#include "empresa.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id){
    tEmpresa emp;
    emp.id = id; emp.qtdFuncionarios=0;
    return emp;
}

tEmpresa leEmpresa(){
    tEmpresa emp;
    int i,leituras;
    scanf("%d%d\n",&emp.id,&leituras);
    emp.qtdFuncionarios=0;
    
    for(i=0;i<leituras;i++){
        tFuncionario func = leFuncionario();
        int j,funcionarioNovo=1;
        
        for(j=0;j<emp.qtdFuncionarios;j++){
            if(getIdFuncionario(emp.funcionarios[j])==getIdFuncionario(func)){
                printf("A empresa %d ja possui um funcionario com o id %d\n",emp.id,getIdFuncionario(func));
                funcionarioNovo=0; break;
            }
        }
        if(funcionarioNovo){
            emp = contrataFuncionarioEmpresa(emp,func);
        }
    }
    return emp;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    empresa.funcionarios[empresa.qtdFuncionarios]=funcionario;
    empresa.qtdFuncionarios++;
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    printf("Empresa %d:\n",empresa.id);
    for(int i=0;i<empresa.qtdFuncionarios;i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}