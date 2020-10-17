//
// Created by Mohamed Hashim on 10/17/2020.
//
#include"bits/stdc++.h"
#include<iostream>

using namespace std;

// BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utitlity function to create a new node
Node *newNode(int data) {
    Node *temp = new Node;

    temp->data = data;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// A utility function to insert a new
// Node with given key in BST
//left node has to be less than or equal the root
//right node has to be greater than the root
Node *insert(Node *root, int key) {
    // Create a new Node containing
    // the new element
    Node *newnode = newNode(key);

    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    Node *x = root;

    // Pointer y maintains the trailing
    // pointer of x
    Node *y = NULL;

    while (x != NULL) {
        y = x;
        if (key < x->data)
            x = x->left;
        else
            x = x->right;
    }

    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;

        // If the new key is less then the leaf node key
        // Assign the new node to be its left child
    else if (key < y->data)
        y->left = newnode;

        // else assign the new node its right child
    else
        y->right = newnode;

    // Returns the pointer where the
    // new node is inserted
    return y;
}

//InOrder traversal (left, root, right)
void inOrder(Node *node) {
    if (node == NULL) {
        cout << "# ";
        return;
    }

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);

}

//PreOrder traversal (root, left, right)
void preOrder(Node *node) {

    if (node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);

}

//PostOrder traversal (left, right, root)
void postOrder(Node *node) {

    if (node == NULL) {
        cout << "# ";
        return;
    }

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";

}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    Node *root = newNode(50);
    insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 100);

    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}

