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
        } else if (_str[i] != ' ') {
            if (_str[i] == '(') {
                _fixStack.push(_str[i]);
                _priorityStack.push(open);
            } else if (_fixStack.isEmpty()) {
                if (_str[i] == ')') {
                    _fixStack.push(_str[i]);
                    _priorityStack.push(close);
                } else if (_str[i] == '+' || _str[i] == '-') {
                    _fixStack.push(_str[i]);
                    _priorityStack.push(plusm);
                } else if (_str[i] == '*' || _str[i] == '/') {
                    _fixStack.push(_str[i]);
                    _priorityStack.push(multd);
                }
            } else if (is > _priorityStack.get()) {
                _fixStack.push(_str[i]);
                _priorityStack.push(is);
            } else if (_str[i] == ')') {
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
