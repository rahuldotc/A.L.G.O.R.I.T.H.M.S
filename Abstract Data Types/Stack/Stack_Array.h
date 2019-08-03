#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "../../Data Structures/Array.h"

class Stack_Array {
	Array stack_arr;
public:
	void push(int);
	int pop();
	int peek();
	void display();
	int len();
};

void Stack_Array::push(int data) {
	stack_arr.insert(data, stack_arr.len());
}

int Stack_Array::pop() {
	return stack_arr.remove(stack_arr.len()-1);
}

int Stack_Array::peek() {
	return stack_arr.getElement(stack_arr.len()-1);
}

void Stack_Array::display() {
	stack_arr.display();
}

int Stack_Array::len() {
	return stack_arr.len();
}

#endif