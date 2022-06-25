#include <iostream>
#include <string>
#include <cstring>
#include <new>
#include <cstdbool>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstdarg>

// #define DEBUG
// #undef DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};

    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

typedef struct NODE
{
    int height;
    int key;
    NODE *leftChild;
    NODE *rightChild;
} Node;

int heightOfNode(Node *currNode);
Node *insertNode(Node *node, int key);
int max(int a, int b);
int getBalanceFactor(Node *node);
Node *leftLeftRotate(Node *node);
Node *rightRightRotate(Node *node);
Node *leftRightRotate(Node *node);
Node *rightLeftRotate(Node *node);
void inorderTraversalOfAVLTree(Node *currNode);
bool isTreeBalanced(Node *currNode);
void displayHeightsOfAllNodes(Node* currNode);
Node* getPredecessorNode(Node* node);

int main()
{
    Node* root = NULL;
    root = insertNode(root, 14);
    root = insertNode(root, 17);
    root = insertNode(root, 11);
    root = insertNode(root, 7);
    root = insertNode(root, 53);
    root = insertNode(root, 4);
    root = insertNode(root, 13);
    root = insertNode(root, 12);
    root = insertNode(root, 8);
    root = insertNode(root, 60);
    root = insertNode(root, 19);
    root = insertNode(root, 16);
    root = insertNode(root, 20);

    // root = insertNode(root, 8);
    // root = insertNode(root, 6);
    // root = insertNode(root, 15);
    // root = insertNode(root, 3);
    // root = insertNode(root, 19);
    // root = insertNode(root, 29);
    cout << "InOrderTraversal Of Tree is:" << endl;
    inorderTraversalOfAVLTree(root);

    if (isTreeBalanced(root) == true)
    {
        cout << "Output is correct. Its an AVL Tree"<< endl;
    }
    else
    {
        cout << "Output is incorrect. Its not an AVL Tree"<< endl;
    }
    
    displayHeightsOfAllNodes(root);
    return 0;
}

