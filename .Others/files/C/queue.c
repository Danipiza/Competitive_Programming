#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Define a deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

// Function to initialize a deque
Deque* createDeque() {
    Deque* deque=(Deque*)malloc(sizeof(Deque));
    deque->front=NULL;
    deque->rear=NULL;
    return deque;
}

// Function to add an element to the front of the deque
void insertFront(Deque* deque, int data) {
    Node* newNode=createNode(data);
    if (deque->front==NULL) {
        deque->front=newNode;
        deque->rear=newNode;
    }
    else {
        newNode->next=deque->front;
        deque->front->prev=newNode;
        deque->front=newNode;
    }
}

// Function to add an element to the rear of the deque
void insertRear(Deque* deque, int data) {
    Node* newNode=createNode(data);
    if (deque->rear==NULL) {
        deque->front=newNode;
        deque->rear=newNode;
    }
    else {
        newNode->prev=deque->rear;
        deque->rear->next=newNode;
        deque->rear=newNode;
    }
}

// Function to remove an element from the front of the deque
int deleteFront(Deque* deque) {
    if (deque->front==NULL) {
        printf("Deque is empty\n");
        return -1; 
    }
    Node* tmp=deque->front;
    int data=tmp->data;
    deque->front=deque->front->next;
    if (deque->front!=NULL) {
        deque->front->prev=NULL;
    }
    else deque->rear=NULL;
    
    free(tmp);
    return data;
}

// Function to remove an element from the rear of the deque
int deleteRear(Deque* deque) {
    if (deque->rear==NULL) {
        printf("Deque is empty\n");
        return -1; 
    }

    Node* tmp=deque->rear;
    int data=tmp->data;
    deque->rear=deque->rear->prev;
    if (deque->rear!=NULL) {
        deque->rear->next=NULL;
    }
    else deque->front=NULL;

    free(tmp);
    return data;
}