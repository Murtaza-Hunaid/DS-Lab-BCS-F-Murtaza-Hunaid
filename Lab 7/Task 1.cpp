#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char name[21];
    int score;
    Node* next;
    Node(const char* n, int s) : score(s), next(nullptr) {
        strncpy(name, n, 20);
        name[20] = '\0';
    }
};

void printList(Node* head) {
    for (Node* p = head; p; p = p->next) {
        cout << p->name << " " << p->score << "\n"; }
    cout << "\n";
}

int getMaxScore(Node* head) {
    int mx = -1;
    for (Node* p = head; p; p = p->next) {
        if (p->score > mx) mx = p->score; }
    return mx;
}

void countingSortPass(Node** headRef, int place) {
    Node* bucket[10] = { nullptr };
    Node* bucketTail[10] = { nullptr };
    Node* cur = *headRef;
    while (cur) {
        int digit = (cur->score / place) % 10;
        Node* nxt = cur->next;
        cur->next = nullptr;
        if (bucket[digit] == nullptr) {
            bucket[digit] = bucketTail[digit] = cur; } 
		else {
            bucketTail[digit]->next = cur;
            bucketTail[digit] = cur; }
        cur = nxt;
    }
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    for (int i = 0; i < 10; ++i) {
        if (bucket[i]) {
            if (newHead == nullptr) {
                newHead = bucket[i];
                newTail = bucketTail[i]; } 
			else {
                newTail->next = bucket[i];
                newTail = bucketTail[i]; } } }
    *headRef = newHead;
}

void radixSortLinkedList(Node** headRef) {
    int maxScore = getMaxScore(*headRef);
    for (int place = 1; maxScore / place > 0; place *= 10) {
        countingSortPass(headRef, place); }
}

void deleteNode(Node** headRef, Node* toDelete) {
    if (!toDelete) {
		return; }
    if (*headRef == toDelete) {
        *headRef = toDelete->next;
        delete toDelete;
        return; }
    Node* prev = *headRef;
    while (prev->next != toDelete) prev = prev->next;
    prev->next = toDelete->next;
    delete toDelete;
}

void addNode(Node** headRef, const char* name, int score) {
    Node* newNode = new Node(name, score);
    newNode->next = *headRef;
    *headRef = newNode;
}

int main() {
    Node* head = nullptr;
    addNode(&head, "Ayan",   90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara",   70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed",  20);
    cout << "Original list:\n";
    printList(head);
    radixSortLinkedList(&head);
    cout << "After Radix sort:\n";
    printList(head);
    cout << "Enter a name to delete or type quit to end: ";
    char target[21];
    while (cin >> target && strcmp(target, "quit") != 0) {
        Node* found = nullptr;
        for (Node* p = head; p; p = p->next) {
            if (strcmp(p->name, target) == 0) {
                found = p;
                break; } }
        if (found) {
            deleteNode(&head, found);
            cout << "Record deleted\n"; } 
		else {
            cout << "Record not found\n"; }
        cout << "Updated list:\n";
        printList(head);
        cout << "Enter another name or end: "; }
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp; }
    return 0;
}
