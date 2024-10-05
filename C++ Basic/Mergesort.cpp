#include<iostream>
using namespace std;

void merge(int a[],int l,int mid,int r){
    int i=l;
    int j=r;
    int k=l;
    while(j<=mid && j<=r){
        
    }
}

void mergeSort(int a[],int l,int r){
    if(l<r){
    int mid=l+r/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
    }
}

