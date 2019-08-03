#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <climits>
using namespace std;

class LinkedList;

class Node {
	friend class LinkedList;
private:
	Node *next;
	int data;
public:
	Node(int data) { this->data = data; next = NULL; }
};

class LinkedList {
	Node *head;
	int length;
public:
	LinkedList() { head = NULL; length = 0; }
	void insert(int, int);
	int remove(int);
	void removeKey(int);
	int getElement(int);
	void display();
	int len();
};

void LinkedList::insert(int data, int position) {
	
	//CREATE NODE
	Node *new_node = new Node(data);

	//INSERT NODE
	if(!head) {
		head = new_node;
	} else {
		if(position == 0) {
			new_node->next = head;
			head = new_node;
		} else if(position > 0 && position <= length) {
			Node *current = head;
			for(int i = 1; i < position; i++) {
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		} else {
			cout << "Out Of Bounds Exception" << endl;
			return;
		}
	}
	length++;
}

int LinkedList::remove(int position) {
	int temp = INT_MAX;
	if(!head) {
		cout << "List is empty!" << endl;
		return temp;
	} else {
		if(position == 0) {
			Node *temp_node = head;
			temp = temp_node->data;
			head = head->next;
			delete (temp_node);
		} else if(position >= 1 && position <= length) {
			Node *current = head, *previous = current;
			for(int i = 1; i <= position; i++) {
				previous = current;
				current = current->next;
			}
			temp = current->data;
			previous->next = current->next;
			delete (current);
			// delete (previous);
		} else {
			cout << "Out Of Bounds Exception" << endl;
			return temp;
		}	
	}
	length--;
	return temp;
}


void LinkedList::removeKey(int key) {
	if(!head) {
		cout << "List is empty!" << endl;
	} else if(head->data == key) {
		Node *temp = head;
		head = head->next;
		delete (temp);
		length--;
	} else {
		Node *current = head, *previous = current;
		while(current->data != key && current->next != NULL) {
			previous = current;
			current = current->next;
		}
		if(current->data == key) {
			previous->next = current->next;
			delete (current);
			length--;
		} else {
			cout << "Key absent!" << endl;
		}
	}
}

int LinkedList::getElement(int position) {
	Node *current = head;
	for(int i = 0; i < position; i++) {
		current = current->next;
	}
	return current->data;
}

void LinkedList::display() {
	Node *current = head;
	while(current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int LinkedList::len() {
	return length;
}

#endif