/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// treeStructureDG.cpp
// Dean Gadberry
// COSC 2436 0400
// Problem Set 3, Problem 2
// References:

#include <iostream>
#include <string>

void runAgain();

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

bool checkIdentical(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    return checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right);
}

int main() {
    char choice;
    Node* root1 = nullptr;
    Node* root2 = nullptr;
    
    // Input tree 1
    std::cout 
        << "Enter tree 1: ";
    int val;
    while (std::cin >> val) {
        root1 = insertNode(root1, val);
        if (std::cin.get() == '\n') {
            break;
        }
    }
    
    // Input tree 2
    std::cout 
        << "Enter tree 2: ";
    while (std::cin >> val) {
        root2 = insertNode(root2, val);
        if (std::cin.get() == '\n') {
            break;
        }
    }
    
    if (checkIdentical(root1, root2)) {
        std::cout 
            << "Same structure." 
            << std::endl;
    }
    else {
        std::cout 
            << "Not same structure." 
            << std::endl;
    }
   runAgain();
   return 0;
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

