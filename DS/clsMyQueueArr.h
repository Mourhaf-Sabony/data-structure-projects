#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class T>
class clsMyQueueArr
{
protected:

    clsDynamicArray <T> _MyArr;
public:

    void push(T value)
    {
        _MyArr.InsertAtEnd(value);
    }

    void pop()
    {
        _MyArr.DeleteFirstItem();
    }

    void Print()
    {
        _MyArr.PrintList();
    }

    int Size()
    {
        return _MyArr.Size();
    }

    bool IsEmpty()
    {
        return _MyArr.IsEmpty();
    }

    T front()
    {
        return  _MyArr.GetItem(0);
    }

    T back()
    {
        return  _MyArr.GetItem(Size() - 1);
    }

    T GetItem(int index)
    {
        return _MyArr.GetItem(index);
    }

    void Reverse()
    {
        _MyArr.Reverse();
    }

    void UpdateItem(int index, T value)
    {
        _MyArr.SetItem(index, value);
    }

    void InsertAfter(int index, T value)
    {
        _MyArr.InsertAfter(index, value);
    }

    void InsertAtFront(T value)
    {
        _MyArr.InsertAtBeginning(value);
    }

    void InsertAtBack(T value)
    {
        _MyArr.InsertAtEnd(value);
    }

    void Clear()
    {
        _MyArr.Clear();
    }
};

