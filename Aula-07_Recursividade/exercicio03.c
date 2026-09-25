#include <stdio.h>
int somaVetor(int v[], int n)
{
    if (n == 0)
        return 0;

    return v[n - 1] + somaVetor(v, n - 1);
}
int main()
{
    int v[] = {10, 20, 30, 40, 50};
    int n = sizeof(v)/sizeof(v[0]);
    printf("%d", somaVetor(v, n));
    return 0;
}