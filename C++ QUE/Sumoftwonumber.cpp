#include<iostream>
using namespace std;

bool chkpair(int a[],int n, int x)
{
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==x)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    int x;
    cout<<"Enter the size of array:";
    cin>>n;

    int a[n];
    cout<<"Enter the elements in the array:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the number you want to check:";
    cin>>x;

    if(chkpair(a,n,x)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}