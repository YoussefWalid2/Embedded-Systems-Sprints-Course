#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[256];
char x[256];
int top = -1;
int i;

void push(char);
void pop();
int main()
{
	printf("Type your expression:");
	scanf("%s", &x);

	for (i = 0;x[i] != '\0';i++)
	{
		if (x[i] =='(' || x[i] == '[' || x[i] == '{')
		{
			push(x[i]);
		}
		else if (x[i] == ')' || x[i] == ']' || x[i] == '}')
		{
			pop();
			if (top == -2)
			{
				break;
			}
		}

	}
	if (top == -1)
	{
		printf("\nExpression is balanced\n");
	}
	else
	{
		printf("\nExpression is unbalanced\n");
	}

}

void push(char x)
{
	top = top + 1;
	stack[top] = x;
}
void pop()
{
	top = top - 1;
	stack[top-1] = x;
}
