<h1 align="center">
    LANGUAGE: <img src="https://skillicons.dev/icons?i=ruby" alt="C Language Icon" width="30" height="30" />
</h1>


<div align="center">
 
 This document provides a quick reference to essential **Ruby** concepts and methods.
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
```Ruby
if a < b
	<code>
elsif a > b 
	<code>
else
	<code>
end
```
### Switch:
```Ruby
case var
  when <var_1>
    <code>
  when <var_2>
    <code>
  else
    <code>
end
```
### INLINE conditions:
```Ruby
<1_line_code> if a == b
puts a == b ? "equal" : "not equal" 
```
### Operations:
```Ruby
and	# AND.		true if both conditions are true. false otherwise.
or	# OR.		true if one or more conditions are true. false otherwise.
not	# NOT.		Negates a boolean value.
^	# XOR.		Performs a logical exclusive OR.
&	# Bitwise AND.  Performs a bitwise AND operation.
|	# Bitwise OR.   Performs a bitwise OR operation.
~ 	# Bitwise NOT.  Flips all bits.
```

<hr>

## Loops
### Iterates from 0 to n
```Ruby
for i in 0..n-1 
n.times do
0.upto(n)
(1...n).step(1) do |i|
while i < n
	
	<code>
end
```
### Iterates from n to 0
```Ruby
while i >= 0
n.downto(0) do |i|

	<code>
end
```
### For each
```Ruby
array.each do |val|
	<code>
end

str.each_char do |char|
	<code>
end
```
### INLINE For each
```Ruby
array.each { |x| <1_line_code> }
```
### Control flow
```Ruby
next 	# Skips the current iteration and moves to the next one.
break	# Exits the loop completely.
```

<hr>

## String
```Ruby
"abc".length 	      # 3.     Length of the string.
"abc".reverse 	      # "cba". Reverses the characters in the string.
"abc".upcase 	      # "ABC". Converts all lowercase chars to uppercase.
"ABC".downcase        # "abc". Converts all uppercase chars to lowercase.
"abc".capitalize      # "Abc". Capitalizes the first letter.
"abc".gsub!(/a/, "d") # "dbc". Replaces all occurrences of 'a'.
"abc".sub!(/a/, "d")  # "dbc". Replaces the first occurrence of 'a'.
"1".to_i 	      # 1.     String to int .

"abc".chars 	      # ['a','b','c']. Transform into a list if chars.
```

## Characters
```Ruby
97.chr 		# = 'a' Convert an ASCII code to a character
'a'.ord 	# = 97. ASCII value
'a'.upcase      # 'A'.  Convert to uppercase.
'A'.downcase    # 'a'.  Convert to lowercase
'a'.capitalize  # 'A'.  Capitalize the character (if it's a letter)
'a'.swapcase    # 'A'.  Swap case (e.g., 'a' -> 'A', 'B' -> 'b')
```

<hr>

## Arrays
###  Init.
```Ruby
arr = [1, 2, 3]           	 # Create an array.
arr = Array.new           	 # Create an empty array.
arr = Array.new(3) { |i| i }     # Create an array with values [0, 1, 2].
arr = Array.new(n, 0) 		 # Create an array with n zeros.
arr=Array.new(n){Array.new(n,0)} # Create a 2D-array.
```
### Access
```Ruby
arr[0]	  # First element.
arr[-1]   # Last element.
arr[1..3] # Range of elements (inclusive).

array.max/min # Get maximum/minimum value of the array.
```
### Add element 
```Ruby
arr.push(val)     # End.
arr.append(val)   
arr << val

arr.unshift(val)  # Beginning.    
```
### Remove and return
```Ruby
arr.pop() # Last element.
arr.shift # First element.
```
### Other functions.
```Ruby
arr.include?(val) # Check if array includes element.
arr.length        # Length of the array.
arr.reverse       # Reverse array.
```

<hr>

## Sorting 
### Ascending order.
```Ruby
array.sort! # array.sort!(&:first) # for faster computation
array=array.sort
```
### Descending order.
```Ruby
array.sort! { |a, b| b <=> a }  
array=array.sort.reverse
```
### Conparation 
```Ruby
b <=> a # 0: a == b; 1: b > a; -1: b < a
```
### Priority_queue
```Ruby
class Node
   attr_accessor :name, :height

   def initialize(name, height)
       @name = name
       @height = height
   end

   def <=>(other)
       other.height <=> @height
   end
end

def sort_people(names, heights)
   n=names.length
   nodes=[]
   for i in 0..n-1
       nodes << Node.new(names[i],heights[i])
   end
    
   sorted_nodes = nodes.sort
end
```
<hr>

## Queue 
### Init.
```Ruby
queue = []    
q=Queue.new
```
### Functions.
```Ruby
queue.push(1) # Add element to the end.
queue.shift   # Remove element from the front.
queue.first   # Peek at the front element.
```

<hr>

## Stack 
### Functions.
```Ruby
require 'collections'
stack = Collections::Stack.new
```
### Functions.
```Ruby
stack.push(val)
puts stack.peek   # Access to the last value pushed.
puts stack.pop    # Access and removes the last value pushed.
puts stack.empty? # Checks if the stack is empty.
puts stack.size   # Size of the stack.
```

<hr>

## Deque 
### Init:
```Ruby
require 'deque'
deque = Deque.new
```
### Add:
```Ruby
deque.push_back(1)  # To the end.
deque.push_front(2) # To the front.
```
### Remove:
```Ruby
deque.pop_back      # From the end.
deque.pop_front     # From the front.
```
### Peek:
```Ruby
deque.first         # At the front.
deque.last          # At the end.
```

<hr>

## Maps
### Init:
```Ruby
hash = { key_1 => val_1, key_2 => val_2 }   # Create a hash.
hash = Hash.new(0)              	    # Create an empty hash.
hash = {}
```
### Access/Set value:
```Ruby
hash[key] = val  # Add/Update.
hash.delete(key) # Remove.
hash.keys        # Get all keys.
hash.values      # Get all values.
hash[key] 	 # Get value by key.
hash.fetch(key)  # Get value by key (raises error if key doesn't exist).
```
### Iterate over the map:
```Ruby
hash.each do |key, value|  
  <code>
end
```
# Check functions:
```Ruby
hash.key?(key)
hash.has_key?(key) 
 
mapN.empty? # Check if map is empty.
```

<hr>

## Sets  
### Init:
```Ruby
require 'set'
set = Set.new([val_1, val_2, val_3]) # Create a set.
set = Set.new([]) 		     # Create an empty set.
```
### Add/Remove:
```Ruby
set.add(val)   
set.delete(val)
```
### Iterate over the set elements:
```Ruby
set.each do |val|
	<code>
end
```
### Funcionts:
```Ruby
set.include?(val)   # Check if element is present.
set.size            # Get the number of elements
set.merge([5, 6])   # Add multiple elements
set.subtract([1])   # Remove multiple elements
```

<hr>

## Class
```Ruby
class Class
   attr_accessor: var_1 # Automatic Getter and Setter
   attr_reader : var_2  # Automatic Getter 
   attr_writer : var_3  # Automatic Setter
   
   def initialize(name, age)
	 @name = name 	# Class variable. One instance.
	 @age = age 	# Class variable.
	 @@done = false # Shared class variable. All the instances.
   end

   def greet
     "Hello, my name is #{@name} and I am #{@age} years old."
   end
	
end

class_var = Class.new(<name>, <age>)
```



## Comment
```Ruby
# <one_line_comment>

=begin
    <comment>
=end
```
