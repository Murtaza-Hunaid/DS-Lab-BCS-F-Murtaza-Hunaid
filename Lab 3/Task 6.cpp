#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

Node* flattenList(Node* head) {
    if (!head) return nullptr;
    Node* current = head;
    while (current) {
        if (!current->child) {
            current = current->next; } 
		else {
            Node* child = current->child;
            while (child->next) {
                child = child->next; }
            child->next = current->next;
            current->next = current->child;
            current->child = nullptr;
            current = current->next; } }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next; }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    cout << "Original List: ";
    printList(head);
    Node* flattened = flattenList(head);
    cout << "Flattened List: ";
    printList(flattened);
    Node* current = flattened;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp; }
    return 0;
}
