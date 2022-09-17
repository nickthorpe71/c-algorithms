#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Entity {
    char name[10];
};

void main() 
{
    srand(time(NULL));   // ONLY CALL ONCE
    int r = rand() % 20; // number between 0 and 19
    int a = rand() % 20; // number between 0 and 19
    int n = rand() % 20; // number between 0 and 19
    int d = rand() % 20; // number between 0 and 19
    printf("%d %d %d %d\n", r, a, n, d);
}