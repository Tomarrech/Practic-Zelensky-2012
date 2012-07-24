#include "stdafx.h"
#include "mysearch.h"

int mysearch(int *ARRAY, int SIZE_ARRAY, int Elem)
{
	int start = 0;
	int last = SIZE_ARRAY - 1;
	int middle;
	
	if(ARRAY[start] > Elem)
	{
		return -1;
	}
	if(ARRAY[last] < Elem)
	{
		return -1;
	}
	
	while(start <= last)
	{
		middle = start + (last - start) / 2;

		if(ARRAY[middle] == Elem)
		{
			return middle;
		}
		else if(ARRAY[middle] < Elem)
		{
			start = middle + 1;
		}
		else if(ARRAY[middle] > Elem)
		{
			last = middle;
		}
	}

	return -1;
}