/*
Author: Ben Hanson
Date: 11/8/22
Description: This code implements a stack
*/
#include <iostream>
#include "stack.h"

// creates stack of size size
struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->a = (double *)malloc(size * sizeof(double));
    return stack;
}

// adds to stack increases top by 1
void push(struct Stack *stack, int number)
{
    if (stack->top == stack->size - 1)
    {
        return;
    }
    stack->a[++stack->top] = number;
}

// removes/returns from stack decreases top by 1
int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        return -1;
    }
    return stack->a[stack->top--];
}
