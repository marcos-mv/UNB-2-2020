#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


void trataSinal (int s){
    int r;
    char string[11];
    r = scanf(" %s",string);
    if (r != 1 ){ // r==EOF
        exit(0);
    }   
    if (s == SIGUSR1 && string[3]== 'r'){
        printf("Certo\n");
    }
    else if (s == SIGUSR2 && string[3]== 'a'){
        printf("Certo\n");
    }
    else if (s == SIGINT && string[3]== '1'){
        printf("Certo\n");
    }
    else if (s == SIGTERM && string[3]== '2'){
        printf("Certo\n");
    }
    else if (s == SIGALRM && string[3]== 'e'){
        printf("Certo\n");
    }
    else{
        printf("ERRO\n");
    }
}

int main(void){
    signal(SIGUSR1,trataSinal);
    signal(SIGUSR2,trataSinal);
    signal(SIGINT,trataSinal);
    signal(SIGTERM,trataSinal);
    signal(SIGALRM,trataSinal);

    while(1){
        pause();
    }
}