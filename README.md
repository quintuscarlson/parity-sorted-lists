# Parity Lists (C++)

## Overview
This project stores integers in **two sorted singly-linked lists** based on parity:
- **Even** numbers are stored in one sorted list
- **Odd** numbers are stored in another sorted list

It showcases linked-list construction, dynamic memory management, and class design in C++.

---

## Files
main.cpp // Driver program
parity.h // Parity class declaration
parity.cpp // Parity implementation (deep copy, insert, min/max, etc.)
node.h // Node class and list utility function declarations
node.cpp // Node utility function implementations

---

## Skills Demonstrated
- **Linked list implementation** (manual node management)
- **Dynamic memory management** (`new`, `delete`, destructor)
- **Deep copying** (copy constructor + assignment operator)
- **Operator overloading** (`operator<<`)
- **Encapsulation & class design**
- **Sorted list insertion logic**
- **Pointer handling & invariants**
- **Clean header/implementation separation**
- **Use of size tracking and O(1) tail insertion**

---

## Build Instructions
Compile with a standard C++ compiler:

g++ -std=c++17 main.cpp parity.cpp node.cpp -o parity
Then run:
./parity

---

## Usage
The program prompts for integers:
Enter a list of ints, one per line, 0 to end:
The program prints:
- Sorted even values
- Sorted odd values
- Minimum value
- Maximum value

---

## Example
Input:
4
7
2
9
5
0

Output:
Evens: 2, 4
Odds: 5, 7, 9
The max value you entered is 9
The min value you entered is 2

---

## Notes
- 0 is the sentinel value and is not stored.
- Both lists maintain non-decreasing order.
- min() and max() return valid values from either list; if both are empty, they return 0.
