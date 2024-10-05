#include <iostream>
using namespace std;

class node {
public:
    int info;
    node* next;
};

class List : public node {
    node* first, * last;
public:
    List() {
        first = NULL;
        last = NULL;
    }

    void create() {
        char choice;
        do {
            int value;
            cout << "Enter the element of list: ";
            cin >> value;
            append(value);

            cout << "Do you want to add another element (y/n)? ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

    void append(int value) {
        node* temp = new node;
        temp->info = value;
        temp->next = NULL;

        if (first == NULL) {
            first = temp;
            last = temp; 
        } else {
            last->next = temp;
            last = temp;
        }
    }

    void display() {
        node* temp = first;
        if (temp == NULL) {
            cout << "List is Empty" << endl;
        } else {
            while (temp != NULL) {
                cout << temp->info << " ";
                if (temp->next != NULL) {
                    cout << "-> ";
                }
                temp = temp->next;
            }
            cout << "-> NULL" << endl;
        }
    }
};

int main() {
    List list1;
    list1.create();
    list1.display();
    return 0;
}
