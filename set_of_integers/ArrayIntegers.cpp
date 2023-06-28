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
	bool same_elememt = false;
	int element;
	for (int i = 0; i < size; i++)
	{
		element = arr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (element == arr[j])
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
		if (_arr[i] == element)
		{
			same_elememt = true;
			break;
		}
	}
	if (same_elememt == true) cout << "Array includes element \"" << element << "\"\n";
	else cout << "Array doesn't include element \"" << element << "\"\n";
}

ArrayIntegers ArrayIntegers::operator+(int& right)
{
	ArrayIntegers temp;
	bool same_elememt = false;
	for (int i = 0; i < this->_size; i++)
	{
		if (this->_arr[i] == right)
		{
			same_elememt = true;
			break;
		}
	}
	if (same_elememt == true)
	{
		temp._size = this->_size;
		if (this->_arr == nullptr)
		{
			temp._arr = nullptr;
		}
		else
		{
			temp._arr = new int[this->_size];
			if (temp._arr == NULL)
			{
				cout << "Error\n";
				exit(-1);
			}
			for (int i = 0; i < this->_size; i++)
			{
				temp._arr[i] = this->_arr[i];
			}
		}
	}
	else
	{
		temp._size = this->_size + 1;
		if (this->_arr == nullptr)
		{
			temp._arr = new int[this->_size + 1];
			if (temp._arr == NULL)
			{
				cout << "Error\n";
				exit(-1);
			}
			temp._arr[0] = right;
		}
		else
		{
			temp._arr = new int[this->_size + 1];
			if (temp._arr == NULL)
			{
				cout << "Error\n";
				exit(-1);
			}
			for (int i = 0; i < this->_size; i++)
			{
				temp._arr[i] = this->_arr[i];
			}
			temp._arr[this->_size] = right;
		}

	}

	return temp;
}

ArrayIntegers ArrayIntegers::operator+=(int right)
{

	bool same_elememt = false;
	for (int i = 0; i < this->_size; i++)
	{
		if (this->_arr[i] == right)
		{
			same_elememt = true;
			break;
		}
	}
	if (same_elememt == true)
	{
		return *this;
	}
	else
	{
		
		if (this->_arr == nullptr)
		{
			this->_size += 1;
			this->_arr = new int[this->_size];
			if (this->_arr == NULL)
			{
				cout << "Error\n";
				exit(-1);
			}
			this->_arr[0] =right;
			return *this;
		}
		else
		{
			int *temp = new int[this->_size+1];
			if (temp == NULL)
			{
				cout << "Error\n";
				exit(-1);
			}
			for (int i = 0; i < this->_size; i++)
			{
				temp[i] = this->_arr[i];
			}
			temp[this->_size] = right;
			delete[]this->_arr;
			this->_arr = temp;
			this->_size += 1;
		}

	}

	
}

ostream& operator<<(ostream& out, const ArrayIntegers& right)
{
	string str;
	if (right._arr != nullptr)
	{
		for (int i = 0; i < right._size; i++)
		{
			if (i == 0 && right._size != 1) str += "{" + to_string(right._arr[i]) + ", ";
			else if (i == right._size - 1 && right._size != 1)str += to_string(right._arr[i]) + "}";
			else if (right._size == 1) str += "{" + to_string(right._arr[i]) + "}";
			else str += to_string(right._arr[i]) + ", ";

		}

	}
	else str = "{}";

	out << str;
	return out;
}
