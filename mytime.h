#include <iostream>
#include <ctime>
using namespace std;

typedef void (*f_sort)(int *ARRAY, int SIZE_ARRAY);

double timeTest(f_sort fun, int *ARRAY, int SIZE_ARRAY);