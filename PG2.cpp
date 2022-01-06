//Lucas Christianson - 02/21/21 - Data Structures
//This program performs a shellsort operation on a linked list entered by the user and prints
//the list.  The program then calls shellsort() on the entered list.  The list is split into an array
//of LLN* which has a size less than the length of the original list.  Inside this filled array, each position therin
//is sorted via the mildsort() method.  After being sorted in reverse alphabetical order, the rejoin() method is called
//which empties the array back into a new list which is then returned.  This process is repeated with each iteration
//decrementing the size of the array until the list as a whole is sorted with mildsort().  After this step, the returned
//list is fully sorted alphabetically.

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG2.h"
#include "LL.h"
using namespace std;

int main(int argc, char** argv) {

	LL* list = new LL();
	while (true) {
		string d;
		getline(cin, d);
		if (d == "") break;
		list->add(d);
	}
	list->print();
	list->shellsort();
	list->print();

	delete list;
	return 0;
}

/*
* The rejoin method takes a filled linked list node pointer array (arr) with length, len, and fills the linked list, l, 
* starting at the head of arr[wh].  From here, the method is called recursively with wh being decremented each iteration
* until arr is empty.  The updated linked list head, l, is then returned.
*/
LLN* rejoin(LLN** arr, int len, int wh, LLN* l) {
	if (wh < 0)
		wh = (len - 1);
	if (arr[wh] == nullptr)
		return l;
	LLN* np;
	if (arr[wh]->getnext() != nullptr) {
		np = arr[wh]->getnext();
		arr[wh]->setnext(l);
		l = arr[wh];
		arr[wh] = np;
	}
	else {
		arr[wh]->setnext(l);
		l = arr[wh];
		arr[wh] = nullptr;
	}
	l = rejoin(arr, len, --wh, l);
	return l;
	}
