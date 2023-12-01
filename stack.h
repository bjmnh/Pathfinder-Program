/*
Author: Ben Hanson
Date: 11/8/22
Description: This code outlines a stack
*/
#pragma once

struct Stack
{
    int size;
    int top;
    double *a;
};

struct Stack *createStack(int);
void push(struct Stack *, int);
int pop(struct Stack *);