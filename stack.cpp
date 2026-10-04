#include "stack.h"
#include <iostream>
using namespace std;


template<typename T>
stack<T>::stack() {
    top = nullptr;
}


template<typename T>
stack<T>::~stack() {
    while (top != nullptr) {
        node<T>* temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename T>
bool stack<T>::is_empty() {
    return top == nullptr;
}

template<typename T>
void stack<T>::push(T x) {
    node<T>* newnode = new node<T>(x);
    newnode->next = top;
    top = newnode;
   
}

template<typename T>
T stack<T>::pop() {
    if (is_empty()) {
        cout << "Stack is empty." << endl;
        return T() ; 
    }
    node<T>* temp = top;
    T val = temp->value;
    top = top->next;
    delete temp;
    return val;
}

template<typename T>
T stack<T>::peek() {
    if (is_empty()) {
        cout << "Stack is empty." << endl;
        return T() ;
    }
    return top->value;
}

template<typename T>
void stack<T>::display() {
    if (is_empty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    node<T>* temp = top;
    while (temp != nullptr) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Explicit template instantiations (to avoid linker errors)
template class stack<int>;
template class stack<double>;
template class stack<string>;
template class stack<char>;