/*
 * calceng.h
 * Arquivo de cabeçalho (header) para a biblioteca de Cálculos de Engenharia.
 * Contém as declarações de todas as funções públicas da biblioteca.
 * ALUNO: Luiz Henrique Poleto Falcão -- CÓDIGO 844893
 */

#define _USE_MATH_DEFINES  // Necessário para definir constantes matemáticas como M_PI (não é padrão C++)

// Estas são "Header Guards". Elas impedem que o conteúdo deste arquivo 
// seja incluído mais de uma vez, o que causaria erros de compilação.
#ifndef CALCENG_H
#define CALCENG_H

// Precisamos desta biblioteca para a constante M_PI (o número Pi)
#include <math.h>

/*
 * =============================================================================
 * Seção 1: Cálculos de Áreas [Requisito 1]
 * =============================================================================
 */

/**
 * @brief Calcula a área de um retângulo.
 * @param base A base do retângulo.
 * @param altura A altura do retângulo.
 * @return A área calculada. Retorna -1.0 se a entrada for inválida (negativa).
 */
double area_retangulo(double base, double altura); 

/**
 * @brief Calcula a área de um triângulo.
 * @param base A base do triângulo.
 * @param altura A altura do triângulo.
 * @return A área calculada. Retorna -1.0 se a entrada for inválida (negativa).
 */
double area_triangulo(double base, double altura);

/**
 * @brief Calcula a área de um círculo.
 * @param raio O raio do círculo.
 * @return A área calculada. Retorna -1.0 se a entrada for inválida (negativa).
 */
double area_circulo(double raio);

/*
 * =============================================================================
 * Seção 2: Cálculos de Volumes [Requisito 2]
 * =============================================================================
 */

/**
 * @brief Calcula o volume de um prisma de base retangular.
 * @param area_base A área da base do prisma.
 * @param altura A altura do prisma.
 * @return O volume calculado. Retorna -1.0 se a entrada for inválida (negativa).
 */
double volume_prisma_retangular(double area_base, double altura);

/**
 * @brief Calcula o volume de um cilindro.
 * @param raio O raio da base do cilindro.
 * @param altura A altura do cilindro.
 * @return O volume calculado. Retorna -1.0 se a entrada for inválida (negativa).
 */
double volume_cilindro(double raio, double altura); 

/*
 * =============================================================================
 * Seção 3: Conversões de Unidades [Requisito 3]
 * =============================================================================
 */

/**
 * @brief Converte metros para centímetros.
 * @param metros Valor em metros.
 * @return O valor equivalente em centímetros.
 */
double converter_metros_para_cm(double metros);

/**
 * @brief Converte centímetros para metros.
 * @param cm Valor em centímetros.
 * @return O valor equivalente em metros.
 */
double converter_cm_para_metros(double cm);

/**
 * @brief Converte metros para milímetros.
 * @param metros Valor em metros.
 * @return O valor equivalente em milímetros.
 */
double converter_metros_para_mm(double metros);

/**
 * @brief Converte milímetros para metros.
 * @param mm Valor em milímetros.
 * @return O valor equivalente em metros.
 */
double converter_mm_para_metros(double mm);


/*
 * =============================================================================
 * Seção 4: Estimativas de Materiais [Requisito 4]
 * =============================================================================
 */

/**
 * @brief Estima a quantidade de tijolos para uma parede simples.
 * @param area_parede A área total da parede (em metros quadrados).
 * @param area_tijolo A área de um único tijolo (em metros quadrados).
 * @return O número estimado de tijolos. Retorna -1 se a entrada for inválida.
 */
int estimar_quantidade_tijolos(double area_parede, double area_tijolo);

/*
 * =============================================================================
 * Seção 5: Cálculos Estruturais Simples [Requisito 5]
 * =============================================================================
 */

/**
 * @brief Calcula o peso estimado de uma viga de concreto.
 * @param volume_viga O volume da viga (em metros cúbicos).
 * @param densidade_concreto A densidade do concreto (em kg/m³).
 * @return O peso estimado da viga (em kg). Retorna -1.0 se a entrada for inválida.
 */
double calcular_peso_viga_concreto(double volume_viga, double densidade_concreto);


#endif // CALCENG_H