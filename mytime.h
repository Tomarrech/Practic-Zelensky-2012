#include <iostream>
#include <ctime>
using namespace std;

typedef void (*f_sort)(int *ARRAY, int SIZE_ARRAY);
typedef int (*f_search)(int *ARRAY, int SIZE_ARRAY, int Elem);

double timeTest(f_sort fun, int SIZE_ARRAY);
double timeTest(f_search fun, int SIZE_ARRAY);