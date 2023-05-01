/* Copyright (C) Dean Gadberry - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Dean Gadberry <code@deangadberry.com>, 2023
 */
// drawNetworkNodesDG.cpp
// Dean Gadberry
// COSC 2436 0400
// Problem Set 3, Problem 2
// References:
    // https://cplusplus.com/reference/cstring/memset/
    // https://stackoverflow.com/questions/2181375/in-c-how-to-print-ascii-art-to-the-console
    // https://en.wikipedia.org/wiki/Adjacency_matrix

#include <iostream>
#include <cstring>
#include <cctype>

void runAgain();

int main() {
    int num_nodes;

    std::cout << "Enter number of nodes: ";
    std::cin >> num_nodes;

    bool adj_matrix[26][26];
    std::memset(adj_matrix, false, sizeof(adj_matrix));

    std::cout << "Enter node pairs (edges):\n";
    for (int i = 0; i < num_nodes; i++) {
        char node1, node2;
        std::cin >> node1 >> node2;

        node1 = std::toupper(node1);
        node2 = std::toupper(node2);

        adj_matrix[node1-'A'][node2-'A'] = true;
        adj_matrix[node2-'A'][node1-'A'] = true;
    }

    std::cout << "The network:\n";
    for (int i = 0; i < num_nodes; i++) {
        std::cout << static_cast<char>(i+'A') << " ";

        for (int j = 0; j < num_nodes; j++) {
            if (j > i) {
                if (adj_matrix[i][j]) {
                    std::cout << "- ";
                } else {
                    std::cout << "  ";
                }
            } else {
                if (adj_matrix[i][j]) {
                    std::cout << "| ";
                } else {
                    std::cout << "  ";
                }
            }
        }

        std::cout << "\n";
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
