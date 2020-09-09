#include<stdio.h>
#define MAXLINE 999
/* WIP */
int getline(int lim, char s[]);
int digits_to_numerals(int num);
int numerals_to_digits(char s[]);

main()
{
	int len, digits;
	char line[MAXLINE], choice[MAXLINE], numeral[MAXLINE];

	printf("Convert:\nA.) Number to Numeral form\nB.) Numeral to Number form\nEnter a letter: ");
	len = getline(MAXLINE, choice);

	if (choice[0] == 'A' || choice[0] == 'a') {
		printf("Enter the value to be converted (MAX Value is 3999): ");
		len = getline(MAXLINE, line);
		digits = atoi(len, line);
		digits_to_numerals(digits);
	}
	else if (choice[0] == 'B' || choice[0] == 'b') {
		printf("Enter the value to be converted (MAX Value is 3999): ");
		len = getline(MAXLINE, line);
		digits = numerals_to_digits(line);
		printf("%d", digits);
	}
}

int getline(int lim, char s[])
{
	int i;
	char c;

	for( i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if ( c == '\n' )
		s[i++] = '\n';
	s[i] = '\0';

	return i;
}

int atoi(int lim, char s[])
{
	int i, val;

	for(i = val = 0; i < lim-1; ++i)
		val = (val * 10) + (s[i]-'0');

	return val;
}

int digits_to_numerals(int num)
{
	int lim, count = 0;
	enum roman_numerals { I=1, IV=4, V=5, IX=9, X=10, XL=40, L=50, XC=90, C=100, CD=400, D=500, 				CM=900, M=1000};
	/* Thousands */
	if(num >= 1000 && num <= 3999) {
		lim = num / M;
		num -= M*lim;		/* sets remaining number value */
		while (count++ < lim) /* number of times to print numeral */
			printf("M");
		count = 0;
	}
	/* Hundreds */
	if(num <= 999 && num >= 100) {
		if ( num / CM == 1 ) {
			num -= CM;
			printf("CM");
		}
		else if ( num - D == 0 ) {
			num -= D;
			printf("D");
		}
		else if (num > 500 ) {
			printf("D");
			lim = (num - D) / C;
			num -= D + C*lim;
			while (count++ < lim)
				printf("C");
		}
		else if ( num / CD == 1 ) {
			num -= CD;
			printf("CD");
		}
		else {
			lim = num / C;
			num -= C*lim;
			while (count++ < lim)
				printf("C");
		}
		count = 0;
	}
	/* Tens */
	if(num <= 99 && num >= 10) {
		if ( num / XC == 1 ) {
			num -= XC;
			printf("XC");
		}
		else if ( num - L == 0 ) {
			num -= L;
			printf("L");
		}
		else if (num > 50 ) {
			printf("L");
			lim = (num - L) / X;
			num -= L + X*lim;
			while (count++ < lim)
				printf("X");
		}
		else if ( num / XL == 1 ) {
			num -= XL;
			printf("XL");
		}
		else {
			lim = num / X;
			num -= X*lim;
			while (count++ < lim)
				printf("X");
		}
		count = 0;
	}
	/* Ones */
	if(num <= 9 && num >= 1) {
		if ( num / IX == 1 ) {
			num -= IX;
			printf("IX");
		}
		else if ( num - V == 0 ) {
			num -= V;
			printf("V");
		}
		else if (num > 50 ) {
			printf("V");
			lim = (num - V) / I;
			num -= V + I*lim;
			while (count++ < lim)
				printf("I");
		}
		else if ( num / IV == 1 ) {
			num -= IV;
			printf("IV");
		}
		else {
			lim = num / I;
			num -= I*lim;
			while (count++ < lim)
				printf("I");
		}
		count = 0;
	}
}

int numerals_to_digits (char s[])
{
	int i, value, hold;
	enum roman_numerals { I=1,  V=5,  X=10,  L=50,  C=100,  D=500, M=1000 };

	for ( i = value = 0 ; s[i] != '\n'; ++i ) {
		
	}

	return value;
}
