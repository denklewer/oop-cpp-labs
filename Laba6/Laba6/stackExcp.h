#pragma once
#include "stdafx.h"
class StackUnderflow { /* ... */ };


class StackOverflow {/*....*/};
class StackOutOfRange{
private:
	int value;
public:

	StackOutOfRange(int i) : value(i) { };
	int getValue(int i){
		return value;
	};
	~StackOutOfRange(){};
	void Out() {
		cout << "StackOverflow exception" << endl;
	}

};









