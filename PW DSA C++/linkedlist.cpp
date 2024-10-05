#include<iostream>
using namespace std;

class node{
    public:
    int info;
    node * next;

    node(int data){
        info=data;
        next=NULL;
    }
};

int main(){
    node*n=new node(1);
    cout<<n->info<<" "<<n->next<<endl;

}
