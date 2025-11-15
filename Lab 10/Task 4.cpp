#include <iostream>
using namespace std;

int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void heapifyDown(int arr[], int n, int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    if (l < n && arr[l] > arr[largest]) {
        largest = l; }
    if (r < n && arr[r] > arr[largest]) { 
        largest = r; }
    if (largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapifyDown(arr, n, largest); }
}

void convertMinToMax(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapifyDown(arr, n, i); }
}

int main() {
    int n, i;
    int arr[100];
    cout << "Enter n: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> arr[i]; }
    convertMinToMax(arr, n);
    for (i = 0; i < n; i++) {
        cout << arr[i] << " "; }
    return 0;
}
