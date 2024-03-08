#include<iostream>
using namespace std;
/*Merge Sort Algorithm is based on the principle of Divide and Conquer.*/

void merge(int A[],int beg,int mid,int end)
{
    int L_size=mid-beg+1;
    int R_size=end-mid;

    //Create temprary Subarrays.
    int L[L_size]; //Left array.
    int R[R_size]; //Right array.

    //Copy data to temprary subarrays L[] and R[].
    for (int i = 0; i < L_size; i++)
    {
        L[i]=A[beg+i];  //For array L[].
    }
    for (int j = 0; j < R_size; j++)
    {
        R[j]=A[mid+1+j]; //For array R[]
    }

    int L_index=0,R_index=0;
    int A_index=beg;

    //Merge the temprary subarrays back into A[beg...end].
    while ((L_index<L_size) && (R_index<R_size))
    {
        if (L[L_index]<=R[R_index]){
            A[A_index]=L[L_index];
            L_index++;
        }
        else{
            A[A_index]=R[R_index];
            R_index++;
        }
        A_index++;
    }

    //Copy remaining elements of L[] if any.
    while (L_index<L_size){
        A[A_index]=L[L_index];
        L_index++;
        A_index++;
    }

    //Copy remaining elements of R[] if any.
    while (R_index<R_size){
        A[A_index]=R[R_size];
        R_index++;
        A_index++;
    }

    // delete[] L;
    // delete[] R;
}

void merge_sort(int A[],int beg,int end)
{
    if (beg<end)
    {
        int mid = (beg+end)/2;
        merge_sort(A,beg,mid); //Sorting Left part.
        merge_sort(A,mid+1,end); //Sorting Right part.
        merge(A,beg,mid,end); //Merging left and right part.
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
    merge_sort(A,0,s-1);
    display(A,s);         
    return 0;
}