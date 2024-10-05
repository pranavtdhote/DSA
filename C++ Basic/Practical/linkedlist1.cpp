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

    void deleteAtStart() {
        if (first == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        node* temp = first;
        first = first->next;
        delete temp;
        if (first == NULL) {
            last = NULL;
        }
    }

    void deleteAtEnd() {
        if (first == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (first == last) {
            delete first;
            first = last = NULL;
            return;
        }
        node* temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = NULL;
    }

    void deleteAtPosition(int position) {
        if (first == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (position == 1) {
            node* temp = first;
            first = first->next;
            delete temp;
            if (first == NULL) {
                last = NULL;
            }
            return;
        }
        node* prev = first;
        for (int i = 1; i < position - 1 && prev != NULL; i++) {
            prev = prev->next;
        }
        if (prev == NULL || prev->next == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        node* temp = prev->next;
        prev->next = temp->next;
        if (temp == last) {
            last = prev;
        }
        delete temp;
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
            cout << "4. Delete at start\n";
            cout << "5. Delete at end\n";
            cout << "6. Delete at position\n";
            cout << "7. Display list\n";
            cout << "8. Exit\n";
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
                    deleteAtStart();
                    break;
                case 5:
                    deleteAtEnd();
                    break;
                case 6:
                    cout << "Enter position to delete: ";
                    cin >> position;
                    deleteAtPosition(position);
                    break;
                case 7:
                    display();
                    break;
                case 8:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice, please try again." << endl;
            }
        } while (choice != 8);
    }
};

int main() {
    List list1;
    list1.menu();
    return 0;
}
