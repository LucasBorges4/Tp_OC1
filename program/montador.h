#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>


#define NUM_INSTRUCT_TYPE_I 6
#define NUM_INSTRUCT_TYPE_R 7
#define NUM_INSTRUCT_TYPE_S 3
#define NUM_INSTRUCT_TYPE_B 4


typedef struct Type_R { 
    /*Struct para instrucoes do tipo R
    Contem:
    -Nome da instrucao
    -Funct7 da instrucao(7bits)
    -Rs1(Primeiro registrador)(5bits)
    -Rs2(Segundo registrador)(5bits)
    -Funct3 da instrucao(3bits)
    -Rd(Registrador de destino)(5bits)
    -Opcode da instrucao(7bits)
    */
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
       /*Struct para instrucoes do tipo I
    Contem:
    -Nome da instrucao
    -Imediato da instrucao(12bits)
    -Rs1(Primeiro registrador)(5bits)
    -Rd(Registrador de destino)(5bits)
    -Opcode da instrucao(7bits)
    */
    
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
     /*Struct para instrucoes do tipo S
    Contem:
    -Nome da instrucao 
    -Imediato da instrucao(12bits)  //Primeira parte- 7bits  Segunda parte - 5bits
    -Rs1(Primeiro registrador)(5bits)
    -Rs2(Segundo registrador)(5bits)
    -Funct3 da instrucao(3bits)
    -Rd(Registrador de destino)
    -Opcode da instrucao(7bits)
    */
    
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

typedef struct TipoB {
       /*Struct para instrucoes do tipo B
    Contem:
    -Nome da instrucao
    -Imediato da instrucao(12bits)
    -Rs1(Primeiro registrador)(5bits)
    -Rd(Registrador de destino)(5bits)
    -Opcode da instrucao(7bits)
    */
    
    //Estrutura da instrução;
    char nome_Instrucao[6];
    int immediate_7; // 31 - 25
    int immediate_5; // 11 - 6
    int Rs1_5; // 19 - 15
    int funct_3; // 14 - 12
    int Rs2_5; // 11 - 7
    int opcode_7; // 6 - 0
    
} Type_B;

//Funções dos Tipos

/* */

//Funções Primordiais

char* instruct_Converter_to_Binary(char* str);

size_t octal_to_binary(size_t octal);
size_t hexa_to_binary(char* hexa);
size_t decimal_to_Binary(size_t decimal);
//size_t decimal_to_Binary_neg(char* num);

int shift_Num(int num);

//Funções de leitura de arquivo

void abre_Arquivo(FILE** arqEntrada, FILE** arqSaida, char* endereco_Entrada);
//void fecha_Arquivo(FILE arqEntrada, FILE arqSaida);

short le_Linha(FILE* arqEntrada, Type_I* vetor_I, Type_R* vetor_R, Type_S* vetor_S, Type_B *vetor_B, Type_I *Result_I, Type_R *Result_R, Type_S *Result_S, Type_B *Result_B);
short le_instrucao_R(Type_R *montador, char* str);
short le_instrucao_S(Type_S *montador, char* str);
short le_instrucao_I(Type_I *montador, char* str);
short pesquisa_instrução(char* str, Type_I* montador_I, Type_R* montador_R, Type_S* montador_S, Type_B *montador_B,
Type_I * Result_I,Type_R * Result_R,Type_S * Result_S,Type_B * Result_B);


char* adicionar_zeros_esquerda(int binario,int num_bits);
void set_registradores_S(Type_S * struct_S,int immediate,int Rs1,int Rs2);
void set_registradores_R(Type_R * struct_R,int Rd,int Rs1,int Rs2);
void set_registradores_I(Type_I * struct_I,int Rd,int immediate,int Rs1);
void set_registradores_B(Type_B * struct_B,int immediate,int Rs1,int Rs2);
int get_substring(char* string,int initial_pos,int length);
char *get_S_binary(Type_S struct_S);
char *get_I_binary(Type_I struct_I);
char *get_R_binary(Type_R struct_R);
char *get_B_binary(Type_B struct_B);
