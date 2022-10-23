#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
  int data;
  struct NODE *leftChild;
  struct NODE *rightChild;
} node;

node *root = NULL;

void insertNode(int data);
void DisplayPreOrderTraversal(node *root);
void DisplayInOrderTraversal(node *root);
void DisplayPostOrderTraversal(node *root);
void searchNode(int data);
void deleteNode(int data);
node *getInOrderSuccNode(node *currentNode);
void findMax();
void findMin();

int main()
{

  int opt;
  printf("Enter 1 to Insert, 2 to Delete, 3 to Search, 4 to InorderTraversal, 5 to PreOrderTraversal, 6 to PostOrderTraversal, 7 to Get Minimum ELement, 8 to Get Maximum Element, 0 to quit: ");
  scanf("%d", &opt);
  while (opt != 0)
  {
    int data;
    switch (opt)
    {
    case 1:
    {
      printf("Enter the Value to insert: ");
      scanf("%d", &data);
      insertNode(data);
      break;
    }
    case 2:
    {
      printf("Enter the Value to delete: ");
      scanf("%d", &data);
      deleteNode(data);
      break;
    }
    case 3:
    {
      printf("Enter the Value to search: ");
      scanf("%d", &data);
      searchNode(data);
      break;
    }
    case 4:
    {
      printf("The InOrder Traversal of Tree is: ");
      DisplayInOrderTraversal(root);
      printf("\n");
      break;
    }
    case 5:
    {
      printf("The PreOrder Traversal of Tree is: ");
      DisplayPreOrderTraversal(root);
      printf("\n");
      break;
    }
    case 6:
    {
      printf("The PostOrder Traversal of Tree is: ");
      DisplayPostOrderTraversal(root);
      printf("\n");
      break;
    }
    case 7:
    {
      findMin();
      break;
    }
    case 8:
    {
      findMax();
      break;
    }
    default:
    {
      printf("Entered Invalid Option");
      break;
    }
    }
    printf("Enter 1 to Insert, 2 to Delete, 3 to Search, 4 to InorderTraversal, 5 to PreOrderTraversal, 6 to PostOrderTraversal, 7 to Get Minimum ELement, 8 to Get Maximum Element, 0 to quit: ");
    scanf("%d", &opt);
  }

  return 0;
}

void insertNode(int data)
{
  node *tempNode = (node *)malloc(sizeof(node));
  node *currentNode;
  node *parentNode;

  if (tempNode == NULL)
  {
    printf("Memory Allocation Failed");
    return;
  }

  tempNode->data = data;
  tempNode->leftChild = NULL;
  tempNode->rightChild = NULL;

  if (root == NULL)
  {
    root = tempNode;

    return;
  }

  currentNode = root;
  parentNode = NULL;

  while (currentNode != NULL)
  {
    parentNode = currentNode;
    if (data < parentNode->data)
    {
      currentNode = currentNode->leftChild;
    }
    else
    {
      currentNode = currentNode->rightChild;
    }
  }

  if (data < parentNode->data)
  {
    parentNode->leftChild = tempNode;
  }
  else
  {
    parentNode->rightChild = tempNode;
  }

  return;
}

void searchNode(int data)
{
  node *currentNode = root;
  int level = 0;

  while (currentNode != NULL)
  {
    if (currentNode->data == data)
    {
      printf("The level of searched node is %d\n", level);
      return;
    }

    if (currentNode->data < data)
    {
      currentNode = currentNode->rightChild;
      level++;
    }
    else
    {
      currentNode = currentNode->leftChild;
      level++;
    }
  }

  printf("No Node with the given data\n");
  return;
}

void deleteNode(int data)
{
  node *currentNode = root;
  node *parentNode = NULL;
  while ((currentNode != NULL) && (currentNode->data != data))
  {
    parentNode = currentNode;
    if (currentNode->data < data)
    {
      currentNode = currentNode->rightChild;
    }
    else
    {
      currentNode = currentNode->leftChild;
    }
  }

  if (currentNode == NULL)
  {
    printf("The Node with given data doesnt exist\n");
    return;
  }

  if ((currentNode->leftChild == NULL) && (currentNode->rightChild == NULL))
  {
    if (currentNode != root)
    {
      if (parentNode->leftChild == currentNode)
      {
        parentNode->leftChild = NULL;
      }
      else
      {
        parentNode->rightChild = NULL;
      }
    }
    else
    {
      root = NULL;
    }

    free(currentNode);
    return;
  }

  if ((currentNode->leftChild == NULL) || (currentNode->rightChild == NULL))
  {
    node *childNode = currentNode->leftChild ? currentNode->leftChild : currentNode->rightChild;
    if (currentNode != root)
    {
      if (currentNode == parentNode->leftChild)
      {
        parentNode->leftChild = childNode;
      }
      else
      {
        parentNode->rightChild = childNode;
      }
    }
    else
    {
      root = childNode;
    }

    free(currentNode);
    return;
  }

  if ((currentNode->leftChild != NULL) && (currentNode->rightChild != NULL))
  {
    node *inOrderSuccNode = getInOrderSuccNode(root->rightChild);
    int newData = inOrderSuccNode->data;
    deleteNode(inOrderSuccNode->data);
    currentNode->data = newData;
    return;
  }
}

node *getInOrderSuccNode(node *currentNode)
{
  while (currentNode->leftChild != NULL)
  {
    currentNode = currentNode->leftChild;
  }
  return currentNode;
}

void DisplayInOrderTraversal(node *root)
{
  if (root == NULL)
  {
    return;
  }

  DisplayInOrderTraversal(root->leftChild);
  printf("%d ", root->data);
  DisplayInOrderTraversal(root->rightChild);
}

void DisplayPreOrderTraversal(node *root)
{
  if (root == NULL)
  {
    return;
  }

  printf("%d ", root->data);
  DisplayPreOrderTraversal(root->leftChild);
  DisplayPreOrderTraversal(root->rightChild);
}

void DisplayPostOrderTraversal(node *root)
{
  if (root == NULL)
  {
    return;
  }

  DisplayPostOrderTraversal(root->leftChild);
  DisplayPostOrderTraversal(root->rightChild);
  printf("%d ", root->data);
}

void findMax()
{
  node *currNode = root;
  while (currNode != NULL && currNode->rightChild != NULL)
  {
    currNode = currNode->rightChild;
  }

  printf("The Maximum value of a node is %d\n", currNode->data);
}

void findMin()
{
  node *currNode = root;
  while (currNode != NULL && currNode->leftChild != NULL)
  {
    currNode = currNode->leftChild;
  }

  printf("The Minimum value of a node is %d\n", currNode->data);
}
