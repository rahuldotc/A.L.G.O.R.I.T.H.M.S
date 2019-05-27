#include<iostream>

using namespace std;

template<class X> void swap(X arr[], int i, int j){
    X temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template<class X> void BubbleSort(X arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] > arr[j]){
                swap(arr, i, j);
            }
        }
    }
}

int main(){
    double arr[] = { 10.2, 8.6, 4, 3.5, 8, 0, -34, -5, 7 };

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
