#include<iostream>
using namespace std;

   int binarySearch(int a[],int key,int n){
    int l=0;
    int h=n;
    
    while(l<=h){
        int mid=(l+h)/2;
        if(key<a[mid]){
            h=mid-1;
        }
        if(key==a[mid]){
            return mid;
        }
        if(key>a[mid]){
            l=mid+1;
        }
    }
    return -1;
}
    


int main()
{
    int n,key,j;
    cout<<"Enter the size of the Array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the Element "<<i+1<<" :";
        cin>>a[i];
    }
    cout<<"Which Element You Want To Find:";
    cin>>key;
    
    j=binarySearch(a,key,n);
    if(j>=0){
        cout<<"The key is at "<<j<<" position";
    }
    else{
        cout<<"The key is not in array.";
    }
    return 0;
}
