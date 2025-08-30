#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;

public:
    SafePointer() {
        ptr = new int(0);
    }

    void setValue(int v) {
        *ptr = v;
    }

    int getValue() {
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }

    ~SafePointer() {
        if (ptr != nullptr) {
            delete ptr; }
    }
};

int main() {
    int n = 5;
    SafePointer students[5];
    cout << "Enter marks of " << n << " students:" << endl;
    for (int i = 0; i < n; i++) {
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        students[i].setValue(mark); }
    cout << "\nStored Marks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl; }
    for (int i = 0; i < n; i++) {
        students[i].release(); }
    return 0;
}
