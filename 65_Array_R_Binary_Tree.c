#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15  // Maximum size of the binary tree array

// Function to print     the binary tree (array representation)
void printTree(int tree[], int size) {
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1)  // Ignore empty (-1) nodes
            printf("Node at index %d: %d\n", i, tree[i]);
    }
}

// Function to get left and right children of a node
void getChildren(int tree[], int index) {
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    printf("Parent Node: %d\n", tree[index]);

    if (leftIndex < MAX_SIZE && tree[leftIndex] != -1)
        printf("  Left Child: %d\n", tree[leftIndex]);
    else
        printf("  No Left Child\n");

    if (rightIndex < MAX_SIZE && tree[rightIndex] != -1)
        printf("  Right Child: %d\n", tree[rightIndex]);
    else
        printf("  No Right Child\n");
}

int main() {
    // Initialize tree with -1 (indicating empty nodes)
    int tree[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }

    // Manually inserting elements in a binary tree
    tree[0] = 10;  // Root
    tree[1] = 20;  // Left child of 10
    tree[2] = 30;  // Right child of 10
    tree[3] = 40;  // Left child of 20
    tree[4] = 50;  // Right child of 20
    tree[5] = 60;  // Left child of 30
    tree[6] = 70;  // Right child of 30

    printf("Binary Tree (Array Representation):\n");
    printTree(tree, MAX_SIZE);

    // Get children of a specific node
    printf("\nFetching children of node at index 1:\n");
    getChildren(tree, 0);  // Getting children of node at index 1 (value 20)

    return 0;
}
