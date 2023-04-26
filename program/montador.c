#include "montador.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

size_t decimal_to_Binary(size_t decimal){ //Funcao que objetiva receber um decimal e retornar um binario de tipo size_t(similar ao unsigned int)
    size_t resultado = 0; //Variavel para armazenar o resultado final(binario)
    u_short i = 0; 
    while (decimal != 0) {  //Loop termina quando o decimal for zero
        resultado += decimal%2 * pow(10, i); //Resultado recebe ele mesmo mais o resto da variavel decimal por 2 vezes a potencia 10^i
        decimal/=2; //Decimal reduzido na metade
        i++; //Incremento do indice i
    }
    return resultado;
}


size_t octal_to_binary(size_t octal){ //Funcao que objetiva receber um octal e retornar um binario de tipo size_t(similar ao unsigned int)
    size_t resultado = 0; //Variavel para armazenar o resultado final(binario)
    u_short i = 0;
    /*Loop com o objetivo de transformar octal em decimal */
    while (octal != 0) { //Loop termina quando o octal for zero
        resultado += octal%10 * pow(8, i); //Resultado recebe ele mesmo mais o resto da variavel decimal por 10 vezes a potencia 8^i
        i++; //Incremento do indice i
        octal/=10; //Decimal reduzido em 10 vezes
    }
    resultado = decimal_to_Binary(resultado); //Resultado, agora em decimal, e transformado em binario pela funcao decimal_to_Binary
    return resultado;
}

size_t hexa_to_binary(char* hexa){  //Funcao que objetiva receber um hexadecimal e retornar um binario de tipo size_t(similar ao unsigned int)
    size_t resultado = 0;  //Variavel para armazenar o resultado final(binario)
    u_short i = 0, temp, TAM;
    TAM = strlen(hexa); //Variavel que armazena o comprimento da string hexa
        /*Loop com o objetivo de transformar hexadecimal em decimal */
    while (i < TAM) { //Enquanto o indice i for menor que o comprimento da string hexa
        if (hexa[i] >= 48 && hexa[i] <= 57) { //Analizamos o char no indice i da string hexa e vemos se ele esta entre 0 e 9 na tabela Ascii (0->48 ate 9->57)
            temp = hexa[i] - 48; //Variavel temp recebe o char no indice i da string hexa convertido para inteiro('0' -> 0, '1'->1)
            resultado += temp * pow(16, TAM - i - 1); //O resultado incrementa em temp vezes 16^(comprimento da string hexa - indice - 1)
        }

        else if (hexa[i] >= 97 && hexa[i] <= 102) { //Analizamos o char no indice i da string hexa e vemos se ele esta entre 'a' e 'f' na tabela Ascii (a->97 ate f->102)
            temp = hexa[i] - 87;//Variavel temp recebe o char no indice i da string hexa convertido para inteiro('a' -> 97, 'b'->98)
            resultado += temp * pow(16, TAM - i - 1); //O resultado incrementa em temp vezes 16^(comprimento da string hexa - indice - 1)
        }
        
        i++; //Incremento do indice i
    }
    resultado = decimal_to_Binary(resultado); //O resultado, agora em decimal, e transformado em binario pela funcao decimal_to_Binary
    return resultado;
}


int shift_Num(int num){ //Funcao com o objetivo de realizar uma operacao de deslocamento de bits a esquerda
    return num << 1; //retorna o numero com o deslocamento feito
}

void abre_Arquivo(FILE** arqEntrada,FILE** arqSaida, char* endereco_Entrada){ //Funcao com o objetivo de abrir os possiveis arquivos de entrada e saida
    
    *arqEntrada = fopen(endereco_Entrada,"r"); //Abre o arquivo de entrada no modo 'leitura'
    *arqSaida = fopen("./assembly/binary","a"); //Abre o arquivo de saida no modo 'escrita'

    if(arqEntrada == NULL || arqSaida == NULL){ //Caso algum dos arquivos nao exista
        printf("Erro ao abrir arquivos!\n"); 
        exit(1); 
    }
}

