// Parity implementation file
#include "parity.h"  
// Default constructor: initializes an empty Parity object
Parity::Parity() {
    headE = tailE = nullptr;
    headO = tailO = nullptr;
    nE = nO = 0;
}

// Copy constructor: deep-copies all even and odd lists
Parity::Parity(const Parity& other) {
    headE = tailE = nullptr;
    headO = tailO = nullptr;

    // Copy evens
    node* curr = other.headE;
    while (curr != nullptr) {
        list_insert_tail(headE, tailE, curr->data());
        curr = curr->link();
    }

    // Copy odds
    curr = other.headO;
    while (curr != nullptr) {
        list_insert_tail(headO, tailO, curr->data());
        curr = curr->link();
    }

    nE = other.nE;
    nO = other.nO;
}

// insert: inserts val into appropriate (even or odd) sorted list
void Parity::insert(int val) {
    if (val % 2 == 0) {
        list_insert_sorted(headE, tailE, val);
        nE++;
    } else {
        list_insert_sorted(headO, tailO, val);
        nO++;
    }
}

// operator<< : prints even list followed by odd list
ostream& operator<<(ostream& out, const Parity& lists) {
    out << "Evens: ";
    node* temp = lists.headE;
    while (temp != nullptr) {
        out << temp->data() << ", ";
        temp = temp->link();
    }

    out << "Odds: ";
    node* temp2 = lists.headO;
    while (temp2 != nullptr) {
        out << temp2->data() << ", ";
        temp2 = temp2->link();
    }

    return out;
}

// min: returns the smallest value among both lists
// Assumes both lists are sorted and non-empty
int Parity::min() const {
    if (headE == nullptr) return headO->data();
    if (headO == nullptr) return headE->data();
    return (headE->data() <= headO->data()) ? headE->data() : headO->data();
}

// max: returns the largest value among both lists
int Parity::max() const {
    if (tailE == nullptr) return tailO->data();
    if (tailO == nullptr) return tailE->data();
    return (tailE->data() >= tailO->data()) ? tailE->data() : tailO->data();
}

// Destructor: frees all dynamic memory
Parity::~Parity() {
    // Delete evens
    while (headE != nullptr) {
        node* temp = headE;
        headE = headE->link();
        delete temp;
    }

    // Delete odds
    while (headO != nullptr) {
        node* temp = headO;
        headO = headO->link();
        delete temp;
    }

    headE = tailE = nullptr;
    headO = tailO = nullptr;
    nE = nO = 0;
}

// Assignment operator: deep copy with cleanup
Parity& Parity::operator=(const Parity& rhs) {
    if (this == &rhs) return *this;  // Guard self-assignment

    // Cleanup current even list
    while (headE != nullptr) {
        node* temp = headE;
        headE = headE->link();
        delete temp;
    }

    // Cleanup current odd list
    while (headO != nullptr) {
        node* temp = headO;
        headO = headO->link();
        delete temp;
    }

    headE = tailE = nullptr;
    headO = tailO = nullptr;

    // Copy evens
    if (rhs.headE != nullptr) {
        headE = new node(rhs.headE->data(), nullptr);
        tailE = headE;

        node* cur = rhs.headE->link();
        while (cur != nullptr) {
            node* temp = new node(cur->data(), nullptr);
            tailE->set_link(temp);
            tailE = temp;
            cur = cur->link();
        }
    }

    // Copy odds
    if (rhs.headO != nullptr) {
        headO = new node(rhs.headO->data(), nullptr);
        tailO = headO;

        node* cur2 = rhs.headO->link();
        while (cur2 != nullptr) {
            node* temp2 = new node(cur2->data(), nullptr);
            tailO->set_link(temp2);
            tailO = temp2;
            cur2 = cur2->link();
        }
    }

    nE = rhs.nE;
    nO = rhs.nO;

    return *this;
}







