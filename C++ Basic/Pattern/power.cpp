#include<iostream>
using namespace std;

int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;

    int result=1;
    for(int i=1;i<=b;i++){
        result*=a;
    }
    cout<<result<<endl;
    return 0;
}