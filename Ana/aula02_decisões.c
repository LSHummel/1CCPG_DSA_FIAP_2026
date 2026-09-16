#include<stdio.h>

int main(){

    int idade;

    printf("Digite a sua idde: ");
    scanf("%d", &idade);

    if(idade >= 18){
        printf("voce e velho");
    }else{
        printf("voce e bebe");
    }


    return 0;
}