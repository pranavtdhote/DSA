#include<iostream>
using namespace std;
//2d Array
// int main(){
//     int array[3][3]={
//         {1,2,3},
//         {4,5,6},
//         {7,8,9}
//     };

//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cout<<array[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }  

//insertion of element in Array
// int main(){
//     int arr[10]={1,2,3,4,5};
//     int n=5;
//     int pos=3;
//     int value=99;

//     for(int i=n;i>pos;i--){
//         arr[i]=arr[i-1];
//     }
//     arr[pos]=value;
//     n++;
//     cout<<"Array after insertion is:";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//deletiontion of element in Array
// int main(){
//     int arr[10]={1,2,3,4,5};
//     int n=5;
//     int pos=3;
    

//     for(int i=pos;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
    
//     n--;

//     cout<<"Array after deletion is:";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//finding maximum number in the array
// int main(){
//     int n,max;
//     cout<<"Enter the no of element you want to insert in array:";
//     cin>>n;

//     int a[n];
//     cout<<"Enter the element in the array:";
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     max=a[0];
//     for(int i=1;i<n;i++){
//         if(a[i]>max){
//             max=a[i];
//         }
//     }
//     cout<<"Maximum Element:"<<max<<endl;
//     return 0;
// }

//finding minimum element in the array
// int main(){
//     int n,min;
//     cout<<"Enter the no of element you want to insert in array:";
//     cin>>n;

//         int a[n];
//     cout<<"Enter the element in the array:";
//     for(int i=1;i<n;i++){
//         cin>>a[i];
//     }
//     min=a[0];
//     for(int i=1;i<n;i++){
//         if(a[i]<min){
//             min=a[i];
//         }
//     }
//     cout<<"Minimum Element:"<<min<<endl;
//     return 0;
// }

// Merging the Sorted array
//  int main(){
//     int n1,n2;
//     cout<<"Enter the no of element you want to insert in array 1:";
//     cin>>n1;
//     int a1[n1];
//     for(int i=0;i<n1;i++){
//         cin>>a1[i];
//     }

//     cout<<"Enter the no of element you want to insert in array 1:";
//     cin>>n2;
//     int a2[n2];
//     for(int j=0;j<n2;j++){
//         cin>>a2[j];
//     }

//     int merge[n1+n2];
//     int i=0,j=0,k=0;

//     while(i<n1 && j<n2){
//         if(a1[i]<a2[j]){
//             merge[k++]=a1[i++];
//         }
//         else{
//             merge[k++]=a2[j++];
//         }
//     }

//     while(i<n1){
//         merge[k++]=a1[i++];
//     }

//     while(j<n2){
//         merge[k++]=a2[j++];
//     }

//     cout<<"Sorted Array:\n";
//     for(int i=0;i<n1+n2;i++){
//         cout<<merge[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
//  }

//Reversed Array
// int main(){
//     int n;
//     cout<<"Enter the number of elements you wnat to insert in the array:";
//     cin>>n;

//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout<<"Reversed Array:\n";
//     for(int i=n-1;i>=0;i--){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

//Sum of Elements in the array
// int main(){
//     int n;
//     int sum=0;
//     cout<<"Enter the number of element you want to insert.";
//     cin>>n;

//     int arr[n];
//     cout<<"Enter the element in the array:";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         sum=sum+arr[i];
//     }

//     cout<<"Sum Of elements in array is:"<<sum;
//     return 0;
// }

//Average of Elements in the array
// int main(){
//     int n;
//     int sum=0;
//     cout<<"Enter the number of element you want to insert.";
//     cin>>n;

//     int arr[n];
//     cout<<"Enter the element in the array:";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         sum=sum+arr[i];
//     }

//     cout<<"Sum Of elements in array is:"<<float(sum)/n;
//     return 0;
// }

//Arrangin Elements in Accsending Order
// int main(){
//     int n,temp;
//     cout<<"Enter the Number of Element You want to insert in Array:";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Enter the "<<i+1<<" Element in the Array:";
//         cin>>arr[i];    
//     }
    
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
//     cout<<"Sorted Array:";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

//ADDITION OF MATRIX
int main(){
    
}
