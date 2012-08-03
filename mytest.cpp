#include "stdafx.h"
#include "mytest.h"

bool fTest(f_sort func, int *ARRAY, int SIZE_ARRAY);
void fEmptyTest(f_sort func, int *ARRAY);
void fOneTest(f_sort func, int *ARRAY);
void fTwoTest(f_sort func, int *ARRAY);
void fBigTest(f_sort func, int *ARRAY);
void fIdenTest(f_sort func, int *ARRAY);

void FullTest(f_sort func)
{
	int *ARRAY;
	ARRAY = (int*)malloc(1000000 * sizeof(int));
	fEmptyTest(func, ARRAY);
	fOneTest(func, ARRAY);
	fTwoTest(func, ARRAY);
	fBigTest(func, ARRAY);
	fIdenTest(func, ARRAY);
	free(ARRAY);
}

bool fTest(f_sort func, int *ARRAY, int SIZE_ARRAY)
{
	func(ARRAY, SIZE_ARRAY);
	for(int i = 1; i < SIZE_ARRAY; ++i)
	{
		if(ARRAY[i] < ARRAY[i-1])
		{
			return false;
		}
	}
	return true;
}

void fEmptyTest(f_sort func, int *ARRAY)
{
	int SIZE_ARRAY = 1;
	bool check;

	check = fTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array is empty\n");
	}
}
void fOneTest(f_sort func, int *ARRAY)
{
	int SIZE_ARRAY = 1;
	bool check;

	ARRAY[0] = 5;

	func(ARRAY, SIZE_ARRAY);
	check = (ARRAY[0] == 5);
	if(!check)
	{
		printf("Sort fault if the array consists of only one element\n");
	}
}
void fTwoTest(f_sort func, int *ARRAY)
{
	int SIZE_ARRAY = 2;
	bool check;

	ARRAY[0] = 2;
	ARRAY[1] = 1;

	check = fTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array consists of two element\n");
	}
}
void fBigTest(f_sort func, int* ARRAY)
{
	int SIZE_ARRAY = 1000000;
	bool check;

	for (int i = 0; i < SIZE_ARRAY; ++i)
	{
		ARRAY[i] = SIZE_ARRAY - i;
	}

	check = fTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array consists of 1000000 element\n");
	}
}
void fIdenTest(f_sort func, int *ARRAY)
{
	int SIZE_ARRAY = 1000;
	bool check;

	for(int i = 0; i < 1000; ++i)
	{
		ARRAY[i] = 1;
	}

	check = fTest(func, ARRAY, SIZE_ARRAY);
	if(!check)
	{
		printf("Sort fault if the array consists of identical element\n");
	}
}