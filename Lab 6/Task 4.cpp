#include <iostream>
using namespace std;

const int N = 4;

int arr[N];
int rear = -1;
int front = -1;

bool isEmpty()
{
    if(front == -1 && rear == -1)
        return true;
    else
        return false;
}

bool isFull()
{
    if((rear + 1) % N == front)
        return true;
    else
        return false;
}

void enqueue(int value)
{
    if(isFull())
    {
        cout << "Queue is full, cannot enqueue " << value << endl;
        return;
    }
    else if(isEmpty())
    {
        rear = front = 0;
    }
    else
    {
        rear = (rear + 1) % N;
    }
    arr[rear] = value;
    cout << value << " enqueued\n";
}

int dequeue()
{
    int x = 0;
    if(isEmpty())
    {
        cout << "Queue is empty, cannot dequeue" << endl;
        return -1;
    }
    else if(front == rear)
    {
        x = arr[front];
        front = rear = -1;
    }
    else
    {
        x = arr[front];
        front = (front + 1) % N;
    }
    return x;
}

void display()
{
    if(isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    
    cout << "Queue elements: ";
    int i = front;
    while(true)
    {
        cout << arr[i] << " ";
        if(i == rear)
            break;
        i = (i + 1) % N;
    }
    cout << endl;
}

int main() {
    cout << "Circular Queue:-\n";
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    enqueue(50);
    cout << dequeue() << " dequeued\n";
    cout << dequeue() << " dequeued\n";
    display();  
    enqueue(50);
    enqueue(60);
    display();
    cout << dequeue() << " dequeued\n";
    cout << dequeue() << " dequeued\n";
    cout << dequeue() << " dequeued\n";
    display();
    cout << dequeue() << " dequeued\n";
    return 0;
}
