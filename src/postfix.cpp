//  Copyright 2020 GHA created by Klykov Anton

#include "postfix.h"
#include "MyStack.h"

#include <cstring>
#include <string>

std::string infix2postfix(std::string _str) {
    MyStack<char> _fixStack;
    MyStack<int> _priorityStack;
    std::string _fix;
    size_t i{0};
    int is{0};
    while (_str[i] != '\0') {
        switch (_str[i]) {
            case '(':
                is = 0;
                break;
            case ')':
                is = 1;
                break;
            case '+':
                is = 2;
                break;
            case '-':
                is = 2;
                break;
            case '/':
                is = 3;
                break;
            case '*':
                is = 3;
                break;
            case ' ':
                is = -2;
                break;
            default:
                is = -1;
                break;
        }
        if (is == -1) {
            _fix.push_back(_str[i]);
        } else if (is != -2) {
            if (is == 0) {
                _fixStack.push(_str[i]);
                _priorityStack.push(0);
            } else if (_fixStack.isEmpty()) {
                if (is == 2) {
                    _fixStack.push(_str[i]);
                    _priorityStack.push(2);
                } else if (is == 3) {
                    _fixStack.push(_str[i]);
                    _priorityStack.push(3);
                }
            } else if (is > _priorityStack.get()) {
                _fixStack.push(_str[i]);
                _priorityStack.push(is);
            } else if (is == 1) {
                while (_fixStack.get() != '(') {
                    _fix.push_back(_fixStack.pop());
                    _priorityStack.pop();
                }
                _priorityStack.pop();
                _fixStack.pop();
            } else if (is <= _priorityStack.get()) {
                while (is <= _priorityStack.get()) {
                    _fix.push_back(_fixStack.pop());
                    _priorityStack.pop();
                }
                _fixStack.push(_str[i]);
                _priorityStack.push(is);
            }
        }
        i++;
    }
    while (!_fixStack.isEmpty()) {
        _fix.push_back(_fixStack.pop());
    }
    return _fix;
}
