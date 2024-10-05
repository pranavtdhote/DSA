#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a,b;
    cout<<"Enter the Value of A:";
    cin>>a;
    cout<<"Enter the Value of B:";
    cin>>b;
    swap(a,b);
    cout<<"The Value of A and B after Swaping is:\n";
    cout<<"A=\n"<<a<<"B=\n"<<b<<endl;
    return 0;
}