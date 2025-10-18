#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAX = 100;

class Stack {
    int top;
public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow";
            return false;
        } else {
            a[++top] = x;
            return true;
        }
    }
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow";
            return 0;
        } else {
            int x = a[top--];
            return x;
        }
    }
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty";
            return 0;
        } else {
            int x = a[top];
            return x;
        }
    }
    bool isEmpty() {
        return (top < 0);
    }
};

int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string infix) {
    string postfix = "";
    Stack s;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];      
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                char op = s.pop();
                postfix += op;
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();
            }
        } else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }   
    while (!s.isEmpty()) {
        char op = s.pop();
        postfix += op;
    }   
    return postfix;
}

int evaluatePostfix(string postfix) {
    Stack s;   
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];      
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();          
            if (c == '+') {
                s.push(val1 + val2);
            } else if (c == '-') {
                s.push(val1 - val2);
            } else if (c == '*') {
                s.push(val1 * val2);
            } else if (c == '/') {
                s.push(val1 / val2);
            } else if (c == '^') {
                s.push(pow(val1, val2));
            }
        }
    }  
    return s.pop();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix; 
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl; 
    int result = evaluatePostfix(postfix);
    cout << "Postfix evaluation result: " << result << endl;
    return 0;
}
