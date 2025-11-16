#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val); }
        if (val < node->data) {
            node->left = insert(node->left, val); } 
		else if (val > node->data) {
            node->right = insert(node->right, val); }
        return node;
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right); }
    }

    int countNodes(Node* node) {
        if (node == NULL) {
			return 0; }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void findKth(Node* node, int k, int& count, int& result) {
        if (node == NULL || count >= k) {
			return; }
        findKth(node->left, k, count, result);   
        count++;
        if (count == k) {
            result = node->data;
            return; }       
        findKth(node->right, k, count, result);
    }

public:
    BST() : root(NULL) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void displayInorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    double findMedian() {
        int n = countNodes(root);
        if (n == 0) {
            throw runtime_error("Tree is empty"); }       
        if (n % 2 == 1) {
            int count = 0, result = 0;
            findKth(root, (n + 1) / 2, count, result);
            return result; } 
		else {
            int count1 = 0, result1 = 0;
            int count2 = 0, result2 = 0;
            findKth(root, n / 2, count1, result1);
            findKth(root, n / 2 + 1, count2, result2);
            return (result1 + result2) / 2.0; }
    }

    int getNodeCount() {
        return countNodes(root);
    }
};

int main() {
    BST tree1;
    int values1[] = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values1) {
        tree1.insert(val); }  
    tree1.displayInorder();
    cout << "Number of nodes: " << tree1.getNodeCount() << endl;
    cout << "Median: " << tree1.findMedian() << endl;
    cout << endl;   
    BST tree2;
    int values2[] = {5, 3, 7, 2, 4, 6};
    for (int val : values2) {
        tree2.insert(val); }   
    tree2.displayInorder();
    cout << "Number of nodes: " << tree2.getNodeCount() << endl;
    cout << "Median: " << tree2.findMedian() << endl; 
    return 0;
}
