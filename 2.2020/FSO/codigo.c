#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int a=0, b=0, c=0, d=0;

void trataSinal (int s){
 
    if (s == SIGINT ){
        printf("Recebi %d\n", getpid());
        a = 1;
    }
    else if (s == SIGUSR2 && a == 1){
        printf("Recebi %d \n", getpid());
        b=1;
    }
    else if (s == SIGTERM && b == 1){
        printf("Recebi %d \n", getpid());
        c=1;
    }
    else if (s == SIGTERM && c == 1){
        printf("Senha acionada\n");
        printf("Recebi %d \n", getpid());
        d=1;
    }
    else if (s == SIGUSR1 && d== 1){
        printf("Tchau\n");
        exit(0);
    }
    else if (s == SIGUSR2 ){
        printf("Recebi %d \n", getpid());
    }
    else if (s == SIGUSR1 ){
        printf("Recebi %d \n", getpid());
    }
    else if (s == SIGTERM ){
        printf("Recebi %d \n", getpid());
    }
}

int main(void){
    signal(SIGUSR1,trataSinal);
    signal(SIGUSR2,trataSinal);
    signal(SIGINT,trataSinal);
    signal(SIGTERM,trataSinal);

    while(1){
        pause();
    }
}