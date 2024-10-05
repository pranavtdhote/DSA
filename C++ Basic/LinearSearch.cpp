#include<iostream>
using namespace std;

int search(int a[], int n,int elem)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==elem)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    int elem;
    cout<<"Enter the size of Array:";
    cin>>n;
    int a[n];

    cout<<"Enter the elements in the array:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the number to be Searched:";
    cin>>elem;

    cout<<"The array is:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    int result=search(a,n,elem);

    if (result == -1)
    {
        cout<<"Enter a valid number:";
    }
    else{
        cout<<"\nThe Index of Searchd Number:"<<result;
    }

return 0;
}