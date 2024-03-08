#include<iostream>
using namespace std;

void selection_sort(int arr[],int n){
    int least;
    for (int i = 0; i < n; i++)
    {
        least=i;
        for (int j = i+1; j < n+1; j++)
        {
            if(arr[j]<arr[least]){
                least=j;
            }
        }
        if (i!=least){
                swap(arr[i],arr[least]);
        }
        
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
    selection_sort(A,s);
    display(A,s);
    return 0;        
}