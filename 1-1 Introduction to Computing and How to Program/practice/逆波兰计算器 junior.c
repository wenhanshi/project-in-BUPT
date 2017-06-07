#include<stdio.h>
#include<stdlib.h>

void push(int);
int pop(void);

int main(void)
{
	int type;
	int op2;
	
	while((type=getchar())!=EOF)
	{
		switch(type)
		{
			case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '0':
				push(type-'0');
				break;
			case '+':
				push(pop()+pop());
				break;
			case '-':
				op2=pop();
				push(pop()-op2);
				break;
			case '*':
				push(pop()*pop());
				break;
			case '/':
				op2=pop();
				if(op2==0)
				{
					printf("Error:zero cant be devisior!");
				}
				else
				{
					push(op2/pop());
				}
				break;
			case '\n':
				printf("%d\n",pop());
				break;
			default:
				printf("Error:unknown command %c",type);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100
int val[MAXVAL];
int sp;

void push(int f)
{
	if(sp<MAXVAL)
	{
		val[sp++]=f;
	}
	else
	{
		printf("Error:the stack is full!");
	}
}
int pop(void)
{
	if(sp>0)
	{
		return val[--sp];
	}
	else
	{
		printf("Error:the stack is clean!");
		return 0;
	}
}

