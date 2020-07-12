#include<stdio.h>
#include<ctype.h>
#define MAXLINE 999
#define BAL 30000.00F

int getline ( char s[], int lim );
int strcmp ( char s[], char t[] );
float atof ( char s[] );
void reinit ( char s[], int lim );
void transac ( char s[], long t[] );

main()
{
	char line[MAXLINE]; 
	long receipt[MAXLINE];
	int len, option;
	float num, new_bal;

	printf("Enter your pin: ");
	len = getline(line, MAXLINE);
	while (strcmp(line, "092796") != 0) {
		printf("Error! Enter the correct pin: ");
		len = getline(line, MAXLINE);
	}
	printf("Authenticated.\n");
	getchar();
	reinit(line, len);

	printf("BALANCE: %.2f\nChoose Transaction:\na.) Withdraw\nb.) Deposit\n", BAL); 
	printf("Enter option (type \"exit\" to finish transaction): ");
	len = getline(line, MAXLINE);
	if ((option = strcmp(line, "exit")) == 0 )
		printf("Thank you for your transaction.\nHave a great day!");
	else if ((option = strcmp(line, "a")) == 0 ) {
		reinit(line, len);
		printf("Enter the amount you would like to withdraw: ");
		len = getline(line, MAXLINE);
		num = atof(line);
		if( BAL >= num ) {
			new_bal = BAL - num;
			printf("Your new balance is %.2f.\n", num, new_bal);
		}
		else
			printf("You cannot withdraw more than your current balance.");
	}
	else if ((option = strcmp(line, "b")) == 0 ) {
		reinit(line, len);
		printf("Enter the amount you would like to deposit: ");
		len = getline(line, MAXLINE);
		num = atof(line);
		new_bal = BAL + num;
		printf("Your new balance is %.2f.\n", num, new_bal);
	}
	reinit(line, len);
	printf("Thank you for your transaction.\nHave a great day!");
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

int strcmp ( char s[], char t[] )
{
	int i, bool;
	for ( i = bool = 0; t[i] != '\0'; ++i )
		if ( tolower(s[i]) != tolower(t[i]) )	/* will cause undefined behavior */
			bool = 1;
	if ( bool == 1 )
		return bool;
	else
		return bool;
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