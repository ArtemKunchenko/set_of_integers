#pragma once
#include<iostream>
#include<string>;
using namespace std;

class ArrayIntegers
{
public:
	ArrayIntegers();//constructor default
	ArrayIntegers(int element);//costructor with parametrs
	ArrayIntegers(int* arr, const int size);//costructor with parametrs
	~ArrayIntegers();//distructor
	ArrayIntegers(const ArrayIntegers& other);//copy constructor
	void operator=(const ArrayIntegers& other);//copy operator
	bool elementInArray(int element);
	ArrayIntegers& operator+ (int& right);
	ArrayIntegers& operator+= (int right);
	ArrayIntegers& operator+ (ArrayIntegers& right);
	friend ostream& operator<< (ostream& out, const ArrayIntegers & right);
private:
	int _size;
	int* _arr;
};
ostream& operator<< (ostream& out, const ArrayIntegers& right);




