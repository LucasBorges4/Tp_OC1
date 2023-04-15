#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//Funções Primordiais

char concatenar_String(char* str_A, char* str_B);
char* instruct_Converter_to_Binary(char* str);
int decimal_to_Binary(int decimal);
int shift_Num(int num);

//Funções de leitura de arquivo
void abre_Arquivo(FILE** arqEntrada, FILE** arqSaida, char* endereco_Entrada);
void fecha_Arquivo(FILE arqEntrada, FILE arqSaida);
short le_Linha(FILE* arqEntrada);