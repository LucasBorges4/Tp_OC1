#include "montador.h"

size_t decimal_to_Binary(size_t decimal){ //Funcao que objetiva receber um decimal e retornar um binario de tipo size_t(similar ao unsigned int)
    size_t resultado = 0; //Variavel para armazenar o resultado final(binario)
    size_t fator = 1;

    while (decimal != 0) {  //Loop termina quando o decimal for zero
        resultado += decimal%2 * fator; //Resultado recebe ele mesmo mais o resto da variavel decimal por 2 vezes a potencia 10^i
        fator *= 10;
        decimal/=2; //Decimal reduzido na metade
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

short le_instrucao_I(Type_I* montador, char* str){ //Retorna o indice da instrucao no tipo I, se existir, caso contrario, retorna -1
    for (int i = 0; i < 6; i++) {
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) {
            return i;
        }
    }
    return -1;
}

short le_instrucao_R(Type_R *montador, char* str){ //Retorna o indice da instrucao no tipo R, se existir, caso contrario, retorna -1
    for (int i = 0; i < 7; i++) {
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) {
            return i;
        }
    }

    return -1;
}

short le_instrucao_S(Type_S *montador, char* str){ //Retorna o indice da instrucao no tipo S, se existir, caso contrario, retorna -1
    for (int i = 0; i < 3; i++) {
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) {
            return i;
        }
    }
    return -1;
}

short le_instrucao_B(Type_B *montador, char* str){ //Retorna o indice da instrucao no tipo B, se existir, caso contrario, retorna -1
    for (int i = 0; i < 3; i++) {
        if (!strcmp(montador[i].nome_Instrucao, &str[0])) {
            return i;
        }
    }
    return -1;
}

short pesquisa_instrução(char* str, Type_I* montador_I, Type_R* montador_R, Type_S* montador_S, Type_B *montador_B,
Type_I * Result_I,Type_R * Result_R,Type_S * Result_S,Type_B * Result_B){ //Funcao para encontrar o tipo de uma certa instrucao e atribuir ao devido struct seus parametros(funct_3,funct_7,opcode)
        
    for (int i = 0; i < NUM_INSTRUCT_TYPE_I; i++) {
        int index = le_instrucao_I(&montador_I[i], str); //Indice recebe o possivel indice da instrucao no vetor I
        if (index != -1){    //Caso nao for -1, a funcao pertence nesse tipo
            *Result_I = montador_I[index]; //Result_I recebe a struct no indice index no montador_I
            return 1; //Retorna 1 se instrucao for do tipo I
            break;
        }
    }
      
    for (int i = 0; i < NUM_INSTRUCT_TYPE_S; i++) {
       int index = le_instrucao_S(&montador_S[i], str); //Indice recebe o possivel indice da instrucao no vetor S
        if (index != -1){  //Caso nao for -1, a funcao pertence nesse tipo
            *Result_S = montador_S[index];  //Result_S recebe a struct no indice index no montador_S

            return 2; //Retorna 2 se instrucao for do tipo S
            break;
        }
    }

    for (int i = 0; i < NUM_INSTRUCT_TYPE_R; i++) {
        int index = le_instrucao_R(&montador_R[i], str); //Indice recebe o possivel indice da instrucao no vetor R
        if (index != -1){     //Caso nao for -1, a funcao pertence nesse tipo
            *Result_R = montador_R[index];  //Result_R recebe a struct no indice index no montador_R
            return 3; //Retorna 3 se instrucao for do tipo R
            break;
        }
    }
     for (int i = 0; i < NUM_INSTRUCT_TYPE_B; i++) {
        int index = le_instrucao_B(&montador_B[i], str); //Indice recebe o possivel indice da instrucao no vetor R
        if (index != -1){     //Caso nao for -1, a funcao pertence nesse tipo
            *Result_B = montador_B[index];  //Result_R recebe a struct no indice index no montador_R
            return 4; //Retorna 3 se instrucao for do tipo R
            break;
        }
    }

    return 0; //Retorna 0 se a instrucao for desconhecida    
}
/*Funções de leitura de arquivo*/

