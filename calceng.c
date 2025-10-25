/*
 * calceng.c
 * Arquivo de implementação (source) para a biblioteca de Cálculos de Engenharia.
 * Contém a lógica e a matemática de todas as funções declaradas em calceng.h.
 */

// Incluímos o "menu" (nosso próprio arquivo .h).
// Usamos "aspas" porque é um arquivo local do nosso projeto, 
// e não uma biblioteca do sistema (como <math.h>).
#include "calceng.h"


/*
 * =============================================================================
 * Seção 1: Cálculos de Áreas [Requisito 1]
 * =============================================================================
 */

/**
 * @brief Implementação do cálculo de área do retângulo.
 */
double area_retangulo(double base, double altura) {
    // Requisito: Validação de entrada
    if (base < 0 || altura < 0) {
        return -1.0; // Retorna -1.0 para indicar um erro (área não pode ser negativa)
    }
    return base * altura;
}

/**
 * @brief Implementação do cálculo de área do triângulo.
 */
double area_triangulo(double base, double altura) {
    // Requisito: Validação de entrada
    if (base < 0 || altura < 0) {
        return -1.0;
    }
    return (base * altura) / 2.0;
}

/**
 * @brief Implementação do cálculo de área do círculo.
 * Usa a constante M_PI da biblioteca <math.h> (incluída via calceng.h).
 */
double area_circulo(double raio) {
    // Requisito: Validação de entrada
    if (raio < 0) {
        return -1.0;
    }
    // M_PI é a constante para Pi (aprox. 3.14159...)
    return M_PI * (raio * raio);
}

/*
 * =============================================================================
 * Seção 2: Cálculos de Volumes [Requisito 2]
 * =============================================================================
 */

/**
 * @brief Implementação do cálculo de volume de prisma retangular.
 */
double volume_prisma_retangular(double area_base, double altura) {
    // Requisito: Validação de entrada
    if (area_base < 0 || altura < 0) {
        return -1.0;
    }
    return area_base * altura;
}

/**
 * @brief Implementação do cálculo de volume de cilindro.
 */
double volume_cilindro(double raio, double altura) {
    // Requisito: Validação de entrada
    if (raio < 0 || altura < 0) {
        return -1.0;
    }
    // Volume = (Área da base circular) * Altura
    double area_base_circular = area_circulo(raio);
    return area_base_circular * altura;
}

/*
 * =============================================================================
 * Seção 3: Conversões de Unidades [Requisito 3]
 * =============================================================================
 */

/**
 * @brief Converte metros para centímetros.
 */
double converter_metros_para_cm(double metros) {
    // Validação: Embora distâncias negativas possam existir em física,
    // para engenharia/arquitetura, geralmente lidamos com medidas positivas.
    // Vamos validar por via das dúvidas.
    if (metros < 0) {
        return -1.0;
    }
    return metros * 100.0;
}

/**
 * @brief Converte centímetros para metros.
 */
double converter_cm_para_metros(double cm) {
    if (cm < 0) {
        return -1.0;
    }
    return cm / 100.0;
}

/**
 * @brief Converte metros para milímetros.
 */
double converter_metros_para_mm(double metros) {
    if (metros < 0) {
        return -1.0;
    }
    return metros * 1000.0;
}

/**
 * @brief Converte milímetros para metros.
 */
double converter_mm_para_metros(double mm) {
    if (mm < 0) {
        return -1.0;
    }
    return mm / 1000.0;
}


/*
 * =============================================================================
 * Seção 4: Estimativas de Materiais [Requisito 4]
 * =============================================================================
 */

/**
 * @brief Estima a quantidade de tijolos para uma parede.
 * Nota: Retorna int (número de tijolos), não double.
 */
int estimar_quantidade_tijolos(double area_parede, double area_tijolo) {
    // Requisito: Validação de entrada
    if (area_parede <= 0 || area_tijolo <= 0) {
        return -1; // Retorna -1 (int) para indicar erro
    }
    
    // Cálculo simples. Em um projeto real, adicionaríamos uma % para perdas/juntas.
    // O professor não especificou, então fazemos o cálculo direto.
    // Usamos a função ceil() de <math.h> para arredondar para CIMA.
    // Não podemos ter "meio tijolo" faltando, sempre compramos a mais.
    
    // `math.h` já está incluído através do `calceng.h`, então podemos usar `ceil`.
    
    double tijolos_exatos = area_parede / area_tijolo;
    int tijolos_necessarios = (int)ceil(tijolos_exatos); // ceil() vem de math.h
    
    return tijolos_necessarios;
}

/*
 * =============================================================================
 * Seção 5: Cálculos Estruturais Simples [Requisito 5]
 * =============================================================================
 */

/**
 * @brief Calcula o peso estimado de uma viga de concreto.
 */
double calcular_peso_viga_concreto(double volume_viga, double densidade_concreto) {
    // Requisito: Validação de entrada
    if (volume_viga < 0 || densidade_concreto <= 0) {
        return -1.0;
    }
    // Fórmula: Peso = Volume * Densidade
    return volume_viga * densidade_concreto;
}