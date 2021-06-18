#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int main()
{
  int d[31] = { 0 };
  int l[31] = { 0 }; 

  int numero;
  char lado;
  while (scanf("%d %c", &numero, &lado) == 2)
  {
    if (lado == 'D')
    {
      d[numero - 30]++;
    }
    else
    {
      l[numero - 30]++;
    }
  }
  int count = 0;
  for (int i = 0; i < 31; i++)
  {
    if (d[i] != 0 && l[i] != 0)
    {

      if (d[i] > l[i])
      {
        count += l[i];
      }
      else
      {
        count += d[i];
      }
    }
  }

  printf("%d\n", count);

  return 0;
}