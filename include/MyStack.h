// Copyright Salakhov Ramazan

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

template <typename T>
class MyStack {
 private:
    T* stackPtr;
    int size;
    T top = 0;

 public:
    explicit MyStack(int n_size) {
        size = n_size;
        stackPtr = new T[size];
    }

    MyStack(const MyStack& another_stack) {
        size = another_stack.size;
        stackPtr = new T[size];
        top = another_stack.top;

        for (unsigned int i = 0; i < top; i = i + 1)
            stackPtr[i] = another_stack.stackPtr[i];
    }

    ~MyStack() {
        delete[] stackPtr;
    }

    void push(T value) {
        stackPtr[top] = value;
        top++;
    }

    T pop() {
        top--;
        return stackPtr[top];
    }

    T get() const {
        return stackPtr[top - 1];
    }

    bool isFull() const {
        if (top == size) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() const {
        if (top == 0) {
            return true;
        } else {
            return false;
        }
    }
};
