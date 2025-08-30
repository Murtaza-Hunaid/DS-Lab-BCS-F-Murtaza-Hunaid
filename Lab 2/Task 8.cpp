#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter number of temperature readings per day: ";
    cin >> m;
    double** temps = new double*[n];
    for (int i = 0; i < n; i++) {
        temps[i] = new double[m]; }
    for (int i = 0; i < n; i++) {
        cout << "Enter temperatures for day " << (i + 1) << ":" << endl;
        for (int j = 0; j < m; j++) {
            cout << "Reading " << (j + 1) << ": ";
            cin >> temps[i][j]; } }
    double* daily_avgs = new double[n];
    int hottest_day = 0, coldest_day = 0;
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < m; j++) {
            sum += temps[i][j]; }
        if (m > 0) {
            daily_avgs[i] = sum / m; } 
		else {
            daily_avgs[i] = 0.0; }
        if (i > 0) {
            if (daily_avgs[i] > daily_avgs[hottest_day]) {
                hottest_day = i; }
            if (daily_avgs[i] < daily_avgs[coldest_day]) {
                coldest_day = i; } } }
    cout << "\nDaily Average Temperatures:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Day " << (i + 1) << ": " << daily_avgs[i] << " C" << endl; }
    cout << "\nHottest Day: Day " << (hottest_day + 1) << " with average " << daily_avgs[hottest_day] << " C" << endl;
    cout << "Coldest Day: Day " << (coldest_day + 1) << " with average " << daily_avgs[coldest_day] << " C" << endl;
    for (int i = 0; i < n; i++) {
        delete[] temps[i]; }
    delete[] temps;
    delete[] daily_avgs;
    return 0;
}
