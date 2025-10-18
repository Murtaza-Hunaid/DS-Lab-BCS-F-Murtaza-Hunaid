#include <iostream>
using namespace std;

#define MAX_SIZE 5
int front = -1, rear = -1;
int arr[MAX_SIZE];

bool isFull() {
    return rear == MAX_SIZE - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full, cannot enqueue " << value << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    arr[++rear] = value;
    cout << value << " enqueued successfully." << endl;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty, cannot dequeue." << endl;
        return -1;
    }
    return arr[front++];
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return; }
    cout << "Queue contents: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " "; }
    cout << endl;
}

void checkStatus() {
    if (isFull()) {
        cout << "Queue is full." << endl; } 
    else if (isEmpty()) {
        cout << "Queue is empty." << endl; } 
    else {
        cout << "Queue is neither full nor empty." << endl; }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    checkStatus();
    cout << dequeue() << " dequeued." << endl;
    cout << dequeue() << " dequeued." << endl;
    display();
    checkStatus();
    return 0;
}
