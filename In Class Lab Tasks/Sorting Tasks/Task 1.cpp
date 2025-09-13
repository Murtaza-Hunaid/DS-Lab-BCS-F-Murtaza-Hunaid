#include <iostream>
using namespace std;

void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; } } }
}

int main() {
    int arr[10] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};
    int n = 10;
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; }
    cout << endl;
    bubbleSortDescending(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; }
    cout << endl;
    return 0;
}
