#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void counting_sort(vector<int> &A)
{
    // Finding the maximum element in the input array.
    int max = *max_element(A.begin(),A.end());

    // Creating another array 'count' to store the count of each element.
    vector<int> count(max + 1, 0); //Creating an array with 'size'=max+1 and initializing all values with 0.

    // Store the count of each element in 'count' array.
    for (int i=0; i<A.size();i++){
        count[A[i]]++;
    }

    // Modify the count array to store the actual position of each element in the sorted array.
    for (int i = 1; i <= max; i++)
    {   
        count[i] = count[i] + count[i-1];
    }

    // Create a temporary 'output' array to store the sorted output.
    vector<int> output(A.size());

    // Building the 'output' array.
    for (int i = A.size()-1;i>=0;--i){
        output[count[A[i]]-1] = A[i];
        --count[A[i]];
    }

    // Copy sorted element from 'output' array back into orignal 'A' array.
    for (int i=0; i<A.size();i++){
        A[i]=output[i];
    }
    output.clear(); // Free the memory by clearing the 'output' array.
}

void display(vector<int> &arr)
{
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {4,4,4,2,2,8,3,3,1};
    
    cout<<"Orignal Array :"<<endl;
    display(arr);

    counting_sort(arr);

    cout<<"Sorted Array :"<<endl;
    display(arr);
    
    return 0;
}