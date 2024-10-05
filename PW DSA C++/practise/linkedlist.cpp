// #include<iostream>
// using namespace std;

// class node{
//     public:
//     int info;
//     node* next;

//     node(int data){
//         info=data;
//         next=NULL;
//     }

// };

// int main(){
//     node*n=new node(3);
//     cout<<n->info<<"->"<<n->next<<endl;
// }

#include<iostream>
using namespace std;

class Node{
    public:
    int info;
    Node*next;
};

class slist{
    public:
    Node *first,*last;
    slist(){
        first=NULL;
        last=NULL;
    }

    void addFirstNode(int value){
        Node*temp=new Node();
        temp->info=value;
        temp->next=first;
        first=temp;
        if(last==NULL){
            last=temp;
        }
    }

    void display(){
        Node*temp=first;
        while (temp!=NULL){
            cout<<temp->info<<" ";
            if(temp->next!=NULL){
                cout<<"->";
            }
            temp=temp->next;
        }
        cout<<"-> NULL"<<endl;
    }
};
int main(){
    int value;
    slist sll;
    cout<<"Enter the value:";
    cin>>value;
    sll.addFirstNode(value);
    sll.display();
}
