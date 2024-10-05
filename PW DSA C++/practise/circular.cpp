#include<iostream>
using namespace std;

class Node{
    public:
    int info;
    Node*next;
};

class list{
    public:
    Node* last;
    list(){
        last=NULL;
    }

    void addFirstNode(int value){
    Node*temp=new Node();
    temp->info=value;
    if(last==NULL){
        last=temp;
        last->next=last; //Establish self link
    }
    else{
        temp->next=last->next;
        last->next=temp;
    }
    }

    void addlastNode(int value){
    Node*temp=new Node();
    temp->info=value;
    if(last==NULL){
        last=temp;
        last->next=last;
    }
    else{
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
    }

    void display(){
        if(last==NULL){
            cout<<"List is empty";
        }
        Node*temp=last->next;
        do{
            cout<<temp->info<<" ";
            if(temp->next!=last->next){
                cout<<"->";
            }
            temp=temp->next;
        }
        while(temp!=last->next);
            cout<<" "<<endl;
    }

};
int main(){
    list scll;
    int value;
    int choice;
    do {
        cout << "Menu" << endl;
        cout << "1. Insert At Beginning" << endl;
        cout << "2. Insert At Ending" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Value to insert: ";
                cin >> value;
                scll.addFirstNode(value);
                break;

            case 2:
                cout << "Enter the Value to insert: ";
                cin >> value;
                scll.addlastNode(value);
                break;

            case 3:
                scll.display();
                break;

            case 4:
                cout << "Exiting the Program......." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
}
