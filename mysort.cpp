#include "stdafx.h"
#include "mysort.h"
#include <ctime>
#include <time.h>
#include <assert.h>

int findPivot(int *Array, int size);
void swap(int *fElem, int *sElem);
void partition(int* Array, int* start, int* last, int middle);

void qSort(int* Array, int size)
{
	assert(size >= 0);
	int middle = findPivot(Array, size);
	int start = 0; 
	int last = size - 1;

	partition(Array, &start, &last, middle);

	if(start < size - 1)
	{
		qSort(Array + start, size - start);
	}
	if(last > 0)
	{
		qSort(Array, last + 1);
	}
}

int findPivot(int *Array, int size)
{
	srand(clock());
	return Array[rand() % size];
}

void partition(int* Array, int* start, int* last, int middle)
{
	while(true) 
	{
		while(Array[*start] < middle)
		{
			(*start)++;
		}
		while(Array[*last] > middle)
		{
			(*last)--;
		}
		if(*start <= *last)
		{
			swap(&Array[*start], &Array[*last]);
			(*start)++;
			(*last)--;
		}
		else
		{
			break;
		}
	} 
}

void swap(int *fElem, int *sElem)
{
	int temp;
	temp = *fElem;
	*fElem = *sElem;
	*sElem = temp;
}