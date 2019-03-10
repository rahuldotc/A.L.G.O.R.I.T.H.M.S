#include<iostream>

using namespace std;

void MaxSubArray(int arr[], int size){
    int start, end, max = arr[0];

    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = i; j < size; j++){
            sum += arr[j];
            if(sum > max){
                start = i;
                end = j;
                max = sum;
            }
        }
    }
    cout<<max<<endl;
    for(int i = start; i <= end; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 22, -9, 12, -5, -22, 15, -4, 7};
    int size = sizeof(arr)/sizeof(int);

    MaxSubArray(arr, size);

    return 0;
}
