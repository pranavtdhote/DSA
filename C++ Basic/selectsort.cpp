#include<iostream>
using namespace std;

void selectsort(int a[],int n)
{
    int temp,min,loc;
    for(int i=0;i<n;i++){
        min=a[i];
        loc=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];;
                loc=j;
            }
        }
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the array "<<i+1<<" elements:";
        cin>>a[i];
    }
    cout<<"\nUnsorted Array:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    selectsort(a,n);
    cout<<"\nSorted array is:";
    for(int i=0;i<n;i++)
    {
    cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

