#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value);

Node* InsertNode(Node* head, int value);

void bubbleSort(int arr[]);

void printInorder(Node* head);

int countNodes(Node* root);

int MorrisTraversal(Node* head, int num);

int print_height(Node* head);

Node* createBinaryTreeManual(Node* root);

Node* convertFileToBST(const char* ccFilename);

Node* convertSpaceToBreak(Node* sfileNums);

Node* deleteNode (Node* root, int value);


#endif
