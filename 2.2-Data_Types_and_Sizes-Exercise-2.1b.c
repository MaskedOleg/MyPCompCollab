#include<stdio.h>

/*	Argument type for printf function:
	For signed char and int data types, use i or d argument type.
	For long data types, use ld argument type.
	For unsigned char and int data types, use u argument type.	*/

main()
{	
	char cmaxmin;
	int imaxmin, x, y;
	long lmaxmin;
	short smaxmin;
	unsigned char ucmax;
	unsigned int uimax;
	unsigned long ulmax;
	unsigned short usmax;
	float fmaxmin;
	double dmaxmin;
	
	x = 0;
	y = 0;
	cmaxmin = 0;
	imaxmin = 0;
	lmaxmin = 0;
	smaxmin = 0;
	ucmax = 0;
	uimax = 0;
	ulmax = 0;
	usmax = 0;
	fmaxmin = 1;
	dmaxmin = 1;

	while ( cmaxmin > -1 )
		++cmaxmin;
	printf("CHAR_MAX\t:\t%d\n", cmaxmin*-1-1);
	printf("CHAR_MIN\t:\t%d\n", cmaxmin);

	while ( imaxmin > -1 )
		++imaxmin;
	printf("INT_MAX\t\t:\t%d\n", imaxmin*-1-1);
	printf("INT_MIN\t\t:\t%d\n", imaxmin);

	while ( lmaxmin > -1 )
		++lmaxmin;
	printf("LONG_MAX\t:\t%d\n", lmaxmin*-1-1);
	printf("LONG_MAX\t:\t%d\n", lmaxmin);

	while ( smaxmin > -1 )
		++smaxmin;
	printf("SHORT_MAX\t:\t%d\n", smaxmin*-1-1);
	printf("SHORT_MAX\t:\t%d\n", smaxmin);

	while ( ucmax == 0 )
		--ucmax;
	printf("UCHAR_MAX\t:\t%u\n", ucmax);

	while ( uimax == 0)
		--uimax;
	printf("UINT_MAX\t:\t%u\n", uimax);
	
	while ( ulmax == 0)
		--ulmax;
	printf("ULONG_MAX\t:\t%u\n", ulmax);

	while ( usmax == 0 )
		--usmax;
	printf("USHORT_MAX\t:\t%u\n", usmax);

	while ( x < 127 ) {
		fmaxmin = fmaxmin * 2;
		++x;
	}
	printf("FLT_MAX\t\t:\t%e\n", fmaxmin); /* approx value */

	while ( y < 1023 ) {
		dmaxmin = dmaxmin * 2;
		++y;
	}
	printf("DBL_MAX\t\t:\t%e\n", dmaxmin); /* approx value */

/* WIP */
}
