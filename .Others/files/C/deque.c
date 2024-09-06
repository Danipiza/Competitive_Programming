#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

typedef struct {
    int front, rear, size;
    int items[MAX];
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front=0;
    q->rear=-1;
    q->size=0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) { return q->size==0; }

// Function to check if the queue is full
int isFull(Queue* q) { return q->size==MAX; }

// Function to enqueue an element into the queue
void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear=(q->rear+1) % MAX;
    q->items[q->rear] = item;
    q->size++;
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; 
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return item;
}

// Function to get the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; 
    }
    return q->items[q->front];
}