#include "montador.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decimal_to_binary(int decimal){
    int i = 0, resultado = 0;
    while (decimal != 0) {
        resultado += decimal%2 * pow(10, i);
        decimal/=2;
        i++;
    }
    return resultado;
}

void shift_num(int num){
    printf("%d << 1 = %d\n", num, num << 1);

}

void abre_arquivo(FILE* arqEntrada,FILE* arqSaida){
    arqEntrada = fopen("*.asm","r");
    arqSaida = fopen("saida.txt","a");
    if(arqEntrada == NULL || arqSaida == NULL){
        printf("Erro ao abrir arquivos!\n");
        exit(1);
    }
}

/*Funções de leitura de arquivo*/

short le_linha(FILE *arqEntrada){
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
        printf("Erro na função le_linha!\n");
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