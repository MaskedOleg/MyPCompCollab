#include <stdio.h>

#define MAXLINE 1000	/* Maximum string length */

int getline(char s[], int lim);
int syncheck(char str[], char new_str[]);

main() 
{
	int i;
	int length;		/* current line length */
	int new_length;		/* new line length */
	char line[MAXLINE];	/* current input line */
	char newline[MAXLINE];	/* altered input line */

	printf("Enter a line:\n");

	length = getline(line, MAXLINE);
	printf("Original input:\n");
	for (i = 0; i < length; ++i)
		printf("%c", line[i]);
	new_length = syncheck(line, newline);
	printf("Fixed syntax:\n");
	for (i = 0; i < new_length; ++i)
		printf("%c", newline[i]);
	
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
int syncheck(char str[], char new_str[])
{
	int a, b;

	for ( a = 0; str[a] != EOF; ++a )
		;
}