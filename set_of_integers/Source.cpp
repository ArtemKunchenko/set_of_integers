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
	const int size2 = 4;
	int a = 4;
	int arr[size] = { 1, 2, 3 };
	int arr2[size] = { 4, 2, 1 };
	int arr3[size] = { 1, 2, 3 };
	int arr4[size2] = { 1, 2, 3, 4 };
	ArrayIntegers test(arr, size);
	ArrayIntegers test2(arr2, size);
	ArrayIntegers test3(arr3, size);
	ArrayIntegers test4(arr4, size2);
	cout << test << endl;
	cout << test2 << endl;
	cout << test3 << endl;
	cout << test4 << endl;
	cout << (test==test2) <<endl;
	cout << (test == test3) << endl;
	cout << (test == test4) << endl;

	system("pause");
	return 0;
}