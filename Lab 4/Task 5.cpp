#include <iostream>

using namespace std;

int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            if (arr[left] == target) return left;
            return -1; }
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if (pos < 0 || pos >= size) {
            return -1; }
        if (arr[pos] == target) {
            return pos; }
        if (arr[pos] < target) {
            left = pos + 1; } 
		else {
            right = pos - 1; } }
    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " "; }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size]; 
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i]; }
    int target;
    cout << "Enter the target value to search: ";
    cin >> target;
    cout << "Array: ";
    printArray(arr, size);
    int result = interpolationSearch(arr, size, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl; } 
	else {
        cout << "Element not found in the array" << endl; }
    return 0;
}
