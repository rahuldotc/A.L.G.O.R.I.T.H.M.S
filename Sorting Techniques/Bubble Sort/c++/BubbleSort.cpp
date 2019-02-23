#include<iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void BubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] > arr[j]){
                swap(arr, i, j);
            }
        }
    }
}

int main(){
    int arr[] = { 10, 8, 4, 3, 8, 0, -34, -5, 7 };

    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    BubbleSort(arr, 9);
    cout<<endl;
    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
