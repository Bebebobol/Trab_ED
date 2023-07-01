#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value);

Node* InsertNode(Node* head, int value);

void mainMenu();

int countNodes(Node* head);

void bubbleSort(int arr[], int n);

void printInorder(Node* head);

void BFS(Node* head, int height);

int MorrisTraversal(Node* head, int num);

bool checkComplete ( Node* head, int index, int count);

int print_height(Node* head);

double printProcessingTime(function<void()> func);

void shellsort(int arr[], int count);

void selectionSort(int arr[], int count);

void insertionSort(int arr[], int count);

int leafnum(Node* head);

bool Check_perfect(Node* head, int height, int leafnum);

Node* createBinaryTreeManual(Node* pRoot);

Node* convertFileToBST(const char* ccFilename);

Node* deleteNode (Node* pRoot, int nValue);

Node* printAddress(Node* root, int value);

#endif
