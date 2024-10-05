#include<iostream>
using namespace std;

class Node {
    public:
    int info;
    Node* prev;
    Node* next;
};
class list{
    Node *first,*last;
    public:
    list(){
        first==NULL;
        last==NULL;
    }

    void insertlastode(){
        Node*temp=new Node();
        cout<<"Enter the data:";
        cin>>temp->info;
        temp->prev=NULL;
        temp->next=NULL;
    }

    void display(){
        
    }
    

};