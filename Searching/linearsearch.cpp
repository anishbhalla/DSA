#include<iostream>
using namespace std;
/*Linear Searching on an Array*/
                    
int linearsearch(int arr[],int n,int key){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==key){
            return i;
        }
    }
    return -1;    
}
                   
int main(){
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

    cout<<linearsearch(arr,n,key);        
    return 0;
}