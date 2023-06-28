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

Node* Texfile();  // Matheus mude o nome da função de acordo com o seu módulo



#endif
