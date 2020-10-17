//
// Created by Mohamed Hashim on 10/17/2020.
//

#include"bits/stdc++.h"
#include<iostream>

using namespace std;


struct node {
    int data;
    struct node *left, *right;
};

/* Function to insert new nodes to the tree. */
struct node *newNode(int data) {
    struct node *node;
    node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to insert the formed nodes to the binary tree when a parent node does not have a left or the right child. */
/* insertion in the queue (root, root->left, root->right, root->left->left, root->left->right, root->right->left, root->right->right) */
void insert(node *root, int data) {
    struct node *temp;
    queue<struct node *> q;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        /* Insert node as the left child of the parent node. */
        if (temp->left == NULL) {
            temp->left = newNode(data);
            break;
        }

            /* If the left node is not null push it to the queue. */
        else
            q.push(temp->left);

        /* Insert node as the right child of the parent node. */
        if (temp->right == NULL) {
            temp->right = newNode(data);
            break;
        }

            /* If the right node is not null push it to the queue. */
        else
            q.push(temp->right);
    }
}

//InOrder traversal (left, root, right)
void inOrder(node *node) {
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);

}

//PreOrder traversal (root, left, right)
void preOrder(node *node) {

    if (node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);

}

//PostOrder traversal (left, right, root)
void postOrder(node *node) {

    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";

}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    node *root = newNode(50);
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