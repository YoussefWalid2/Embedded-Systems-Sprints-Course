#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[256];    
char x[256];         // The user input is Limited to 256 Bytes in this case 
int top = -1;

void push(char);
void pop();
int main()
{
	printf("Type your expression:");
	scanf("%s", &x);

	for (int i = 0;x[i] != '\0';i++)   //'\0' is considered as string termination to exit the loop
	{
		if (x[i] =='(' || x[i] == '[' || x[i] == '{')
		{
			push(x[i]);  
		}
		else if (x[i] == ')' || x[i] == ']' || x[i] == '}')
		{
			pop();
			if (top == -2) // This if statement helps preventing a closing bracket to be the start of the input
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
