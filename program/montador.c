#include "montador.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decimal_to_Binary(int decimal){
    int i = 0, resultado = 0;
    while (decimal != 0) {
        resultado += decimal%2 * pow(10, i);
        decimal/=2;
        i++;
    }
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
