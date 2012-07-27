#include "stdafx.h"
#include "mytime.h"

void arrayFill(int *ARRAY, int SIZE_ARRAY);

double timeTest(f_sort fun, int SIZE_ARRAY)
{
	int *ARRAY;
	ARRAY = (int*) malloc(SIZE_ARRAY * sizeof(int));
	arrayFill(ARRAY, SIZE_ARRAY);

	clock_t ts = clock();
	fun(ARRAY, SIZE_ARRAY);
	clock_t te = clock();
	
	free(ARRAY);
	
	double res = (double)(te - ts) / CLOCKS_PER_SEC;
	return res;
}

void arrayFill(int *ARRAY, int SIZE_ARRAY)
{
	for(int i = 0; i < SIZE_ARRAY; ++i)
	{
		ARRAY[i] = rand();
	}
}