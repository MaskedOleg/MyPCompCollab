#include<stdio.h>
#define MAXLINE 999

int getline ( char s[], int lim );
float atof ( char s[] );
void reinit ( char s[], int lim );
void transac ( char s[], long t[] );

main()
{
	char line[MAXLINE]; 
	long receipt[MAXLINE];
	int len;
	float num;

	printf("Enter your pin: ");
	len = getline(line, MAXLINE);
	reinit(line, len);
	printf("Enter a value: ");
	len = getline(line, MAXLINE);
	num = atof(line);
	printf("You'd like to deposit: %.2f", num);
}

int getline ( char s[], int lim )
{
	int i;
	char c;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';

	return i;
}

float atof ( char s[] )
{
	int i, point;
	int whole_num; 
	float deci_num, multiplier, total;

	whole_num = 0;
	deci_num = 0;
	multiplier = 0.1f;

	for ( i = point = 0; s[i] != '\n'; ++i ) {
		if( s[i] == '.' )
			point = 1;
		else if( point == 0 )
			whole_num = whole_num * 10 + (s[i] - '0');
		else {
			deci_num = deci_num + multiplier * (s[i] - '0');
			multiplier *= 0.1f;
		}
	}
	return total = whole_num + deci_num;
}

void reinit ( char s[], int lim ) 
{
	int i;

	i = 0;
	while( i < lim )
		s[i++] = 0;
}