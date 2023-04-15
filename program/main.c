#include "montador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *arq_Entrada;
    FILE *arq_Saida;

    Type_I* instrucoes_tipo_I;
    Type_R* instrucoes_tipo_R;
    Type_S* instrucoes_tipo_S;
   
    char* endereco_entrada;

    endereco_entrada = (char*) malloc(50*sizeof(char));
    strcpy("./stdin/assembly.asm", endereco_entrada);
    
    abre_Arquivo(&arq_Entrada, &arq_Saida, endereco_entrada);
    
    free(endereco_entrada);
    le_Linha(arq_Entrada);

    while (le_Linha(arq_Entrada));
    
    fclose(arq_Entrada);
    //fclose(arq_Saida);
    return 0;
}