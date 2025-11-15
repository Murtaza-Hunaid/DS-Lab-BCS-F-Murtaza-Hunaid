#include <iostream>
using namespace std;

int heap[100];
int heapSize = 0;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void heapifyDown(int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < heapSize && heap[l] > heap[largest])
        largest = l;

    if (r < heapSize && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapifyDown(largest); }
}

void heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = temp;
        i = parent(i); }
}

void insertKey(int val) {
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}

void printHeap() {
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    cout << endl;
}

void update_key(int i, int new_val) {
    int old_val = heap[i];
    heap[i] = new_val;
    if (new_val > old_val) {
        heapifyUp(i); }
    else {
        heapifyDown(i); }
}

void delete_key(int i) {
    heap[i] = heap[heapSize - 1];
    heapSize--;
    heapifyUp(i);
    heapifyDown(i);
}

int main() {
    insertKey(8);
    insertKey(7);
    insertKey(6);
    insertKey(5);
    insertKey(4);
    cout << "Initial Max Heap: ";
    printHeap();
    update_key(3, 10);
    cout << "Heap after update: ";
    printHeap();
    delete_key(1);
    cout << "Heap after delete: ";
    printHeap();
    return 0;
}
