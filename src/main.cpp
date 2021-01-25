// Copyright Salakhov Ramazan
#include "MyStack.h"
#include "postfix.h"

int main()
{
    std::string s1("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4");
    std::string s2 = infix2prefix(s1);
    std::string s3;
    char* okey = new char[s1.length() + 1];
    okey[0] = s2[0];
    int i = 0, j = 1;
    for (std::string::size_type i = 1; i < s2.size(); ++i) {
        if (s2[i - 1 != '.']) {
            okey[j++] = ' ';
            okey[j++] = s2[i];
        }
    }

    okey [j] = '\0';
    std::cout << okey;  // 2 6 3 * 4 2 - / +
}

