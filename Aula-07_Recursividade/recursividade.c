#include<stdio.h>

long long fatorial(int n){
    //condição base
    if(n == 0){
        return 1;
    }
    return n * fatorial(n - 1);
}
long long fat_tail(int n, int acc){
    if(n == 0) return acc;
    return fat_tail(n - 1, n*acc);
}
int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("%d! = %lld\n", n, fatorial(n));

    int acc = 1;

    printf("%d! = %lld\n", n, fatorial(n));
    printf("%d\n", sizeof(fatorial(n)));

}


