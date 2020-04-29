#include<stdio.h>
#define LIMIT 999

int getline(char str[], int size);
void uncomment(char str[], char new_str[]);

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
		str[i] = '\n';
	++i;
	str[i] = '\0';

	return i;
}

void uncomment(char str[], char new_str[]) {
	int i, j, k;
	int hold;
	
	j = 0;
	k = 0;

	for ( i = 0; str[i] != '\0'; ++i ) {
		if( str[hold] == '/' && str[i] == '*') {
			j = 1;
			k = i -1;
		}
		else if ( str[hold] == '*' && str[i] == '/') {
			j = 0;
			++i;
		}
		if ( j == 0) {
			new_str[k] = str[i];
			printf("new_str[%d] = %c\t", k, new_str[k]);
			++k;
		}
		printf("hold[%d] = %c\tstr[%d] = %c\n", hold, str[hold], i, str[i]);
		hold = i;
		
	}
	new_str[i] = '\0';
}