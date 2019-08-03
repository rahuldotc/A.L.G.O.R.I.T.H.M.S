#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "../../Data Structures/LinkedList.h"

class Stack_List {
	LinkedList stack_list;
public:
	void push(int);
	int pop();
	int peek();
	void display();
	int len();
};

void Stack_List::push(int data) {
	stack_list.insert(data, stack_list.len());
}

int Stack_List::pop() {
	return stack_list.remove(stack_list.len()-1);
}

int Stack_List::peek() {
	return stack_list.getElement(stack_list.len()-1);
}

void Stack_List::display() {
	stack_list.display();
}

int Stack_List::len() {
	return stack_list.len();
}

#endif