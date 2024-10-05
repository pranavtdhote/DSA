#include<iostream>
using namespace std;

float average(int num1,int num2,int num3)
{
    int average;
    int sum=0;
    sum=num1+num2+num3;
    average=(sum)/3;
    return average;
}

int main(){
    int number_1,number_2,number_3;
    cout<<"Enter the number 1:";
    cin>>number_1;
    cout<<"Enter the number 2:";
    cin>>number_2;
    cout<<"Enter the number 3:";
    cin>>number_3;
    cout<<"The Average of Numbers are:"<<average(number_1,number_2,number_3);
    return 0;
}