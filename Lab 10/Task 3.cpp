#include <iostream>
using namespace std;

int parent(int i) { return (i - 1) / 2; }
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

void buildMaxHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapifyDown(arr, n, i); }
}

int kthLargest(int arr[], int n, int k) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= n - k + 1; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapifyDown(arr, i, 0); }
    return arr[0];
}

int main() {
    int n, k, i;
    cout << "Enter n: ";
    cin >> n;
    int arr[100];
    for (i = 0; i < n; i++) {
        cin >> arr[i]; }
    cout << "Enter K: ";
    cin >> k;
    cout << kthLargest(arr, n, k);
    return 0;
}

