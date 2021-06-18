#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define PAGESIZE 4096
# define N 500000

char mat [N ][ PAGESIZE ];

void funcao_B ( char c) {
 int i ,j;
 for ( j = 0; j < PAGESIZE ; j ++)
 for ( i = 0; i < N; i ++)
 mat [i ][ j ] = c ;
 }

int main () {

    clock_t t;
    t = clock();

    clock();
    funcao_B ('-');
    

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("took %f seconds to execute \n", time_taken);

    clock();
    return 0;
}