#pragma once
#include<iostream>
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
	void elementInArray(int element);
private:
	int _size;
	int* _arr;
};

