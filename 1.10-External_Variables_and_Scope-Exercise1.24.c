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
	printf("\nSyntax Error:\n");
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
	int a, b, c;
	int r_pths, l_pths, r_brkt, l_brkt, r_brcs, l_brcs, sq, dq, cmt, es;
	
	b = 0;
	c = 0;
	r_pths = 0;
	l_pths = 0;
	r_brkt = 0;
	l_brkt = 0;
	r_brcs = 0;
	l_brcs = 0;
	dq = 0;
	sq = 0;
	cmt = 0;
	es = 0;

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
		else if ( str[a] == '/' ) {
			if ( (cmt > 0) && (str[a-1] == '*') )
				++cmt;
			else if ( (cmt == 0 ) && (str[a+1] == '*') ) {
				++cmt;
				b = a;
				while ( str[b] != 59 )	/* finds last semi-colon index before comment start */
					--b;
			}
		}
		else if (str[a]== 92) {
			c = str[a+1];
			if(c=='a'||c=='b'||c=='e'||c=='f'||c=='n'||c=='r'||c=='t'||c=='v'||c==92||c=='?')
				es = 0;
			else if( c == 34 )
				--dq;
			else if ( c == 39 )
				--sq;
			else
				es = 1;
		}
	}
	if ( b > 0 )
		a = b + 2;	/* sets last semi-colon index */
	else
		;

	if ( r_pths != l_pths ) {
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
		printf("Line has unequal number of single quotes.");
	else if ( dq % 2 != 0 )
		printf("Line has unequal number of double quotes.");
	else if ( es == 1 )
		printf("Escape sequence is non existent.");
	else if ( cmt % 2 != 0 )
		printf("Line has unequal number of comment tag.");
	else if ( str[a-2] != 59 )
		printf("Line must terminate with a semi-colon. Add a ';' at the end of the line.");
	else
		printf("--No Syntax Errors.--");
}