#include<iostream>
using namespace std;

void reverse(int a[],int n)
{
    int temp;
    for(int i=n-1;i>=0;i--){
        temp=a[n-i-1];
        a[n-i-1]=a[i];
        a[i]=temp;
    }
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the elements in the array:";
        cin>>a[i]; 
    }
    cout<<"\nUnsorted Array:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    reverse(a,n);
    cout<<"\nSorted Array:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}