#include<iostream>
using namespace std;
                    
int binarysearch(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int mid=(s+e)/2; //OR mid=s+(e-s)/2
    while (s<=e){
        if (arr[mid]==key){ //If 'mid' element is equal to 'key', return 'mid' index.
            return mid;
        }
        else if (arr[mid]>key){
            e=mid-1; // Go to right part of 'mid' element.
        }
        else{ // Go to left part of 'mid' element.
            s=mid+1;
        }
        mid=(s+e)/2; //OR mid=s+(e-s)/2
    }
    return -1; // Return -1 if 'key' not present in array.
}
 
int main(){
    /*NOTE- Binary Search is always applied on mentoning functions 
    (i.e ascending OR descending arrays)*/
    int n;
    cout<<"Enter size of your Array :";cin>>n;

    int arr[n];

    cout<<"Enter elements in your Array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int key;
    cout<<"Enter Key value to be searched in the Array :";cin>>key;

    cout<<binarysearch(arr,n,key);
       
    return 0;
}