//node implementation file
#include "node.h"
// Recursively prints each data value.
ostream& operator<<(ostream& out, const node* head) {
if (head == nullptr) return out;
out << head->data() << " ";
return out << head->link();
}

// Inserts a new node at the beginning of the list.
// Updates Head and tail (if list was empty before).
void list_insert_head(node*& head, node*& tail, int val) {
head = new node(val, head);
if (tail == nullptr) tail = head;
}

// Inserts a node at the end of the list. 
// Handles empty list case.
void list_insert_tail(node*& head, node*& tail, int val) {
node* temp = new node(val, nullptr);

if (tail == nullptr) {
head = tail = temp;
} else {
tail->set_link(temp);
tail = temp;
}
}

// Recursively counts the number of nodes in the list.
size_t list_size(const node* head) {
if (head == nullptr) return 0;
return 1 + list_size(head->link());
}

// Recursively searches list for a given value.
// Returns true if found, false otherwise.
bool list_search(const node* head, int val) {
if (head == nullptr) return false;
if (head->data() == val) return true;
return list_search(head->link(), val);
}

// Inserts a new value into the list in ascending order.
// Maintains head and tail pointers.
void list_insert_sorted(node*& head, node*& tail, int val) {

// Empty list case
if (head == nullptr) {
head = new node(val, nullptr);
tail = head;
return;
}

// Insert at head
if (head->data() >= val) {
node* temp = new node(val, head);
head = temp;
return;
}

// General case: find insertion point
node* cur = head;
while (cur->link() != nullptr && cur->link()->data() < val) {
cur = cur->link();
}

// Insert new node
node* newNode = new node(val, cur->link());
cur->set_link(newNode);

// Update tail if inserted at end
if (newNode->link() == nullptr) {
tail = newNode;
}
}
