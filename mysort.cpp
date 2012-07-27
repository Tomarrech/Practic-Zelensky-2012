#include "stdafx.h"
#include "mysort.h"
#include <ctime>
#include <time.h>

int midRand(int SIZE_ARRAY);
void FirstHalfCheck(int *ARRAY, int *start, int middle);
void LastHalfCheck(int *ARRAY, int *last, int middle);
void SwapCheck(int *ARRAY, int *start, int *last);
void swap(int *fElem, int *sElem);
void RecFirstHalfQSort(int *ARRAY, int start, int SIZE_ARRAY);
void RecLastHalfQSort(int *ARRAY, int last);

void qSort(int* ARRAY, int SIZE_ARRAY)
{
	int middle = ARRAY[midRand(SIZE_ARRAY)/*(SIZE_ARRAY - 1) / 2*/];
	int start = 0; 
	int last = SIZE_ARRAY - 1;

	do 
	{
		FirstHalfCheck(ARRAY, &start, middle);
		LastHalfCheck(ARRAY, &last, middle);
		SwapCheck(ARRAY, &start, &last);
	} while(start <= last);

	RecFirstHalfQSort(ARRAY, start, SIZE_ARRAY);
	RecLastHalfQSort(ARRAY, last);
}

int midRand(int SIZE_ARRAY)
{
	srand(clock());
	return rand() % SIZE_ARRAY;
}

void FirstHalfCheck(int *ARRAY, int *start, int middle)
{
	while(ARRAY[*start] < middle)
	{
		(*start)++;
	}
}

void LastHalfCheck(int *ARRAY, int *last, int middle)
{
	while(ARRAY[*last] > middle)
	{
		(*last)--;
	}
}

void SwapCheck(int *ARRAY, int *start, int *last)
{
	if((*start) <= (*last))
	{
		swap(&ARRAY[*start], &ARRAY[*last]);
		(*start)++;
		(*last)--;
	}
}

void swap(int *fElem, int *sElem)
{
		int temp;
		temp = *fElem;
		*fElem = *sElem;
		*sElem = temp;
}

void RecFirstHalfQSort(int *ARRAY, int start, int SIZE_ARRAY)
{
	if(start < SIZE_ARRAY - 1)
	{
		qSort(ARRAY + start, SIZE_ARRAY - start);
	}
}

void RecLastHalfQSort(int *ARRAY, int last)
{
	if(last > 0)
	{
		qSort(ARRAY, last + 1);
	}
}