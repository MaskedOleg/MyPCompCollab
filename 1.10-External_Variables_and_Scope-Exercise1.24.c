#include <stdio.h>

#define MAXLINE 1000	/* Maximum string length */

int getline(char s[], int lim);
int syncheck(char str[], int len);

main() 
{
	int i;
	int length;		/* current line length */
	char line[MAXLINE];	/* current input line */

	printf("Enter a line:\n");
	length = getline(line, MAXLINE);
	printf("Syntax Error:\n");
	syncheck(line, length);

	return 0;
}

/* getline; read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* syncheck: checks for rudimentary syntax errors */
int syncheck(char str[], int len)
{
	int a, b;
	int r_pths, l_pths, r_brkt, l_brkt, r_brcs, l_brcs, sq, dq;
	
	r_pths = 0;
	l_pths = 0;
	r_brkt = 0;
	l_brkt = 0;
	r_brcs = 0;
	l_brcs = 0;
	dq = 0;
	sq = 0;

	for ( a = 0; a < len; ++a ) {
		if ( str[a] == '(' )
			++r_pths;
		else if ( str[a] == ')' )
			++l_pths;
		else if ( str[a] == '[' )
			++r_brkt;
		else if ( str[a] == ']' )
			++l_brkt;
		else if ( str[a] == '{' )
			++r_brcs;
		else if ( str[a] == '}' )
			++l_brcs;
		else if ( str[a] == 39 )
			++sq;
		else if ( str[a] == 34 )
			++dq;
	}
	if ( dq % 2 != 0 )
		printf("Line has unequal number of double quotes");
	else if ( r_pths != l_pths ) {
		printf("Line has unequal number of parentheses. ");
		if ( r_pths > l_pths )
			printf("Supply an additional ')' to close the line.");
		else if ( r_pths < l_pths )
			printf("Supply an additional '(' to close the line.");
	}
	else if ( r_brkt != l_brkt ) {
		printf("Line has unequal number of brackets. ");
		if ( r_brkt > l_brkt )
			printf("Supply an additional ']' to close the line.");
		else if ( r_brkt < l_brkt )
			printf("Supply an additional '[' to close the line.");
	}
	else if ( r_brcs != l_brcs ) {
		printf("Line has unequal number of braces. ");
		if ( r_brcs > l_brcs )
			printf("Supply an additional '}' to close the line.");
		else if ( r_brcs < l_brcs )
			printf("Supply an additional '{' to close the line.");
	}
	else if ( sq % 2 != 0 )
		printf("Line has unequal number of single quotes");
	else if ( str[a-2] != 59 )
		printf("Line must terminate with a semi-colon. Add a ';' at the end of the line.");
	else
		printf("No Syntax Errors.");
}