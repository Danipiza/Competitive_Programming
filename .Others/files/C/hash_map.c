#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100  // Size 

// Define a node structure for the hash map
typedef struct Node {
    char key[256];
    int val;
    struct Node* next;
} Node;

// Define a hash map structure
typedef struct HashMap {
    Node* table[TABLE_SIZE];
} HashMap;

// Hash function
unsigned int hash(char* key) {
    unsigned long int hashval=0;
    while (*key) hashval=(hashval << 5)+*key++;

    return hashval%TABLE_SIZE;
}

// Initialize the hash map
void initHashMap(HashMap* map) {
    for (int i=0;i<TABLE_SIZE;i++) map->table[i]=NULL;
}

// Insert key-val pair into the hash map
void insert(HashMap* map, char* key, int val) {
    unsigned int index=hash(key);

    Node* newNode=(Node*)malloc(sizeof(Node));

    strcpy(newNode->key, key);
    newNode->val=val;
    newNode->next=map->table[index];

    map->table[index]=newNode;
}

// Search for a val by key
int search(HashMap* map, char* key) {
    unsigned int index=hash(key);
    Node* curr=map->table[index];
    while (curr) {
        if (strcmp(curr->key, key)==0) {
            return curr->val;
        }
        curr=curr->next;
    }
    return -1;  // Key not found
}

// Delete a key-val pair
void delete(HashMap* map, char* key) {
    unsigned int index=hash(key);
    Node* curr=map->table[index];
    Node* prev=NULL;

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            if (prev) prev->next = curr->next;
            else map->table[index] = curr->next;

            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
}

// Display the hash map
void for_each(HashMap* map) {
    for (int i=0;i<TABLE_SIZE;i++) {
        Node* curr=map->table[i];
        if (curr) {
            printf("Bucket %d:\n", i);
            while (curr) {
                printf("  %s: %d\n", curr->key, curr->val);
                curr=curr->next;
            }
        }
    }
}