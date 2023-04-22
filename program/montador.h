#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Type_R {
    // Nome
    char nome_Instrucao[6];
    //Estrutura da instrução;
    int funct_7; // 31 - 25
    int Rs2_5; // 24 - 20
    int Rs1_5; // 19 - 15
    int funct_3; // 14 - 12
    int Rd_5; // 11 - 7
    int opcode_7; // 6 - 0

    //Type of instruction "82"


} Type_R;

typedef struct Tipo_I {
    //Estrutura da instrução;
    char nome_Instrucao[6];
    int immediate_12; // 31 - 20
    int Rs1_5; // 19 - 15
    int funct_3; // 14 - 12
    int Rd_5; // 11 - 7
    int opcode_7; // 6 - 0

    //Type of instruction "73"
    

} Type_I;

typedef struct TipoS {
    //Estrutura da instrução;
    char nome_Instrucao[5];
    int immediate_7; // 31 - 25
    int Rs2_5; // 24 - 20
    int Rs1_5; // 19 - 15
    int funct_3; // 14 - 12
    int immediate_5; // 11 - 7
    int opcode_7; // 6 - 0;

    //Type of instruction "83"
    
} Type_S;

//Funções dos Tipos

/* */

Type_I construtor_binario_Tipo_I(Type_I* instrucao);
Type_R construtor_binario_Tipo_R(Type_R* instrucao);
Type_S construtor_binario_Tipo_S(Type_S* instrucao);







//Funções Primordiais

char* instruct_Converter_to_Binary(char* str);
int decimal_to_Binary(int decimal);
int shift_Num(int num);

//Funções de leitura de arquivo
void abre_Arquivo(FILE** arqEntrada, FILE** arqSaida, char* endereco_Entrada);
void fecha_Arquivo(FILE arqEntrada, FILE arqSaida);
short le_Linha(FILE* arqEntrada);
char* adicionar_zeros_esquerda(int binario,int num_bits);
