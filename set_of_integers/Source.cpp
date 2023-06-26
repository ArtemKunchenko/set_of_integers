#include "ArrayIntegers.h"

int main()
{
	const int size = 3;
	int arr[size] = { 1, 2, 3 };
	ArrayIntegers test(arr, size);
	test.elementInArray(4);
	system("pause");
	return 0;
}