#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* node = new Node;
    node->data = value;
    node->left = node->right = nullptr;

    return node;
}

void Print(Node* root)
{
    if(root==nullptr)
    return;

    std::cout << root->data << " - " ;
    Print(root->left);
    Print(root->right);
}


int main()
{
    //level 01
    Node* root = createNode(1);

    //level 02
    root->left = createNode(2);
    root->right = createNode(3);

    //level 03
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    //level 04
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    Print(root);
}