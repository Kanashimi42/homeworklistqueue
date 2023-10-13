#pragma once
#include <iostream>
#include "Element.h"

using namespace std;

template <class T>
class List {
    Element<T>* Head, * Tail;
    int count;
    int maxQueueLength;

public:
    List(int m);
    ~List();

    void Push(int d);
    void Clear();
    void Extract();

    bool IsEmpty();
    bool IsFull();
    int GetCount();

    void Print();
    void DelAll();
};

template <class T>
List<T>::List(int m) {
    maxQueueLength = m;
}

template <class T>
List<T>::~List() {
    DelAll();
}

template <class T>
void List<T>::Push(int d) {
    if (!IsFull()) {
        Element<T>* temp = new Element<T>(d);
        temp->next = 0;
        temp->prev = Tail;

        if (Tail != 0)
            Tail->next = temp;

        if (count == 0)
            Head = Tail = temp;
        else
            Tail = temp;

        count++;
    }
}

template <class T>
void List<T>::Extract() {
    if (count != 0) {
        Element<T>* del = Head;

        if (count != 1) {
            Element<T>* temp = Head;
            temp = temp->next;
            temp->prev = NULL;
            Head = temp;
        }

        delete del;
        count--;
    }
    else
        cout << "No more elements!" << endl;
}

template <class T>
void List<T>::Clear() {
    count = 0;
    DelAll();
}

template <class T>
bool List<T>::IsEmpty() {
    return count == 0;
}

template <class T>
bool List<T>::IsFull() {
    return count == maxQueueLength;
}

template <class T>
int List<T>::GetCount() {
    return count;
}

template <class T>
void List<T>::Print() {
    if (count != 0) {
        Element<T>* temp = Head;
        while (temp->next != 0) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
    }
    else
        cout << "No more elements!" << endl;
}

template <class T>
void List<T>::DelAll() {
    while (count != 0) {
        int i = 1;
        Element<T>* Del = Head;
        Element<T>* PrevDel = Del->prev;
        Element<T>* AfterDel = Del->next;

        if (PrevDel != 0 && count != 1)
            PrevDel->next = AfterDel;
        if (AfterDel != 0 && count != 1)
            AfterDel->prev = PrevDel;

        Head = AfterDel;
        Tail = PrevDel;

        delete Del;
        count--;
    }
}
