#include<stdio.h>

#define NUM 7

void nouse_1(int n, int m); /* old style function */
void nouse_2(int o, int p); /* modern style function */

main()
{
	int zero;
	char a;

	zero = 0;
	a = 'a';

	printf("This is a program to make errors.\n");
	if( NUM == 7 ) {
		if( zero == 0 ) {
			if( a == 'a' ) {
				printf("Inside the conditions.");
			}
		}
	}
}

void nouse_1(n, m)
int n, m;
{
	printf("This does nothing.");
}

void nouse_2(int o, int p)
{
	printf("This also does nothing.");
}