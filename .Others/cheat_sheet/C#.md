<h1 align="center">
    LANGUAGE: <img src="https://skillicons.dev/icons?i=cs" alt="C# Language Icon" width="30" height="30" />
</h1>


<div align="center"> 
 
 This document provides a quick reference to essential **C#** concepts and methods.
 :-----:
 
</div>

# INDEX
1. [Conditions](#conditions)
2. [Loops](#loops)
3. [String](#string)
4. [Characters](#characters)
5. [Arrays](#arrays)
6. [Sorting](#sorting)
7. [ListNode](#listnode)
8. [Queue](#queue)
9. [PriorityQueue](#priorityqueue)
10. [Stack](#stack)
11. [Sets](#sets)
12. [Dictionaries](#dictionaries)
13. [Class](#class)
14. [Comment](#comment)


## Conditions
### IF and ELSE:
```csharp
if (a < b) {
   // <code>
} else if (a > b) {
   // <code>
} else {
   // <code>
}
```
### Switch:
```csharp
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
```csharp
<1_line_<code>> = (a == b) ? <true_code> : <false_code>;
```
### Operations:
```csharp
&&	// AND.		        true if both conditions are true. false otherwise.
||	// OR.		        true if one or more conditions are true. false otherwise.
!	// NOT.		        Negates a boolean val.
^	// XOR.		        Performs a logical exclusive OR.
&	// Bitwise AND.  Performs a bitwise AND operation.
|	// Bitwise OR.   Performs a bitwise OR operation.
~ 	// Bitwise NOT.  Flips all bits.
```

<hr>

## Loops
### Iterates from 0 to n
```csharp
for (int i = 0; i < n; i++) {
while (i < n) {
	
	<code>
}
```
### Iterates from n to 0
```csharp
for (int i = n; i >= 0; i--) {
while (i >= 0) {

	<code>
}
```
### For-each
```csharpsharp
foreach(<type> num in <data>)
```
### Control flow
```csharp
continue; // Skips the curr iteration and moves to the next one.
break;	   // Exits the loop completely.
```

<hr>

## String
```csharp
string str = "aaaaa";
string str = new string('a', 5); 
string str = $"Value: {a}"; // interpolation

// Concatenation
string combined = str1 + " World";
string concat   = string.Concat(str1, " ", "World");
// Length and access
int n = str.Length;
char first = str[0];
// TODO

```

## Characters
```csharp
char c = 'A';
char c = '\u006A'; // Unicode escape sequence
char c = '\x006A'; // Hexadecimal escape sequence
char c = (char)106; // Cast from integer
// Comparing
int compareResult = char.Compare(c1, c2);

// TODO
```

<hr>

## Arrays
### Init.
```csharp
int[] arr = new int[3]; // Create an empty array.
int[] arr = new int[] {1, 2, 3}; // Create an array with 3 values.
int[] arr = {1, 2, 3};
```
### Matrix
```csharp
int[,] mat = new int[3, 3] {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
int[,] mat = new int[,] {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Jagged arrays
int[][] mat = new int[3][];
int[][] mat = new int[][]
{
    new int[] {1, 2, 3},
    new int[] {4, 5},
    new int[] {6, 7, 8, 9}
};
```
<hr>

## Sorting 
### Array
```csharp
Array.Sort(arr);                     // Ascending order.
Array.Reverse(arr);                  // Descending order.
```
### List
```csharp
list.Sort();                         // Ascending order.
list.Sort((a, b) => b.CompareTo(a)); // Descending order.
```

### Priority_queue
```csharp
public class Node : IComparable<Node> {
    public int val;
    public int idx;

    public Node(int val, int idx) {
        this.val = val;
        this.idx = idx;
    }

    public int CompareTo(Node other) {        
        if (other.val != this.val) return other.val.CompareTo(this.val); 
        else return other.idx.CompareTo(this.idx);
    }
}
```
<hr>

## ListNode
```csharp
public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val=0, ListNode next=null) {
    	this.val = val;
    	this.next = next;
    }
}
```

<hr>

## Queue 
### Init
```csharp
var Q = new Queue<type>();
var queue = new Queue<int>(array);
```
### Operations
```csharp
Q.Enqueue(_);			 // Add values at the end.
type x = Q.Dequeue();		 // Remove and check the value at the front.
type first = Q.Peek();		 // Check the value at the front.
bool exits = Q.Contains(_);	 // Check for an element.
int n = Q.Count;		 // Number of elements.
Q.Clear();			 // Clear.
int[] array = numbers.ToArray(); // Transform to an array.
foreach (int number in numbers)  // Iterates.
```
<hr>


## PriorityQueue
> [!TIP]
> You can use an SortedSet. One element instead of two with the prio. 

```csharp
// Init
var pq = new PriorityQueue<Element, Prio>();
// Operations
pq.Enqueue(_,_);
PrioType x = pq.Dequeue();
```




## Stack
### Init
```csharp
var S = new Stack<type>();
var stack = new Stack<int>(array);
```
### Operations
```csharp
S.Push(_);			 // Add values at the end.
type x = S.Pop();		 // Remove and check the value at the front.
type first = S.Peek();		 // Check the value at the front.
bool exits = S.Contains(_);	 // Check for an element.
int n = S.Count;		 // Number of elements.
Q.Clear();			 // Clear.
int[] array = numbers.ToArray(); // Transform to an array.
foreach (int number in numbers)  // Iterates.
```
<hr>

## Sets
### Init
```csharp
var set = new HashSet<type>();
var set = new HashSet<string> { "A", "B", "C" };
```
### Operations
```csharp
set.Add(type);		// Adding.
set.Remove(type);	// Remove an element.
set.Contains(type);	// Check for an element.
int n = set.Count;	// Size.
set.Clear();		// Clear.

set1.UnionWith(set2);		// Union of two sets.
set1.IntersectWith(set2);	// Intersection of two sets.
set1.ExceptWith(set2);		// Removes elements present in another set.

foreach (var item in set) // Iterate
```
### SortedSet
```csharp
var set = new SortedSet<int>();
```

<hr>

## Dictionaries
### Init
```csharp
var dict = new Stack<KeyType,ValueType>();
var dict = new Dictionary<string, int>
{
    {"A", 1},
    {"B", 2},
    {"C", 3}
};
```
### Operations
```csharp
dict.Add(KeyType,ValueType);	// Adding.
dict[KeyType] = ValueType;
ValueType val = dict[KeyType];	// Access to an element.
dict.Remove(KeyType);		// Remove an element.
dict.ContainsKey(KeyType);	// Check for an element.
int n = dict.Count;		// Size.
dict.Clear();			// Clear.

foreach (KeyValuePair<KeyType, ValueType> _ in dict) // Iterate
```

<hr>

## Class
```csharp
public class Person {
   string name;
   int age;
   // TODO
};
```



## Comment
```csharp
// <inline_comment>

/*
    <comment>
*/
```
