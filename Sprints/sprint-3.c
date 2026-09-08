#include <stdio.h>

// FUNÇÃO DOS MENUS
void menu(void)
{
    printf("================================\n");
    printf("      ESTACAO DE RECARGA\n");
    printf("================================\n");
    printf("1 - Nova sessao de recarga\n");
    printf("2 - Listar sessoes\n");
    printf("3 - Buscar sessao\n");
    printf("4 - Ordenar sessoes\n");
    printf("5 - Estatisticas\n");
    printf("6 - Fim da Simulacao\n");
    printf("Escolha uma opcao: ");
}

void menu_ordem(void)
{
    printf("=========================\n");
    printf("     ORDENAR SESSAO\n");
    printf("=========================\n");
    printf("\n1 - Ordenar por ID\n");
    printf("2 - Ordenar por Energia Consumida\n");
    printf("3 - Ordenar por Custo da Sessao\n");
    printf("4 - Ordenar por Tempo da Recarga\n");
    printf("Escolha uma forma de ordenacao: ");
}

// FUNÇÃO DE FECHAR
void close(int fechar)
{
    printf("Para voltar ao menu digite 0\n");
    scanf("%d", &fechar);
    while (fechar != 0)
    {
        printf("Para voltar ao menu digite 0\n");
        scanf("%d", &fechar);
        switch (fechar)
        {
        case 0:
            break;
        }
    }
}

// STRUCT
typedef struct
{
    float ener_consumida;
    float valor_total;
    float tempo;
    int tempo_hora;
    int tempo_min;
    float porcentagem_f;
} Variaveis;

typedef struct
{
    int ID;
    float total_kwh;
    float porcentagem;
    int hora;
    Variaveis variaveis;
} Carro;

// FUNÇÕES DE TAXA
float f_fator_tempo(int carro_atual)
{
    if (carro_atual > 8)
    {
        return 2.0;
    }
    else if (carro_atual > 5)
    {
        return 1.5;
    }
    else if (carro_atual > 2)
    {
        return 1.2;
    }
    else
    {
        return 1.0;
    }
}

float f_fator_horario(Carro carro)
{
    if (6 < carro.hora && carro.hora <= 10)
    {
        return 1.1;
    }
    else if (16 < carro.hora && carro.hora <= 21)
    {
        return 1.1;
    }
    else
    {
        return 1.0;
    }
}

// FUNÇÃO DE BUSCA LINEAR
int buscar_linear(Carro carro[], int carro_atual, int ID)
{
    for (int i = 0; i < carro_atual; i++)
    {
        if (carro[i].ID == ID)
        {
            return i;
        }
    }
    return -1;
}

//  FUNÇÃO DE ORDENAÇÃO

void Ordenacao_bubble(Carro carro[], int carro_atual, int criterio)
{
    for (int i = 0; i < carro_atual - 1; i++)
    {
        for (int j = 0; j < carro_atual - 1 - i; j++)
        {

            int trocar = 0;

            if (criterio == 1)
            {
                if (carro[j].ID > carro[j + 1].ID)
                {
                    trocar = 1;
                }
            }
            else if (criterio == 2)
            {
                if (carro[j].variaveis.ener_consumida > carro[j + 1].variaveis.ener_consumida)
                {
                    trocar = 1;
                }
            }
            else if (criterio == 3)
            {
                if (carro[j].variaveis.valor_total > carro[j + 1].variaveis.valor_total)
                {
                    trocar = 1;
                }
            }
            else if (criterio == 4)
            {
                if (carro[j].variaveis.tempo > carro[j + 1].variaveis.tempo)
                {
                    trocar = 1;
                }
            }

            if (trocar)
            {
                Carro temp = carro[j];
                carro[j] = carro[j + 1];
                carro[j + 1] = temp;
            }
        }
    }
}

