// Copyright Salakhov Ramazan
#include "MyStack.h"
#include "postfix.h"

int main()
{
    std::string s1("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4");
    std::string s2 = infix2postfix(s1);
    std::string s3;
    std::cout << s2;
}

