#include<iostream>
#define MAX 5
using namespace std;

class circularQueue{
    private:
    int queue[MAX];
    int front,rear;

    public:
    circularQueue(){
        front=-1;
        rear=-1;
    }
    void insert(int token){
        if((rear+1)%MAX==front){
            cout<<"Queue Overflow!Cannot Issue More Token";
            return;
        }
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%MAX;
        queue[rear]=token;
        cout<<"The Token"<<token<<"is issued to the customer.\n";
    }

    void remove(){
        if(front==-1){
            cout<<"Queue Underflow!Cannot Serve More Token";
            return; 
        }
        cout<<"Serving Customer with"<<queue[front]<<"\n";
        if(front==rear){
            front=rear=-1;
        }
        else{
            front = (front + 1) % MAX;
        }
    }

    void display(){
        if(front==-1){
            cout<<"Queue is Empty";
        }
        int i=front;
        while(true){
            cout<<queue[i]<<" ";
            if(i==rear){
                break; // Stop at the rear of the queue
            }
            i = (i + 1) % MAX; // Wrap around in circular manner
        }
        cout<<endl;
    }
};

int main(){
    circularQueue q;
    int choice,token=1;
    do {
        cout <<"\nMenu:\n";
        cout <<"1. Issue a token\n";
        cout <<"2. Serve a customer\n";
        cout <<"3. Display token numbers\n";
        cout <<"4. Exit\n";
        cout <<"Enter your choice:";
        cin >> choice;

    switch (choice)
    {
    case 1:
        q.insert(token);
        token++;
        break;
    case 2:
        q.remove();
        break;
    case 3:
        q.display();
        break;
    case 4:
        cout<<"Exiting the program....";
        break;
    
    default:
        cout<<"Invalid Choice!Enter Valid Choice.";
        break;
    }
}  while (choice != 4);
    return 0;
}