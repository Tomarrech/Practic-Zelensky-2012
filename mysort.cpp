#include "stdafx.h"
#include "mysort.h"

void swap(int *fElem, int *sElem)
{
		int temp;
		temp = *fElem;
		*fElem = *sElem;
		*sElem = temp;
}

void qSort(int* ARRAY, int SIZE_ARRAY)
{
	int middle = ARRAY[(SIZE_ARRAY - 1) / 2];
	int start = 0; 
	int last = SIZE_ARRAY - 1;

	while(true)
	{
		while(ARRAY[start] < middle)
		{
			start++;
		}
		while(ARRAY[last] > middle)
		{
			last--;
		}

		if(start <= last)
		{
			int temp;
			swap(&ARRAY[start], &ARRAY[last]);
			start++;
			last--;
		}
		else
		{
			break;
		}
	}

	if(start < SIZE_ARRAY - 1)
	{
		qSort(ARRAY + start, SIZE_ARRAY - start);
	}
	if(last > 0)
	{
		qSort(ARRAY, last + 1);
	}
}