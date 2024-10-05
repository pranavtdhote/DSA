#include<iostream>
using namespace std;

class Node{
    public:
    int info;
    Node* prev;
    Node* next;
};
class list{
    Node *first,*last;
    public:
    list(){
        first=NULL;
        last=NULL;
    }

    void addFirstnode(int value){
    Node*temp=new Node();
    temp->info=value;
    temp->prev=NULL;
    temp->next=NULL;

    if(first==NULL){
        first=temp;
        last=temp;
    }
    else{
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}
    void display() {
        Node* temp = first;
        while (temp != NULL) {
            cout << temp->info << " ";
            if (temp->next != NULL) {
                cout << "<-> ";
            }
            temp = temp->next;
        }
        cout << "<-> NULL" << endl;
    }
};


int main() {
    list dll;
    dll.addFirstnode(10);
    dll.addFirstnode(20);
    dll.addFirstnode(30);
    dll.display();
    return 0;
}