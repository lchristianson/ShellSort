//Lucas Christianson
// This is the source code for a linked list class.  It contians the head of the linked list and various
//auxillary methods such as print and add.
#include <iostream>
#include <string>
#include <cstdlib>
#include "LL.h"
#include "LLN.h"
#include "PG2.h"
using namespace std;

//Constructs a new linked list.
LL::LL() {
	head = nullptr;
}

//Destructor for linked list.
LL::~LL() {
	delete head;
}

//Prints the linked list starting with the head and working its way down
//to the end of the list.
void LL::print() {
	cout << "*****" << endl;
	if (head) head->print();
	cout << "*****" << endl;
}

//Adds a new node to the list at the head position.
void LL::add(string d) {
	head = new LLN(d, head);
}

//returns an integer which represents the count of the nodes in the list.
int LL::ct() {
	if (!head) return 0;
	return head->ct();
}


/*
* The shellsort method takes the linked list and produces an array of LLN*'s with size < that of the linked list.  
* This array, arr, is then fed into the split method (see split method description).  Next, this method loops
* through the filled array, arr, and mildsorts (see mildsort description) each "mini" list within arr.  From here,
* the rejoin method (see description) is fed the newly sorted arr of LLN*'s which returns a new head that is assigned
* to the head of the linked list.
*/
void LL::shellsort() {
	int c = ct();
	if (c <= 1) return;
	for (int diff = c - 1; diff >= 1; diff--) {
		int tdiff = diff;
		while (tdiff % 2 == 0) tdiff /= 2;
		while (tdiff % 3 == 0) tdiff /= 3;
		if (tdiff > 1) continue;
		LLN** arr = new LLN * [diff];
		for (int i = 0; i < diff; i++)
			arr[i] = nullptr;
		head->split(arr, diff, 0);
		for (int i = 0; i < diff; i++)
			arr[i] = arr[i]->mildsort();
		head = rejoin(arr, diff, (c - 1 + diff) % diff, nullptr);
	}
	
}