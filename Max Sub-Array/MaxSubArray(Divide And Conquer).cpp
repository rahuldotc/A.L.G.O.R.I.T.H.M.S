#include<iostream>

using namespace std;

int MaxCrossSubArray(int arr[], int start, int middle, int end) {
    int left_sum = arr[middle], sum = 0;
    for(int i = middle; i >= start; i--) {
        sum += arr[i];
        if(sum > left_sum) {
            left_sum = sum;
        }
    }
    int right_sum = arr[middle + 1]; sum = 0;
    for(int i = middle + 1; i <= end; i++) {
        sum += arr[i];
        if(sum > right_sum) {
            right_sum = sum;
        }
    }
    return (left_sum + right_sum);
}

int MaxSubArray(int arr[], int start, int end) {
    if(start == end) {
        return arr[start];
    } else {
        int middle = (start + end)/2, left_sum, right_sum, cross_sum;
        left_sum = MaxSubArray(arr, start, middle);
        right_sum = MaxSubArray(arr, middle + 1, end);
        cross_sum = MaxCrossSubArray(arr, start, middle, end);

        if(left_sum >= right_sum && left_sum >=cross_sum) {
            return left_sum;
        } else if(right_sum >=left_sum && right_sum >= cross_sum) {
            return right_sum;
        } else {
            return cross_sum;
        }
    }
}

int main(){
    int arr[] = {112, -3, -25, 20, -3, -16, -23, 18, 22, -9, 12, -5, -22, 15, -4, 7};
    int size = sizeof(arr)/sizeof(int);

    int MaxSum = MaxSubArray(arr, 0, size - 1);
    cout << MaxSum << endl;

    return 0;
}
