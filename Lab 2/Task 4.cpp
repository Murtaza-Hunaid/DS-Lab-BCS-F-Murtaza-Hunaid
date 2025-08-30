#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of months: ";
    cin >> n;
    double* expenses = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter expense for month " << (i + 1) << ": Rs. ";
        cin >> expenses[i]; }
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += expenses[i]; }
    double average;
	if (n > 0) {
    	average = total / n; } 
	else {
    	average = 0.0; }
    cout << "\nTotal Expenses: Rs. " << total << endl;
    cout << "Average Expenses: Rs. " << average << endl;
    char choice;
    cout << "\nDo you want to track more months? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        int additional_months;
        cout << "How many more months? ";
        cin >> additional_months;
        double* new_expenses = new double[n + additional_months];
        for (int i = 0; i < n; i++) {
            new_expenses[i] = expenses[i]; }
        delete[] expenses;
        expenses = new_expenses;
        for (int i = n; i < n + additional_months; i++) {
            cout << "Enter expense for month " << (i + 1) << ": $";
            cin >> expenses[i]; }
        n += additional_months;
        total = 0.0;
        for (int i = 0; i < n; i++) {
            total += expenses[i]; }
		if (n > 0) {
    		average = total / n; } 
		else {
    		average = 0.0; }
        cout << "\nTotal Expenses: Rs. " << total << endl;
        cout << "Average Expenses: Rs. " << average << endl; }
    delete[] expenses;
    return 0;
}
