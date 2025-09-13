#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--; }
        arr[j + 1] = key; }
}

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; } 
		else if (arr[mid] < target) {
            low = mid + 1; } 
		else {
            high = mid - 1; } }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; }
    cout << endl;
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; }
    insertionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << "Enter the target value to search: ";
    cin >> target;
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl; } 
	else {
        cout << "Element not found" << endl; }
    return 0;
}
