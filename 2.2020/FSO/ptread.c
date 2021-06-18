// #include <stdio.h>
// #include <pthread.h>
// #include <stdlib.h>
// #include <unistd.h>

// void *funcao(void *a){
//     (*((int*)a))++;
//     sleep(1);
//     (*((int*)a))++;
//     printf("dormindo\n");
//     sleep(5);
//     printf("acabando\n");
// }

// int main(void){
//     pthread_t tid;
//     int a = 10;
//     printf("a=%d\n",a);
//     pthread_create(&tid,NULL,&funcao,(void*)&a);
//     printf("thread criada\n");
//     sleep(1);
//     printf("a=%d\n",a);
//     a++;
//     pthread_join(tid,NULL);
//     printf("a=%d\n",a);
//     return 0;
// }

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *funcao(void *a){
    while(1);
}

int main(void){
    pthread_t tid;
    int a = 10;
    printf("a=%d\n",a);
    pthread_create(&tid,NULL,&funcao,(void*)&a);
    pthread_create(&tid,NULL,&funcao,(void*)&a);
    pthread_create(&tid,NULL,&funcao,(void*)&a);
    sleep(10);
    return 0;
}