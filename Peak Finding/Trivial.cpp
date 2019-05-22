#include <iostream>
using namespace std;

/*This algorithm will work by checking each element of an array for a peak, and will take O(n) time in the worst case
This will be the case when there is only 1 peak at the end of the array (Asceneding order)*/

int findPeak(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		if( (arr[i-1] && arr[i] > arr[i-1]) && (arr[i+1] && arr[i] > arr[i+1]) ) {
			return i;
		}
	}
	return -1;
}

int main() {
	int arr[] = {5, 10, 15, 25, 30, 45, 65, 50, 35, 1};
	int size = sizeof(arr)/sizeof(int);

	int peak = findPeak(arr, size);

	if(peak != -1) {
		cout << "A peak exists at position " << peak << " -> " << arr[peak] << endl;
	} else {
		cout << "Peak does not exist" << endl;
	}

	return 0;
}