#include "MyStack.h"
#include "postfix.h"
#define MAX 50

std::string infix2postfix(std::string infix) {
    MyStack <char> s(infix.length() + 1);
    char* postfix = new char[infix.length() + 1];
    char x, token;
    int i, j, z = 0;    //i-index of infix, j-index of postfix
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];
        if (token != ' ')
        {
            if (isalnum(token) || token == '.') {
                postfix[j++] = token;
            }
            else {
                if (token == '(')
                    s.push(token);
                else
                    if (token == ')')
                        while ((x = s.pop()) != '(') {
                            postfix[j++] = x;
                        }
                    else {
                        while (precedence(token) <= precedence(s.get()) && !s.isEmpty()) {
                            x = s.pop();
                            postfix[j++] = x;
                        }
                        s.push(token);
                    }
            }
        }
        
    }

    while (!s.isEmpty()) {
        x = s.pop();
        postfix[j++] = x;
    }

    postfix[j] = '\0';

    j = 1;
    char* okey = new char[1000];

    okey[0] = postfix[0];
    for (i = 1; i < infix.length() + 1; i++) {
        if (postfix[i - 1] != '.') {
            okey[j++] = ' ';
            okey[j++] = postfix[i];
        }
    }

    okey[j] = '\0';

    return okey;
}

int precedence(char x) {
    if (x == '(')
        return(0);
    if (x == ')')
        return(1);
    if (x == '+' || x == '-')
        return(2);
    if (x == '*' || x == '/') {
        return(3);
    }

    return(4);
}