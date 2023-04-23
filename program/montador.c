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


/*
while (octal[i] != '\0') {
        
        resultado += octal%2 * pow(10, i);
        octal/=2;
        i++;
    }

*/



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

/*Funções de leitura de arquivo*/

short le_Linha(FILE *arqEntrada){
    //Declara a string para a linha, aloca e armazena a linha
    char *linha;
    short TAM_linha = 100;

    linha = (char*) malloc(TAM_linha*sizeof(char));
    fgets(linha, TAM_linha, arqEntrada);

    //Mede o tamanho da 'string' lida no arquivo;
    TAM_linha = strlen(linha);
    
    // Realloca memoria da variavel linha de acordo com o tamanho;
    linha = realloc(linha, TAM_linha*sizeof(char));
    
    //Caso não tenha memoria retorna um erro e a função acaba;
    if (linha == NULL) {
        printf("Fim da leitura!\n");
        return 0;
    }
    //Lê a linha;
    printf("%s\n", linha);

    //Libera memoria e retorna;
    free(linha);
    return 1;
}

void fecha_arquivo(FILE* arqEntrada,FILE* arqSaida){
    fclose(arqSaida);
    fclose(arqEntrada);
}

char* adicionar_zeros_esquerda(int binario,int num_bits){
    char *str= (char*)malloc(sizeof(char)*num_bits);
     sprintf(str, "%0*d", num_bits,binario);
     return str;
}