short le_Linha(FILE *arqEntrada, Type_I* vetor_I, Type_R* vetor_R, Type_S* vetor_S, Type_B* vetor_B, Type_I *Result_I, Type_R *Result_R, Type_S *Result_S, Type_B *Result_B){ //Funcao com o objetivo de ler o arquivo de entrada linha por linha
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

    const char delim[3] = " ("; //Delimitador a ser utilizado
    char *token;

    token = strtok(linha, delim);  //A funcao strtok e responsavel por separar a string baseada em certos delimitadores, que nesse caso e um espaco

    short i = 0; //variavel indice

    char str[4][5]; //string constante que armazenara o vetor de strings gerado pela separacao da linha baseado em espacos

    int num, num1, num2;

    while (token != NULL) { //Enquanto token ainda nao for nulo
        strcpy(str[i], token); //Atribuido ao vetor str no indice i o valor de token
        token = strtok(NULL, delim); //token recebe um strtok para que seja separado novamente pelo delimitador espaco
        i++; //indice incrementa 
    }
    
    //printf("%s %s %s %s\n", str[0], str[1], str[2], str[3]);
    
    sscanf(str[1], "%*[^0123456789]%d", &num); //Procura no primeiro parametro algum numero e atribui a num

    if (str[2][0] == 120) {
        sscanf(str[2], "%*[^0123456789]%d", &num1); //Procura no segundo paramentro algum numero e atribui a num1
    } // se caso for um registrador já que x = 120 na tabela ascii, entao passa pelo if e faz a procura

    else {
        sscanf(str[2], "%d", &num1); //caso nao, entao é um imediato, se é entao procura e converte-lo para inteiro
    }

    if (str[3][0] == 120) {
        sscanf(str[3], "%*[^0123456789]%d", &num2);  //Procura no segundo paramentro algum numero e atribui a num1
        // se caso for um registrador já que x = 120 na tabela ascii, entao passa pelo if e faz a procura
    }

    else {
        sscanf(str[3], "%d", &num2); //caso nao, entao é um imediato, se é entao procura e converte-lo para inteiro
    }
    
    int tipo = pesquisa_instrução(str[0], vetor_I, vetor_R, vetor_S, vetor_B, Result_I, Result_R, Result_S, Result_B);
        
    int entrada = 0;
    FILE *fp;
    fp = fopen("./stdin/binary.txt", "a+");
    
    if (tipo == 1) {
        set_registradores_I(Result_I, num,  num2, num1);
        //referenciado de acordo com comando da entrada.
        if (entrada) printf("%s\n", get_I_binary(*Result_I));
        else {
            fprintf(fp, "%s\n", get_I_binary(*Result_I));
        }
    }

    if (tipo == 2) {
        set_registradores_S(Result_S, num1, num, num2);
        if (entrada) printf("%s\n", get_S_binary(*Result_S)); //referenciado de acordo com comando da entrada
        else fprintf(fp, "%s\n", get_S_binary(*Result_S));
    }

    if (tipo == 3) {
        set_registradores_R(Result_R, num, num1, num2);
        if (entrada) printf("%s\n", get_R_binary(*Result_R)); //refernciado de acordo com ocmando da entrada.
        else fprintf(fp, "%s\n", get_R_binary(*Result_R));
    }

    if (tipo == 4) {
        set_registradores_B(Result_B, num2, num, num1);
        if (entrada) printf("%s\n", get_B_binary(*Result_B)); //refernciado de acordo com ocmando da entrada.
        else fprintf(fp, "%s\n", get_B_binary(*Result_B));
    }
    

    //Libera memoria e retorna;
    
    fclose(fp);
    free(linha);
    return 1;
}

void limpa_Arquivo(FILE* arq, const char* str){
    arq = fopen(str, "w");
    fprintf(arq, ""); //LIMPA ARQUIVO DE SAIDA;
    fclose(arq);
}

char* adicionar_zeros_esquerda(int binario, int num_bits){ //Funcao com o objetivo de adicionar zeros a esquerda baseado em um numero de bits especifico
    
    char *str = (char*)malloc(sizeof(char)*num_bits); //str alocada dinamicamente com num_bits caracteres
    sprintf(str, "%0*d", num_bits,binario); //sprintf para que sejam adicionados zeros a esquerda ate que o binario tenha num_bits bits
    
    return str; //Retorna o binario, que, agora, e representado por uma string, visto que zeros a esquerda sao removidos por padrao em tipos inteiros
}


