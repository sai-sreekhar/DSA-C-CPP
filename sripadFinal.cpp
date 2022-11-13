#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000
#define MAX_CHARS 26
//a b c d e f g h

typedef struct node
{
    char data;
    struct node *leftChild, *rightChild;
} node;
node *rootNode = NULL;

int truthValues[MAX_CHARS]; // array to store truth value. size is 26 for 26 lower cased alphabets

class Stack
{
    int top;

public:
    char stackArr[MAX_SIZE];

    Stack() { top = -1; }
    void pushStack(int dataToPush);
    void popStack();
    char peekStack();
    bool isStackEmpty();
};

void Stack::pushStack(int dataToPush)
{
    if (top >= (MAX_SIZE - 1)) // if stack is full
    {
        cout << "Stack Overflow";
    }
    else
    {
        stackArr[++top] = dataToPush; // insert element into stack by incrementing top
    }
}

void Stack::popStack()
{
    if (top < 0) // if stack is empty
    {
        cout << "Stack Underflow";
        return;
    }
    else
    {
        int poppedVal = stackArr[top--]; // decrementing top
        return;
    }
}
char Stack::peekStack()
{
    if (top < 0) // if stack is empty
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        char val = stackArr[top]; // returning top element in stack
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
        printf("%c", rootNode->data);
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
    ///+ab
    if (currentIdx == s.size())
        return NULL;
    node *rootNode = new node;
    rootNode->data = s[++currentIdx];
    if (s[currentIdx] == '*' || s[currentIdx] == '~' || s[currentIdx] == '+' || s[currentIdx] == '>') // constructing tree with leaf nodes as operands and inner nodes as operators
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
            if (prefixExpression[i] == '>') // logic for implication
            {
                if (val1 == 1 && val2 == 0)
                {
                    operandStack.pushStack(0); // push false i.e 0
                }
                else
                {
                    operandStack.pushStack(1); // push true i.e 1
                }
            }
            else if (prefixExpression[i] == '*') // logic for and
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
            else if (prefixExpression[i] == '+') // logic for or
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
        else if (prefixExpression[i] == '~') // logic for negation
        {
            int val = operandStack.peekStack();
            operandStack.popStack();
            if (val == 0)
            {
                operandStack.pushStack(1);
            }
            else
            {
                operandStack.pushStack(0);
            }
        }
        else
        {
            int truthVal;
            if (truthValues[prefixExpression[i] - 'a'] == -1) // if truth value is -1 take the input
            {
                cout << "Enter the truth value for " << prefixExpression[i] << " : ";
                cin >> truthVal;                                   // taking input for truth values
                truthValues[prefixExpression[i] - 'a'] = truthVal; // store the truth value
            }
            operandStack.pushStack(truthValues[prefixExpression[i] - 'a']); // pushing the truth values to stack
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
        return 1 + max(getHeightOfParseTree(rootNode->leftChild), getHeightOfParseTree(rootNode->rightChild)); // iterate through left and right subtrees
    }
}

bool isOperator(char opr)
{
    return (!isalpha(opr) && !isdigit(opr)); // checking whether given character is operator
}

int getPrecedence(char opr)
{
    if (opr != '(') // precendences if all operators are 1 except for "("
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

        if (isalpha(infixExpression[i]) || isdigit(infixExpression[i])) // if is ooperand append to output string
            postfixExpression += infixExpression[i];
        else if (infixExpression[i] == '(') // if its open bracket push into stack
            operatorStack.pushStack('(');
        else if (infixExpression[i] == ')')
        {
            while (operatorStack.peekStack() != '(') // if its closed bracket pop all the elements until u get ()
            {
                postfixExpression += operatorStack.peekStack();
                operatorStack.popStack();
            }
            operatorStack.popStack();
        }
        else
        {
            if (isOperator(operatorStack.peekStack())) // push operator into stack
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
    while (!operatorStack.isStackEmpty()) // if input string is completely traversed pop all elements from stack and append to output string
    {
        postfixExpression += operatorStack.peekStack();
        operatorStack.popStack();
    }
    return postfixExpression;
}

string infixToPrefix(string infixExpression)
{
    int low = infixExpression.size();
    reverse(infixExpression.begin(), infixExpression.end()); // reverse given infix

    for (int i = 0; i < low; i++)
    {

        if (infixExpression[i] == '(') // while reversing open bracket and closed brackets should interchange
        {
            infixExpression[i] = ')';
        }
        else if (infixExpression[i] == ')')
        {
            infixExpression[i] = '(';
        }
    }

    string prefixExpression = infixToPostfix(infixExpression); // convert reversed infix to postfix

    reverse(prefixExpression.begin(), prefixExpression.end()); // reverse the postfix to get prefix

    return prefixExpression;
}

int main()
{
    memset(truthValues, -1, sizeof(truthValues));
    string propositionalLogic;
    cout << "Enter the Propositional Logic (Note: It is not case sensitive. Expression should contain only small cased leters) ";
    cin >> propositionalLogic;
    string prefixExpression = infixToPrefix(propositionalLogic);
    cout << "The Prefix Expression is: " << prefixExpression << endl;
    int currentIdx = -1;
    rootNode = constructTree(prefixExpression, currentIdx);
    cout << "The Infix expression is (From Parse Tree): ";
    inorderTraversal(rootNode);
    cout << "\n";
    cout << "Height of Parse tree is ";
    cout << getHeightOfParseTree(rootNode) - 1 << "\n";
    evaluate(prefixExpression);
    return 0;
}