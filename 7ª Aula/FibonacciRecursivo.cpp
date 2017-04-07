#include <iostream>

//função recursiva para o numero fibonacci
int fibonacci(int numero,int x, int y)
{
  if(numero == 0)
    return 0;
  if(numero > 1)
    return y + fibonacci(numero - 1, y, x + y);
  else
    return 1;
}

//função principal
int main()
{
  int numero= 0;
  printf("Posicao: ");
  scanf("%d",&numero);
  printf("O numero da posicao %d dos numeros fibonacci eh %d\n",numero,fibonacci(numero,1,0));
  return 0;
}