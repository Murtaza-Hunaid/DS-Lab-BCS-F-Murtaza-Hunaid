#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

void shellSort(int arr[], int n, int &comparisons, int &swaps) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int res = j;
            while (res >= gap) {
                comparisons++;
                if (arr[res - gap] > temp) {
                    arr[res] = arr[res - gap];
                    swaps++;
                    res -= gap; } 
				else {
                    break; } }
            arr[res] = temp; } }
}

void bubbleSort(int arr[], int n, int &comparisons, int &swaps) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swaps++;
                swapped = true; } }
        if (!swapped) break; }
}

void insertionSort(int arr[], int n, int &comparisons, int &swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j+1] = arr[j];
                swaps++;
                j--; } 
			else {
                break; } }
        arr[j+1] = key; }
}

int main() {
    int n;
    cout << "Enter the array size: ";
    cin >> n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
	// random number and timing(chrono) copied from deepseek
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    for (int i = 0; i < n; i++) {
        int num = dis(gen);
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num; }

    int comparisons = 0, swaps = 0;
    auto start = high_resolution_clock::now();
    shellSort(arr1, n, comparisons, swaps);
    auto stop = high_resolution_clock::now();
    auto duration_shell = duration_cast<microseconds>(stop - start);
    cout << "Shell Sort: Time = " << duration_shell.count() << " microseconds, Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    comparisons = 0; swaps = 0;
    start = high_resolution_clock::now();
    bubbleSort(arr2, n, comparisons, swaps);
    stop = high_resolution_clock::now();
    auto duration_bubble = duration_cast<microseconds>(stop - start);
    cout << "Bubble Sort: Time = " << duration_bubble.count() << " microseconds, Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    comparisons = 0; swaps = 0;
    start = high_resolution_clock::now();
    insertionSort(arr3, n, comparisons, swaps);
    stop = high_resolution_clock::now();
    auto duration_insertion = duration_cast<microseconds>(stop - start);
    cout << "Insertion Sort: Time = " << duration_insertion.count() << " microseconds, Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}
