
#include <stdio.h>
#include <string.h>

// typedef (ubnsigned int) (unit)
typedef unsigned int unit; // semelhante ao python --> import numpy as numpy

//typedef int inteiro;
//typedef double doisfloat;

// Deste modo não é nescessario colocar "struct" na hora de escrever o codigo --> mais comum

// typedef struct{ 
//     int rm;
//     char nome[50];
//     float nota[2];
//     //email, data de nascimento, turma...
// }Aluno;

typedef struct{
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
}Endereco;

struct Aluno{
    int rm;
    char nome[50];
    float nota[2];
    // endereço --> rua(char[]), numero(int) - bairro (char[]), cidade (char[])
    Endereco endereco;
    //email, data de nascimento, turma...
};


int main()
{
    struct Aluno aluno[3];
    aluno[0].rm = 0;
    strcpy(aluno[0].nome, "Leonardo Soares Rodrigues");
    printf("Nome completo: %s", aluno[0].nome);
    aluno[0].nota[0] = 10;
    aluno[0].nota[1] = 6;
    //sizeoff: ele pega o tamanho em bytes do elemento ou tipo de dado
    //int -> 4bytes
    //char -> 1byte
    //2 valores no vetor nota, então 2*4bytes = 8bytes -> sizeof(aluno[0].nota)
    printf("\n%d", sizeof(aluno[0].nota) / sizeof(aluno[0].nota[0]));
    
    int tam_vetor = sizeof(aluno[0].nota) / sizeof(aluno[0].nota[0]);
    
    float media = (aluno[0].nota[0] + aluno[0].nota[1])/tam_vetor;
    
    printf("\nA media do aluno: %s é %.2f",aluno[0].nome, media);
    
    // Exibir Rua, numero - Bairro - Cidade
    
    strcpy(aluno[0].endereco.rua, "Av. Paulista");
    aluno[0].endereco.numero = 144;
    strcpy(aluno[0].endereco.bairro, "Bras");
    strcpy(aluno[0].endereco.cidade, "São Paulo");
    printf("\n %s, %d - %s - %s", aluno[0].endereco.rua, aluno[0].endereco.numero, aluno[0].endereco.bairro, aluno[0].endereco.cidade);
    
    
    
    
    

    return 0;
}