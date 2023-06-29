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

bool ArrayIntegers::elementInArray(int element)
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
	return same_elememt;
	/*if (same_elememt == true) cout << "Array includes element \"" << element << "\"\n";
	else cout << "Array doesn't include element \"" << element << "\"\n";*/
}

ArrayIntegers& ArrayIntegers::operator+(int& right)
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

ArrayIntegers& ArrayIntegers::operator+=(int right)
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
			this->_arr[0] = right;
			return *this;
		}
		else
		{
			int* temp = new int[this->_size + 1];
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
			return *this;
		}

	}


}

ArrayIntegers& ArrayIntegers::operator+(ArrayIntegers& right)
{

	ArrayIntegers* temp = new ArrayIntegers();

	if (this->_arr == nullptr)
	{
		temp->_size = right._size;
		temp->_arr = new int[temp->_size];

		for (int i = 0; i < temp->_size; i++)
		{
			temp->_arr[i] = right._arr[i];
		}
	}
	else
	{
		int counter = 0;
		int sum_size = this->_size + right._size;
		int* sum_arr = new int[sum_size];
		for (int i = 0, j = 0, k = 0; i < sum_size; i++)
		{
			if (i < this->_size)
			{
				sum_arr[j] = this->_arr[j];
				counter++;
				j++;
			}
			else
			{
				if (this->elementInArray(right._arr[k]) == false)
				{
					sum_arr[j] = right._arr[k];
					counter++;
					j++;
				}
				k++;
			}

		}
		temp->_size = counter;
		temp->_arr = new int[counter];
		for (int i = 0; i < temp->_size; i++)
		{
			temp->_arr[i] = sum_arr[i];
		}
		delete[]sum_arr;

	}

	return *temp;
}

ArrayIntegers& ArrayIntegers::operator+=(ArrayIntegers& right)
{
	if (this->_arr == nullptr)
	{
		if (right._arr == nullptr)
		{
			return *this;
		}
		else
		{
			this->_size = right._size;
			this->_arr = new int[this->_size];

			for (int i = 0; i < this->_size; i++)
			{
				this->_arr[i] = right._arr[i];
			}
			return *this;
		}
	}
	else
	{
		if (right._arr == nullptr)
		{
			return *this;
		}
		else
		{
			int counter = 0;
			int sum_size = this->_size + right._size;
			int* sum_arr = new int[sum_size];
			for (int i = 0, j = 0, k = 0; i < sum_size; i++)
			{
				if (i < this->_size)
				{
					sum_arr[j] = this->_arr[j];
					counter++;
					j++;
				}
				else
				{
					if (this->elementInArray(right._arr[k]) == false)
					{
						sum_arr[j] = right._arr[k];
						counter++;
						j++;
					}
					k++;
				}

			}
			this->_size = counter;
			delete[]this->_arr;
			this->_arr = new int[counter];
			for (int i = 0; i < this->_size; i++)
			{
				this->_arr[i] = sum_arr[i];
			}
			delete[]sum_arr;
			return *this;
		}
	}
}

ArrayIntegers& ArrayIntegers::operator-(int& right)
{

	ArrayIntegers* temp = new ArrayIntegers();
	if (this->elementInArray(right) == true)
	{
		temp->_size = this->_size - 1;
		if (temp->_size == 0)
		{
			temp->_arr = nullptr;
		}
		else
		{
			temp->_arr = new int[temp->_size];
			if (temp->_arr == nullptr)
			{
				cout << "Error\n";
				exit(-1);
			}
			for (int i = 0, j = 0; i < this->_size; i++)
			{
				if (this->_arr[i] != right)
				{
					temp->_arr[j] = this->_arr[i];
					j++;
				}
			}
		}
	}
	else
	{
		if (this->_arr == nullptr)
		{
			temp->_size = 0;
			temp->_arr = nullptr;
		}
		else
		{
			temp->_size = this->_size;
			temp->_arr = new int[temp->_size];
			if (temp->_arr == nullptr)
			{
				cout << "Error\n";
				exit(-1);
			}
			for (int i = 0; i < temp->_size; i++)
			{
				temp->_arr[i] = this->_arr[i];
			}
		}
	}

	return *temp;
}

ArrayIntegers& ArrayIntegers::operator-=(int& right)
{

	if (this->elementInArray(right) == true)
	{
		this->_size -= 1;
		if (this->_size == 0)
		{
			delete[]this->_arr;
			this->_arr = nullptr;
		}
		else
		{
			int* sub_arr = new int[this->_size];
			if (sub_arr == nullptr)
			{
				cout << "Error\n";
				exit(-1);
			}
			for (int i = 0, j = 0; i < this->_size + 1; i++)
			{
				if (this->_arr[i] != right)
				{
					sub_arr[j] = this->_arr[i];
					j++;
				}
			}
			delete[]this->_arr;
			this->_arr = sub_arr;

		}
	}
	else
	{
		return*this;
	}

	return *this;
}

