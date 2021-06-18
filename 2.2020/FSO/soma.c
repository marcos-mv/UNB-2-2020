#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    fork();
    fork();

    printf("Oi\n");
}


int main(void){
    pid_t x;
    x=fork();
    sleep(5);
    if(x==0){
        sleep(10);
        printf("Sou filho, pid=%d, e pai= %d \n", getpid(),getppid() );
        return 3;
    }else{
        sleep(10);
        printf("Sou pai, com filho pid=%d, e me pai é = %d \n", x,getppid() );
        int s;
        wait(&s);
        printf("Meu filho devolveu: %d \n", WEXITSTATUS(s));
        sleep(10);
    }
    return 0;
}