char *get_R_binary(Type_R struct_R){ //Funcao que retorna o binario de 32 bits do tipo R
    char *binary=(char*)malloc(sizeof(char)*32); //Alocacao de 32 chars
    /*Passa todos os inteiros contidos na estrutura R em
    forma de binario e, se necessario, com zeros a esquerda */
    sprintf(binary, "%s%s%s%s%s%s",adicionar_zeros_esquerda(struct_R.funct_7,7),  //sprintf para conversao de todos os inteiros em um unico char
    adicionar_zeros_esquerda(struct_R.Rs2_5,5),
    adicionar_zeros_esquerda(struct_R.Rs1_5,5),
    adicionar_zeros_esquerda(struct_R.funct_3,3),
    adicionar_zeros_esquerda(struct_R.Rd_5,5),
    adicionar_zeros_esquerda(struct_R.opcode_7,7));
    
    return binary;

    
}
char *get_I_binary(Type_I struct_I){ //Funcao que retorna o binario de 32 bits do tipo I
    char *binary=(char*)malloc(sizeof(char)*32); //Alocacao de 32 chars
     /*Passa todos os inteiros contidos na estrutura I em
    forma de binario e, se necessario, com zeros a esquerda */
    sprintf(binary, "%s%s%s%s%s",adicionar_zeros_esquerda(struct_I.immediate_12,12),  //sprintf para conversao de todos os inteiros em um unico char
    adicionar_zeros_esquerda(struct_I.Rs1_5,5),
    adicionar_zeros_esquerda(struct_I.funct_3,3),
    adicionar_zeros_esquerda(struct_I.Rd_5,5),
    adicionar_zeros_esquerda(struct_I.opcode_7,7));
    
    return binary;

    
}
char *get_S_binary(Type_S struct_S){ //Funcao que retorna o binario de 32 bits do tipo S
    
    char *binary=(char*)malloc(sizeof(char)*32); //Alocacao de 32 chars
    /*Passa todos os inteiros contidos na estrutura S em
    forma de binario e, se necessario, com zeros a esquerda */
    sprintf(binary, "%s%s%s%s%s%s",adicionar_zeros_esquerda(struct_S.immediate_7,7), //sprintf para conversao de todos os inteiros em um unico char
    adicionar_zeros_esquerda(struct_S.Rs2_5,5),
    adicionar_zeros_esquerda(struct_S.Rs1_5,5),
    adicionar_zeros_esquerda(struct_S.funct_3,3),
    adicionar_zeros_esquerda(struct_S.immediate_5,5),
    adicionar_zeros_esquerda(struct_S.opcode_7,7));
    
    return binary;

    
}
char *get_B_binary(Type_B struct_B){ //Funcao que retorna o binario de 32 bits do tipo B
    
    char *binary=(char*)malloc(sizeof(char)*32); //Alocacao de 32 chars
    /*Passa todos os inteiros contidos na estrutura B em
    forma de binario e, se necessario, com zeros a esquerda */
    sprintf(binary, "%s%s%s%s%s%s",adicionar_zeros_esquerda(struct_B.immediate_7,7), //sprintf para conversao de todos os inteiros em um unico char
    adicionar_zeros_esquerda(struct_B.Rs2_5,5),
    adicionar_zeros_esquerda(struct_B.Rs1_5,5),
    adicionar_zeros_esquerda(struct_B.funct_3,3),
    adicionar_zeros_esquerda(struct_B.immediate_5,5),
    adicionar_zeros_esquerda(struct_B.opcode_7,7));
    
    return binary;

    
}

int get_substring(char* string,int initial_pos,int length){ //Funcao com o objetivo de pegar um intervalo(substring) dentro de uma string
    char *substring = (char*)malloc(length-initial_pos+1); //Alocacao de memoria apropriada
        strncpy(substring,string+(initial_pos-1),length); //Atribui a substring para a variavel
        return atoi(substring); //Retorna a substring como inteiro pela funcao atoi    
}


void set_registradores_I(Type_I * struct_I,int Rd,int immediate,int Rs1){ //Coloca os valores dos registradores e imediatos no tipo I
    struct_I->immediate_12=decimal_to_Binary(immediate); //Imediato convertido para binario
    struct_I->Rs1_5=decimal_to_Binary(Rs1); //Rs1 convertido para binario
    struct_I->Rd_5=decimal_to_Binary(Rd); //Rd convertido para binario
}
void set_registradores_R(Type_R * struct_R,int Rd,int Rs1,int Rs2){  //Coloca os valores dos registradores e imediatos no tipo R
    struct_R->Rs1_5=decimal_to_Binary(Rs1); //Rs1 convertido para binario
    struct_R->Rs2_5=decimal_to_Binary(Rs2); //Rs2 convertido para binario
    struct_R->Rd_5=decimal_to_Binary(Rd); //Rd convertido para binario
}

void set_registradores_S(Type_S * struct_S, int immediate,int Rs1,int Rs2){ //Coloca os valores dos registradores e imediatos no tipo S
    struct_S->immediate_7=decimal_to_Binary(get_substring(adicionar_zeros_esquerda(immediate,7),5,11)); //Imediato[11:5] convertido para binario
    
    struct_S->Rs1_5=decimal_to_Binary(Rs1); //Rs1 convertido para binario
    struct_S->Rs2_5=decimal_to_Binary(Rs2); //Rs2 convertido para binario
    struct_S->immediate_5=decimal_to_Binary(get_substring(adicionar_zeros_esquerda(immediate,7),0,4)); //Imediato[4:0] convertido para binario 
}


void set_registradores_B(Type_B * struct_B, int immediate,int Rs1,int Rs2){ //Coloca os valores dos registradores e imediatos no tipo B
    struct_B->immediate_7=  decimal_to_Binary(pow(10,get_substring(adicionar_zeros_esquerda(immediate,7),12,12)) + get_substring(adicionar_zeros_esquerda(immediate,7),5,10)); //Imediato[11:5] convertido para binario
    struct_B->Rs1_5=decimal_to_Binary(Rs1); //Rs1 convertido para binario
    struct_B->Rs2_5=decimal_to_Binary(Rs2); //Rs2 convertido para binario
    struct_B->immediate_5=decimal_to_Binary(get_substring(adicionar_zeros_esquerda(immediate,7),1,4) + get_substring(adicionar_zeros_esquerda(immediate,7),11,11)); //Imediato[4:0] convertido para binario 
}
