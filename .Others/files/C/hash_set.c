#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100  // Size of the hash table

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* table[TABLE_SIZE];
} Set;

// Hash function
unsigned int hash(int key) {
    return key%TABLE_SIZE;
}

// Initialize the set
void initSet(Set* set) {
    for (int i=0;i<TABLE_SIZE;i++) {
        set->table[i]=NULL;
    }
}

// Insert an element into the set
void insert(Set* set, int val) {
    unsigned int index=hash(val);
    Node* curr=set->table[index];
    while (curr!=NULL) {
        if (curr->data==val) return; // Element already in the set
        curr=curr->next;
    }
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=set->table[index];
    set->table[index]=newNode;
}

// Check if an element is in the set
int contains(Set* set, int val) {
    int index=hash(val);
    Node* curr=set->table[index];
    while (curr!=NULL) {
        if (curr->data==val) return 1; // Element found
        curr=curr->next;
    }
    return 0; // Element not found
}

// Remove an element from the set
void remove(Set* set, int val) {
    int index=hash(val);
    Node* curr=set->table[index];
    Node* prev=NULL;
    while (curr!=NULL) {
        if (curr->data==val) {
            if (prev==NULL) set->table[index]=curr->next;
            else prev->next=curr->next;

            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
}