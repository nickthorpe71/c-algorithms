#include <stdio.h>
int main(int argc, char *argv[])
{
  float profit, inc, payout = 0;
  int days;

  sscanf(argv[1], "%f", &profit);
  sscanf(argv[2], "%f", &inc);
  sscanf(argv[3], "%i", &days);

  for (int i = 0; i < days; i++)
  {
    profit *= inc;
    if (profit > 500000)
    {
      profit -= 500;
      payout += 500;
    }
  }

  printf("total: %9.6f, payout:%9.6f\n", profit, payout);
  return 0;
}