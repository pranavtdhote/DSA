#include<iostream>
using namespace std;

int sum(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;

    int a[n];
    cout<<"Enter the elelments in the array:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"The Sum of elements in the given array:"<<sum(a,n)<<endl;
    return 0;
}