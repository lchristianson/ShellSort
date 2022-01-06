//Lucas Christianson
//This is the header file for the linked list node (LLN) class.  This defines all the methods and variables
//of the LLN class.
#ifndef _LLN_
#define _LLN_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class LLN {
private:
	string data;
	LLN* next;
public:
	LLN(string d, LLN* n);
	~LLN();
	void print();
	int ct();
	void split(LLN** arr, int len, int wh);
	LLN* mildsort();
	string getdata();
	LLN* getnext();
	void setnext(LLN* n);
};
#endif