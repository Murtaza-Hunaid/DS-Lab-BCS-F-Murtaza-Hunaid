#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
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

    Node* find_min(Node* node) {
        while (node && node->left != NULL) { 
            node = node->left; }
        return node;
    }

    Node* delete_node(Node* node, int val) {
        if (node == NULL) {
            return node; }
        if (val < node->data) {
            node->left = delete_node(node->left, val); }
        else if (val > node->data) {
            node->right = delete_node(node->right, val); }
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL; }
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp; }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp; }
            else {
                Node* temp = find_min(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data); } }
        return node;
    }

    Node* search(Node* root, int data) {
        if (root == NULL || root->data == data) {
            return root; }
        if (data < root->data) {
            return search(root->left, data); }
        return search(root->right, data);
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right); }
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right); }
    }

    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " "; }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = delete_node(root, val);
    }

    bool search(int val) {
        return search(root, val) != NULL;
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    cout << "Inorder: ";
    tree.displayInorder();
    cout << "Preorder: ";
    tree.displayPreorder();
    cout << "Postorder: ";
    tree.displayPostorder();
    tree.remove(30);
    tree.displayInorder();
    cout << "Search 40: ";
    if (tree.search(40)) {
        cout << "Found" << endl; }
    else {
        cout << "Not found" << endl; }
    cout << "Search 35: ";
    if (tree.search(35)) {
        cout << "Found" << endl; }
    else {
        cout << "Not found" << endl; }
    return 0;
}
