#include "montador.h"

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