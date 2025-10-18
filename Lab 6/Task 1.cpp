#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
    int top;
public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void display();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    } 
	else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    } 
	else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    } 
	else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return; }
    cout << "Stack contents: ";
    for (int i = top; i >= 0; i--) {
        cout << a[i] << " "; }
    cout << endl;
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); 
    cout << s.pop() << " popped from stack\n";
    cout << "Top element is: " << s.peek() << endl;
    s.display();
    return 0;
}
