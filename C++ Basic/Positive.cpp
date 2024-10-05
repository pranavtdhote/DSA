#include<iostream>
using namespace std;

bool positive_or_negative(int number)
{
    if(number>0){
        return true;
    } 
    else{
        return false;
    } 
}
int main()
{
    int number;
    string result;
    cout<<"Enter the number:";
    cin>>number;
    if(positive_or_negative(number))
    {
        result="Positive";
    }
    else{
        result="Negative";
    }
    cout<<"Given Number" <<number<< "is" <<result<<endl;
    return 0;
}