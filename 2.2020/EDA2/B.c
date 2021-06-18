#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int d[31] = {0}, l[31]={0};

  int numero;
  char lado;
  while (scanf("%d %c", &numero, &lado) == 2){
    if (lado == 'D'){
      d[numero - 30]++;
    }else{
      l[numero - 30]++;
    }
  }
  int conjunto = 0;
  for (int i = 0; i < 31; i++){
    if (d[i] != 0 && l[i] != 0){
      if (d[i] > l[i]){
        conjunto += l[i];
      }else{
        conjunto += d[i];
      }
    }
  }
  printf("%d\n", conjunto);

  return 0;
}