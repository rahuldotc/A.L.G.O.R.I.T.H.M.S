#include <iostream>
using namespace std;

/*Divide and Conquer technique will check only log(n) (base-2) elements of the array, instead of all of them
(as in the case of the Trivial Algorithm), Hence the worst case running time is log(n)*/

int findPeak(int arr[], int start, int end) {
	int middle = start + (end-start)/2;

	if((arr[middle-1] && arr[middle] >= arr[middle-1]) && (arr[middle+1] && arr[middle] >= arr[middle+1])) {
		return middle;
	} else if(arr[middle-1] && arr[middle] <= arr[middle-1]) {
		findPeak(arr, start, middle-1);
	} else {
		findPeak(arr, middle+1, end);
	}
}

int main() {
	int arr[] = {5, 10, 15, 25, 30, 45, 65, 50, 35, 1};
	int size = sizeof(arr)/sizeof(int);

	int peak = findPeak(arr, 0, size-1);

	if(peak != -1) {
		cout << "A peak exists at position " << peak << " -> " << arr[peak] << endl;
	} else {
		cout << "Peak does not exist" << endl;
	}

	return 0;
}