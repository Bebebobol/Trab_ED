#include <iostream>
#include <fstream>
#include <stack>
#include <chrono>



using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    if (!newNode) {
        cout << "Memory allocation failed!";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countNodes(Node* root)
{
 
    int l = coutNodes(head->left);
    int r = countNodes(head->right);
 
    return 1 + l + r;
}

int MorrisTraversal(Node* head, int num){
    int arr;
    
    if (head == NULL){
        return 0;
    }
    Node* current = head;
    
    for(int i = 0; i < num; i++) {
        if (current->left == NULL) {
            int arr[i] = current->data;
            current = current->right;
        }
        else {
            Node* pre = current->left;
            while (pre->right != NULL
                   && pre->right != current) {
                pre = pre->right;

            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            else {
                pre->right = NULL;
                int arr[i] = current->data;
                current = current->right;
            } 
            }
        }
    }
    return arr;
    
}

int print_height(Node* head) {
    int l;
    int r;
    if (head == NULL){
        return 0;
    }
    else {
        int l = print_height(head->left);
        int r = print_height(head->right);
        if (l >= r)
            return l + 1;
        else
            return r + 1;
    }

}

int print_height(Node* head) {
    int l;
    int r;
    Node* temp = head;
    if(head == NULL){
        return 0;
    }
    else {
        int l = print_height(temp->left);
        int r = print_height(temp->right);
        if (l >= r)
            return l + 1;
        else
            return r + 1;
    }
}



int leafnum(Node* head){
    if(head == NULL)    
        return 0;
    if(head->left == NULL && head->right == NULL)
        return 1;        
    else
        return leafnum(head->left)+
            leafnum(head->right);
}

bool Check_perfect(Node* head, int height, int leafnum) {
    if (head == NULL) {
        return false;
    }
    else if(height == 1 && leafnum == 1) {
        return true;
    }
    else if (leafnum == pow(2, height - 1)) {
        return true;
    }
    else {
        return false;
    }
}


Node* InsertNode(Node* head, int value) {
    if (head == NULL) {
        head = createNode(value);
        return head;

    } else {
        Node* temp = head;
        while (temp->left != NULL || temp->right != NULL) {
            if (temp->data > value) {
                if (temp->left != NULL) {
                    temp = temp->left;
                } else {
                    temp->left = createNode(value);
                    break;
                }
            } else if (temp->data < value) {
                if (temp->right != NULL) {
                    temp = temp->right;
                } else {
                    temp->right = createNode(value);
                    break;
                }
            } else {
                // Duplicate value, handle accordingly
                break;
            }
        }
    }
    return head;
}

void printInorder(Node* head)
{
    if (head == NULL)
        return;
 
    // First recur on left child
    printInorder(head->left);
 
    // Then print the data of node
    printf("%d ", head->data);
 
    // Now recur on right child
    printInorder(head->right);
}

Node* createBinaryTreeFromFile() {
}

double printProcessingTime(function<void()> func) {
    //get inicial time
    auto startTime = high_resolution_clock::now(); 

    func();

    //ending time
    auto endTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(endTime - startTime);

    return duration.count() / 1000000.0; //in seconds
}


void mainMenu() {
    while (true) {
        cout << "Binary Tree Menu:" << endl;
        cout << "1. Create Binary Tree from Manual Inputs" << endl;
        cout << "2. Create Binary Tree from File" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                createBinaryTreeManual();
                break;
            case 2:
                createBinaryTreeFromFile();
                break;
            case 3:
                cout << "Exiting the program..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
