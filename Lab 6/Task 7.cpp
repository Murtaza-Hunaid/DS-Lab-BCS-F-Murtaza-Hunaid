#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class Queue {
public:
	int front, rear;
    int arr[MAX];
    Queue() { front = -1; rear = -1; }
    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    
    bool isFull() {
        return rear == MAX - 1;
    }
    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front++];
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Stack {
    int top;
public:
    int a[MAX];
    Stack() { top = -1; }
    
    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow";
            return false;
        } else {
            a[++top] = x;
            return true;
        }
    }
    
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow";
            return 0;
        } else {
            int x = a[top--];
            return x;
        }
    }
    
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty";
            return 0;
        } else {
            int x = a[top];
            return x;
        }
    }
    
    bool isEmpty() {
        return (top < 0);
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

struct Process {
    int id;
    int priority;
};

int main() {
    Queue arrivalQueue; 
    Stack executionStack; 
    cout << "Job Scheduling System:-\n";
    cout << "\n1. Processes arriving and stored in queue:\n";
    Process processes[] = {
        {101, 2}, {102, 1}, {103, 3}, {104, 2}, {105, 3} };  
    for (int i = 0; i < 5; i++) {
        arrivalQueue.enqueue(processes[i].id * 10 + processes[i].priority);
        cout << "Process " << processes[i].id << " (Priority " << processes[i].priority << ") arrived\n"; }  
    arrivalQueue.display();
    cout << "\n2. Transferring high priority tasks to stack:\n";
    int highest_priority = 0;
    int temp_queue[MAX];
    int temp_front = arrivalQueue.front;
    int temp_rear = arrivalQueue.rear;
    for (int i = temp_front; i <= temp_rear; i++) {
        int process_data = arrivalQueue.arr[i];
        int priority = process_data % 10;
        if (priority > highest_priority) {
            highest_priority = priority; } }
    cout << "Highest priority found: " << highest_priority << endl;    
    while (!arrivalQueue.isEmpty()) {
        int process_data = arrivalQueue.dequeue();
        int processId = process_data / 10;
        int priority = process_data % 10;        
        if (priority == highest_priority) {
            executionStack.push(process_data);
            cout << "High priority process " << processId << " pushed to stack\n"; } 
		else {
            arrivalQueue.enqueue(process_data); } }
    cout << "\n3. Execution order using LIFO from stack:\n";
    executionStack.display();
    arrivalQueue.display();
    cout << "\n4. Executing processes:\n";
    while (!executionStack.isEmpty()) {
        int process_data = executionStack.pop();
        int processId = process_data / 10;
        int priority = process_data % 10;
        cout << "Executing Process " << processId << " (Priority " << priority << ")\n"; }
    cout << "\n5. Remaining lower priority processes in queue:\n";
    arrivalQueue.display();   
    return 0;
}
