//In the created class «Set of integers» :
//Set elements to store in dynamic array;
//each element of the set is unique(elements are not repeated);
//elements are not ordered.
//Implement methods :
//constructors(default, with parameters, copying);
//destructor;
//feature set verification.
//
//Implement operations :
//adding the element to the set(+, +=);
//union of two sets(+, +=);
//removal of the element(-, -=);
//set difference(-, -=);
//intersection of sets(*, *=);
//assignment(= );
//set comparison(== );
//streaming outputand input(<>).
#include "ArrayIntegers.h"

int main()
{
	const int size = 3;
	int a = 4;
	int arr[size] = { 1, 2, 3 };
	int arr2[size] = { 4, 2, 5 };
	ArrayIntegers test(arr, size);
	ArrayIntegers test2(arr2, size);
	ArrayIntegers test3;
	cout << test3 << endl;
	test3 -= a;
	cout << test3 << endl;

	system("pause");
	return 0;
}