#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "../../Data Structures/LinkedList.h"

class Queue_List {
	LinkedList queue_list;
public:
	void enqueue(int);
	int dequeue();
	void display();
	int len();
	bool isEmpty();
};

void Queue_List::enqueue(int data) {
	queue_list.insert(data, queue_list.len());
}

int Queue_List::dequeue() {
	return queue_list.remove(0);
}

void Queue_List::display() {
	queue_list.display();
}

int Queue_List::len() {
	return queue_list.len();
}

bool Queue_List::isEmpty() {
	return queue_list.len() ? false : true;
}

#endif
