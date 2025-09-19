#include <iostream>
using namespace std;

int sumTail(int n, int total) {
    if (n == 0) {
        return total; }
    return sumTail(n - 1, total + n);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int result = sumTail(num, 0);  
    cout << "Sum of numbers from 1 to " << num << " is: " << result << endl;
    return 0;
}
