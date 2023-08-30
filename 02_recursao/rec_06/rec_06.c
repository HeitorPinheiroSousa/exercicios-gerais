#include <stdio.h>

int fibonnaci(int n){
    if(n<=1) return n;
    else return(fibonnaci(n-2)+fibonnaci(n-1));
}

int main(){
    int n; scanf("%d",&n); n=fibonnaci(n); printf("%d\n",n);
}