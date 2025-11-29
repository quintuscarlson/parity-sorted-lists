// Parity interface file 
#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>
#include "node.h"
using std::ostream;

/* class Parity
   Manages two sorted linked lists: one for even integers and
   one for odd integers. Supports insertion, min/max retrieval,
   deep copying, and formatted printing. */
class Parity {
public:
// Constructors / Destructor / Assignment
Parity(); // default constructor
Parity(const Parity& other); // copy constructor
~Parity(); // destructor
Parity& operator=(const Parity& rhs); // assignment operator

// Mutator
void insert(int val); // insert val into correct list (even or odd)

// Accessors
int min() const; // return smallest value in both lists
int max() const; // return largest value in both lists

// Stream output
friend ostream& operator<<(ostream& out, const Parity& lists);

private:
// Even list
node* headE;
node* tailE;
size_t nE;

// Odd list
node* headO;
node* tailO;
size_t nO;

// INVARIANTS:
// headE and tailE mark the first and last nodes of the sorted list
// containing the nE even integers.
// headO and tailO mark the first and last nodes of the sorted list
// containing the nO odd integers.
// Both lists always remain sorted in non-decreasing order.
};

#endif 

