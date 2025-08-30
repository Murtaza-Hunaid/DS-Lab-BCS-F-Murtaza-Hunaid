#include <iostream>
using namespace std;

int main() {
    int benches, seats, input;
	cout << "Enter number of benches: ";
    cin >> benches;
    cout << "Enter number of seats each bench has: ";
    cin >> seats;
    int** arr = new int*[benches]; 
    for (int i = 0; i < benches; i++) {
        arr[i] = new int[seats]{0}; }
    cout<< "Enter 1 if seat is occupied, else enter 0.\n";
    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
			while (true){
				cout<< "For Bench: " << i+1<<" and ";
				cout<< "Seat: "<< j+1<<"\n";
	            cin >> input;
	            if ((input == 0) || (input == 1)) {
	            	arr[i][j] = input;
	            	break; }
				else {
					cout << "Not valid. Enter 0 or 1.\n"; } } } }
    cout << "Seating Chart:\n";
    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
            cout << arr[i][j] << "."; }
        cout << endl; }
    for (int i = 0; i < benches; i++) {
        delete[] arr[i]; }
    delete[] arr;
    return 0;
}
