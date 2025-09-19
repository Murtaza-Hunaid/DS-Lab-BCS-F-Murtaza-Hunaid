#include <iostream>
using namespace std;

void printNumbs(int n) {
    if (n < 1) {
        return; }
    cout << n << " ";
    printNumbs(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Numbers from " << num << " to 1: ";
    printNumbs(num);
    cout << endl;
    return 0;
}
