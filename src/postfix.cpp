// Copyright Salakhov Ramazan
#include "MyStack.h"
#include "postfix.h"
#define MAX 50

std::string infix2postfix(std::string infix) {
    MyStack <char> s(infix.length() + 1);
    char* postfix = new char[infix.length() + 1];
    char x, token;
    int i, j, z = 0;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];
        if (token != ' ') {
            if (isalnum(token) || token == '.') {
                postfix[j++] = token;
            } else {
                if (token == '(') {
                    s.push(token);
                } else {
                    if (token == ')') {
                        while ((x = s.pop()) != '(') {
                            postfix[j++] = x;
                        }
                    } else {
                        while (prcd(token) <= prcd(s.get()) && !s.isEmpty()) {
                            x = s.pop();
                            postfix[j++] = x;
                        }
                        s.push(token);
                    }
                }
            }
        }
    }

    while (!s.isEmpty()) {
        x = s.pop();
        postfix[j++] = x;
    }

    postfix[j] = '\0';

    int result = j;
    j = 1;
    char* postfix_probel = new char[infix.length() + 1];

    postfix_probel[0] = postfix[0];
    for (i = 1; i < result + 1; i++) {
        if (postfix[i - 1] != '.' && postfix[i] != '.') {
            postfix_probel[j++] = ' ';
        }
        postfix_probel[j++] = postfix[i];
    }

    postfix_probel[j - 2] = '\0';

    return postfix_probel;
}

int prcd(char x) {
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
