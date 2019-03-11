#include<iostream>

using namespace std;

void Display(int arr[], int start, int end){
    for(int k = start; k <= end; k++){
        cout<<arr[k]<<" ";
    }
}

int Max(int a, int b){
    if(b > a){
        return b;
    } else{
        return a;
    }
}

void MaxSubArray(int arr[], int size){

    int max = arr[0], temp = arr[0], start = 0, end = 0;

    for(int i = 1; i < size; i++){
        if(Max(arr[i], temp + arr[i]) == arr[i]){
            start = i;
        }
        temp = Max(arr[i], temp + arr[i]);
        if(Max(max, temp) == temp){
            end = i;
        }
        max = Max(max, temp);
    }
    cout<<max<<endl;
    Display(arr, start, end);
}

int main(){
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 22, -9, 12, -5, -22, 15, -4, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    MaxSubArray(arr, size);

    return 0;
}
