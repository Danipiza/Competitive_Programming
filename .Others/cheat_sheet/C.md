<h1 align="center">
    LANGUAGE: <img src="https://skillicons.dev/icons?i=c" alt="C Language Icon" width="30" height="30" />
</h1>


<div align="center"> 
 
 This document provides a quick reference to essential **C** concepts and methods.
 :-----:
 
</div>

# INDEX
1. [Conditions](#conditions)
2. [Loops](#loops)
3. [String](#string)
4. [Characters](#characters)
5. [Arrays](#arrays)
6. [Sorting](#sorting)
7. [Queue](#queue)
8. [Deque](#deque)
9. [Maps](#maps)
10. [Sets](#sets)
11. [Class](#class)
12. [Comment](#comment)


## Conditions
### IF and ELSE:
```C
if (a < b) {
   // <code>
} else if (a > b) {
   // <code>
} else {
   // <code>
}
```
### Switch:
```C
switch (var) {
   case var_1:
       // <code>
       break;
   case var_2:
       // <code>
       break;
   default:
       // <code>
}
```
### INLINE conditions:
```C
<1_line_<code>> = (a == b) ? <true_code> : <false_code>;
```
### Operations:
```C
&&	// AND.		       true if both conditions are true. false otherwise.
||	// OR.		        true if one or more conditions are true. false otherwise.
!	 // NOT.		        Negates a boolean val.
^	 // XOR.		        Performs a logical exclusive OR.
&	 // Bitwise AND.  Performs a bitwise AND operation.
|	 // Bitwise OR.   Performs a bitwise OR operation.
~ 	// Bitwise NOT. Flips all bits.
```

<hr>

## Loops
### Iterates from 0 to n
```C
for (int i = 0; i < n; i++) {
while (i < n) {
	
	<code>
}
```
### Iterates from n to 0
```C
for (int i = n; i >= 0; i--) {
while (i >= 0) {

	<code>
}
```
### Control flow
```C
continue; // Skips the curr iteration and moves to the next one.
break;	   // Exits the loop completely.
```

<hr>

## String
```C
strlen("abc"); 		                    // 3. 	   Length of the string.
strrev("abc"); 	                  	  // "cba". Reverses the characters in the string.
strupr("abc");  		                   // "ABC". Converts all lowercase chars to uppercase.
strlwr("ABC");   	                   // "abc". Converts all uppercase chars to lowercase.
strcap("abc");  	                    // "Abc". Capitalizes the first letter.
str_replace("abc", "a", "d");        // "dbc". Replaces all occurrences of 'a'.
str_replace_first("abc", "a", "d");  // "dbc". Replaces the first occurrence of 'a'.
aoti("1");			                        // 1.	   String to int .

str_to_list("abc");              		  // ['a','b','c']. Transform into a list if chars.

```

## Characters
```C
(char)97; 			  // Convert an ASCII <code> to a character
(int)'a'; 		   // = 97. ASCII val
toupper('a');  // 'A'. Convert to uppercase.
tolower('A');  // 'a'. Convert to lowercase
swapcase('a'); // 'A'. Swap case (e.g., 'a' -> 'A', 'B' -> 'b')
```

<hr>

## Arrays
###  Init.
```C
int arr[] = {1, 2, 3}; // Create an array.
int arr[3] = {0};      // Create an array with 3 zeros.
int arr[n][n] = {0};   // Create a 2D-array.
```
### Allocate array
```C
int* arr = (int*)malloc(3 * sizeof(int)); // Allocate memory for an array of 3 integers
```
### Allocate matrix
```C
int** ret = (int**)malloc(numsSize/3 * sizeof(int*));
for (int i=0;i<numsSize/3;++i){
   ret[i] = (int*)malloc(3*sizeof(int));
}
// return matrix in LeetCode
*returnSize=n;    
*returnColumnSizes=(int*)malloc(sizeof(int)*n);
for (i=0;i<n;i++) {
   (*returnColumnSizes)[i]=m;
}
```
### Access/Add
```C
arr[i]	            // i-th element.
arr[size++] = val; // End.
```

<hr>

## Sorting 
### Ascending order.
```C
qsort(array, size, sizeof(int), compare_asc);
```
### Descending order.
```C
qsort(array, size, sizeof(int), compare_desc);
```
### Conparation 
```C
int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
```
### Priority_queue
```C
typedef struct {
    char* name;
    int height;
} Node;

int compare(const void* a, const void* b) {
    Node* nodeA = (Node*)a;
    Node* nodeB = (Node*)b;
    return nodeB->height - nodeA->height; 
}

qsort(nodes, n, sizeof(Node), compare);
```
<hr>

## Queue 
```C
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
   q->items[q->rear]=item;
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
```

[CODE](https://github.com/Danipiza/Competitive_Programming/blob/main/.Others/files/C/queue.c)

> [!TIP]
> You can use an array, instead of this class. With two pointers: the first one to get the front vals, and the last one to add new ones. 

<hr>

## Deque 
```C
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
```
[CODE](https://github.com/Danipiza/Competitive_Programming/blob/main/.Others/files/C/deque.c)

<hr>

### Stack
```C
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
```
[CODE](https://github.com/Danipiza/Competitive_Programming/blob/main/.Others/files/C/stack.c)

> [!TIP]
> You can use an array, instead of this class. With one pointer: the last value inserted.


<hr>

## Maps
```C
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
```
[CODE](https://github.com/Danipiza/Competitive_Programming/blob/main/.Others/files/C/hash_map.c)

<hr>

## Sets:
```C
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
```

[CODE](https://github.com/Danipiza/Competitive_Programming/blob/main/.Others/files/C/hash_set.c)

<hr>

## Class
```C
typedef struct Person {
   char name[100];
   int age;
   void (*setName)(struct Person*, const char*);
   void (*setAge)(struct Person*, int);
   void (*printInfo)(struct Person*);
} Person;

# EXAMPLE
void setName(Person* p, const char* name) {
   strncpy(p->name, name, sizeof(p->name)-1);
   p->name[sizeof(p->name)-1]='\0'; // Ensure null-termination
}
```



## Comment
```C
// <inline_comment>

/*
    <comment>
*/
```