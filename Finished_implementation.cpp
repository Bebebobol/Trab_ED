#include <iostream>
#include <fstream>
#include <stack>
#include <chrono>
#include <string>
#include <boost/algorithm/string.hpp> // header file contain all the functions of boost
#include <bits/stdc++.h> // Using the Boost method to turn the line spaces into break lines



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

    if (head == nullptr) { 
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
            break; // Quebra se não houver mais nós
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
 
void insertionSort(int arr[], int count) {
    for (int i = 1; i < count; ++i) {
        // Cria um elemento j baseado no i
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j], arr[j - 1]);
            // Troca a posição de j de forma que ele itere por ttoda a lista
            j = j - 1;
        }
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

Node* InsertNode(Node* pHead, int nValue) {
    if (pHead == NULL) {
        pHead = createNode(nValue);
        return pHead;
    } 

    Node* pTemp = pHead;
    while (pTemp != NULL) {
        if (nValue < pTemp->data) {
            if (pTemp->left == NULL) {
                // Caso o filho esquerdo da folha esteja vazio
                pTemp->left = createNode(nValue);
                break;
            } else {
                pTemp = pTemp->left;
            }
        } else if (nValue > pTemp->data) {
            if (pTemp->right == NULL) {
                // Caso o filho direito da folha esteja vazio
                pTemp->right = createNode(nValue);
                break;
            } else {
                pTemp = pTemp->right;
            }
        } else {
            // Evita valores duplicados encerrando a funçaõ caso o nó já tenha sido alocado
            break;
        }
    }

    return pHead;
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

Node* createBinaryTreeManual(Node* pRoot) {
    int nTamanho;
    //Quantidade de nós que o usuário quer que a árvore tenha
    cout<<"Number of nodes: ";
    cin>>nTamanho;
    int arrEscolhas[nTamanho];
    //Recebe os valores dados pelo usuário
    //e os insere na árvore
    for (int i=0; i<nTamanho; i++) {
        cout<<"Chosen value "<<i+1<<": ";
        cin>>arrEscolhas[i];
        pRoot = InsertNode(pRoot, arrEscolhas[i]);
    }
    return pRoot;
}

Node* convertFileToBST(const char* ccFilename) {
    Node* root = nullptr;
    string line;
    ifstream file(ccFilename);
    // Seleciona a linha inteira
    if (file.is_open()) {
        while (getline(file, line)) {
            string number;
            // Divide os digitos
            for (char c : line) {
                if (isdigit(c)) {
                    number += c;
                    // Caso seja um número aloca ele na árvore
                } else if (!number.empty()) {
                    root = InsertNode(root, stoi(number));
                    // Limpa a memória
                    number.clear();
                }
            }
            if (!number.empty()) {
                root = InsertNode(root, stoi(number));
            }
        }
        // Fecha o arquivo
        file.close();
    }
    else {
        cout << "Failed to open the file." << endl;
    }

    return root;
}

Node* deleteNode (Node* pRoot, int nValue) {
    // Caso de uma árvore vazia
    if (pRoot == NULL)
        return pRoot;
 
    // Encontrar o nó a ser deletado
    if (pRoot->data > nValue) {
        pRoot->left = deleteNode(pRoot->left, nValue);
        return pRoot;
    }
    else if (pRoot->data < nValue) {
        pRoot->right = deleteNode(pRoot->right, nValue);
        return pRoot;
    }
 
    // Quando o nó é encontrado
    // Se um dos filhos do nó é vazio
    if (pRoot->left == NULL) {
        //
        Node* pTemp = pRoot->right;
        delete pRoot;
        return pTemp;
    }
    else if (pRoot->right == NULL) {
        Node* pTemp = pRoot->left;
        delete pRoot;
        return pTemp;
    }
 
    // Quando os dois filhos existem
    else {
        // Encontra o nó com o valor mínimo na subárvore direita
        Node* pParent = pRoot;
        Node* pChild = pRoot->right;
        while (pChild->left != NULL) {
            pParent = pChild;
            pChild = pChild->left;
        }

        // Atualiza as referências dos nós para removê-lo corretamente
        if (pParent != pRoot)
            pParent->left = pChild->right;
        else
            pParent->right = pChild->right;
 
        // Copia o valor do nó encontrado para o nó a ser excluído
        pRoot->data = pChild->data;
 
        // Libera a memória alocada para o nó encontrado
        delete pChild;
        // Retorna a raiz da árvore atualizada
        return pRoot;
    }
}


Node* printAddress(Node* root, int value) {
    // Retorna nullo se não houver root
    if (root == nullptr) {
        return nullptr;
    }
    // Caso o root tenha o valor retorna ele próprio
    if (root->data == value) {
        return root;
    }

    Node* foundNode = printAddress(root->left, value); // Recursivamente procura na árvore esquerda
    if (foundNode == nullptr) {
        foundNode = printAddress(root->right, value); // Se nada for achaddo recursivamente procura na direita
    }

    return foundNode;
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
    Node* root = nullptr;
    int* arr = nullptr; 
    bool treeCreated = false;
    bool arraycreated = false;
    while (true) {
        // Printa as opções
        cout << "Binary Tree Menu:" << endl;
        cout << "1. Create Binary Tree from Manual Inputs" << endl;
        cout << "2. Create Binary Tree from File" << endl;
        cout << "3. Print Inorder Traversal" << endl;
        cout << "4. Print BFS Traversal" << endl;
        cout << "5. Count Nodes" << endl;
        cout << "6. Morris Traversal" << endl;
        cout << "7. Print Height" << endl;
        cout << "8. Count Leaf Nodes" << endl;
        cout << "9. Check if Tree is Perfect" << endl;
        cout << "10. Check if Tree is Complete" << endl;
        cout << "11. Sort Tree using Bubble Sort" << endl;
        cout << "12. Sort Tree using Shell Sort" << endl;
        cout << "13. Sort Tree using Selection Sort" << endl;
        cout << "14. Sort Tree using Insertion Sort" << endl;
        cout << "15. Print address of node in tree" << endl;
        cout << "16. To test the delete function" << endl;
        cout << "17. Exit" << endl;

        int choice;
        // Bom auto explicativo
        cout << "Digite um número de 1-17: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = createBinaryTreeManual(root);
                treeCreated = true;
                break;
            case 2:
                root = convertFileToBST("input.txt");
                treeCreated = true;
                break;
            case 3:
                if (treeCreated) {
                    cout << "Inorder Traversal: ";
                    double timeTaken = printProcessingTime([&]() {
                    printInorder(root);
                    });
                    cout << "Time do Pink Floyd: " << timeTaken << " e muito bom" << endl;
                    cout << endl;
                } else {
                    cout << "Cria uma árvore antes cara" << endl;
                }
                break;
            case 4:
                if (treeCreated) {
                    int height = print_height(root);
                    cout << "BFS Traversal: ";
                    double timeTaken = printProcessingTime([&]() {
                    BFS(root, height);
                    });
                    cout << "Processing Time: " << timeTaken << " seconds" << endl;
                    cout << endl;
                } else {
                    cout << "Rapaz cria uma árvore" << endl;
                }
                break;
            case 5:
                if (treeCreated) {
                    int count = countNodes(root);
                    cout << "Number of Nodes: " << count << endl;
                } else {
                    cout << "Porque você só não cria uma árvore?" << endl;
                }
                break;
            case 6:
                if (treeCreated) {
                    int count = countNodes(root);
                    delete[] arr;
                    arr = new int[count];
                    double timeTaken = printProcessingTime([&]() {
                        MorrisTraversal(root, arr);
                    });
                    cout << "Morris Traversal: ";
                    for (int i = 0; i < count; i++) {
                        cout << arr[i] << " ";
                    }
                    arrayCreated = true;
                    cout << endl;
                    cout << "Processing Time: " << timeTaken << " seconds" << endl;
                } else {
                    cout << "Crie uma árvore!!!" << endl;
                }
                break;
            case 7:
                if (treeCreated) {
                    int height = print_height(root);
                    cout << "Height of the Tree: " << height << endl;
                } else {
                    cout << "The tree is a lie" << endl;
                }
                break;
            case 8:
                if (treeCreated) {
                    int count = leafnum(root);
                    cout << "Number of Leaf Nodes: " << count << endl;
                } else {
                    cout << "Crie uma árvore" << endl;
                }
                break;
            case 9:
            if (treeCreated) {
                //Convoca as funções auxiliares height e leafcount
                int height = print_height(root);
                int leafCount.
                    = leafnum(root);
                    bool isPerfect = checkPerfect(root, height, leafCount);
                    if (isPerfect) {
                        cout << "The tree is perfect." << endl;
                    } else {
                        cout << "The tree is not perfect." << endl;
                    }
                } else {
                    cout << "Crie uma árvore binária antes" << endl;
                }
                break;
            case 10:
                if (treeCreated) {
                    bool isComplete = checkComplete(root);
                    if (isComplete) {
                        cout << "The tree is complete." << endl;
                    } else {
                        cout << "The tree is not complete." << endl;
                    }
                } else {
                    cout << "Crie uma árvore binária antes" << endl;
                }
                break;
            case 11:
                if (arrayCreated) {
                    double timeTaken = printProcessingTime([&]() {
                        bubbleSort(arr);
                    });
                    cout << "Tree sorted using Bubble Sort." << endl;
                    cout << "Processing Time: " << timeTaken << " seconds" << endl;
                } else {
                    cout << "Primeiramente crie um array" << endl;
                }
                break;
            case 12:
                if (arraycreated) {
                double timeTaken = printProcessingTime([&]() {
                    shellSort(arr);
                });
                cout << "Tree sorted using Shell Sort." << endl;
                cout << "Processing Time: " << timeTaken << " seconds" << endl;
                } else {
                    cout << "Primeiramente crie um array" << endl;
                }
                break;
            case 13:
                if (arraycreated) {
                double timeTaken = printProcessingTime([&]() {
                    selectionSort(arr);
                });
                cout << "Tree sorted using Selection Sort." << endl;
                cout << "Processing Time: " << timeTaken << " seconds" << endl;
                } else {
                    cout << "Primeiramente crie um array" << endl;
                }
                break;
            case 14:
                if (arraycreated) {
                double timeTaken = printProcessingTime([&]() {
                    insertionSort(arr);
                });
                    cout << "Tree sorted using Insertion Sort." << endl;
                cout << "Processing Time: " << timeTaken << " seconds" << endl;
                } else {
                    cout << "Primeiramente crie um array" << endl;
                }
                break;
            case 15:
            if (treeCreated) {
                    int targetValue;
                    cout << "Coloque um valor que deseja enccontrar na árvore: ";
                    cin >> targetValue;

                    Node* foundNode = findNodeByValue(root, targetValue);
                    if (foundNode != nullptr) {
                        cout << "Endereço na árvore " << targetValue << ": " << foundNode << endl;
                    } else {
                        cout << "Nó " << targetValue << " não encontrado na árvore" << endl;
                    }
                } else {
                    cout << "Crie uma árvore binária antes" << endl;
                }
                break;

            case 16:
            {
                Node* pRoot = nullptr;
                int arrValores[7] = {6,4,8,5,3,9,7};
                for (int i=0;i<7;i++) {
                    pRoot = InsertNode(pRoot, arrValores[i]);
                }
                cout<<"Original binary tree: ";
                printInorder(pRoot);
                cout<<endl;

                int nDel;
                cout<<"Choose a value to be removed: ";
                cin>>nDel;

                Node* pNewRoot = deleteNode(pRoot,nDel);
                cout<<"New tree: ";
                printInorder(pNewRoot);
                cout<<endl;

                double dTime = printProcessingTime(deleteNode);
                cout << "Processing time: " << dTime << " seconds" << endl;
                break;
            }
            case 17:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}





int main() {
    mainMenu();
    return 0;
}
