#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;
    Node* tail;
    CircularLinkedList() : head(nullptr), tail(nullptr) {}
    void append(int val) {
        Node* new_node = new Node(val);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            tail->next = head; } 
		else {
            tail->next = new_node;
            tail = new_node;
            tail->next = head; }
    }

    void display() {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next; } 
		while (temp != head);
        cout << endl;
    }

    int josephus(int n, int k) {
        if (head == nullptr) return -1;
        Node* curr = head;
        Node* prev = tail;
        while (n > 1) {
            for (int i = 1; i < k; i++) {
                prev = curr;
                curr = curr->next; }
            prev->next = curr->next;
            if (curr == head) head = head->next;
            if (curr == tail) tail = prev;
            delete curr;
            curr = prev->next;
            n--; }
        return curr->data;
    }
};

int main() {
    int n = 7, k = 3;
    CircularLinkedList circle;
    for (int i = 1; i <= n; i++) {
        circle.append(i); }
    cout << "Initial circle: ";
    circle.display();
    int survivor = circle.josephus(n, k);
    cout << "The survivor is at position: " << survivor << endl;
    return 0;
}
