#include<iostream>
using namespace std;

int search(int a[],int key,int n){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,key;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" element in the array:";
        cout<<a[i];
    }

    cout<<"Enter the element you want to search:";
    cin>>key;

    int j=search(a,key,n);
    if(j>=0){
        cout<<"Enter the valid Number:";
    }
    else{
        cout<<"The element you searched is at"<<j<<"position";
    }
    return 0;
}