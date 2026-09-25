#include <stdio.h>

int somatoria(int n)
{
    // Caso Base
    if (n == 0){return 0;
    }
    // Caso Recursivo
    return n + somatoria(n - 1);
}
int main()
{
    printf("%d", somatoria(5));
    return 0;
}