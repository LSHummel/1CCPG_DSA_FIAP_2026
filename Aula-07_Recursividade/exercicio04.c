#include <stdio.h>

int maiorElemento(int v[], int n)
{
    if (n == 1)
        return v[0];
   int anterior = maiorElemento(v, n - 1);
    if (v[n - 1] > anterior)
        return v[n - 1];
    return anterior;
}
int main()
{
    int v[] = {10, 20, 70, 30, 40, 50};
    int n = sizeof(v) / sizeof(v[0]);
    printf("%d", maiorElemento(v, n));
    return 0;
}