#include <iostream>
using namespace std;

int sumNonTail(int n) {
    if (n == 0) {
        return 0; }
    return n + sumNonTail(n - 1);  
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int result = sumNonTail(num);
    cout << "Sum of numbers from 1 to " << num << " is: " << result << endl;
    return 0;
}
