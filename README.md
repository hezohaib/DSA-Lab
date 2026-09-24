# Data Structures — C++

Lab work from my Data Structures course at COMSATS University Islamabad, Attock Campus. All implementations are written in C++ from scratch without using any STL containers.

## Topics Covered

### Array Lists (Week 1)
Custom array-backed list implemented as a struct with manual bounds checking.

| Operation              | Description                              |
|------------------------|------------------------------------------|
| insertEnd              | Append to the back                       |
| insertAtBeginning      | Prepend, shifting all elements right     |
| deleteAtPosition       | Remove element from a specific position  |
| displayList            | Print all elements                       |
| Pointer Traversal      | Find min, max, sum using raw pointers    |
| Median & Averages      | Calculate median, general average and special average |
| Closest Value          | Find closest value to special average and update the list |

## Assignment 01 extends this with raw pointer traversal to compute:

Min, max, sum, median
* General average vs. special average (min + median + max / 3)
* Closest value to the special average
* Final score combining all three distances
* Deletion of the closest element and re-insertion of the rounded special average

### Singly Linked Lists (Week 2)

| File | What it does |
| :--- | :--- |
| `task1.cpp` | Build a linked list; display forward, reverse (recursive), and reverse (iterative) |
| `task2.cpp` | Build two separate linked lists; merge them into a third |
| `task3.cpp` | Search a linked list for all positions where a value occurs; count occurrences |

## How to Compile & Run

Requires a C++ compiler (g++ recommended).

```bash
# Example
g++ -o out "Lab-01/filename.cpp" && ./out
```
## Course Information

* Subject: Data Structures
* University: COMSATS University Islamabad, Attock Campus
* Language: C++ (no STL containers — manual implementations only)
* Semester: Fall 25
