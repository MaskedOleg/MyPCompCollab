#include<stdio.h>
#define LIMIT 999

int getline(char str[], int size);
char uncomment(char str[], char new_str[]);

main() {
	char line[LIMIT];	/* Input array of characters */
	char newline[LIMIT];	/* For no comment array of characters */
	int len;
	
	printf("Enter a line with comments:\n");
	len = getline(line, LIMIT);
	printf("Line with comments:\n%s", line);	
	uncomment(line, newline);
	printf("Line without comments:\n%s", newline);
	
}

int getline(char str[], int size) {
	char c;
	int i;

	for( i = 0 ; i < size - 1 && (c=getchar()) != EOF && c != '\n' ; ++i )
		str[i] = c;
	if( c == '\n' )
		str[i] == '\n';
	++i;
	str[i] = '\0';

	return i;
}

char uncomment(char str[], char new_str[]) {
	int i, j;
	int slash, asterisk;

	i = 0;
	slash = 0;
	asterisk = 0;

	while ( str[i] != EOF )
		++i;	/* Gets size of array */

	for ( j = 0; j < i; ++j ) {
		if (str[j] == '/')
			++slash;
		else if (str[j] == '*')
			++ asterisk;
		else {
			slash = 0;
			asterisk = 0;
		}
		if (slash >= 1 && asterisk >= 1)
			;
		else
			new_str[j] = str[j];
	}
}