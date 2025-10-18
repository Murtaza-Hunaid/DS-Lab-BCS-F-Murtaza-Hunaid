#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAX = 100;

class Stack {
    int top;
public:
    char a[MAX];
    Stack() { top = -1; }
    bool push(char x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow";
            return false;
        } else {
            a[++top] = x;
            return true;
        }
    }
    char pop() {
        if (top < 0) {
            cout << "Stack Underflow";
            return 0;
        } else {
            char x = a[top--];
            return x;
        }
    }
    char peek() {
        if (top < 0) {
            cout << "Stack is Empty";
            return 0;
        } else {
            char x = a[top];
            return x;
        }
    }
    bool isEmpty() {
        return (top < 0);
    }
};

int getPrecedence(char c) {
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

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string infix) {
    string prefix = "";
    Stack st;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        if (isalnum(c)) {
            prefix = c + prefix;
        } else if (c == ')') {
            st.push(c);
        } else if (c == '(') {
            while (!st.isEmpty() && st.peek() != ')') {
                prefix = st.pop() + prefix;
            }
            if (!st.isEmpty() && st.peek() == ')') {
                st.pop();
            }
        } else if (isOperator(c)) {
            while (!st.isEmpty() && getPrecedence(st.peek()) > getPrecedence(c)) {
                prefix = st.pop() + prefix;
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        prefix = st.pop() + prefix;
    }

    return prefix;
}

int evaluatePrefix(string prefix) {
    Stack s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];       
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        } else {
            int val1 = s.pop();
            int val2 = s.pop();           
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
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl; 
    int result = evaluatePrefix(prefix);
    cout << "Prefix evaluation result: " << result << endl;  
    return 0;
}
