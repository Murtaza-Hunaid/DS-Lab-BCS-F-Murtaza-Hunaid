#include <iostream>
using namespace std;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

bool isBinaryHeap(int arr[], int n) {
    for (int i = 0; i <= (n / 2) - 1; i++) {
        int l = left(i);
        int r = right(i);
        if (l < n && arr[i] < arr[l]) {
            return false; }
        if (r < n && arr[i] < arr[r]) {
            return false; } }
    return true;
}

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

void heapSortAscending(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapifyDown(arr, i, 0); }
}

int main() {
    int arr[5] = {8, 7, 6, 5, 4};
    int n = 5;
    cout << "Is Heap: " << isBinaryHeap(arr, n) << endl;
    heapSortAscending(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; }
    return 0;
}
