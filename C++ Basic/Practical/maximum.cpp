#include<iostream>
using namespace std;

int max(int a[],int n)
{
        int max=a[0];
        for(int i=1;i<n;i++){
            if(a[i]>max){
                max=a[i];
            }
        }
        return max;
}

int main()
{
    int n;
    cout<<"Enter The Size of Array:";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" element in the array:";
        cin>>a[i];
    }

    int result=max(a,n);
        cout<<"The maximum number in tha array is:"<<result<<endl;
    return 0;

}