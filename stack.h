#pragma once
template<typename T>


class node {
public:
    T value;
    node<T>* next;
    node(T val) : value(val), next(nullptr) {}
};

template<typename T>
class stack
{
private:
    node<T>* top;
public:
    stack();
    ~stack();
    bool is_empty();
    void push(T x);
    T pop();
    T peek();
    void display();
};



