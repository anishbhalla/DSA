#include<iostream>
using namespace std;

void insertion_sort(int arr[],int n){
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1; //Will Store index of previous element.
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j]; //Shifting elements.
            j--; //Will check previous indices.
        }
        arr[j+1]=key;
    }
}

void display(int arr[],int size){
    cout<<"Array is :"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
                    
int main(){
    int s;
    cout<<"Enter size of your Array :";cin>>s;
    int A[s];
    cout<<"Enter Array elements :"<<endl;
    for (int i = 0; i < s; i++)
    {
        cin>>A[i];
    }
    cout<<"Orignal"<<endl;
    display(A,s);
    cout<<"After sorting"<<endl;
    insertion_sort(A,s);
    display(A,s);
    return 0;
}