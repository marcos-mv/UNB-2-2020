#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int i=0;

void trataSinal (int s){
    if (s == SIGUSR1){
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }
    else if (s == SIGALRM && i < 2){
        printf("Ai que sono, quero dormir mais um pouco\n");
        i++;
    }
    else if (s == SIGALRM && i == 2){
        printf("Os incomodados que se mudem, tchau\n");
        exit(0);
    }
}

int main(void){
    signal(SIGUSR1,trataSinal);
    signal(SIGALRM,trataSinal);

    while(1){
        pause();
    }
}