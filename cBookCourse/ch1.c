#include <stdio.h>

// 1.1 Hello World
void helloWorld() 
{
  printf("hello, world\n");
}

// 1.2 Variables and Arithmetic

/* print Fahrenheit-Celsius table
 * for f = 0, 20, ..., 300 */

void printCtoF() 
{
  int lower, upper, step;
	float fahr, celsius;
	lower = 0; /* lower limit of temperature table */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	fahr = lower;

	while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
		printf("%4.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

// 1.3 The For Statement

void printCtoFFor() /* Fahrenheit-Celcius table */
{
  int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
	  printf("%4d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

// 1.4 Symbolic Constnats

# define LOWER 0   /* lower limit of table */
# define UPPER 300 /* upper limit */
# define STEP  20  /* step size */

void printCtoFFor14() /* Fahrenheit-Celcius table */
{
  int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	  printf("%4d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

// 1.5 A Collection of Useful Programs

void fileCopy1() /* copy input to output; 1st version */
{
  int c;
	c = getchar();

	while (c != EOF) {
    putchar(c);
		c = getchar();
	}
}

void fileCopy2() /* copy input to output; 2nd version */
{
  int c;
	while ((c = getchar()) != EOF)
	  putchar(c);
}


void main() 
{
  fileCopy2();  
}




