#include<iostream>
#define MAX 50
using namespace std;
class Queue
{
private:
    int queue[MAX];
    int front,rear;
public:
    Queue()
    {
        front=-1;
        rear=-1;
    }
    void insert(int token)
    {
        if(rear==MAX-1)
        {
            cout<<"Queue Overflow!Cannot issue token.\n";
            return;
        }
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=token;
        cout<<"Token Number"<<token<<"issued to the customer.\n";
    }
};