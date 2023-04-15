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

    Type_I* vetor_I;
    Type_R* vetor_R;
    Type_S* vetor_S;

    // Tipo I addi, andi, ori, lw, lb, lh
    // Tipo R add, sub, and, or, xor, sll e srl
    // Tipo S sw, sb e sh
    
    vetor_I = (Type_I*) malloc(sizeof(Type_I));


    instrucoes_tipo_I->nome_Instrucao = *string;
    printf("%s\n", &instrucoes_tipo_I->nome_Instrucao[0]);

    char* endereco_entrada;

    endereco_entrada = (char*) malloc(50*sizeof(char));
    strcpy(endereco_entrada, "./stdin/assembly.asm");

    abre_Arquivo(&arq_Entrada, &arq_Saida, endereco_entrada);

    free(endereco_entrada);
    
    while (le_Linha(arq_Entrada));

    fclose(arq_Entrada);

    //fclose(arq_Saida);
    return 0;
}
