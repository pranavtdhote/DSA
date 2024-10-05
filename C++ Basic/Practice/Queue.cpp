#include<iostream>
#define MAX 50
using namespace std;
class Queue{
    private:
    int queue[MAX];
    int front,rear;

    public:
    Queue()
    {
    front=-1;
    rear=-1;
    }

    //Function to issue token
    void insert(int token){
        if(rear==MAX-1){
            cout<<"Queue is Overflow!Cannot issue more token.\n";
            return;
        }
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=token;
        cout<<"Token Number"<<token<<"is issued\n";
    }

    //Function to Serve token
    void remove(){
        if(front==-1||front>rear){
            cout<<"Queue is Underflow!Cannot serve more token.\n";
        }
        cout<<"Token Number"<<queue[front]<<"Is Serve";
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }

    //Function to Display Queue
    void display(){
        if(front==-1||front>rear){
            cout<<"Queue is Empty.\n";
            return;
        }
        cout<<"Token in the Queue:";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};
