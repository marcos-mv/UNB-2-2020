#include <stdio.h>
#include <stdlib.h>

int main(){

    int i = 1000300;

    char *a=&i;

    char a[4];

    printf("%d\n",i);
    printf("%c%c%c%c\n",a[0],a[1],a[2],a[3]);
    printf("ola mundo\n");

    return 0;
}