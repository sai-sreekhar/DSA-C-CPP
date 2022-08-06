#include <iostream>
#include <cstring>

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
		return stack->array[stack->top--];
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

int infixToPostfix(char *exp)
{
	int i, k;
	struct Stack *stack = createStack(strlen(exp));
	if (!stack)
		return -1;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];

		else if (exp[i] == '(')
			push(stack, exp[i]);

		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1;
			else
				pop(stack);
		}
		else
		{
			while (!isEmpty(stack) &&
				   precedence(exp[i]) <= precedence(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}
	}
	
	while (!isEmpty(stack))
		exp[++k] = pop(stack);

	exp[++k] = '\0';
	printf("%s", exp);
}

int main()
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}
