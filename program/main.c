#include "montador.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *arq_Entrada;
    FILE *arq_Saida;

    Type_I vetor_I[6];
    Type_R vetor_R[7];
    Type_S vetor_S[3];

    // Tipo I addi, andi, ori, lw, lb, lh, -> 6 
    // Tipo R add, sub, and, or, xor, sll e srl -> 7
    // Tipo S sw, sb e sh -> 3
    // Pseudo instruções li, mv, j, o binário gerado é o mesmo que numa lógica padrão;
    // Por exemplo -> MV tem o mesmo binario que add x19, x19, x0
    
    char instrucoes_I[6][4] = {"addi", "andi", "ori", "lw", "lb", "lh"};
    char instrucoes_R[7][3] = {"add", "sub", "and", "or", "xor", "sll", "srl"};
    char instrucoes_S[3][3] = {"sw", "sb", "sh"};

    
    char *p;

    int cont = 0;
    for (p = &instrucoes_I[0][0]; p < &instrucoes_I[6][0]; p += 4) {
        if (strlen(p) > 4) {
            for (int i = 0; i < 4; i++) {
                printf("%c", p[i]);
            }
            printf(" ");
        }
        else printf("%s ", p);
        //strcpy(vetor_I->nome_Instrucao, p);
    
    }
    printf("\n");


    for (p = &instrucoes_R[0][0]; p < &instrucoes_R[7][0]; p += 3) {
        if (strlen(p) > 3) {
            for (int i = 0; i < 3; i++) {
                printf("%c", p[i]);
            }
            printf(" ");
        }
        else printf("%s ", p);
        
        //strcpy(vetor_I->nome_Instrucao, p);
    }

    printf("\n");

    cont = 0;
    for (p = &instrucoes_S[0][0]; p < &instrucoes_S[3][0]; p += 3) {
        printf("%s ", p);
        strcpy(*(vetor_S)->nome_Instrucao, p);
        cont++;
    }

    //printf("%s", &vetor_I->nome_Instrucao);
    //printf("%s", (*vetor_I+1)->nome_Instrucao);
    printf("\n");
/*
    for (j = &vetor_R[0]; j < &vetor_R[7]; j++) {
        int cont = 0;
        strcpy((*j)->nome_Instrucao, *(instrucoes_R+cont));
        cont++;
    }

    for (k = &vetor_S[0]; k < &vetor_S[3]; k++) {
        int cont = 0;
        strcpy((*k)->nome_Instrucao, *(instrucoes_S+cont));
        cont++;
    } 
*/

    char* endereco_entrada;

    endereco_entrada = (char*) malloc(50*sizeof(char));
    strcpy(endereco_entrada, "./stdin/assembly.asm");

    abre_Arquivo(&arq_Entrada, &arq_Saida, endereco_entrada);

    free(endereco_entrada);
    
    //while (le_Linha(arq_Entrada));

    fclose(arq_Entrada);

    //fclose(arq_Saida);
    return 0;
}