int heightOfNode(Node *currNode)
{
    if (currNode == NULL)
    {
        return 0;
    }
    else
    {
        TRACE("Calculating Height Of tree with currentNode key %d\n", currNode->key);
        return 1 + max(heightOfNode(currNode->leftChild), heightOfNode(currNode->rightChild));
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

Node *insertNode(Node *node, int key)
{
    if (node == NULL)
    {
        TRACE("Here node is NULL with key %d\n",key);
        Node *newNode;
        TRACE("Allocating Memeory for new Node with key %d\n", key);
        try
        {
            newNode = new Node;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        TRACE("Assigning attributes to new Node of key %d\n", key);
        newNode->key = key;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->height = 0;
        return newNode;
    }

    if (key < node->key)
    {
        TRACE("Here newNode key %d is less than currentNode key %d\n", key, node->key);
        node->leftChild = insertNode(node->leftChild, key);
    }
    else
    {
        TRACE("Here newNode key %d is more than currentNode key %d\n", key, node->key);
        node->rightChild = insertNode(node->rightChild, key);
    }

    TRACE("Calc height of node with data %d\n", node->key);
    node->height = heightOfNode(node);

    TRACE("Calling get Balance Factor Function with key %d\n", node->key);
    int balanceFactor = getBalanceFactor(node);

    TRACE("The Balance Factor with key %d is %d\n",node->key,balanceFactor);
    if ((balanceFactor > 1) && (key < node->leftChild->key))
    {
        TRACE("Calling rightRightRotate Function for key %d\n", node->key);
        return leftLeftRotate(node);
    }

    if ((balanceFactor > 1) && (key > node->leftChild->key))
    {
        TRACE("Calling leftRightRotate Function with key %d\n", node->key);
        return leftRightRotate(node);
    }

    if ((balanceFactor < -1) && (key > node->rightChild->key))
    {
        TRACE("Calling leftleftRotate Function with key %d\n", node->key);
        return rightRightRotate(node);
    }

    if ((balanceFactor < -1) && (key < node->rightChild->key))
    {
        TRACE("Calling rightLeftRotate Function with key %d\n", node->key);
        return rightLeftRotate(node);
    }

    return node;
}

int getBalanceFactor(Node *node)
{
    if (node == NULL)
    {
        TRACE("Calculating Balance Factor when root is null with key %d\n", node->key);
        return 0;
    }

    TRACE("Calculating Balance Factor when root isn't null with key %d\n", node->key);
    return (heightOfNode(node->leftChild) - heightOfNode(node->rightChild));
}

Node *leftLeftRotate(Node *node)
{
    Node *tempNode;
    tempNode = node->leftChild;

    TRACE("Left Left Rotation with node key %d tempNode key %d\n", node->key, tempNode->key);
    node->leftChild = tempNode->rightChild;
    tempNode->rightChild = node;

    tempNode->height = heightOfNode(tempNode);
    node->height = heightOfNode(node);
    return tempNode;
}

Node *rightRightRotate(Node *node)
{
    Node *tempNode;
    tempNode = node->rightChild;

    TRACE("Right Right Rotation with node key %d tempNode key %d\n", node->key, tempNode->key);
    node->rightChild = tempNode->leftChild;
    tempNode->leftChild = node;

    tempNode->height = heightOfNode(tempNode);
    node->height = heightOfNode(node);
    return tempNode;
}

Node *leftRightRotate(Node *node)
{
    TRACE("Processing Left Right Rotation with node key %d\n", node->key);

    Node *tempNode;
    tempNode = node->leftChild;

    TRACE("Right Right Rotation with node key %d tempNode key %d\n", node->key, tempNode->key);
    node->leftChild = rightRightRotate(tempNode);

    tempNode->height = heightOfNode(tempNode);
    node->height = heightOfNode(node);

    TRACE("Left Left Rotation with node key %d tempNode key %d\n", node->key, tempNode->key);
    return leftLeftRotate(node);
}

Node *rightLeftRotate(Node *node)
{
    TRACE("Processing Right Left Rotation with node key %d\n", node->key);

    Node *tempNode;
    tempNode = node->rightChild;

    TRACE("Left Left Rotation with node key %d tempNode key %d\n", node->key, tempNode->key);
    node->rightChild = leftLeftRotate(tempNode);

    tempNode->height = heightOfNode(tempNode);
    node->height = heightOfNode(node);

    TRACE("Right Right Rotation with node key %d tempNode key %d\n", node->key, tempNode->key);
    return rightRightRotate(node);
}

void inorderTraversalOfAVLTree(Node *currNode)
{
    if (currNode == NULL)
    {
        return;
    }

    inorderTraversalOfAVLTree(currNode->leftChild);
    cout << currNode->key << endl;
    inorderTraversalOfAVLTree(currNode->rightChild);
}

bool isTreeBalanced(Node *currNode)
{
    if (currNode == NULL)
    {
        return true;
    }
    
    if (abs(getBalanceFactor(currNode)) <= 1 && isTreeBalanced(currNode->leftChild) && isTreeBalanced(currNode->rightChild))
    {
        return true;
    }

    return false;
}

void displayHeightsOfAllNodes(Node* currNode)
{
    cout << "Height of Node with key" << currNode->key << "is: " << heightOfNode(currNode) << endl;

    if (currNode->leftChild != NULL)
    {
        displayHeightsOfAllNodes(currNode->leftChild);
    }

    if (currNode->rightChild != NULL)
    {
        displayHeightsOfAllNodes(currNode->rightChild);
    }  
}

Node* getPredecessorNode(Node* node)
{
    Node* currNode = node;
    while (currNode->leftChild != NULL)
    {
        TRACE("Calculating Predecessor Node with currentNode key %d",currNode->key);
        currNode = currNode->leftChild;
    }

    return currNode;
    
}

Node* deleteNode(Node* node,int key)
{
    if (node == NULL)
    {
        TRACE("Deleting Node When Root is NULL given key is %d",key);
        return node;
    }

    if (key < node->key)
    {
        TRACE("Deleting Node when key %d is less than currentNode key %d",key,node->key);
        deleteNode(node->leftChild,key);
    }
    else if (key > node->key)
    {
        TRACE("Deleting Node when key %d is more than currentNode key %d",key,node->key);
        deleteNode(node->rightChild,key);
    }
    else
    {
        TRACE("Deleting Node when key %d is equal to currentNode key %d",key,node->key);
        if ((node->leftChild == NULL) && (node->rightChild == NULL))
        {
            
        }
        
    }
    
    


    
}