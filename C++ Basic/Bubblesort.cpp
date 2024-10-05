#include<iostream>
using namespace std;


void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];

    cout<<"Enter the array:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubblesort(a,n);
    cout<<"\nSorted array is:";
    for(int i=0;i<n;i++)
    {
    cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

