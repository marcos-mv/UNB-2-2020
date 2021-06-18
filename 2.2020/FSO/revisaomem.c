#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char buffer[4096][4096];

int main(){

    clock_t t;
    t = clock();

    for(int i =0; i<4096; i++){
        for(int j =0; j<4096; j++){
            buffer[i][j]=1;
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("took %f seconds to execute \n", time_taken);
    return 0;

    clock();
    return 0;
}