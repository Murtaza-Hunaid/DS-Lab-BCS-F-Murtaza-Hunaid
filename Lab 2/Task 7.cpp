#include <iostream>

using namespace std;

int main() {
    int num_depts;
    cout << "Enter the number of departments: ";
    cin >> num_depts;
    int* emp_counts = new int[num_depts];
    double** salaries = new double*[num_depts];
    for (int i = 0; i < num_depts; i++) {
        cout << "Enter the number of employees in department " << (i + 1) << ": ";
        cin >> emp_counts[i];
        salaries[i] = new double[emp_counts[i]];   
        cout << "Enter salaries for department " << (i + 1) << " employees:" << endl;
        for (int j = 0; j < emp_counts[i]; j++) {
            cout << "Employee " << (j + 1) << ": $";
            cin >> salaries[i][j]; } }
    double* max_salaries = new double[num_depts];
    double* avg_salaries = new double[num_depts];
    int max_avg_dept = 0;
    for (int i = 0; i < num_depts; i++) {
        double max_salary = salaries[i][0];
        double sum = 0.0;      
        for (int j = 0; j < emp_counts[i]; j++) {
            if (salaries[i][j] > max_salary) {
                max_salary = salaries[i][j]; }
            sum += salaries[i][j]; } 
        max_salaries[i] = max_salary;
        if (emp_counts[i] > 0) {
    		avg_salaries[i] = (double)sum / emp_counts[i]; } 
		else {
    		avg_salaries[i] = 0.0; }  
        if (i > 0 && avg_salaries[i] > avg_salaries[max_avg_dept]) {
            max_avg_dept = i; } }
    cout << "\nHighest salary in each department:" << endl;
    for (int i = 0; i < num_depts; i++) {
        cout << "Department " << (i + 1) << ": $" << max_salaries[i] << endl; }
    cout << "\nDepartment with highest average salary:" << endl;
    cout << "Department " << (max_avg_dept + 1) << ": $" << avg_salaries[max_avg_dept] << endl;
    for (int i = 0; i < num_depts; i++) {
        delete[] salaries[i]; }
    delete[] salaries;
    delete[] emp_counts;
    delete[] max_salaries;
    delete[] avg_salaries;
    return 0;
}
