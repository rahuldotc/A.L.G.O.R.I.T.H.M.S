#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <climits>
using namespace std;

class Array {
	int *arr;
	int length;
public:
	Array() {
		arr = new int[2];
		length = 0;
	}
	void insert(int, int);
	int remove(int);
	void removeKey(int);
	void resize();
	void display();
	int getElement(int position);
	int len();
};

void Array::insert(int data, int position) {
	if(position < 0 || position > length) {
		cout << "Out of bounds exception!" << endl;
		return;
	}
	
	//SHIFT CONTENTS
	for(int i = length; i > position; i--) {
		arr[i] = arr[i-1];
	}
	arr[position] = data;
	length++;

	if(length % 2 == 0) {
		resize();
	}
}

int Array::remove(int position) {
	if(position < 0 || position >= length) {
		cout << "Out of bounds exception!" << endl;
		return INT_MAX;
	}
	int temp = arr[position];

	//SHIFT CONTENTS
	for(int i = position; i < length; i++) {
		arr[i] = arr[i+1];
	}
	length--;

	if(length % 2 == 0) {
		resize();
	}

	return temp;	
}

void Array::removeKey(int key) {
	for(int i = 0; i < length; i++) {
		if(arr[i] == key) {
			remove(i);
			return; 
		}
	}
	cout << "Key Not Found!" << endl;
}

void Array::resize() {
	if(length == 0) { arr = new int[2]; return; }

	//ALLOCATE NEW ARRAY
	int *new_arr = new int[2*length];

	//COPY CONTENTS
	for(int i = 0; i < length; i++) {
		new_arr[i] = arr[i];
	}
	arr = new_arr;
}

void Array::display() {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int Array::getElement(int position) {
	if(position < 0 || position >= length) {
		cout << "Out of bounds exception!" << endl;
		return INT_MAX;
	}
	return (arr[position]);
}

int Array::len() {
	return length;
}

#endif