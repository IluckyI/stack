#include "Header.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int ALLOC_STEP = 100;

void push_stack(LiteStackPtr* ptr, const char data)
{
	assert(ptr != 0);
	//考虑空队列
	if (*ptr == 0)
	{
		*ptr = (LiteStackPtr)calloc(1, sizeof(LiteStack));
	}
	//考虑队列内部数据空间不足时扩容
	if ((*ptr)->size + 1 > (*ptr)->capacity)
	{
		//给数据成员分配空间
		(*ptr)->data = (char*)realloc((*ptr)->data, (*ptr)->capacity + ALLOC_STEP);
		(*ptr)->capacity = (*ptr)->capacity + ALLOC_STEP;
	}
	//给队列内部数据按索引赋值(尾部)
	(*ptr)->data[(*ptr)->size] = data;
	(*ptr)->size += 1;

}
char pop_stack(LiteStackPtr* ptr)
{
	assert(ptr != 0 && (*ptr) != 0 && (*ptr)->size != 0);

	char ret = (*ptr)->data[(*ptr)->size-1];

	char* pdata = (char*)malloc((*ptr)->capacity);
	memcpy(pdata, (*ptr)->data , (*ptr)->size - 1);
	free((*ptr)->data);
	(*ptr)->data = pdata;

	//memmove((*ptr)->data, (*ptr)->data + 1, (*ptr)->size - 1);

	(*ptr)->size -= 1;

	return ret;
}

bool stack_empty(LiteStackPtr stack)
{
	assert(stack != 0);
	return stack->size == 0;
}

void stack_foreach(LiteStackPtr stack, LITE_FUNC func)
{
	assert(stack);
	for (int i = 0; i < stack->size; i++)
	{
		func(stack->data[i]);
	}
}
void instructions(void);

void printElement(char data)
{
	printf("%c ", data);
}
int main()
{
	LiteStackPtr pStack = 0;

	char item;

	instructions();
	printf("? ");
	int choice;
	scanf("%d", &choice);

	while (choice != 4)
	{

		switch (choice)
		{

		case 1:
		{
			printf("Enter a character: ");
			scanf("\n%c", &item);
			push_stack(&pStack, item);
		}
		break;
		case 2:
		{
			if (!stack_empty(pStack))
			{
				item = pop_stack(&pStack);
				printf("\'%c\' has been deStack.\n", item);
			}

		}
		break;

		case 3:
		{
			printf("Stack elements:\n");
			stack_foreach(pStack, printElement);
			printf("\n");
		}
		break;

		default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}

		printf("? ");
		scanf("%d", &choice);
	}

	printf("End of run.\n");
	return 0;
}

void instructions(void)
{
	printf("Enter your choice:\n"
		"   1 to add an item to the Stack\n"
		"   2 to remove an item from the Stack\n"
		"   3 show all elements in the Stack\n"
		"   4 to end\n");
}