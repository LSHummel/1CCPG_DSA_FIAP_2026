#include <stdio.h>
#include <stdlib.h> //malloc (memory allocation), realloc

// Não utilizar o typedef para construção do Nó
/*typedef struct{
    int dado;
    struct novoNode *proximo;

}Node;*/

struct Node
{
    int dado;
    struct Node *proximo;
};

void inserirInicio(struct Node **head, int valor)
{
    struct Node *novo = malloc(sizeof(struct Node));
    novo->dado = valor;
    novo->proximo = *head;
    *head = novo;
}

void imprimirLista(struct Node *head)
{
    struct Node *atual = head;
    while (atual != NULL)
    {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

struct Node *buscar(struct Node *head, int alvo)
{
    struct Node *atual = head;
    while (atual != NULL)
    {
        if (atual->dado == alvo)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int main()
{
    struct Node *No; // Declaração do No da Lista Ligada

    No = (struct Node *)malloc(sizeof(struct Node));

    printf("%d\n", No->dado);
    No->dado = 10;
    No->proximo = NULL;
    printf("%d\n", No->dado);
    if (No == NULL)
    {
        printf("Erro: Memória insuiciente!\n");
        exit(1);
    }

    inserirInicio(&No, 5);
    inserirInicio(&No, 30);

    // inserirInicio(&No, 67);
    inserirInicio(&No, 24);

    imprimirLista(No);

    struct Node *novoNo;
    int alvo = 67;
    novoNo = buscar(No, alvo);
    if (novoNo == NULL)
    {
        printf("Valor não encontrado!\n");
        exit(1);
    }
    printf("O valor buscado -> %d.\nValor encontrado -> %d", alvo, novoNo->dado);

    /*if(n1 == NULL || n2 == NULL || n3 == NULL){
        printf("Erro:  Memória insuficiente!\n");
        exit(1);
    }
    inserirInicio(n2, 10);
    inserirInicio(n3, 20);
    inserirInicio(NULL, 30);
    imprimirLista(n3);

    //printf("%d\n", novoNo->dado); // Estruturas (struct), ponteiros
    //novoNo->dado = 10;
    //printf("%d\n", novoNo->dado);
    //novoNo->proximo = NULL;
    */
    return 0;
}
