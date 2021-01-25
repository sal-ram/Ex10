// Copyright Salakhov Ramazan
#include "MyStack.h"
#include "postfix.h"

int main()
{
    std::string s1("(2 + 8.3) * (6 - 3.2)");
    std::string s2 = infix2postfix(s1);
    std::cout << s2;
}
