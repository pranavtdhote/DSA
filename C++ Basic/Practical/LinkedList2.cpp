#include <iostream>
using namespace std;

class node {
public:
    int info;
    node* next;
};

class List {
    node* first, * last;
public:
    List() {
        first = NULL;
        last = NULL;
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

    void addAtStart(int value) {
        node* temp = new node;
        temp->info = value;
        temp->next = first;
        first = temp;
        if (last == NULL) {
            last = temp;
        }
    }

    void addAtPosition(int value, int position) {
        node* temp = new node;
        temp->info = value;
        temp->next = NULL;

        if (position == 1) {
            temp->next = first;
            first = temp;
            if (last == NULL) {
                last = temp;
            }
            return;
        }

        node* prev = first;
        for (int i = 1; i < position - 1 && prev != NULL; i++) {
            prev = prev->next;
        }

        if (prev == NULL) {
            cout << "Position out of range" << endl;
            delete temp;
        } else {
            temp->next = prev->next;
            prev->next = temp;
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

    void menu() {
        int choice, value, position;
        do {
            cout << "\nMenu:\n";
            cout << "1. Insert at start\n";
            cout << "2. Insert at end\n";
            cout << "3. Insert at position\n";
            cout << "4. Display list\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to insert at start: ";
                    cin >> value;
                    addAtStart(value);
                    break;
                case 2:
                    cout << "Enter value to insert at end: ";
                    cin >> value;
                    append(value);
                    break;
                case 3:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    cout << "Enter position: ";
                    cin >> position;
                    addAtPosition(value, position);
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    List list1;
    list1.menu();
    return 0;
}
