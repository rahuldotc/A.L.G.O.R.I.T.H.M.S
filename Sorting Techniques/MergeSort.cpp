#include<iostream>

using namespace std;

template<class X> void Merge(X arr[], int start, int middle, int end){

    int size1 = middle - start + 1, size2 = end - middle;
    X arr1[size1], arr2[size2];

    for(int i = 0; i < size1; i++){
        arr1[i] = arr[start + i];
    }
    for(int i = 0; i < size2; i++){
        arr2[i] = arr[middle + 1 + i];
    }
    int i = start, p = 0, q = 0;
    while(p < size1 && q < size2){
        if(arr1[p] <= arr2[q]){
            arr[i] = arr1[p];
            p++;
        } else{
            arr[i] = arr2[q];
            q++;
        }
        i++;
    }
    while(p < size1){
        arr[i] = arr1[p];
        p++; i++;
    }
    while(q < size2){
        arr[i] = arr2[q];
        q++; i++;
    }
}


template<class X> void MergeSort(X arr[], int start, int end){

    if(start < end){
        int middle = start + (end - start) / 2;

        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);
        Merge(arr, start, middle, end);
    }
}

template<class X> void Display(X arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    double arr[] = {7.5, 9.4, 4.1, 23, 0.3, -54, 3, -78, 4.0999};
    int size = sizeof(arr)/sizeof(double);
    cout<<size;
    cout<<"\nBefore"<<endl;
    Display(arr, size);

    MergeSort(arr, 0, size - 1);

    cout<<"\nAfter"<<endl;
    Display(arr, size);

    return 0;
}
