#include <iostream>
#include <cstring>

#define MAX_SIZE_EXP 100

using namespace std;
typedef struct Stack
{
	int top;
	int size;
	int *array;
} Stack;

Stack *createStack(int size)
{
	Stack *stack = new Stack;
	if (!stack)
	{
		cout << "Memory Allocation Failed\n";
		return nullptr;
	}

	stack->top = -1;
	stack->size = size;

	stack->array = new int[size];
	return stack;
}

bool isEmpty(Stack *stack)
{
	if (stack->top == -1)
	{
		return true;
	}
	return false;
}

char peek(Stack *stack)
{
	return stack->array[stack->top];
}

char pop(Stack *stack)
{
	if (!isEmpty(stack))
	{
		return stack->array[stack->top--];
	}
	return '#';
}

void push(Stack *stack, char op)
{
	stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		   (ch >= 'A' && ch <= 'Z');
}

int precedence(char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	if (op == '^')
	{
		return 3;
	}
	return -1;
}

void infixToPostfix(char *exp)
{
	int i, k;
	int lenOfExp = strlen(exp);
	struct Stack *stack = createStack(strlen(exp));
	if (!stack)
	{
		return;
	}

	int openingBracketCount = 0;
	int closingBracketCount = 0;
	int operatorCount = 0;
	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
		{
			exp[++k] = exp[i];
		}

		else if (exp[i] == '(')
		{
			openingBracketCount++;
			push(stack, exp[i]);
		}

		else if (exp[i] == ')')
		{
			closingBracketCount++;
			while (!isEmpty(stack) && peek(stack) != '(')
			{
				exp[++k] = pop(stack);
			}
			if (isEmpty(stack))
			{
				cout << "Invalid Expression\n";
				return;
			}
			else
			{
				pop(stack);
			}
		}
		else
		{
			operatorCount++;
			while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
			{
				exp[++k] = pop(stack);
			}
			push(stack, exp[i]);
		}
	}

	while (!isEmpty(stack))
	{
		exp[++k] = pop(stack);
	}

	exp[++k] = '\0';
	if (openingBracketCount != closingBracketCount)
	{
		cout << "Invalid Expression\n";
		return;
	}
	if (lenOfExp - (2 * operatorCount + 1) - (openingBracketCount + closingBracketCount) != 0)
	{
		cout << "Invalid Expression\n";
		return;
	}

	printf("%s\n", exp);
}

int main()
{
	char exp[MAX_SIZE_EXP];
	cout << "Enter the expression: ";
	scanf("%s", exp);
	infixToPostfix(exp);
	return 0;
}