ArrayIntegers& ArrayIntegers::operator-(ArrayIntegers& right)
{
	ArrayIntegers* temp = new ArrayIntegers();
	if (this->_arr == nullptr)
	{
		temp->_size = 0;
		temp->_arr = nullptr;
	}
	else
	{

		int counter = 0;
		int sub_size = this->_size;
		int* sub_arr = new int[sub_size];
		for (int i = 0, j = 0; i < this->_size; i++)
		{
			if (right.elementInArray(this->_arr[i]) == false)
			{
				sub_arr[j] = this->_arr[i];
				j++;
				counter++;
			}
		}

		temp->_size = counter;
		if (counter == 0) temp->_arr = nullptr;
		else
		{
			temp->_arr = new int[counter];
			for (int i = 0; i < temp->_size; i++)
			{
				temp->_arr[i] = sub_arr[i];
			}

		}

		delete[] sub_arr;

	}
	return *temp;
}

ArrayIntegers& ArrayIntegers::operator-=(ArrayIntegers& right)
{
	if (this->_arr == nullptr)
	{
		return *this;
	}
	else
	{

		int counter = 0;
		int sub_size = this->_size;
		int* sub_arr = new int[sub_size];
		for (int i = 0, j = 0; i < this->_size; i++)
		{
			if (right.elementInArray(this->_arr[i]) == false)
			{
				sub_arr[j] = this->_arr[i];
				j++;
				counter++;
			}
		}

		this->_size = counter;
		delete[]this->_arr;
		if (counter == 0) this->_arr = nullptr;
		else
		{
			this->_arr = new int[counter];
			for (int i = 0; i < this->_size; i++)
			{
				this->_arr[i] = sub_arr[i];
			}

		}

		delete[] sub_arr;

	}
	return *this;
}

ArrayIntegers& ArrayIntegers::operator*(ArrayIntegers& right)
{
	ArrayIntegers* temp = new ArrayIntegers();
	if (this->_arr == nullptr)
	{
		temp->_size = 0;
		temp->_arr = nullptr;
	}
	else
	{

		int counter = 0;
		int sub_size = this->_size;
		int* sub_arr = new int[sub_size];
		for (int i = 0, j = 0; i < this->_size; i++)
		{
			if (right.elementInArray(this->_arr[i]) == true)
			{
				sub_arr[j] = this->_arr[i];
				j++;
				counter++;
			}
		}

		temp->_size = counter;
		if (counter == 0) temp->_arr = nullptr;
		else
		{
			temp->_arr = new int[counter];
			for (int i = 0; i < temp->_size; i++)
			{
				temp->_arr[i] = sub_arr[i];
			}

		}

		delete[] sub_arr;

	}
	return *temp;
}

ArrayIntegers& ArrayIntegers::operator*=(ArrayIntegers& right)
{
	if (this->_arr == nullptr)
	{
		return *this;
	}
	else
	{

		int counter = 0;
		int sub_size = this->_size;
		int* sub_arr = new int[sub_size];
		for (int i = 0, j = 0; i < this->_size; i++)
		{
			if (right.elementInArray(this->_arr[i]) == true)
			{
				sub_arr[j] = this->_arr[i];
				j++;
				counter++;
			}
		}

		this->_size = counter;
		delete[]this->_arr;
		if (counter == 0) this->_arr = nullptr;
		else
		{
			this->_arr = new int[counter];
			for (int i = 0; i < this->_size; i++)
			{
				this->_arr[i] = sub_arr[i];
			}

		}

		delete[] sub_arr;

	}
	return *this;
}

bool ArrayIntegers::operator==(ArrayIntegers& right)
{
	bool equal = true;
	for (int i = 0; i < this->_size; i++)
	{
		if (this->_size != right._size || this->_arr[i] != right._arr[i])
		{
			equal = false;
			break;
		}
	}
	return equal;
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
istream& operator>>(istream& in, ArrayIntegers& right)
{
	if (right._arr == nullptr)
	{
		cout << "Enter amount of elements: ";
		in >> right._size;

		right._arr = new int[right._size];
		if (right._arr == nullptr)
		{
			cout << "Error\n";
			exit(-1);
		}

		cout << "Enter the elements of the array:\n";
		for (int i = 0; i < right._size; i++)
		{
			cout << "Element " << (i + 1) << ": ";
			in >> right._arr[i];
		}

	}
	else
	{
		right._size = 0;
		delete[]right._arr;
		right._arr = nullptr;
		cout << "Enter amount of elements: ";
		in >> right._size;
		right._arr = new int[right._size];
		if (right._arr == nullptr)
		{
			cout << "Error\n";
			exit(-1);
		}
		cout << "Enter the elements of the array:\n";
		for (int i = 0; i < right._size; i++)
		{
			cout << "Element " << (i + 1) << ": ";
			in >> right._arr[i];
		}
	}


	return in;
}


