//  Copyright 2020 GHA created by Klykov Anton

#include "postfix.h"
#include "MyStack.h"

#include <cstring>
#include <string>

std::string infix2postfix(std::string _str) {
    MyStack<char> _fixStack(_str.size());
    MyStack<int> _priorityStack(_str.size());
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
        if (_str[i] != ' ') {
            if (is == -1) {
                if (_str[i + 1] == '.') {
                    std::string _temp;
                    size_t k = i;
                    _temp += ' ';
                    while (_str[k] != ' ' && _str[k] != ')') {
                        _temp.push_back(_str[k]);
                        k++;
                    }
                    i = k - 1;
                    _fix += _temp;
                } else {
                    if (_fix.size() != 0) {
                        _fix += ' ';
                        _fix.push_back(_str[i]);
                    } else {
                        _fix.push_back(_str[i]);
                    }
                }
            } else if (is == 0 || _fixStack.isEmpty() ||
                       is > _priorityStack.get()) {
                if (is == 0) {
                    _fixStack.push(_str[i]);
                    _priorityStack.push(0);
                } else if (_fixStack.isEmpty()) {
                    if (is == 2 || is == 3) {
                        _fixStack.push(_str[i]);
                        _priorityStack.push(is);
                    }
                } else if (is > _priorityStack.get()) {
                    _fixStack.push(_str[i]);
                    _priorityStack.push(is);
                }
            } else {
                if (is == 1) {
                    while (_fixStack.get() != '(') {
                        _fix += ' ';
                        _fix.push_back(_fixStack.pop());
                        _priorityStack.pop();
                    }
                    _priorityStack.pop();
                    _fixStack.pop();
                } else if (is <= _priorityStack.get()) {
                    while (is <= _priorityStack.get()) {
                        _fix += ' ';
                        _fix.push_back(_fixStack.pop());
                        _priorityStack.pop();
                    }
                    _fixStack.push(_str[i]);
                    _priorityStack.push(is);
                }
            }
        }
        i++;
    }
    while (!_fixStack.isEmpty()) {
        _fix += ' ';
        _fix.push_back(_fixStack.pop());
    }

    return _fix;
}
