/* Tests the Parity class by reading integers until 0, inserting them,
   then printing min/max values. */
#include <iostream>
#include "parity.h"
using namespace std;

void littleDriverProgram();

int main() {
littleDriverProgram();
return 0;
}

/* Reads integers from the user until 0 is entered. All nonzero
   integers are inserted into a Parity object, which keeps evens
   and odds in separate sorted linked lists. */
void littleDriverProgram() {
Parity lists;
cout << "Enter a list of ints, one per line, 0 to end:
";

int val;
while (true) {
cin >> val;

// 0 ends the input loop
if (val == 0) break;

lists.insert(val);
}

// Display all stored values
cout << lists;

// Display min/max
cout << "The max value you entered is " << lists.max() << endl;
cout << "The min value you entered is " << lists.min() << endl;
}

