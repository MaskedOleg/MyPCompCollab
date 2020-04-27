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
	int i, j, k, l, m;

	i = 0;
	k = 1;

	while ( str[i] != '\n' )
		++i;	/* Gets size of array */
	for ( j = 0; j < i; ++j ) {
		if (str[j] == '/' && str[k] == '*') {
			l = k + 1;
			m = l + 1;
			while( str[l] != '*' && str[m] != '/' ) {
				printf("Skipping %c\n", str[l]);
				++l;
				++m;
			}	 
			j = k = m;
			printf("Removed Comments\n");
		}
		else
			new_str[j] = str[j];
		++k;
	}
}