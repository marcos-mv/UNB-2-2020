#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int i = 0;

void trataSinal (int s){

pid_t pid;

    if ((s == SIGUSR1 || s == SIGUSR2) && i== 0){
        pid = fork();
        if (pid >= 0){
            if (pid == 0){
                exit(EXIT_SUCCESS);
            }
        }
    i++;
    }
    else if((s == SIGUSR1 || s == SIGUSR2) && i==1){
        wait(0);
        i++;
    }
    else if ((s == SIGUSR1 || s == SIGUSR2) && i == 2){
        exit(0);
    }
}

int main(void){
    
        signal(SIGUSR1,trataSinal);
        signal(SIGUSR2,trataSinal);
        

    while(1){
        pause();
    }
}