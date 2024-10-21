# Data-Structures-and-Algorithms-Library
This repository contains implementations of various data structures and algorithms in C++. The goal is to provide a clear understanding of these fundamental concepts, which are essential for computer science and software engineering.

## Data Structures

### 1. Linked List
A linked list is a linear data structure where each element, called a node, contains a value and a pointer to the next node. It allows efficient insertion and deletion of elements.

- **Key Operations**: Insertion, Deletion, Traversal
- **Time Complexity**:
  - Insertion: O(1) at the beginning, O(n) at the end
  - Deletion: O(n)

### 2. Stack
A stack is a linear data structure that follows the Last In First Out (LIFO) principle. Elements can only be added or removed from one end, known as the top of the stack.

- **Key Operations**: Push, Pop, Peek
- **Time Complexity**:
  - Push: O(1)
  - Pop: O(1)
  - Peek: O(1)

### 3. Queue
A queue is a linear data structure that follows the First In First Out (FIFO) principle. Elements are added at the rear and removed from the front.

- **Key Operations**: Enqueue, Dequeue, Front
- **Time Complexity**:
  - Enqueue: O(1)
  - Dequeue: O(1)

### 4. Graph
A graph is a collection of nodes (vertices) and edges connecting them. It can be represented in various ways, such as adjacency lists or matrices. Graphs are useful for representing networks.

- **Key Operations**: Add Vertex, Add Edge, BFS, DFS
- **Time Complexity**:
  - BFS/DFS: O(V + E), where V is the number of vertices and E is the number of edges

## Algorithms

### 1. Quick Sort
Quick Sort is a divide-and-conquer algorithm that sorts an array by selecting a 'pivot' element and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot.

- **Time Complexity**:
  - Average: O(n log n)
  - Worst: O(n²)

### 2. Merge Sort
Merge Sort is a divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves back together.

- **Time Complexity**: O(n log n)

### 3. Binary Search
Binary Search is an efficient algorithm for finding an item from a sorted list of items. It compares the target value to the middle element of the array.

- **Time Complexity**: O(log n)

### 4. Knapsack Problem
The Knapsack Problem is a classic optimization problem where the goal is to determine the maximum value that can be obtained from a set of items, each with a weight and a value, without exceeding a given weight capacity.

- **Time Complexity**: O(nW), where n is the number of items and W is the maximum weight capacity

## Conclusion
This repository serves as a practical guide for understanding and implementing fundamental data structures and algorithms. Each implementation demonstrates essential programming concepts and provides a foundation for further study in computer science.
