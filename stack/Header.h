#pragma once

#ifndef __LITE_QUEUE_h__
#define __LITE_QUEUE_h__

#include <stdbool.h>

typedef struct _LiteStack
{
	char *data;
	int size;
	int capacity;
}LiteStack, *LiteStackPtr;

typedef void(*LITE_FUNC)(char);


void push_stack(LiteStackPtr* ptr, const char data);
char pop_queue(LiteStackPtr* ptr);

void stack_foreach(LiteStackPtr, LITE_FUNC);

bool stack_empty(LiteStackPtr);

#endif

