#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct Entity {
    char name[10];
};

/**
 * returns a random integer between min and max (inclusive)
 */
int randint(int min, int max) 
{
    if (min > max) return 0;
    return rand() % (max - min) + min;
}

/**
 * returns a random name with spedicfied length
 * (max length 9)
 */
char* generateName(int length) 
{
    if (length > 9) length = 9;

    char * name;
    name = malloc(sizeof(char)*10);

    // add random capital first letter
    name[0] = (char)randint(65, 90);

    // add random remaining letters
    for (int i = 1; i < length; i++) 
        name[i] = (char)randint(97, 122);
    
    name[length] = '\0';

    return name;
}

void main() 
{
    // create random number seed
    srand(time(NULL)); // ONLY CALL ONCE

    for (int i = 0; i < 4; i++) {
        char* newName = generateName(randint(2,10));
        printf("%s\n", newName);
        free(newName);
    }
}