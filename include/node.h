// Node interface file 
#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::ostream;


/* A simple singly linked list node storing an integer and a
   pointer to the next node. */
class node {
public:
// Constructors
// Creates a new node with given data and link values
node(int data, node* link) : data_(data), link_(link) {}

// Default constructor initializes to 0 and nullptr
node() : node(0, nullptr) {}

//Constant Accessors
int data() const { return data_; }
node* link() const { return link_; }

//Mutators
void set_data(int newdata) { data_ = newdata; }
void set_link(node* newlink) { link_ = newlink; }

private:
int data_; // stored integer value
node* link_; // pointer to next node in the list
};

// Prints all nodes starting from 'head', space‑separated.
ostream& operator<<(ostream& out, const node* head);

// Non-member linked-list utility functions
void list_insert_head(node*& head, node*& tail, int val); // insert new head
void list_insert_tail(node*& head, node*& tail, int val); // insert new tail
std::size_t list_size(const node* head); // count nodes
bool list_search(const node* head, int val); // search for value

//insert into sorted list
void list_insert_sorted(node*& head, node*& tail, int val);

#endif