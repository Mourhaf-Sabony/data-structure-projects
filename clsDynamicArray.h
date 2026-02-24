#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:

	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArray;

	clsDynamicArray(int size = 0)
	{
		if (size < 0)
			size = 0;

		_Size = size;
		OriginalArray = new T[size];
	}

	bool SetItem(int index, T value)
	{
		if (index < 0 || index >= _Size)
			return false;

		OriginalArray[index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
	}

	void Resize(int newSize)
	{
		if (newSize < 0)
			newSize = 0;

		_TempArray = new T[newSize];

		if (newSize < _Size)
			_Size = newSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = newSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int index)
	{
			return OriginalArray[index];

	}

	void Reverse()
	{
		_TempArray = new T[_Size];
		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[_Size - (i + 1)] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		delete[] OriginalArray;
		OriginalArray = new T(0);
	}

	bool DeleteItemAt(int index)
	{
		if (index < 0 || index >= _Size)
		{
			return false;
		}

		_Size--;

		_TempArray = new T[_Size];
		//copy all items before index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		//copy all items after index
		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}
		
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T value)
	{
		return DeleteItemAt(Find(value));
	}

	bool InsertAt(int index, T value)
	{
		if (index < 0 || index > _Size)
			return false;

		_Size++;

		_TempArray = new T[_Size];
		//copy all items before index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[index] = value;

		//copy all items after index
		for (int i = index + 1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i - 1];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool InsertAtBeginning(T value)
	{
		return InsertAt(0, value);
	}
	
	bool InsertBefore(int index, T value)
	{
		if (index < 1)
			return InsertAt(0, value);

		return InsertAt(index - 1, value);
	}
	
	bool InsertAfter(int index, T value)
	{
		if (index >= _Size)
			return InsertAt(_Size, value);

		return InsertAt(index + 1, value);
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size, value);
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}
};

