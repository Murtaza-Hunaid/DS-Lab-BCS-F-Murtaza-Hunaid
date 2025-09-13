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
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode; }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next; }
    temp->next = newNode;
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

Node* mergeSorted(Node* a, Node* b) {
    if (a == nullptr) {
    	return b; } 
    if (b == nullptr) {
		return a; }
    Node* head = nullptr;
    Node* tail = nullptr;
    if (a->data <= b->data) {
        head = a;
        a = a->next; } 
	else {
        head = b;
        b = b->next; }
    tail = head;
    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next; } 		
		else {
            tail->next = b;
            b = b->next; }
        tail = tail->next; }
    if (a != nullptr) {
		tail->next = a; }
    if (b != nullptr) { 
		tail->next = b; }
    return head;
}

int main() {
    Node* listA = nullptr;
    Node* listB = nullptr;
    int n, m, value;
    cout << "Enter number of nodes in List A: ";
    cin >> n;
    cout << "Enter elements of List A:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        listA = insertEnd(listA, value); }
    cout << "Enter number of nodes in List B: ";
    cin >> m;
    cout << "Enter elements of List B:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> value;
        listB = insertEnd(listB, value); }
    cout << "List A: ";
    printList(listA);
    cout << "List B: ";
    printList(listB);
    Node* merged = mergeSorted(listA, listB);
    cout << "Merged List: ";
    printList(merged);
    return 0;
}
