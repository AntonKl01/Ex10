//  Copyright 2020 GHA created by Klykov Anton

#include "postfix.h"

#include <iostream>
#include <string>

int main() {
    std::string inf = "2 + 6 * 3 / (4 - 2)";
    std::string postf = infix2postfix(inf);

    for (char i : postf) {
        std::cout << i;
    }
    std::cout << "\n";
}
