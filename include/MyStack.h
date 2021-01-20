//  Copyright 2020 GHA created by Klykov Anton

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template<typename T>
class MyStack {
 private:
    T* stack;
    size_t length;
    size_t top;

 public:
    ~MyStack() {
        delete[] stack;
        stack = nullptr;
    }
    explicit MyStack(size_t _size) {
        length = _size;
        top = 0;
        stack = new T[length];
    }
    MyStack(const MyStack& Stack) {
        length = Stack.length;
        top = Stack.top;
        stack = new T[length];
        for (size_t i = 0; i < length; ++i) {
            stack[i] = Stack.stack[i];
        }
    }
    T get() const {
        if (!(*this).isEmpty()) {
            return stack[top - 1];
        }
        return 0;
    }
    T pop() {
        if (!(*this).isEmpty()) {
            T last = stack[top - 1];
            top--;
            T* _tempStack = new T[top];
            for (int i = 0; i < top; ++i) {
                _tempStack[i] = stack[i];
            }
            delete[] stack;
            stack = _tempStack;
            _tempStack = nullptr;
            return last;
        }
        return 0;
    }
    void push(T _value) {
        if (!(*this).isFull()) {
            top++;
            T* _tempStack = new T[top];
            for (int i = 0; i < top - 1; ++i) {
                _tempStack[i] = stack[i];
            }
            _tempStack[top - 1] = _value;
            delete[] stack;
            stack = _tempStack;
            _tempStack = nullptr;
        }
    }
    [[nodiscard]] bool isFull() const {
        if (length == top) {
            return true;
        }
        return false;
    }
    [[nodiscard]] bool isEmpty() const {
        if (top == 0) {
            return true;
        } else {
            return false;
        }
    }
};

#endif  //  INCLUDE_MYSTACK_H_
