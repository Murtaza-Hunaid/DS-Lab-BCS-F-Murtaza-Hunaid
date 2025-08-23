#include <iostream>
#include <cstring>  
using namespace std;

class Exam {
private:
    char* student_name; 
    char* exam_date;     
    int score;

public:
    Exam(const char* name, const char* date, int s) {
        student_name = new char[strlen(name) + 1];
        strcpy(student_name, name);
        exam_date = new char[strlen(date) + 1];
        strcpy(exam_date, date);
        score = s;
    }

    ~Exam() {
        delete[] student_name;
        delete[] exam_date;
        cout << "Destructor called" << endl;
    }

    void display() {
        cout << "Student: " << student_name
             << ", Exam Date: " << exam_date
             << ", Score: " << score << endl;
    }
};

int main() {
    Exam exam1("Murtaza", "23-08-2025", 90);
    cout << "Exam 1 details: ";
    exam1.display();
    Exam exam2 = exam1;
    cout << "Exam 2 details: ";
    exam2.display();
    return 0;
}
