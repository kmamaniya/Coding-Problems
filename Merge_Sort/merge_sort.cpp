#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void mergeSort(int *ptr, size_t size);

int main(){
    // int arr[] = {12, 15, 23, 4 , 6, 10, 35, 28}; //Even number of element
    // int arr[]={}; //Empty list 
    // int arr[] = {4, 6, 10, 12, 15, 23, 28, 35}; //already sorted array
    // int arr[] = {12, 15, 23, 4 , 6, 10, 35}; //odd length array
    // int arr[] = {35, 28, 23, 15, 12, 10, 6, 4}; //descending sorted array input
    // int arr[] = {12};//one element
    // int arr[] = {12, 4}; // two elements
    int arr[] = {12, 15, 23, 4 , 6, 10, 35, 28, 100, 130, 500, 1000, 235, 554, 75, 345, 800, 222, 333, 888, 444, 111, 666, 777, 60};//large list of elements 
    // int arr[] = {12, 15, -23, -4 , 6, 10, -35, 28}; //negative elements
    // int arr[] = {12, 12, 23, 4 , 6, 6, 10, -35, 28}; //duplicate elements
    // int arr[] = {12, 12, 12, 12, 12}; //Same element

    mergeSort(&arr[0], sizeof(arr)/sizeof(arr[0]));
    
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;

    cout << "success" << endl;

    return 0;
}

void mergeSort(int *ptr, size_t size){
    // Base case
    if(ptr == NULL){
        return;
    }

    // Base case
    if(size <= 1){
        return;
    }

    // Make copy of the array to be sorted
    int *ptr2 = new int[size];
    memcpy(ptr2, ptr, size * (sizeof(int)));

    // Split the arr in 2 parts
    int * left = (ptr2);
    int * right = (ptr2 + size/2);

    mergeSort(left, size/2);
    mergeSort(right, (size - size/2));

    int left_cntr = 0, right_cntr = 0, count = 0;

    // Merge

    while(left_cntr < size/2 && right_cntr < (size - size/2)){
        if(left[left_cntr] < right[right_cntr]){
            ptr[count++] = left[left_cntr++];
        }
        else{
            ptr[count++] = right[right_cntr++];
        }
    }

    while (left_cntr < size/2){
        ptr[count++] = left[left_cntr++];
    }

    while (right_cntr < (size - size/2)){
        ptr[count++] = right[right_cntr++];
    }

    delete [] ptr2;
    
    return;
}