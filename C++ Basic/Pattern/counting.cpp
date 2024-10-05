#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int digit=0;
    while(n>0){
        digit++;
        n=n/10;
    }
    cout<<digit<<endl;
    return 0;
}