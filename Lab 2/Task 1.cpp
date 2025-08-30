#include <iostream>
using namespace std;

int main() {
    int n, index, value;
    cout << "Enter size of 1D array: ";
    cin >> n;
    int* arr = new int[n]{0}; 
	while (true){
	    cout << "Enter index to update(or 0 to print array): ";
	    cin >> index;
	    if (index == 0){
	    	break; }
	    cout << "Enter new value: ";
	    cin >> value;
	    arr[index-1] = value; }
    cout << "Values in array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; }
    delete[] arr;
    return 0;
}
