#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long countInversions(int * ptr, size_t size);

int main() {
    vector <int> arr;
    ifstream is("IntegerArray.txt");

    int x;
    while (is >> x){
        arr.push_back(x);
    }

    is.close();

    int * ptr = new int[arr.size()];
    int count = 0;
    for(int x : arr){
        ptr[count++] = x;
    }


    cout << countInversions(ptr, arr.size()) << endl;
    cout << "success" << endl;

    return 0;
}


long countInversions(int * ptr, size_t size){
    // Base case
    if(size <= 1 || ptr == NULL){
        return 0;
    }


    // Make copy of the array to be sorted
    int *ptr2 = new int[size];
    memcpy(ptr2, ptr, size * (sizeof(int)));

    // Split the arr in 2 parts
    int * left = (ptr2);
    int * right = (ptr2 + size/2);


    long left_count = countInversions(left, size/2);
    long right_count = countInversions(right, (size - size/2));
    long combined = 0;

    int left_cntr = 0, right_cntr = 0, count = 0;

    // Merge and count

    while(left_cntr < size/2 && right_cntr < (size - size/2)){
        if(left[left_cntr] < right[right_cntr]){
            ptr[count++] = left[left_cntr++];
        }
        else{
            ptr[count++] = right[right_cntr++];
            combined += size/2 + right_cntr - count;
        }
    }

    while (left_cntr < size/2){
        ptr[count++] = left[left_cntr++];
    }

    while (right_cntr < (size - size/2)){
        ptr[count++] = right[right_cntr++];
    }

    delete [] ptr2;
    
    return (left_count + right_count + combined);

}