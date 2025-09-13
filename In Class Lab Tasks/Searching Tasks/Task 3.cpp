#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false; }
    return true;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; } } }
}

bool isUniform(int arr[], int n) {
    if (n <= 2) return true;
    int diff = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] != diff)
            return false; }
    return true;
}

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1; }
        int pos = low + ((double)(x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == x) {
			return pos; }
        if (arr[pos] < x) {
            low = pos + 1; }
        else {
            high = pos - 1; } }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of account balances: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter account balances: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; }
    if (!isSorted(arr, n)) {
        cout << "Data not sorted. Sorting" << endl;
        bubbleSort(arr, n); }
    if (!isUniform(arr, n)) {
        cout << "Data is not uniformly distributed. Interpolation Search cannot be done." << endl;
        delete[] arr;
        return 0; }
    int target;
    cout << "Enter balance to search: ";
    cin >> target;
    int index = interpolationSearch(arr, n, target);
    if (index != -1) {
        cout << "Balance " << target << " found at index " << index << endl; }
    else {
        cout << "Balance not found" << endl; }
    delete[] arr;
    return 0;
}
