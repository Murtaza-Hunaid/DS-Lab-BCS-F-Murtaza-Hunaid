#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(nullptr) {}
    void insert(int val) {
        Node* new_node = new Node(val);
        if (!head) {
            head = new_node; } 
		else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next; }
            temp->next = new_node; }
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}
    void convertFromSingly(Node* singly_head) {
        if (!singly_head) return;
        head = new Node(singly_head->data);
        Node* current_doubly = head;
        Node* current_singly = singly_head->next;
        while (current_singly) {
            Node* new_node = new Node(current_singly->data);
            current_doubly->next = new_node;
            new_node->prev = current_doubly;
            current_doubly = new_node;
            current_singly = current_singly->next; }
    }
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() : head(nullptr) {}
    void convertFromSingly(Node* singly_head) {
        if (!singly_head) return;
        head = new Node(singly_head->data);
        Node* curr = head;
        Node* temp = singly_head->next;
        while (temp) {
            Node* new_node = new Node(temp->data);
            curr->next = new_node;
            curr = new_node;
            temp = temp->next; }
        curr->next = head;
    }
};

void printSinglyList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
			cout << " -> "; }
        temp = temp->next; }
    cout << endl;
}

void printDoublyList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
			cout << " -> ";}
        temp = temp->next; }
    cout << endl;
}

void printCircularList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data;
        if (temp->next != head) cout << " -> ";
        temp = temp->next; } 
	while (temp != head);
    cout << endl;
}

int main() {
    SinglyLinkedList singly_list;
    singly_list.insert(1);
    singly_list.insert(2);
    singly_list.insert(3);
    singly_list.insert(4);
    cout << "Original Singly Linked List: ";
    printSinglyList(singly_list.head);
    DoublyLinkedList doubly_list;
    doubly_list.convertFromSingly(singly_list.head);
    cout << "Converted to Doubly Linked List: ";
    printDoublyList(doubly_list.head);
    CircularLinkedList circular_list;
    circular_list.convertFromSingly(singly_list.head);
    cout << "Converted to Circular Linked List: ";
    printCircularList(circular_list.head);
    Node* current = singly_list.head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp; }
    current = doubly_list.head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp; }
    current = circular_list.head;
    if (current) {
        Node* start = current;
        do {
            Node* temp = current;
            current = current->next;
            delete temp; } 
		while (current != start); }
    return 0;
}
