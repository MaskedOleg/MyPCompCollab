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
	
	/* Initialize variables */
	j = 0;
	k = 0;
	hold = 0;
	
	for ( i = 0; str[i] != '\0'; ++i ) {
		if( str[hold] == '/' && str[i] == '*' ) { 
			/* Test for previous index(hold) and current index(i) 
			if they signify the START of a comment*/
			j = 1;	/* Counter to identify if array is now the start of a comment */
			k = k - 1;	/* Goes back one index for new_str[] */
		}
		else if ( str[hold] == '*' && str[i] == '/' )
			/* Test for previous index(hold) and current index(i) 
			if they signify the END of a comment*/
			j = 0;	/* Counter set to exist out of a comment */
		else if ( j == 0 ) {	/* As long as Counter is 0, */
			new_str[k] = str[i]; /* Assigns value of str[i] to new_str[k] */
			++k;	/* Only increments if assignment is made */
		}
		hold = i; /* Assigns soon-to-be previous value of i; */
	}
	new_str[k] = '\0'; /* Adds a terminating symbol to array signifying END */
	return k; /* returns total length of new_str[] */
}