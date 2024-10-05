#include <iostream>
using namespace std;

int main(){
    // int array[]={1,2,3,4};
    
    // cout<<sizeof(array)<<endl;
    // cout<<sizeof(array)/sizeof(array[0])<<endl;
    // int size=sizeof(array)/sizeof(array[0]);

    //for loop
    // for(int i=0;i<size;i++){
    //     cout<<array[i]<<endl;
    // }

    //for each loop
    // for(int ele:array){
    //     cout<<ele<<endl;
    // }

    //While loop
    // int index=0;
    // while(index<size){
    //     cout<<array[index]<<" ";
    //     index++;
    // }

    // char vowels[5];

    // for(int i=0;i<5;i++){
    //     cin>>vowels[i];
    // }
    // for(char & element:vowels){
    //     cin>>element;
    // }
    //  for(int i=0;i<5;i++){
    //     cout<<vowels[i]<<" ";
    // }

    //Calculate Sum of Element In given Array
    int n;
    cout<<"Enter the size of Array:";
    cin>>n;
    int array[n];

    cout<<"Enter the element in the array:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
    }

    cout<<sum<<endl;

    return 0;
}