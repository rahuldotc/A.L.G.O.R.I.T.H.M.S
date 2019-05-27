#include <iostream>
using namespace std;

void Display(int arr[], int size) {
	cout << endl;
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}	

void MAX_Heapify(int arr[], int index, int size) {
	int left = 2*(index+1)-1, right = 2*(index+1), nextIndex;

	if(left < size && arr[left] > arr[index]) {
		nextIndex = left;
	} else {
		nextIndex = index;
	}

	if(right < size && arr[right] > arr[nextIndex]) {
		nextIndex = right;
	}

	if(nextIndex != index) {
		//SWAPPING
		int temp = arr[nextIndex];
		arr[nextIndex] = arr[index];
		arr[index] = temp;

		MAX_Heapify(arr, nextIndex, size);
	}
}

void Build_MAX_Heap(int arr[], int size) {

	for(int i = size/2-1; i >= 0; i--) {
		MAX_Heapify(arr, i, size);
	}
}

void HeapSort(int arr[], int size) {

	Build_MAX_Heap(arr, size);

	for(int i = size-1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		MAX_Heapify(arr, 0, i);
	}
}

int main() {

	int arr[] = {1, 4, 10, 14, 3, 9, 7, 2, 8 , 8, 0, -3, 200, 44, 200};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << "RANDOM ARRAY";
	Display(arr, size);

	HeapSort(arr, size);

	cout << "\nSORTED ARRAY";
	Display(arr, size);
	
	return 0;
}