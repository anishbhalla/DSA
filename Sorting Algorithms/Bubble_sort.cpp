#include<iostream>
using namespace std;
                    
void bubble_sort(int arr[],int n){
    for (int  i = 1; i < n; i++) //For round 1 to n-1.
    {
        bool swapped=false;
        for (int j = 0; j < n-i; j++) //Process element till n-i th index.
        {
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if (swapped==false){ //Will help us in optimizing the code for it to not run more rounds when array is already sorted.
            break; 
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
    bubble_sort(A,s);
    display(A,s);
    return 0;
}