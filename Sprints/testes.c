#include <stdio.h>

// FUNÇÃO DO MENU
void menu(void){
    printf("================================\n");
    printf("    MENU - RECARGA DE BATERIA\n");
    printf("================================\n");
    printf("1 - Informacoes do carro\n");
    printf("2 - Energia consumida\n");
    printf("3 - Tempo estimado de recarga\n");
    printf("4 - Custo da recarga\n");
    printf("5 - Relatorio de uso\n");
    printf("6 - Adicionar outro carro\n");
    printf("7 - Fim da Simulacao\n");
    printf("Escolha uma opcao: ");
}

// FUNÇÃO DE FECHAR
void close(int fechar){
    printf("Para voltar ao menu digite 0\n");
    scanf("%d", &fechar);
        while(fechar != 0){
            printf("Para voltar ao menu digite 0\n");
            scanf("%d", &fechar);
            switch(fechar){
                case 0:
                    break;}
                }
            }

// CÓDIGO PRINCIPAL
int main(){

    int opcao;
    int fechar=1;
    int carro_atual=0;

    float fator_tempo=1.0;
    float fator_horario=1.0;
    // Vetores para armazenar varios carros
    float total_kwh[100];
    float porcentagem[100];
    float ener_consumida[100];
    float valor_total[100];
    float tempo[100];
    int tempo_hora[100];
    int tempo_min[100];
    float porcentagem_f[100];
    int hora[100];

    while(opcao != 7){

        menu();
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao){

            case 1:

                printf("=========================\n");
                printf("  Informacoes do carro\n");
                printf("=========================\n");

                printf("Quantos kWh cabem no carro:\n");
                scanf("%f", &total_kwh[carro_atual]);

                printf("Porcentagem de energia do carro:\n");
                scanf("%f", &porcentagem[carro_atual]);

                // Validação da porcentagem
                while(porcentagem[carro_atual] < 0 || porcentagem[carro_atual] > 100){
                    printf("PORCENTAGEM INVALIDA!");
                    printf("A porcentagem esta errada, digite novamente (0 ate 100):\n");
                    scanf("%f", &porcentagem[carro_atual]);
                }

                printf("Digite o horario da recarga em horas (0 ate 23):\n");
                scanf("%d", &hora[carro_atual]);

                // Validação do horario
                while(hora[carro_atual] < 0 || hora[carro_atual] > 23){
                    printf("HORARIO INVALIDO!");
                    printf("Digite o horario da recarga em horas (0 ate 23):\n");
                    scanf("%d", &hora[carro_atual]);
                }

                if(carro_atual > 9){
                    printf("\n");
                    printf("ERRO NO SISTEMA!\n");
                    printf("Quantidade maxima excedida!\n");
                    printf("O sistema foi desligado instantaneamente.\n");
                    printf("Dados da sessao perdidos!\n");
                    return 0;
                }

                // Calculos 

                // Taxa por carro

                if(carro_atual > 8){
                    fator_tempo = 2.0;
                }else if(carro_atual > 5){
                    fator_tempo = 1.5;
                }else if(carro_atual > 2){
                    fator_tempo = 1.2;
                }

                // Taxa do horario
                
                if(6 < hora[carro_atual] && hora[carro_atual] <= 10){
                    fator_horario=1.1;
                }else if(16 < hora[carro_atual] && hora[carro_atual] <= 21){
                    fator_horario=1.1;
                }else{fator_horario=1.0;}

                // Energia consumida pelo carro
                ener_consumida[carro_atual] = total_kwh[carro_atual] - total_kwh[carro_atual] * (porcentagem[carro_atual] / 100);
                // Tempo da recarga em horas
                tempo[carro_atual] = (ener_consumida[carro_atual] / 50) * fator_tempo;
                // Tempo da recarga em horas inteiro
                tempo_hora[carro_atual] = (int)(ener_consumida[carro_atual] / 50) * fator_tempo;
                // Minutos da recarga
                tempo_min[carro_atual] = (tempo[carro_atual] - tempo_hora[carro_atual]) * 60;
                // Custo total
                valor_total[carro_atual] = (ener_consumida[carro_atual] * 2 + 1.80) * fator_horario;
                // Porcentagem que será carregada
                porcentagem_f[carro_atual] = 100 - porcentagem[carro_atual];

                printf("\n");
                close(fechar);

                printf("\n");
                printf("Informacoes salvas com sucesso!\n");
                printf("\n");
                break;

            case 2:

                printf("=========================\n");
                printf("    Energia consumida\n");
                printf("=========================\n");

                printf("Energia consumida: %.2f kWh\n", ener_consumida[carro_atual]);
                printf("\n");

                printf("\n");
                close(fechar);

                break;

            case 3:

                printf("=========================\n");
                printf("Tempo estimado de recarga\n");
                printf("=========================\n");

                printf("Tempo de recarga: %d hora e %d minutos\n", tempo_hora[carro_atual], tempo_min[carro_atual]);
                printf("\n");

                printf("\n");
                close(fechar);

                break;

            case 4:

                printf("=========================\n");
                printf("    Custo da recarga\n");
                printf("=========================\n");

                printf("Custo total: R$%.2f\n", valor_total[carro_atual]);
                printf("\n");

                printf("\n");
                close(fechar);

                break;

            case 5:

                printf("=========================\n");
                printf("       RELATORIO\n");
                printf("=========================\n");

                for(int i = 0; i <= carro_atual; i++){

                    printf("\n");
                    printf("CARRO %d\n", i + 1);
                    printf("-------------------------\n");
                    printf("Horario da recarga: %d hora\n", hora[i]);
                    printf("kWh do carro: %.2f\n", total_kwh[i]);
                    printf("Porcentagem a carregar: %.0f%%\n", porcentagem_f[i]);
                    printf("Energia consumida: %.2f kWh\n", ener_consumida[i]);
                    printf("Tempo estimado: %d hora e %d minutos\n", tempo_hora[i], tempo_min[i]);
                    printf("Custo total: R$%.2f\n", valor_total[i]);
                    printf("-------------------------\n");
                }
                printf("\n");

                printf("\n");
                close(fechar);

                break;

            case 6:

                carro_atual++;

                printf("Novo carro selecionado!\n");
                printf("Agora cadastre as informacoes do novo carro.\n\n");

                printf("\n");
                close(fechar);

                break;

            case 7:
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