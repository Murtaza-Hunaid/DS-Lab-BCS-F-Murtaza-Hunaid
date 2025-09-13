#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* insertEnd(Node* head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        return new_node; }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; }
    temp->next = new_node;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next; }
    cout << endl;
}

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr) return nullptr;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next_node = nullptr;
    int count = 0;
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == nullptr) return head;
        temp = temp->next; }
    while (curr != nullptr && count < k) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
        count++; }
    if (next_node != nullptr) {
        head->next = reverseKGroup(next_node, k);  }
    return prev;
}

int main() {
    Node* head = nullptr;
    int n, value, k;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value); }
    cout << "Enter k: ";
    cin >> k;
    cout << "Original List Input: ";
    printList(head);
    cout << "with k = " << k << "\n";
    head = reverseKGroup(head, k);
    cout << "Reversed List Output: ";
    printList(head);
    return 0;
}
