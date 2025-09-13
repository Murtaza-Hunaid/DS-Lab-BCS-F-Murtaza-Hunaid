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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next_node = nullptr;
    while (curr != nullptr) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node; }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; }
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; }
    Node* second_half = reverseList(slow->next);
    Node* first_half = head;
    Node* temp = second_half;
    while (temp != nullptr) {
        if (first_half->data != temp->data) {
            return false; }
        first_half = first_half->next;
        temp = temp->next; }
    return true;
}

int main() {
    Node* head = nullptr;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value); }
    if (isPalindrome(head)) {
        cout << "True" << endl; } 
	else {
        cout << "False" << endl; }
    return 0;
}
