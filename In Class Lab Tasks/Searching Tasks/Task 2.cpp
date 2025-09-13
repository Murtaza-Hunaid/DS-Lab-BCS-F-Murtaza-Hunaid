#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
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

int findInsertPosition(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1; } 
		else {
            high = mid - 1; } }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of employee IDs: ";
    cin >> n;
    int arr[n];
    cout << "Enter the employee IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; }
    int target = 82;
    sort(arr, arr + n);
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) {
        cout << "Employee with ID " << target << " found at index " << index << " in the sorted array." << endl; } 
	else {
        int pos = findInsertPosition(arr, 0, n - 1, target);
        int newArr[n + 1];
        for (int i = 0; i < pos; i++) {
            newArr[i] = arr[i]; }
        newArr[pos] = target;
        for (int i = pos; i < n; i++) {
            newArr[i + 1] = arr[i]; }
        cout << "Employee ID " << target << " not found. Inserted at position " << pos << "." << endl;
        cout << "Updated array: ";
        for (int i = 0; i < n + 1; i++) {
            cout << newArr[i] << " "; }
        cout << endl; }
    return 0;
}
