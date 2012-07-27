#include "stdafx.h"
#include "mysearch.h"

bool firstCheck(int startElem, int lastElem, int Elem);
int midCalc(int start, int last);
int findResult(int *ARRAY, int *start, int *middle, int *last, int Elem);

int mysearch(int *ARRAY, int SIZE_ARRAY, int Elem)
{
	int start = 0;
	int last = SIZE_ARRAY - 1;
	int result = -1;
	
	if(firstCheck(ARRAY[start], ARRAY[last], Elem))
	{
		int middle = 0;
		while(start <= last)
		{
			result = findResult(ARRAY, &start, &middle, &last, Elem);
		}
		return result;
	}
	else
	{
		return result;
	}
}

bool firstCheck(int startElem, int lastElem, int Elem)
{
	return !(startElem > Elem || lastElem < Elem);
}

int midCalc(int start, int last)
{
	return start + (last - start) / 2;
}

int findResult(int *ARRAY, int *start, int *middle, int *last, int Elem)
{
	*middle = midCalc(*start, *last);

	if(ARRAY[*middle] == Elem)
	{
		return *middle;
	}
	else if(ARRAY[*middle] < Elem)
	{
		*start = *middle + 1;
	}
	else if(ARRAY[*middle] > Elem)
	{
		*last = *middle;
	}
}