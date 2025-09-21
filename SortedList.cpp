
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = -1;  // 0
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {

    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    // 1. Find where item goes
    int i;
    for (int i = 0; i < length; i++)
    {
        // Find the correct position
        if (item <= info[i])
        {
            break;
        }
    }
    // slide over items
    for (int j = length; j >= i + 1 ; j--)
    {
        info[j] = info[j - 1];

    }
    // insert item
    info[i] = item;
    ++length;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    // find the item
    for (int i = 0; i < length; i++)
    {
        // Find the correct position
        if (item == info[i])
        {
            for (int j = i; j < length ; j++)
            {
                info[j] = info[j + 1];

            }
            --length;
            return;
        }
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}

