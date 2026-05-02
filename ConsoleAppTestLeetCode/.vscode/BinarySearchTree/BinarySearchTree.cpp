#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;

    return newNode;
}

void Print(Node *root)
{
    if (root == nullptr)
        return;

    std::cout << root->data << " - ";
    Print(root->left);
    Print(root->right);
}

int main()
{
    Node *root = CreateNode(1);

    root->left = CreateNode(2);
    root->right = CreateNode(3);

    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);

    root->left->right->left = CreateNode(9);
    root->right->right->left = CreateNode(15);

    Print(root);
}