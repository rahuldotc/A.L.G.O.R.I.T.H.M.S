#include<iostream>

using namespace std;

void reArrange(int arr[], int i, int j){
    int temp = arr[i];
    while(i>j){
        arr[i]=arr[i-1];
        i--;
    }
    arr[j] = temp;
}

void InsertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        for(int j=0; j<i; j++){
            if(arr[i] <= arr[j]){
                reArrange(arr, i, j);
                break;
            }
        }
    }
}

int main(){
    int arr[] = { 10, 8, 4, 3, 8, 0, -34, -5, 7 };

    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    InsertionSort(arr, 9);
    cout<<endl;
    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
