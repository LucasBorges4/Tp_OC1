#include "montador.h"
#include <math.h>

int decimal_to_binary(int decimal){
    int i = 0, resultado = 0;
    while (decimal != 0) {
        resultado = decimal%2 * pow(10, i);
        decimal/=2;
        i++;
    }
    return resultado;
}

