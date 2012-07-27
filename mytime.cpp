#include "stdafx.h"
#include "mytime.h"

double timeTest(f_sort fun, int *ARRAY, int SIZE_ARRAY)
{
	clock_t ts = clock();
	fun(ARRAY, SIZE_ARRAY);
	clock_t te = clock();
	double res = (double)(te - ts) / CLOCKS_PER_SEC;
	return res;
}