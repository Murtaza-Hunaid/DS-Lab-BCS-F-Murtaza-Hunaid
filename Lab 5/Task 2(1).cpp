#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n < 1) {
        return; }
    cout << n << " ";
    printNumbers(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Numbers from " << num << " to 1: ";
    printNumbers(num);
    cout << endl;
    return 0;
}
