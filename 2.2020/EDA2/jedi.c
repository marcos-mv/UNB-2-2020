#include <stdio.h>
#include <stdlib.h>

int main(){

    int casos, num;

    scanf("%d", &casos);

    for(int i = 0; i < casos; i++){
        scanf("%d",&num);
        if(num%2 == 0){
            printf("Jedi\n");
        }
        else{
            printf("Sith\n");
        }
    }
    return 0;
}