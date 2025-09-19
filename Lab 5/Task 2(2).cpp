#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n < 1) {
        return; }
    cout << n << " ";
    functionB(n - 1);
}

void functionB(int n) {
    if (n < 1) {
        return; }
    cout << n << " ";
    functionA(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Output: ";
    functionA(num);
    cout << endl;
    return 0;
}
