#include<iostream>
#include<bits/stdc++.h>

using namespace std;
/*Radix Sort Algorithm*/  

void countSort(vector<int> &arr,int exp){
    vector<int> count(10,0); // Creating 'count' array with 10 elements with all 0's.

    // Store the count of each element digit  in 'count' array.
    for (int i = 0; i < arr.size(); i++){
        count[(arr[i] / exp) % 10]++;
    }


    // Modify the count array to store the actual position of each element digit in the 'output' array.
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size()); // Creating  'output' array.

    //Building 'output' array.
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    

    // Copy sorted element from 'output' array back into orignal 'A' array.
    for (int i=0; i<arr.size();i++){
        arr[i]=output[i];
    }
    output.clear(); // Free the memory by clearing the 'output' array.
}

void radixSort(vector<int> &arr){
    // Find the maximum no. to get max number of digits of a element in array.
    int m = *max_element(arr.begin(),arr.end());

    /*Do counting sort for every digit.
    Note that instead of passing digit
    number, exp is passed. exp is 10^i
    where i is current digit number*/
    for (int exp = 1; exp < m/exp; exp*=10)
    {
        countSort(arr,exp);
    }
}

void display(vector<int> &arr)
{
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
                    
int main(){
    vector<int> arr = {543,986,217,765,329};
    
    cout<<"Orignal Array :"<<endl;
    display(arr);

    radixSort(arr);

    cout<<"Sorted Array :"<<endl;
    display(arr);         
    return 0;
}