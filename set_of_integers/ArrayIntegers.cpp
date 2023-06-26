#include "ArrayIntegers.h"

ArrayIntegers::ArrayIntegers()
{
	_size = 0;
	_arr = nullptr;
}

ArrayIntegers::ArrayIntegers(int element)
{
	_size = 1;
	_arr = new int[_size];
	if (_arr == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	_arr[0] = element;
}

ArrayIntegers::ArrayIntegers(int* arr, const int size)
{
	bool same_elememt=false;
	int element;
	for (int i = 0; i < size; i++)
	{
		element = arr[i];
		for (int j = i+1; j < size; j++)
		{
			if (element==arr[j])
			{
				same_elememt = true;
				break;
			}
		}
	}
	if (same_elememt == true)
	{
		_size = 0;
		_arr = nullptr;
		cout << "Error! Array has the same elements!!! Used parametrs by default\n";
	}
	else
	{
		_size = size;
		_arr = new int[_size];
		if (_arr == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = arr[i];
		}
	}
}

ArrayIntegers::~ArrayIntegers() { if (_arr != nullptr) delete[]_arr; }

ArrayIntegers::ArrayIntegers(const ArrayIntegers& other)
{
	if (other._arr == nullptr)
	{
		this->_size = other._size;
		this->_arr = nullptr;
	}
	else
	{
		this->_size = other._size;
		this->_arr = new int[_size];
		if (_arr == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = other._arr[i];
		}
	}
}

void ArrayIntegers::operator=(const ArrayIntegers& other)
{
	if (other._arr == nullptr)
	{
		this->_size = other._size;
		this->_arr = nullptr;
	}
	else
	{
		this->_size = other._size;
		this->_arr = new int[_size];
		if (_arr == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = other._arr[i];
		}
	}
}

void ArrayIntegers::elementInArray(int element)
{

	bool same_elememt = false;
	for (int i = 0; i < _size; i++)
	{
		if (_arr[i]==element)
		{
			same_elememt = true;
			break;
		}
	}
	if (same_elememt == true) cout << "Array includes element \""<<element<<"\"\n";
	else cout << "Array doesn't include element \"" << element << "\"\n";
}
