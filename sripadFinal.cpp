#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000
#define MAX_CHARS 26

typedef struct node
{
    char data;
    struct node *leftChild, *rightChild;
} node;
node *rootNode = NULL;

int truthValues[MAX_CHARS];

class Stack
{
    int top;

public:
    char stackArr[MAX_SIZE];

    Stack() { top = -1; }
    bool pushStack(int dataToPush);
    void popStack();
    char peekStack();
    bool isStackEmpty();
};

bool Stack::pushStack(int dataToPush)
{
    if (top >= (MAX_SIZE - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        stackArr[++top] = dataToPush;
        return true;
    }
}

void Stack::popStack()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return;
    }
    else
    {
        int poppedVal = stackArr[top--];
        return;
    }
}
char Stack::peekStack()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        char val = stackArr[top];
        return val;
    }
}

bool Stack::isStackEmpty()
{
    return (top < 0);
}

void inorderTraversal(node *rootNode)
{
    if (rootNode == NULL)
    {
        return;
    }
    else
    {
        inorderTraversal(rootNode->leftChild);
        printf("%c ", rootNode->data);
        inorderTraversal(rootNode->rightChild);
    }
}

void postOrderTraversal(node *rootNode)
{
    if (rootNode == NULL)
    {
        return;
    }
    else
    {
        postOrderTraversal(rootNode->leftChild);
        postOrderTraversal(rootNode->rightChild);
        printf("%c ", rootNode->data);
    }
}

node *constructTree(string s, int &currentIdx)
{
    if (currentIdx == s.size())
        return NULL;
    node *rootNode = new node;
    rootNode->data = s[++currentIdx];
    if (s[currentIdx] == '*' || s[currentIdx] == '~' || s[currentIdx] == '+' || s[currentIdx] == '>')
    {
        rootNode->leftChild = constructTree(s, currentIdx);
        rootNode->rightChild = constructTree(s, currentIdx);
        return rootNode;
    }
    else
    {
        return rootNode;
    }
}

void evaluate(string prefixExpression)
{
    int len = prefixExpression.length();
    Stack operandStack;
    int i = len - 1;
    while (i >= 0)
    {
        if (prefixExpression[i] == '>' || prefixExpression[i] == '+' || prefixExpression[i] == '*')
        {
            int val1 = operandStack.peekStack();
            operandStack.popStack();
            int val2 = operandStack.peekStack();
            operandStack.popStack();
            if (prefixExpression[i] == '>')
            {
                if (val1 == 1 && val2 == 0)
                {
                    operandStack.pushStack(0);
                }
                else
                {
                    operandStack.pushStack(1);
                }
            }
            else if (prefixExpression[i] == '*')
            {
                if (val1 == 1 && val2 == 1)
                {
                    operandStack.pushStack(1);
                }
                else
                {
                    operandStack.pushStack(0);
                }
            }
            else if (prefixExpression[i] == '+')
            {
                if (val1 == 0 && val2 == 0)
                {
                    operandStack.pushStack(0);
                }
                else
                {
                    operandStack.pushStack(1);
                }
            }
        }
        else if (prefixExpression[i] == '~')
        {
            int val = operandStack.peekStack();
            operandStack.popStack();
            if (val == 0)
            {
                operandStack.pushStack(1);
            }
            else
            {
                operandStack.pushStack(1);
            }
        }
        else
        {
            int truthVal;
            if (truthValues[prefixExpression[i] - 'a'] == -1)
            {
                cout << "Enter the truth value for " << prefixExpression[i] << " : ";
                cin >> truthVal;
                truthValues[prefixExpression[i] - 'a'] = truthVal;
            }
            operandStack.pushStack(truthValues[prefixExpression[i] - 'a']);
        }

        i--;
    }
    int result = operandStack.peekStack();
    cout << "The Truth Value of the propositional logic is: " << result << "\n";
    return;
}

int getHeightOfParseTree(node *rootNode)
{
    if (rootNode == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(getHeightOfParseTree(rootNode->leftChild), getHeightOfParseTree(rootNode->rightChild));
    }
}

bool isOperator(char opr)
{
    return (!isalpha(opr) && !isdigit(opr));
}

int getPrecedence(char opr)
{
    if (opr != '(')
        return 1;
    return 0;
}

string infixToPostfix(string infixExpression)
{
    infixExpression = '(' + infixExpression + ')';
    int low = infixExpression.size();
    Stack operatorStack;
    string postfixExpression;

    for (int i = 0; i < low; i++)
    {

        if (isalpha(infixExpression[i]) || isdigit(infixExpression[i]))
            postfixExpression += infixExpression[i];
        else if (infixExpression[i] == '(')
            operatorStack.pushStack('(');
        else if (infixExpression[i] == ')')
        {
            while (operatorStack.peekStack() != '(')
            {
                postfixExpression += operatorStack.peekStack();
                operatorStack.popStack();
            }
            operatorStack.popStack();
        }
        else
        {
            if (isOperator(operatorStack.peekStack()))
            {
                {
                    while (getPrecedence(infixExpression[i]) < getPrecedence(operatorStack.peekStack()))
                    {
                        postfixExpression += operatorStack.peekStack();
                        operatorStack.popStack();
                    }
                }
                operatorStack.pushStack(infixExpression[i]);
            }
        }
    }
    while (!operatorStack.isStackEmpty())
    {
        postfixExpression += operatorStack.peekStack();
        operatorStack.popStack();
    }
    return postfixExpression;
}

string infixToPrefix(string infixExpression)
{
    int low = infixExpression.size();
    reverse(infixExpression.begin(), infixExpression.end());

    for (int i = 0; i < low; i++)
    {

        if (infixExpression[i] == '(')
        {
            infixExpression[i] = ')';
        }
        else if (infixExpression[i] == ')')
        {
            infixExpression[i] = '(';
        }
    }

    string prefixExpression = infixToPostfix(infixExpression);

    reverse(prefixExpression.begin(), prefixExpression.end());

    return prefixExpression;
}

int main()
{
    memset(truthValues, -1, sizeof(truthValues));
    string propositionalLogic;
    cout << "Enter the Propositional Logic (Note: It is not case sensitive. Expression should contain only small cased leters) ";
    cin >> propositionalLogic;
    string prefixExpression = infixToPrefix(propositionalLogic);

    int currentIdx = -1;
    rootNode = constructTree(prefixExpression, currentIdx);
    cout << "The Infix expression is: ";
    inorderTraversal(rootNode);
    cout << "\n";
    cout << "Height of Parse tree is ";
    cout << getHeightOfParseTree(rootNode) - 1 << "\n";
    evaluate(prefixExpression);
    return 0;
}
