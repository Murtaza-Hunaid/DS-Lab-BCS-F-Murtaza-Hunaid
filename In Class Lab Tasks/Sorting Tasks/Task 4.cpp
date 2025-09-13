#include <iostream>
#include <string>
using namespace std;

int getPriority(const string& designation) {
    if (designation == "CEO") {
		return 1; }
    if (designation == "CTO") { 
		return 2; }
    if (designation == "CFO") { 
		return 3; }
    if (designation == "VP") { 
		return 4; }
    if (designation == "MGR") { 
		return 5; }
    if (designation == "EMP") { 
		return 6; }
    return 7; 
}

void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int keyPriority = getPriority(key);
        int j = i - 1;
        while (j >= 0 && getPriority(arr[j]) > keyPriority) {
            arr[j + 1] = arr[j];
            j--; }
        arr[j + 1] = key; }
}

int main() {
    string desks[] = {"EMP", "CFO", "MGR", "EMP", "VP", "MGR", "CTO", "CEO"};
    int n = sizeof(desks) / sizeof(desks[0]);
    cout << "Original arrangement: ";
    for (int i = 0; i < n; i++) {
        cout << desks[i] << " "; }
    cout << endl;
    insertionSort(desks, n);
    cout << "Sorted arrangement: ";
    for (int i = 0; i < n; i++) {
        cout << desks[i] << " "; }
    cout << endl;
    return 0;
}
