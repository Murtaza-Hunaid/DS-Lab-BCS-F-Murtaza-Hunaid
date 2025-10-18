#include <iostream>
using namespace std;

struct Node {
    int pageNumber;
    Node *next;
};

Node *top = NULL;

void push(int pageNumber) {
    Node *newNode = new Node;
    newNode->pageNumber = pageNumber;
    newNode->next = top;
    top = newNode;
    cout << "Visited page: " << pageNumber << endl;
}

void pop() {
    if (top == NULL) {
        cout << "No previous page to go back to" << endl; }
    else {
        cout << "Going back from page: " << top->pageNumber << endl;
        Node *temp = top;
        top = top->next;
        delete temp; }
}

void peek() {
    if (top == NULL) {
        cout << "No current page" << endl; }
    else {
        cout << "Currently on page: " << top->pageNumber << endl; }
}

void display() {
    if (top == NULL) {
        cout << "No pages visited yet" << endl; }
    else {
        cout << "\nVisited pages:\n";
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->pageNumber << endl;
            temp = temp->next; } }
}

int main() {
    int choice, pageNumber;
    while (true) {
        cout << "\nPage Navigation System:-\n";
        cout << "1. Visit new page\n";
        cout << "2. Go back\n";
        cout << "3. Show current page\n";
        cout << "4. Show visited pages\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter page number: ";
            cin >> pageNumber;
            push(pageNumber); } 
        else if (choice == 2) {
            pop(); } 
        else if (choice == 3) {
            peek(); } 
        else if (choice == 4) {
            display(); } 
        else if (choice == 5) {
            break; } 
        else {
            cout << "Invalid choice\n"; } }
    return 0;
}
