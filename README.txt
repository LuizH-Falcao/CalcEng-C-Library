=========================================
Projeto: Biblioteca CalcEng
=========================================

Autor: Luiz Henrique Poleto Falcão -- RA 844893
Disciplina: Laboratório de Práticas de Programação
Professor: Thiago Nicola Cajuela Garcia

=========================================
Descrição das Funções
=========================================

Esta biblioteca fornece funções de cálculo para engenharia e arquitetura:

* area_retangulo(base, altura): Calcula a área de um retângulo.
* area_triangulo(base, altura): Calcula a área de um triângulo.
* area_circulo(raio): Calcula a área de um círculo.
* volume_prisma_retangular(area_base, altura): Calcula o volume de um prisma.
* volume_cilindro(raio, altura): Calcula o volume de um cilindro.
* converter_metros_para_cm(metros): Converte metros para centímetros.
* converter_cm_para_metros(cm): Converte centímetros para metros.
* converter_metros_para_mm(metros): Converte metros para milímetros.
* converter_mm_para_metros(mm): Converte milímetros para metros.
* estimar_quantidade_tijolos(area_parede, area_tijolo): Estima a quantidade de tijolos para uma parede.
* calcular_peso_viga_concreto(volume_viga, densidade_concreto): Calcula o peso de uma viga de concreto.

=========================================
Instruções de Compilação e Execução
=========================================

O projeto foi desenvolvido e testado com o compilador GCC (MinGW-w64) no Windows.

1.  Abra um terminal (como PowerShell, cmd ou bash).
2.  Navegue até a pasta que contém os arquivos (main.c, calceng.c, calceng.h).
3.  Execute o seguinte comando para compilar o programa:

    gcc main.c calceng.c -o calceng

4.  O comando acima irá gerar um arquivo executável chamado "calceng.exe".
5.  Para executar o programa, digite no mesmo terminal:

    .\calceng.exe