#include <iostream>
#include <fstream>
#include <stack>
#include <chrono>



using namespace std;

struct Node {  // Estrutura do nó
    int data; 
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node; // Crie um novo elemento da estrutura
    if (!newNode) { // Caso não seja possível criar devido há falta de memória
        cout << "Memory allocation failed!";
        return NULL;
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countNodes(Node* head){ // Módulo de contagem de nós recursivo
    int l = countNodes(head->left); // Conta sub-árvore esquerda
    int r = countNodes(head->right); // Conta a direita
 
    return 1 + l + r; // Retorna a soma das duas mais 1, devdio a não contabilização da root
}

int* MorrisTraversal(Node* head, int num) { // Morris Traversal para a conversão da árvore para lista sem a usagem de biblíotecas adicionais
    int* arr = new int[num]; // Ponteiro referente a array de tamnaho n elementos

    if (head == NULL) { 
        return NULL;
    }

    Node* current = head; // Criação de temp

    for (int i = 0; i < num; i++) {
        if (current->left == NULL) {// Preferência de traversal ao filho esquerdo.
            arr[i] = current->data;
            current = current->right;
        }
        else {
            Node* pre = current->left; // Cria um nó "precdente" a esquerda do nó atual
            while (pre->right != NULL && pre->right != current) { // Verifica se há um nó a direita que não o nó pai
                pre = pre->right;
            }

            if (pre->right == NULL) { // Caso não haja nó direito, transfomra o current no nó direito de seu predecessor
                pre->right = current; // Visita a árvore esquerda
                current = current->left;
            }
            else {
                pre->right = NULL; // Caso a árvore direta já ttenha sido visitada, ou current é filho de pré, corta a "conexão" entre os dois 
                arr[i] = current->data; // Armazena o valor do nó
                current = current->right; // Retrocede a um nó mais alto
            }
        }
    }

    return arr; // Retorna o array
}



void BFS(Node* head, int height) {
    if (head == NULL)
        return;

    cout << head->data << " ";

    int currentLevelCount = 1; // Altura atual

    while (currentLevelCount <= height) { // Enquanto altura inferior a altura máxima
        if (head->left != NULL) { // Printa nó esquerdo
            cout << head->left->data << " ";
        }
        if (head->right != NULL) { // Printa nó dreito
            cout << head->right->data << " ";
        }

        currentLevelCount++; // Incrementa altura


        if (head->left != NULL)  // Avança para o próxim estágio
            head = head->left;
        else if (head->right != NULL)
            head = head->right;
        else
            break; // Quebra se não ouvveer mais nós
    }
}


void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped; 

    for (i = 1; i < n ; i++) {
        swapped = false;
        for (j = 0; j < n - i ; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Caso haja troca swap cotinua
                swapped = true;
            }
        }
          if (swapped == false) // break asso não haja mais trocca a serem feitas para este valor
            break;
    }
}

int print_height(Node* head) {
    int l;
    int r;
    if (head == NULL){
        return 0;
    }
    else {
        int l = print_height(head->left); // Recursivamente armazena a altura
        int r = print_height(head->right);
        if (l >= r)
            return l + 1; // Printa o esquerdo caso ele seja mais alto
        else
            return r + 1; // Printa o direito caso ele seja mais alto
    }

}  



void shellsort(int arr[], int count){

    int i, j, gap;
    // Reduz o gap pela metade ao longo das iterações
        for (int gap = count / 2; gap > 0; gap /= 2) {
            // Adiciona individualmente elementos até quee todos estejam organizados de acordo com esse elemento
            for (int i = gap; i < count; ++i) {
                int temp = arr[i];
                int j;
                // Itera em cima de todos os elementos do array
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
}



void selectionSort(int arr[], int count)
{
    int i, j;
    for (i = 0; i < count - 1; i++) {
        // Itera o elemento selecionado j ao longo de todo o array i
        for (j = i + 1; j < count; j++) {
            if (arr[j] < arr[i])
                // Troca de posição os dois lementos caso j < i
                swap(arr[j], arr[i]);
        }
    }
}
 
void insertionSort(int arr[], int count){
    
    int i, j;
    for (int i = 1; i < count; ++i) {
            int j = i;
    }
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j], arr[j - 1]);
            j= j - 1;
        }
}



int leafnum(Node* head){
    if(head == NULL)    
        return 0;
    // Caso haja só a head retorne true
    if(head->left == NULL && head->right == NULL)
        return 1;        
    else
    // Recursivamente conta o número de nós nas duas sub-árvores
        return leafnum(head->left)+
            leafnum(head->right);
}

bool Check_perfect(Node* head, int height, int leafnum) {
    if (head == NULL) {
        return false;
    }
    // Caso haja somente a root node a aravore é perfeita
    else if(height == 1 && leafnum == 1) {
        return true;
    }
    // Verificca se há o número certo de folhas para a dáda alutra da árvore
    else if (leafnum == pow(2, height - 1)) {
        return true;
    }
    else {
        return false;
    }
}


Node* InsertNode(Node* head, int value) {
    // Cria o nó root
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
                    // Caso o filho esquerdo da folha esteja vazio
                    temp->left = createNode(value);
                    break;
                }
            } else if (temp->data < value) {
                if (temp->right != NULL) {
                    temp = temp->right;
                } else {
                    // Caso o filho direio do nó esteja vazio
                    temp->right = createNode(value);
                    break;
                }
            } else {
                // Evita valores duplicados encerrando a funçaõ caso o nó já tenha sido alocado
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
 
    // Recursivamente atravesa a árvore esquerda
    printInorder(head->left);
 
    // Printa o valor do nó
    printf("%d ", head->data);
 
    // Recursivamente atravessa a árvore direita
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

bool checkComplete ( Node* head, int index, int count)
{   // Caso a head seja o unico nó a áravore e completa
    if (head -> left == NULL && head -> right == NULL){
        return (true);
    }
    // Caso o index ultrapasse o count então algum nó no penultim nivle não tem dois ffilhos 
    if (index >= count)
        return (false);
        // Recursivamente verifica se o número de nós aumenta por log2
    return (checkComplete(head->left, 2*index + 1, count) &&
            checkComplete(head->right, 2*index + 2, count));
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
            case 1:{
                createBinaryTreeManual();
                double time = printProcessingTime(createBinaryTreeManual);
                cout << "Processing time: " << time << " seconds" << endl;
                break;
            }
            case 2:{
                createBinaryTreeFromFile();
                double time = printProcessingTime(createBinaryTreeFromFile);
                cout << "Processing time: " << time << " seconds" << endl;
                break;
            }
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
