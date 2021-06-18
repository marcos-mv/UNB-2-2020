#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float n1 = 4;
    float n2 = 9;

    float total = n2 / n1 ;
    float truncado = floor( total * 10.0f ) / 10.0f;

    printf("Media: %.1f ", truncado );
    printf("Media: %.2f ", truncado );
    printf("Media: %.5f ", truncado );

    return 0;
}

