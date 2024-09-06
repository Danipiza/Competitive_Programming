#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size

typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack* s) { s->top=-1; }

// Function to check if the stack is empty
int isEmpty(Stack* s) { return s->top==-1; }

// Function to check if the stack is full
int isFull(Stack* s) { return s->top==MAX-1; }

// Function to push an element onto the stack
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }

    s->items[++(s->top)]=item;
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
       printf("Stack underflow\n");
       return -1; 
    }

    return s->items[(s->top)--];
}

// Function to peek at the top element of the stack
int peek(Stack* s) {
   if (isEmpty(s)) {
      printf("Stack is empty\n");
      return -1; 
   }

   return s->items[s->top];
}