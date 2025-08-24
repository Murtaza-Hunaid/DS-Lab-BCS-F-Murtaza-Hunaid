#include <iostream>
using namespace std;

class Box {
private:
    int* size;

public:
    Box(int s) {
        size = new int(s);
    }

    ~Box() {
        delete size;
        cout << "Destructor called" << endl;
    }

    Box(const Box &obj) {
        size = new int(*obj.size);
    }

    Box& operator=(const Box &obj) {
        if (this != &obj) {
            delete size;
            size = new int(*obj.size); }
        return *this;
    }

    void setSize(int s) {
        *size = s;
    }

    void display() const {
        cout << "Box size: " << *size << endl;
    }
};

int main() {
    cout << "Shallow Copy Behavior:-" << endl;
    int* p = new int(10);
    int* q = p;
    cout << "Original value: " << *p << endl;
    *q = 20;
    cout << "After modifying q, p = " << *p << endl;
    delete p;
    cout << "\nDeep Copy(Rule of Three) Behavior:-" << endl;
    Box box1(30);
    cout << "Box1 "; 
    box1.display();
    Box box2 = box1;
    cout << "Box 2(after copying from Box 1) "; 
    box2.display();
    box2.setSize(50);
    cout << "After modifying Box 2:" << endl;
    cout << "Box 1 "; 
    box1.display();
    cout << "Box 2 "; 
    box2.display();
    Box box3(100);
    cout << "Box 3 "; 
    box3.display();
    box3 = box1;
    cout << "After assigning Box 1 to Box 3:" << endl;
    cout << "Box 1 "; 
    box1.display();
    cout << "Box 3 "; 
    box3.display();
    return 0;
}
