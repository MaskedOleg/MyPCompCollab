#include <stdio.h>

#define MAXLINE 1000	/* Maximum string length */

int getline(char s[], int lim);
int uncomment(char str[], char new_str[]);

main() 
{
	int length;		/* current line length */
	int new_length;		/* new line length */
	char line[MAXLINE];	/* current input line */
	char newline[MAXLINE];	/* altered input line */

	printf("Enter a line:\n");

	length = getline(line, MAXLINE);
	printf("Original input:\n");
	for (int i = 0; i < length; ++i)
		printf("%c", line[i]);
	new_length = uncomment(line, newline);
	printf("No comment code output:\n");
	for (int i = 0; i < new_length; ++i)
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

int uncomment(char str[], char new_str[]) {
	int i, j, k;
	int hold;
	
	j = 0;
	k = 0;
	hold = 0;
	
	for ( i = 0; str[i] != '\0'; ++i ) {
		if( str[hold] == '/' && str[i] == '*' ) {
			j = 1;
			k = k - 1;
		}
		else if ( str[hold] == '*' && str[i] == '/' ) {
			j = 0;
			++i;
		}
		if ( j == 0 ) {
			new_str[k] = str[i];
			printf("new_str[%d] = %c\t", k, new_str[k]);
			++k;
		}
		printf("hold[%d] = %c\tstr[%d] = %c\n", hold, str[hold], i, str[i]);
		hold = i;
	}
	new_str[k] = '\0';
	return k;
}