// FUNCAO LISTAR
void listar_sessoes(Carro carro[], int carro_atual)
{

    printf("\n===== SESSOES =====\n");

    for (int i = 0; i < carro_atual; i++)
    {

        printf("\nCARRO %d\n", i + 1);
        printf("ID: %d\n", carro[i].ID);
        printf("Energia consumida: %.2f kWh\n",
               carro[i].variaveis.ener_consumida);
        printf("Custo: R$ %.2f\n",
               carro[i].variaveis.valor_total);
        printf("Tempo: %.2f horas\n",
               carro[i].variaveis.tempo);
    }
}

// CÓDIGO PRINCIPAL
int main()
{

    Carro carro[100];

    int criterio;
    int opcao = 0;
    int fechar = 1;
    int carro_atual = 0;

    float maior_consumo = 0.0;
    float menor_consumo = 0.0;

    int ID = 0;

    while (opcao != 6)
    {

        menu();
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {

        case 1:

            printf("=========================\n");
            printf("  NOVA SESSAO DE RECARGA\n");
            printf("=========================\n");

            printf("Quantos kWh cabem no carro:\n");
            scanf("%f", &carro[carro_atual].total_kwh);

            printf("Porcentagem de energia do carro:\n");
            scanf("%f", &carro[carro_atual].porcentagem);

            // Validação da porcentagem
            while (carro[carro_atual].porcentagem < 0 || carro[carro_atual].porcentagem > 100)
            {
                printf("PORCENTAGEM INVALIDA!");
                printf("A porcentagem esta errada, digite novamente (0 ate 100):\n");
                scanf("%f", &carro[carro_atual].porcentagem);
            }

            printf("Digite o horario da recarga em horas (0 ate 23):\n");
            scanf("%d", &carro[carro_atual].hora);

            // Validação do horario
            while (carro[carro_atual].hora < 0 || carro[carro_atual].hora > 23)
            {
                printf("HORARIO INVALIDO!");
                printf("Digite o horario da recarga em horas (0 ate 23):\n");
                scanf("%d", &carro[carro_atual].hora);
            }

            if (carro_atual > 9)
            {
                printf("\n");
                printf("ERRO NO SISTEMA!\n");
                printf("Quantidade maxima excedida!\n");
                printf("O sistema foi desligado instantaneamente.\n");
                printf("Dados da sessao perdidos!\n");
                return 0;
            }

            // Energia consumida pelo carro
            carro[carro_atual].variaveis.ener_consumida = carro[carro_atual].total_kwh - carro[carro_atual].total_kwh * (carro[carro_atual].porcentagem / 100);
            // Tempo da recarga em horas
            carro[carro_atual].variaveis.tempo = (carro[carro_atual].variaveis.ener_consumida / 50) * f_fator_tempo(carro_atual);
            // Tempo da recarga em horas inteiro
            carro[carro_atual].variaveis.tempo_hora = (int)(carro[carro_atual].variaveis.ener_consumida / 50) * f_fator_tempo(carro_atual);
            // Minutos da recarga
            carro[carro_atual].variaveis.tempo_min = (carro[carro_atual].variaveis.tempo - carro[carro_atual].variaveis.tempo_hora) * 60;
            // Custo total
            carro[carro_atual].variaveis.valor_total = (carro[carro_atual].variaveis.ener_consumida * 2 + 1.80) * f_fator_horario(carro[carro_atual]);
            // Porcentagem que será carregada
            carro[carro_atual].variaveis.porcentagem_f = 100 - carro[carro_atual].porcentagem;

            carro[carro_atual].ID = carro_atual + 1;
            carro_atual++;

            printf("\n");
            close(fechar);

            printf("\n");
            printf("Informacoes salvas com sucesso!\n");
            printf("\n");
            break;

        case 2:

            printf("=========================\n");
            printf("     LISTA DE SESSOES\n");
            printf("=========================\n");

            for (int i = 0; i < carro_atual; i++)
            {

                printf("\n");
                printf("CARRO %d\n", i + 1);
                printf("-------------------------\n");
                printf("Horario da recarga: %d hora\n", carro[i].hora);
                printf("kWh do carro: %.2f\n", carro[i].total_kwh);
                printf("Porcentagem a carregar: %.0f%%\n", carro[i].variaveis.porcentagem_f);
                printf("Energia consumida: %.2f kWh\n", carro[i].variaveis.ener_consumida);
                printf("Tempo estimado: %d hora e %d minutos\n", carro[i].variaveis.tempo_hora, carro[i].variaveis.tempo_min);
                printf("Custo total: R$%.2f\n", carro[i].variaveis.valor_total);
                printf("-------------------------\n");
            }
            printf("\n");

            printf("\n");
            close(fechar);

            break;

        case 3:

            printf("=========================\n");
            printf("     BUSCAR SESSAO\n");
            printf("=========================\n");
            printf("\n");
            printf("Digite o ID da sessao: ");
            scanf("%d", &ID);

            int resultado = buscar_linear(carro, carro_atual, ID);

            if (resultado != -1)
            {
                printf("     SESSAO ENCONTRADA\n");
                printf("----------------------------\n");
                printf("\n");
                printf("CARRO %d\n", resultado + 1);
                printf("-------------------------\n");
                printf("Horario da recarga: %d hora\n", carro[resultado].hora);
                printf("kWh do carro: %.2f\n", carro[resultado].total_kwh);
                printf("Porcentagem a carregar: %.0f%%\n", carro[resultado].variaveis.porcentagem_f);
                printf("Energia consumida: %.2f kWh\n", carro[resultado].variaveis.ener_consumida);
                printf("Tempo estimado: %d hora e %d minutos\n", carro[resultado].variaveis.tempo_hora, carro[resultado].variaveis.tempo_min);
                printf("Custo total: R$%.2f\n", carro[resultado].variaveis.valor_total);
                printf("-------------------------\n");
            }
            else
            {
                printf("CARRO NAO ENCONTRADO\n");
            }

            close(fechar);

            break;

        case 4:
            menu_ordem();
            scanf("%d", &criterio);

            Ordenacao_bubble(carro, carro_atual, criterio);

            printf("Ordenacao concluida\n");

            listar_sessoes(carro, carro_atual);

            printf("\n");
            close(fechar);
            break;

        case 5:
            printf("=========================\n");
            printf("     ESTATISTICAS\n");
            printf("=========================\n");
            int qt_sessoes = 0;
            Ordenacao_bubble(carro, carro_atual, 1);
            qt_sessoes = carro[carro_atual - 1].ID;
            printf("\nSessoes realizadas: %d\n", qt_sessoes);

            float soma_ener = 0;
            for (int i = 0; i < carro_atual; i++)
            {
                soma_ener = soma_ener + carro[i].variaveis.ener_consumida;
            }
            printf("Energia fornecida: %.2f kWh\n", soma_ener);

            float soma_fatu = 0;
            for (int i = 0; i < carro_atual; i++)
            {
                soma_fatu = soma_fatu + carro[i].variaveis.valor_total;
            }
            printf("Faturamento: R$ %.2f\n", soma_fatu);

            float custo_medio = soma_fatu / qt_sessoes;
            printf("Custo medio: R$ %.2f\n\n", custo_medio);

            Ordenacao_bubble(carro, carro_atual, 2);
            maior_consumo = carro[carro_atual - 1].variaveis.ener_consumida;
            menor_consumo = carro[1].variaveis.ener_consumida;

            printf("Maior consumo: %.2f kwh\n", maior_consumo);
            printf("Menor consumo: %.2f kwh\n", menor_consumo);

            printf("\n");
            close(fechar);
            break;

        case 6:
            printf("Enviando dados da sessao...\n");
            printf("Dados enviados com sucesso!\n");
            printf("---- Fim da Simulacao ----\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}