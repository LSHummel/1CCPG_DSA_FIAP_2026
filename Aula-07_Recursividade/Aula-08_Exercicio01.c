#include<stdio.h>

void contagem(int n){
    // Caso Base
    if(n == 0){
        printf("Fim\n");
        return;
    }
    // Caso recursivo
    printf("%d\n", n);
    contagem(n - 1);
}


int main(){

    contagem(2);

    return 0;
}