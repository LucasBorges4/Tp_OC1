#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//Funções Primordiais

char concatenar_string(char* str_A, char* str_B);
char* instruct_Converter_to_Binary(char* str);
int decimal_to_binary(int decimal);
void shift_num(int num);

//Funções de leitura de arquivo
void abre_arquivo(FILE *arqEntrada, FILE *arqSaida);
void fecha_arquivo(FILE *arqEntrada, FILE *arqSaida);
short le_linha(FILE* arqEntrada);