/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// nameTraversalsDG.cpp
// Dean Gadberry
// COSC 2436 0400
// Make Up Set, Problem 3
// References:
    // Lecture Videos for Week 12 and 13
    // https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/
    // https://www.digitalocean.com/community/tutorials/level-order-traversal-in-a-binary-tree

#include <iostream>
#include <string>
#include <queue>

struct Node 
{
    char data;
    Node* left;
    Node* right;
};

void runAgain();
void inOrderTraversal(Node* root);
void preOrderTraversal(Node* root);
void postOrderTraversal(Node* root);
void levelOrderTraversal(Node* root);
void reverseOrderTraversal(Node* root);

Node* insert(Node* root, char value) 
{
    if (root == nullptr) 
    {
        root = new Node{value, nullptr, nullptr};
    }
    else if (value <= root->data) 
    {
        root->left = insert(root->left, value);
    }
    else 
    {
        root->right = insert(root->right, value);
    }
    return root;
}

int main() 
{
    char answer;
    std::string name;
    std::cout 
        <<std::endl
        <<"Enter a last name: ";
    std::cin 
        >> name;
    Node* root = nullptr;
    for (char c : name) 
    {
        root = insert(root, c);
    }
    std::cout 
        <<std::endl
        <<"Traversals:" 
        <<std::endl
        <<std::endl
        <<"In Order:           ";
    inOrderTraversal(root);
    std::cout 
        <<std::endl
        <<"Pre Order:          ";
    preOrderTraversal(root);
    std::cout 
        <<std::endl 
        <<"Post Order:         ";
    postOrderTraversal(root);
    std::cout 
        <<std::endl 
        <<"Level Order:        ";
    levelOrderTraversal(root);
    std::cout 
        <<std::endl 
        <<"Reverse Order:      ";
    reverseOrderTraversal(root);
    std::cout 
        <<std::endl;
    runAgain();
    return 0;
}

void inOrderTraversal(Node* root) 
{
    if (root != nullptr) 
    {
        inOrderTraversal(root->left);
        std::cout 
            <<root->data 
            <<" ";
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node* root) 
{
    if (root != nullptr) 
    {
        std::cout 
            <<root->data 
            <<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) 
{
    if (root != nullptr) 
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout 
            <<root->data 
            <<" ";
    }
}

void levelOrderTraversal(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();
        std::cout 
            <<current->data 
            <<" ";
        if (current->left != nullptr) 
        {
            q.push(current->left);
        }
        if (current->right != nullptr) 
        {
            q.push(current->right);
        }
    }
}

void reverseOrderTraversal(Node* root) 
{
    if (root != nullptr) 
    {
        reverseOrderTraversal(root->right);
        std::cout 
            <<root->data 
            <<" ";
        reverseOrderTraversal(root->left);
    }
}

void runAgain()
{
    std::cout
        <<std::endl
        <<"Run Again (Y/N): ";
    std::string user_input;
    std::cin
       >>user_input;
    char input = user_input[0];
    switch (input)
    {
        case 'Y': case 'y': 
            main();
        case 'N': case 'n': 
            break;
        default:
            runAgain();       
    };
}
