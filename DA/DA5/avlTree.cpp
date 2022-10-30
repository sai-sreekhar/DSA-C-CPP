#include <bits/stdc++.h>

using namespace std;

// #define DEBUG
// #undef DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, ##__VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

#define CHECK_NULL_AND_PRINT_KEY(node, var) node ? (node->key).c_str() : "node is null"

#define CHECK_NULL_AND_PRINT_OTHERS(node, var) node ? to_string(node->var).c_str() : "node is null"

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
    cout << buffer << "\n"
         << flush;
}

typedef struct Node
{
    string key;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
} Node;

int getHeight(Node *currNode)
{
    TRACE("Calculating Height Of tree with currentNode key %s", CHECK_NULL_AND_PRINT_KEY(currNode, key));
    if (currNode == NULL)
    {
        TRACE("Here Current Node is null and returning zero");
        return 0;
    }

    TRACE("Here Current Node is not NULL. returning %s", CHECK_NULL_AND_PRINT_OTHERS(currNode, height));
    return currNode->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *createNewNode(string key)
{
    TRACE("Creating a new Node for key %s", key.c_str());
    Node *node = new Node;
    if (node == NULL)
    {
        TRACE("Here Node is null");
    }
    TRACE("Node address is %x and its key is %s", node, CHECK_NULL_AND_PRINT_KEY(node, key));
    TRACE("Assigning Key %s", key.c_str());
    node->key = key;
    TRACE("Assigned Key %s", CHECK_NULL_AND_PRINT_KEY(node, key));
    TRACE("Assigning Left and rightChild childs to null");
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->height = 1;

    TRACE("Returning a new node of key %s", CHECK_NULL_AND_PRINT_KEY(node, key));
    return (node);
}

Node *rightRotate(Node *y)
{
    TRACE("Right Rotating the node %s", CHECK_NULL_AND_PRINT_KEY(y, key));
    Node *x = y->leftChild;

    Node *T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    y->height = max(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;
    x->height = max(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;

    TRACE("Recalculated heights of nodes %s and %s and their new heights are %s and %s respectively", CHECK_NULL_AND_PRINT_KEY(y, key), CHECK_NULL_AND_PRINT_KEY(x, key), CHECK_NULL_AND_PRINT_OTHERS(y, height), CHECK_NULL_AND_PRINT_OTHERS(x, height));

    TRACE("returning node %s", CHECK_NULL_AND_PRINT_KEY(x, key));
    return x;
}

Node *leftRotate(Node *x)
{
    TRACE("Left Rotating the node %s", CHECK_NULL_AND_PRINT_KEY(x, key));

    Node *y = x->rightChild;
    Node *T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    x->height = max(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    y->height = max(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;

    TRACE("Recalculated heights of nodes %s and %s and their new heights are %s and %s respectively", CHECK_NULL_AND_PRINT_KEY(x, key), CHECK_NULL_AND_PRINT_KEY(y, key), CHECK_NULL_AND_PRINT_OTHERS(x, height), CHECK_NULL_AND_PRINT_OTHERS(y, height));

    TRACE("returning node %d", CHECK_NULL_AND_PRINT_KEY(y, key));

    return y;
}

int getBalanceFactor(Node *node)
{
    TRACE("Calculating Balance Factor Of node with key %s", CHECK_NULL_AND_PRINT_KEY(node, key));

    if (node == NULL)
    {
        TRACE("Here Node is null and returning balance factor of zero");
        return 0;
    }

    int balanceFactor = getHeight(node->leftChild) - getHeight(node->rightChild);
    TRACE("Here Node is not NULL. returning balance factor %d", balanceFactor);
    return balanceFactor;
}

Node *insertNode(Node *node, string key)
{
    TRACE("Inserting Node of key %s", key.c_str());
    if (node == NULL)
    {
        node = createNewNode(key);
        TRACE("Node is null and returning the result from create new node function key is %s", CHECK_NULL_AND_PRINT_KEY(node, key));
        return node;
    }

    if (key < node->key)
    {
        TRACE("here key is less than node->key. Calling insert node on leftChild subtree. key: %s node->key: %s", key.c_str(), CHECK_NULL_AND_PRINT_KEY(node, key));
        node->leftChild = insertNode(node->leftChild, key);
    }
    else if (key > node->key)
    {
        TRACE("here key is more than node->key. Calling insert node on rightChild subtree. key: %s node->key: %s", key.c_str(), CHECK_NULL_AND_PRINT_KEY(node, key));
        node->rightChild = insertNode(node->rightChild, key);
    }
    else
    {
        TRACE("here key is equal to node->key. Returning node key: %s node->key: %s", key.c_str(), CHECK_NULL_AND_PRINT_KEY(node, key));
        return node;
    }

    TRACE("Re Calculating height of node key: %s", CHECK_NULL_AND_PRINT_KEY(node, key));
    node->height = 1 + max(getHeight(node->leftChild), getHeight(node->rightChild));

    TRACE("Calculating Balance Factor of node key: %s", CHECK_NULL_AND_PRINT_KEY(node, key));
    int balance = getBalanceFactor(node);

    TRACE("The balance factor is %d", balance);

    if (balance > 1 && getBalanceFactor(node->leftChild) >= 0)
    {
        TRACE("Balance is more than 1 and balance factor of node->left is >= 0 balance: %d, key: %s, node->leftChild->key: %s\n Calling Right rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(node->leftChild, key));
        return rightRotate(node);
    }

    if (balance < -1 && getBalanceFactor(node->rightChild) <= 0)
    {
        TRACE("Balance is less than -1 and balance factor of node->left is <= 0 balance: %d, key: %s, node->rightChild->key: %s\n Calling Left Rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(node->rightChild, key));
        return leftRotate(node);
    }

    if (balance > 1 && getBalanceFactor(node->leftChild) < 0)
    {
        TRACE("Balance is more than 1 balance factor of node->left is < 0 balance: %d, key: %s, node->leftChild->key: %s\n Calling Left Rotate and then right rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(root->leftChild, key));
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balance < -1 && getBalanceFactor(node->rightChild) > 0)
    {
        TRACE("Balance is less than -1 and balance factor of node->left is > 0 balance: %d, key: %s, node->rightChild->key: %s\n Calling Right Rotate and then left rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(node->rightChild, key));
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    TRACE("Returning Node of key %s", CHECK_NULL_AND_PRINT_KEY(node, key));

    return node;
}

Node *getInorderPredecessorNode(Node *node)
{
    TRACE("Get Max Value node from leftChild subtree of node key: %s", CHECK_NULL_AND_PRINT_KEY(node, key));
    Node *current = node;

    while (current->rightChild != NULL)
    {
        current = current->rightChild;
        TRACE("Traversing Towards Right most in left subtree currentKey %s", CHECK_NULL_AND_PRINT_KEY(current, key));
    }

    TRACE("Returning Max Value node from leftChild subtree of node key: %s retuning key: %s", CHECK_NULL_AND_PRINT_KEY(node, key), CHECK_NULL_AND_PRINT_KEY(current, key));
    return current;
}

Node *deleteNode(Node *root, string key)
{
    TRACE("Deleting Node of key: %s, rootKey: %s", key.c_str(), CHECK_NULL_AND_PRINT_KEY(root, key));
    if (root == NULL)
    {
        TRACE("Here Node(root) is Null. Returning null");
        return root;
    }

    if (key < root->key)
    {
        TRACE("Here key is less than root->key. key: %s root->key: %s\n Calling Delete in Left Subtree", key.c_str(), CHECK_NULL_AND_PRINT_KEY(root, key));
        root->leftChild = deleteNode(root->leftChild, key);
    }

    else if (key > root->key)
    {
        TRACE("Here key is more than root->key. key: %s root->key: %s\n Calling Delete in Right Subtree", key.c_str(), CHECK_NULL_AND_PRINT_KEY(root, key));
        root->rightChild = deleteNode(root->rightChild, key);
    }
    else
    {
        TRACE("Here key is equal than root->key. key: %s root->key: %s", key.c_str(), CHECK_NULL_AND_PRINT_KEY(root, key));

        if ((root->leftChild == NULL) || (root->rightChild == NULL))
        {
            Node *temp = root->leftChild ? root->leftChild : root->rightChild;

            if (temp == NULL)
            {
                TRACE("The node to be deleted has no children. Making root to null. rootKey: %s", CHECK_NULL_AND_PRINT_KEY(root, key));
                temp = root;
                root = NULL;
            }
            else
            {
                TRACE("The node to be deleted has one child. Making root to childKey. rootKey: %s childKey: %s", CHECK_NULL_AND_PRINT_KEY(root, key), CHECK_NULL_AND_PRINT_KEY(temp, key));
                *root = *temp;
            }

            TRACE("Free the temp");
            free(temp);
        }
        else
        {
            TRACE("The node to be deleted has 2 children. Calling getInorderPredecessorNodeFunc key: %s", CHECK_NULL_AND_PRINT_KEY(root, key));

            Node *temp = getInorderPredecessorNode(root->leftChild);

            TRACE("Setting the node to delete value to returned value old: %s new: %s", CHECK_NULL_AND_PRINT_KEY(root, key), CHECK_NULL_AND_PRINT_KEY(temp, key));

            root->key = temp->key;

            TRACE("Deleting the temp node i.e the inorderPredecessor node. tempData: %s", CHECK_NULL_AND_PRINT_KEY(temp, key));
            root->leftChild = deleteNode(root->leftChild, temp->key);
        }
    }

    if (root == NULL)
    {
        TRACE("Here root is null. So no need to calc heights returning root");
        return root;
    }

    TRACE("Re Calculating height of root key: %s", CHECK_NULL_AND_PRINT_KEY(root, key));
    root->height = 1 + max(getHeight(root->leftChild), getHeight(root->rightChild));

    TRACE("Calculating Balance Factor of root key: %s", CHECK_NULL_AND_PRINT_KEY(root, key));
    int balance = getBalanceFactor(root);

    TRACE("The balance factor is %d", balance);

    if (balance > 1 && getBalanceFactor(root->leftChild) >= 0)
    {
        TRACE("Balance is more than 1 and balance factor of root->left is >= 0 balance: %d, key: %s, root->leftChild->key: %s\n Calling Right rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(root->leftChild, key));
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->rightChild) <= 0)
    {
        TRACE("Balance is less than -1 and balance factor of root->left is <= 0 balance: %d, key: %s, root->rightChild->key: %s\n Calling Left Rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(root->rightChild, key));
        return leftRotate(root);
    }

    if (balance > 1 && getBalanceFactor(root->leftChild) < 0)
    {
        TRACE("Balance is more than 1 balance factor of root->left is < 0 balance: %d, key: %s, root->leftChild->key: %s\n Calling Left Rotate and then right rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(root->leftChild, key));
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->rightChild) > 0)
    {
        TRACE("Balance is less than -1 and balance factor of root->left is > 0 balance: %d, key: %s, root->rightChild->key: %s\n Calling Right Rotate and then left rotate", balance, key.c_str(), CHECK_NULL_AND_PRINT_KEY(root->rightChild, key));
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    TRACE("Returning Node of key %s", CHECK_NULL_AND_PRINT_KEY(root, key));

    return root;
}

void displayInorderTraversal(Node *root)
{
    if (root != NULL)
    {
        displayInorderTraversal(root->leftChild);
        cout << root->key << " ";
        displayInorderTraversal(root->rightChild);
    }
}

void displayPreorderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        displayPreorderTraversal(root->leftChild);
        displayPreorderTraversal(root->rightChild);
    }
}

void displayPostOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        displayPostOrderTraversal(root->leftChild);
        displayPostOrderTraversal(root->rightChild);
        cout << root->key << " ";
    }
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

int main()
{
    Node *root = NULL;
    string inputs[12] = {"jar", "fan", "gal", "ham", "pad", "ice", "cab", "bag", "abs", "van", "tag", "zee"};

    root = insertNode(root, inputs[0]);
    root = insertNode(root, inputs[1]);
    root = insertNode(root, inputs[2]);
    root = insertNode(root, inputs[3]);
    root = insertNode(root, inputs[4]);
    root = insertNode(root, inputs[5]);
    root = insertNode(root, inputs[6]);
    root = insertNode(root, inputs[7]);
    root = insertNode(root, inputs[8]);

    root = deleteNode(root, inputs[3]);
    root = deleteNode(root, inputs[7]);

    root = insertNode(root, inputs[9]);
    root = insertNode(root, inputs[10]);
    root = insertNode(root, inputs[11]);

    root = deleteNode(root, inputs[0]);
    root = deleteNode(root, inputs[1]);

    cout << "The Inorder Traversal of contructed AVL Tree is: ";
    displayInorderTraversal(root);
    cout << "\n";

    cout << "The PreOrder Traversal of contructed AVL Tree is: ";
    displayPreorderTraversal(root);
    cout << "\n";

    cout << "The Post Traversal of contructed AVL Tree is: ";
    displayPostOrderTraversal(root);
    cout << "\n";

    if (isTreeBalanced(root) == true)
    {
        cout << "Output is correct. Contructed Tree is an AVL Tree" << endl;
    }
    else
    {
        cout << "Output is incorrect. Contructed Tree is not an AVL Tree" << endl;
    }

    return 0;
}