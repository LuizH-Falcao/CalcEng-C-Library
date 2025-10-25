/*
 * main.c
 * Programa principal para demonstrar e testar a biblioteca calceng.
 * Contém um menu interativo que chama as funções da biblioteca.
 */

// Bibliotecas padrão do C para entrada/saída (printf, scanf)
// e para funções utilitárias (system)
#include <stdio.h>
#include <stdlib.h>

// A NOSSA BIBLIOTECA!
// Incluímos o arquivo de cabeçalho que define as "promessas"
// das nossas funções.
#include "calceng.h"

// Protótipos de funções auxiliares (APENAS para o menu no main.c)
// É uma boa prática declarar as funções que vamos usar no main
// antes de usá-las.
void exibir_menu_principal();
void limpar_tela();
void pausar_tela();

// Funções para os sub-menus
void menu_areas();
void menu_volumes();
void menu_conversoes();
void menu_materiais();
void menu_estruturas();


/*
 * Função principal do programa
 */
int main() {
    int escolha = 0;

    // Loop infinito do menu principal.
    // O loop só será quebrado quando o usuário digitar 6 (Sair).
    while (1) {
        limpar_tela();
        exibir_menu_principal();

        // Lê a escolha do usuário
        // O %*c é um truque para consumir a quebra de linha (Enter)
        // que fica no buffer de entrada, evitando bugs no scanf.
        if (scanf("%d%*c", &escolha) != 1) {
            // Se o usuário não digitar um número, limpamos a entrada
            // e reiniciamos o loop.
            printf("Entrada invalida. Por favor, digite um numero.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n'); 
            pausar_tela();
            continue; // Volta ao início do 'while'
        }

        // Analisa a escolha do usuário
        switch (escolha) {
            case 1:
                menu_areas(); // Chama o sub-menu de áreas
                break;
            case 2:
                menu_volumes(); // Chama o sub-menu de volumes
                break;
            case 3:
                menu_conversoes(); // Chama o sub-menu de conversões
                break;
            case 4:
                menu_materiais(); // Chama o sub-menu de materiais (tijolos)
                break;
            case 5:
                menu_estruturas(); // Chama o sub-menu de estruturas (viga)
                break;
            case 6:
                printf("Obrigado por usar a CalcEng. Saindo...\n");
                return 0; // Termina o programa com sucesso
            default:
                printf("Opcao invalida! Pressione Enter para tentar novamente.\n");
                pausar_tela();
                break;
        }
    } // Fim do while(1)

    return 0;
}


/*
 * =============================================================================
 * Funções Auxiliares do Menu (para organizar o main)
 * =============================================================================
 */

/**
 * @brief Apenas exibe as opções do menu principal.
 */
void exibir_menu_principal() {
    printf("========================================\n");
    printf("     Biblioteca CalcEng v1.0\n");
    printf("========================================\n");
    printf("Escolha uma categoria:\n\n");
    printf("  1. Calculos de Areas\n");
    printf("  2. Calculos de Volumes\n");
    printf("  3. Conversoes de Unidades\n");
    printf("  4. Estimativa de Materiais\n");
    printf("  5. Calculos Estruturais Simples\n");
    printf("  6. Sair\n\n");
    printf("Digite sua escolha: ");
}

/**
 * @brief Limpa a tela do console.
 * Funciona em Windows ("cls") e Linux/Mac ("clear").
 */
void limpar_tela() {
    // system("cls") para Windows, system("clear") para Linux/Mac
    // Esta é uma forma simples de fazer isso.
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * @brief Pausa o programa esperando o usuário pressionar Enter.
 */
void pausar_tela() {
    printf("\nPressione Enter para continuar...");
    // Lê e descarta todos os caracteres até encontrar um Enter ('\n')
    while (getchar() != '\n');
}

/*
 * =============================================================================
 * Funções dos Sub-Menus (onde chamamos a biblioteca)
 * =============================================================================
 */

/**
 * @brief Sub-menu para cálculos de área.
 */
void menu_areas() {
    int escolha_area = 0;
    double base, altura, raio, resultado;

    limpar_tela();
    printf("--- Calculos de Areas ---\n");
    printf("  1. Area do Retangulo\n");
    printf("  2. Area do Triangulo\n");
    printf("  3. Area do Circulo\n");
    printf("  4. Voltar ao Menu Principal\n");
    printf("Digite sua escolha: ");
    
    if (scanf("%d%*c", &escolha_area) != 1) {
        printf("Entrada invalida.\n");
        while (getchar() != '\n');
        pausar_tela();
        return;
    }

    switch (escolha_area) {
        case 1: // Retângulo
            printf("Digite a base: ");
            scanf("%lf%*c", &base);
            printf("Digite a altura: ");
            scanf("%lf%*c", &altura);

            // Chamando a função da NOSSA BIBLIOTECA
            resultado = area_retangulo(base, altura);

            // Verificação de erro (requisito!) 
            if (resultado == -1.0) {
                printf("Erro: Entradas invalidas (valores nao podem ser negativos).\n");
            } else {
                printf("A area do retangulo e: %.2f\n", resultado);
            }
            break;

        case 2: // Triângulo
            printf("Digite a base: ");
            scanf("%lf%*c", &base);
            printf("Digite a altura: ");
            scanf("%lf%*c", &altura);
            
            resultado = area_triangulo(base, altura);

            if (resultado == -1.0) {
                printf("Erro: Entradas invalidas (valores nao podem ser negativos).\n");
            } else {
                printf("A area do triangulo e: %.2f\n", resultado);
            }
            break;

        case 3: // Círculo
            printf("Digite o raio: ");
            scanf("%lf%*c", &raio);

            resultado = area_circulo(raio);

            if (resultado == -1.0) {
                printf("Erro: Entrada invalida (raio nao pode ser negativo).\n");
            } else {
                printf("A area do circulo e: %.2f\n", resultado);
            }
            break;
        
        case 4: // Voltar
            return;

        default:
            printf("Opcao invalida!\n");
            break;
    }
    pausar_tela();
}

/**
 * @brief Sub-menu para cálculos de volume.
 */
void menu_volumes() {
    int escolha_vol = 0;
    double area_base, altura, raio, resultado;

    limpar_tela();
    printf("--- Calculos de Volumes ---\n");
    printf("  1. Volume do Prisma Retangular\n");
    printf("  2. Volume do Cilindro\n");
    printf("  3. Voltar ao Menu Principal\n");
    printf("Digite sua escolha: ");
    
    if (scanf("%d%*c", &escolha_vol) != 1) {
        printf("Entrada invalida.\n");
        while (getchar() != '\n');
        pausar_tela();
        return;
    }

    switch (escolha_vol) {
        case 1: // Prisma
            printf("Digite a area da base: ");
            scanf("%lf%*c", &area_base);
            printf("Digite a altura: ");
            scanf("%lf%*c", &altura);

            resultado = volume_prisma_retangular(area_base, altura);

            if (resultado == -1.0) {
                printf("Erro: Entradas invalidas (valores nao podem ser negativos).\n");
            } else {
                printf("O volume do prisma e: %.2f\n", resultado);
            }
            break;

        case 2: // Cilindro
            printf("Digite o raio da base: ");
            scanf("%lf%*c", &raio);
            printf("Digite a altura: ");
            scanf("%lf%*c", &altura);
            
            resultado = volume_cilindro(raio, altura);

            if (resultado == -1.0) {
                printf("Erro: Entradas invalidas (valores nao podem ser negativos).\n");
            } else {
                printf("O volume do cilindro e: %.2f\n", resultado);
            }
            break;
        
        case 3: // Voltar
            return;

        default:
            printf("Opcao invalida!\n");
            break;
    }
    pausar_tela();
}

/**
 * @brief Sub-menu para conversões.
 */
void menu_conversoes() {
    int escolha_conv = 0;
    double valor, resultado;

    limpar_tela();
    printf("--- Conversoes de Unidades ---\n");
    printf("  1. Metros (m) para Centimetros (cm)\n");
    printf("  2. Centimetros (cm) para Metros (m)\n");
    printf("  3. Metros (m) para Milimetros (mm)\n");
    printf("  4. Milimetros (mm) para Metros (m)\n");
    printf("  5. Voltar ao Menu Principal\n");
    printf("Digite sua escolha: ");
    
    if (scanf("%d%*c", &escolha_conv) != 1) {
        printf("Entrada invalida.\n");
        while (getchar() != '\n');
        pausar_tela();
        return;
    }

    // Só pedimos o valor se a opção for válida (1 a 4)
    if (escolha_conv >= 1 && escolha_conv <= 4) {
        printf("Digite o valor a ser convertido: ");
        scanf("%lf%*c", &valor);
    }

    switch (escolha_conv) {
        case 1: // m para cm
            resultado = converter_metros_para_cm(valor);
            if(resultado == -1.0) {
                 printf("Erro: Valor nao pode ser negativo.\n");
            } else {
                 printf("%.2f m = %.2f cm\n", valor, resultado);
            }
            break;
        case 2: // cm para m
            resultado = converter_cm_para_metros(valor);
             if(resultado == -1.0) {
                 printf("Erro: Valor nao pode ser negativo.\n");
            } else {
                 printf("%.2f cm = %.2f m\n", valor, resultado);
            }
            break;
        case 3: // m para mm
            resultado = converter_metros_para_mm(valor);
             if(resultado == -1.0) {
                 printf("Erro: Valor nao pode ser negativo.\n");
            } else {
                 printf("%.2f m = %.2f mm\n", valor, resultado);
            }
            break;
        case 4: // mm para m
            resultado = converter_mm_para_metros(valor);
             if(resultado == -1.0) {
                 printf("Erro: Valor nao pode ser negativo.\n");
            } else {
                 printf("%.2f mm = %.2f m\n", valor, resultado);
            }
            break;
        case 5: // Voltar
            return;
        default:
            printf("Opcao invalida!\n");
            break;
    }
    pausar_tela();
}

/**
 * @brief Sub-menu para estimativa de tijolos.
 */
void menu_materiais() {
    double area_parede, area_tijolo;
    int resultado; // A função de tijolos retorna int!

    limpar_tela();
    printf("--- Estimativa de Materiais ---\n");
    printf("Estimativa de Quantidade de Tijolos\n\n");

    printf("Digite a area total da parede (em metros quadrados): ");
    scanf("%lf%*c", &area_parede);
    printf("Digite a area de UM tijolo (em metros quadrados): ");
    scanf("%lf%*c", &area_tijolo);

    // Chamando a função da biblioteca
    resultado = estimar_quantidade_tijolos(area_parede, area_tijolo);

    // Verificação de erro (requisito!) 
    if (resultado == -1) { // Usamos -1 (int) e não -1.0 (double)
        printf("Erro: Areas nao podem ser zero ou negativas.\n");
    } else {
        printf("Voce precisara de aproximadamente %d tijolos.\n", resultado);
        printf("(Este calculo arredonda para cima, sem contar perdas/juntas.)\n");
    }
    
    pausar_tela();
}

/**
 * @brief Sub-menu para cálculo de peso da viga.
 */
void menu_estruturas() {
    double volume_viga, densidade_concreto, resultado;
    
    limpar_tela();
    printf("--- Calculos Estruturais Simples ---\n");
    printf("Calculo de Peso de Viga de Concreto\n\n");

    printf("Digite o volume da viga (em metros cubicos): ");
    scanf("%lf%*c", &volume_viga);
    printf("Digite a densidade do concreto (em kg/metro cubico): ");
    printf("(Padrao: ~2400 kg/metro cubico)\n");
    scanf("%lf%*c", &densidade_concreto);

    // Chamando a função da biblioteca
    resultado = calcular_peso_viga_concreto(volume_viga, densidade_concreto);

    // Verificação de erro (requisito!) 
    if (resultado == -1.0) {
        printf("Erro: Volume ou densidade nao podem ser negativos/zero.\n");
    } else {
        printf("O peso estimado da viga e: %.2f kg\n", resultado);
    }
    
    pausar_tela();
}