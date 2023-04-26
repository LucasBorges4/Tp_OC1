#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>

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

//Funções Primordiais

char* instruct_Converter_to_Binary(char* str);

size_t octal_to_binary(size_t octal);
size_t hexa_to_binary(char* hexa);
size_t decimal_to_Binary(size_t decimal);

int shift_Num(int num);

//Funções de leitura de arquivo

void abre_Arquivo(FILE** arqEntrada, FILE** arqSaida, char* endereco_Entrada);
//void fecha_Arquivo(FILE arqEntrada, FILE arqSaida);

short le_Linha(FILE* arqEntrada, Type_I vetor_I, Type_R vetor_R, Type_S vetor_S);
short le_instrucao_R(Type_R *montador, char* str);
short le_instrucao_S(Type_S *montador, char* str);
short le_instrucao_I(Type_I *montador, char* str);
short pesquisa_instrução(char* str, Type_I** montador_I, Type_R** montador_R, Type_S** montador_S, 
    Type_I** convert_I, Type_R** convert_R, Type_S** convert_S);


char* adicionar_zeros_esquerda(int binario,int num_bits);
