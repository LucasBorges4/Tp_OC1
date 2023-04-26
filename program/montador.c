#include "montador.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

size_t decimal_to_Binary(size_t decimal){
    size_t resultado = 0;
    u_short i = 0;
    while (decimal != 0) {
        resultado += decimal%2 * pow(10, i);
        decimal/=2;
        i++;
    }
    return resultado;
}


size_t octal_to_binary(size_t octal){
    size_t resultado = 0;
    u_short i = 0;

    while (octal != 0) {
        resultado += octal%10 * pow(8, i);
        i++;
        octal/=10;
    }
    resultado = decimal_to_Binary(resultado);
    return resultado;
}

size_t hexa_to_binary(char* hexa){
    size_t resultado = 0;
    u_short i = 0, temp, TAM;
    TAM = strlen(hexa);
    
    while (i < TAM) {
        if (hexa[i] >= 48 && hexa[i] <= 57) {
            temp = hexa[i] - 48;
            resultado += temp * pow(16, TAM - i - 1);
        }

        else if (hexa[i] >= 97 && hexa[i] <= 102) {
            temp = hexa[i] - 87;
            resultado += temp * pow(16, TAM - i - 1);
        }
        
        i++;
    }
    resultado = decimal_to_Binary(resultado);
    return resultado;
}


int shift_Num(int num){
    return num << 1;
}

void abre_Arquivo(FILE** arqEntrada,FILE** arqSaida, char* endereco_Entrada){
    
    *arqEntrada = fopen(endereco_Entrada,"r");
    *arqSaida = fopen("./assembly/binary","a");

    if(arqEntrada == NULL || arqSaida == NULL){
        printf("Erro ao abrir arquivos!\n");
        exit(1);
    }
}

short le_instrucao_I(Type_I* montador, char* str){
    for (int i = 0; i < 6; i++) {
        printf("%s ", montador[i].nome_Instrucao);
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) {
            return 1;
        }
    }
    return 0;
}

short le_instrucao_R(Type_R *montador, char* str){
    for (int i = 0; i < 7; i++) {
        printf("%s ", montador[i].nome_Instrucao);
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) {
            return 1;
        }
    }

    return 0;
}

short le_instrucao_S(Type_S *montador, char* str){
    for (int i = 0; i < 3; i++) {
        printf("%s ", montador[i].nome_Instrucao);
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) {
            return 1;
        }
    }
    return 0;
}

short pesquisa_instrução(char* str, Type_I** montador_I, Type_R** montador_R, Type_S** montador_S, 
    Type_I** convert_I, Type_R** convert_R, Type_S** convert_S){
        
    for (int i = 0; i < 7; i++) {
        if (le_instrucao_I(montador_I[i], str)){    
            
        }
      
    for (int i = 0; i < 3; i++) {
        if (le_instrucao_S(montador_S[i], str)) {
            return 1;
        }
    }

    for (int i = 0; i < 6; i++) {
        if (le_instrucao_R(montador_R[i], str)) {
            break;
        }
    }

    }

    
}


/*Funções de leitura de arquivo*/

short le_Linha(FILE *arqEntrada, Type_I vetor_I, Type_R vetor_R, Type_S vetor_S){
    //Declara a string para a linha, aloca e armazena a linha
    char *linha;
    short TAM_linha = 100;

    linha = (char*) malloc(TAM_linha*sizeof(char));
    fgets(linha, TAM_linha, arqEntrada);

    //Mede o tamanho da 'string' lida no arquivo;
    TAM_linha = strlen(linha);
    
    // Realloca memoria da variavel linha de acordo com o tamanho;
    linha = realloc(linha, TAM_linha*sizeof(char));
    
    //Caso não tenha nada na linha retorna um fim e a função sai;
    if (linha == NULL) {
        printf("Fim da leitura!\n");
        return 0;
    }
    //Lê a linha;
    const char delim[1] = " ";
    char *token;

    token = strtok(linha, delim);

    short i = 0;
    char str[4][5];

    while (token != NULL) {
        printf("%s\n", token);
        strcpy(str[i], token);
        token = strtok(NULL, delim);
        i++;
    }


    //Libera memoria e retorna;
    free(linha);
    return 1;
}

char* adicionar_zeros_esquerda(int binario,int num_bits){
    
    char *str = (char*)malloc(sizeof(char)*num_bits);
    sprintf(str, "%0*d", num_bits,binario);
    
    return str;
}
