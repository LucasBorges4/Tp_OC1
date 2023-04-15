#include "montador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *arq_Entrada;
    FILE *arq_Saida;

    Type_I* vetor_I;
    Type_R* vetor_R;
    Type_S* vetor_S;

    // Tipo I addi, andi, ori, lw, lb, lh, -> 6 
    // Tipo R add, sub, and, or, xor, sll e srl -> 7
    // Tipo S sw, sb e sh -> 3
    
    vetor_I = (Type_I*) malloc(6*sizeof(Type_I));
    vetor_R = (Type_R*) malloc(7*sizeof(Type_R));
    vetor_S = (Type_S*) malloc(3*sizeof(Type_S));

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
