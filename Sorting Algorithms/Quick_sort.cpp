#include<iostream>
using namespace std;
/*Quick Sort Algorithm*/
                                             
int partition(int arr[],int s,int e){   // s -> Start index    e -> End index
    int count = 0; 
    int pivot = arr[s]; //First element of array is taken as pivot.
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i]<=pivot){
            count++;
        }
    }
    int pivotindex = s+count;
    swap(arr[pivotindex],arr[s]);
    int i=s,j=e;
    while ((i<pivotindex)&&(j>pivotindex)){
        //Less than p << [p] >> Greater than p
        while (arr[i]<=pivot){
            i++;
        }
        while( arr[j]>pivot){
            j--;
        }
    }
    if ((i<pivotindex)&&(j>pivotindex)){
        swap(arr[i++],arr[j--]);
    }
    return pivotindex;
}

void quickSort(int arr[],int s,int e){
    // Base Case
    if(s>=e){
        return;
    }
    // Select the pivot element and place it at the start of the array.
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1); // Recursively calling quick sort for Left side of orignal pivotindex.
    quickSort(arr,p+1,e); // Recursively calling quick sort for Right side of orignal pivotindex.
}

int main(){
    int size;
    cout<<"Enter the number of elements: ";
    cin>>size;
    cout<<endl;

    int arr[size];
    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];    
    }
    

    cout<<" Original array:"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    
    cout<<endl;

    quickSort(arr,0,size);
    cout<<" Array after Quick Sort"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    
    cout<<endl;       
    return 0;
}