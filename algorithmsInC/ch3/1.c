#include <stdio.h>

int isPrime();

int main(int argc, char *argv[])
{
  printf("test\n");
  int n = 12, m = 10;
  int a[n][m];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (isPrime(i) == 1 && isPrime(j) == 1 && i != j)
        a[i][j] = 1;
      else
        a[i][j] = 0;

  // print result
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int isPrime(int n)
{
  if (n < 2)
    return 0;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return 0;
  return 1;
}