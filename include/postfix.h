//  Copyright 2020 GHA created by Klykov Anton

#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_

#include <iostream>

enum Prioirty {
    open = 0,
    close = 1,
    plusm = 2,
    multd = 3,
};

std::string infix2postfix(std::string _str);

#endif  // INCLUDE_POSTFIX_H_
