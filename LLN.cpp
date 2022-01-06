//Lucas Christianson
//This is the class source file for a linked list node (LLN).  Linked list calls methods on its head which is a LLN
//in order to complete its shellsorting algorithm.
#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
using namespace std;

//constructs a new linked list node.
LLN::LLN(string d, LLN* n) {
	data = d;
	next = n;
}

//destructor for a linked list node.
LLN::~LLN() {
	delete next;
}

//prints the data of the node and calls print on the node pointed to by "next".
void LLN::print() {
	cout << data << endl;
	if (next) next->print();
}

//recursively returns the count of the "this" node and the nodes after it.
int LLN::ct() {
	if (!next) return 1;
	return 1 + next->ct();
}

/*The split method takes the head of a linked list and recursively fills an array of LLN*'s where len = length of the array.
The array, arr, is filled one position at a time at arr[wh].
*/
void LLN::split(LLN** arr, int len, int wh) {
	if (wh == len)
		wh = 0;
	LLN* np;
	if (next)
		np = next;
	else
		np = nullptr;
	if (arr[wh])
		next = arr[wh];
	else
		next = nullptr;
	arr[wh] = this;
	if(np)
		np->split(arr, len, ++wh);
}

/*
Mildsort takes the head of a linked list and recursively puts it in reverse alphabetical order
and returns the new head of the list.
*/
LLN* LLN::mildsort() {
		if (!next)
			return this;
		LLN* h = next->mildsort();
		next = h;
		if (h->getdata() > data) {
			next = h->getnext();
			h->setnext(this);
			return h;
		}
		else {
			return this;
		}
}

//returns the data in the "this" node.
string LLN::getdata() {
	return data;
}

//returns the node pointed to by "next".
LLN* LLN::getnext() {
	return next;
}

//sets the next pointer to n.
void LLN::setnext(LLN* n) {
	next = n;
}