#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};

string str;
vector<string> vec;
void rootToLeaf(struct node *root)
{
    if (!root)
    {
        str.pop_back();
        return;
    }
    str.append(to_string(root->data));
    if (!root->left && !root->right)
    {

        // cout << "string is" << str << endl;
        vec.push_back(str);
        str.pop_back();
        return;
    }

    rootToLeaf(root->left);
    rootToLeaf(root->right);
    str.pop_back();
    return;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}

struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}

int main()
{
    /*
       4
      9 0
    5 1
    */
    struct node *root = createNode(4);
    insertLeft(root, 9);
    insertRight(root, 0);
    insertLeft(root->left, 5);
    insertRight(root->left, 1);

    rootToLeaf(root);

    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += (stoi(vec[i]));
    }
    cout << sum;
}