short le_instrucao_I(Type_I* montador, char* str){ //Funcao com o objetivo de analisar se a instrucao pertence ao tipo I
    for (int i = 0; i < 6; i++) { //Loop passando por todas as instrucoes do tipo I
        printf("%s ", montador[i].nome_Instrucao);
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) { //Verifica se o nome da instrucao dado na funcao seja igual ao da instrucao do tipo I no indice I do vetor montador
            return 1; //Caso for, a funcao pertence ao tipo I
        }
    }
    return 0; //Caso tenha passado pelo loop sem retorno, a funcao nao pertence ao tipo I
}

short le_instrucao_R(Type_R *montador, char* str){  //Funcao com o objetivo de analisar se a instrucao pertence ao tipo R
    for (int i = 0; i < 7; i++) {//Loop passando por todas as instrucoes do tipo R
        printf("%s ", montador[i].nome_Instrucao);
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) { //Verifica se o nome da instrucao dado na funcao seja igual ao da instrucao do tipo R no indice R do vetor montador
            return 1; //Caso for, a funcao pertence ao tipo R
        }
    }

    return 0; //Caso tenha passado pelo loop sem retorno, a funcao nao pertence ao tipo R
}

short le_instrucao_S(Type_S *montador, char* str){ //Funcao com o objetivo de analisar se a instrucao pertence ao tipo S
    for (int i = 0; i < 3; i++) {  //Loop passando por todas as instrucoes do tipo S
        printf("%s ", montador[i].nome_Instrucao);
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) { //Verifica se o nome da instrucao dado na funcao seja igual ao da instrucao do tipo S no indice S do vetor montador
            return 1; //Caso for, a funcao pertence ao tipo S
        }
    }
    return 0; //Caso tenha passado pelo loop sem retorno, a funcao nao pertence ao tipo S
}

short pesquisa_instrução(char* str, Type_I** montador_I, Type_R** montador_R, Type_S** montador_S, 
    Type_I** convert_I, Type_R** convert_R, Type_S** convert_S){ //Funcao com o objetivo de encontrar a qual tipo uma certa instrucao pertence
        
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

short le_Linha(FILE *arqEntrada, Type_I vetor_I, Type_R vetor_R, Type_S vetor_S){ //Funcao com o objetivo de ler o arquivo de entrada linha por linha
    //Declara a string para a linha, aloca e armazena a linha
    char *linha; //String para armazenar a linha atual
    short TAM_linha = 100; //Limite de caracteres por linha

    linha = (char*) malloc(TAM_linha*sizeof(char)); //Aloca memoria para a string linha baseado no limite de caracteres por linha
    fgets(linha, TAM_linha, arqEntrada); //Funcao para passar para a string linha uma linha do arquivo de entrada

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
    const char delim[1] = " "; //Delimitador a ser utilizado
    char *token;

    token = strtok(linha, delim);  //A funcao strtok e responsavel por separar a string baseada em certos delimitadores, que nesse caso e um espaco

    short i = 0; //variavel indice
    char str[4][5]; //string constante que armazenara o vetor de strings gerado pela separacao da linha baseado em espacos

    while (token != NULL) { //Enquanto token ainda nao for nulo
        printf("%s\n", token);
        strcpy(str[i], token); //Atribuido ao vetor str no indice i o valor de token
        token = strtok(NULL, delim); //token recebe um strtok para que seja separado novamente pelo delimitador espaco
        i++; //indice incrementa 
    }


    //Libera memoria e retorna;
    free(linha);
    return 1;
}

char* adicionar_zeros_esquerda(int binario,int num_bits){ //Funcao com o objetivo de adicionar zeros a esquerda baseado em um numero de bits especifico
    
    char *str = (char*)malloc(sizeof(char)*num_bits); //str alocada dinamicamente com num_bits caracteres
    sprintf(str, "%0*d", num_bits,binario); //sprintf para que sejam adicionados zeros a esquerda ate que o binario tenha num_bits bits
    
    return str; //Retorna o binario, que, agora, e representado por uma string, visto que zeros a esquerda sao removidos por padrao em tipos inteiros
}
