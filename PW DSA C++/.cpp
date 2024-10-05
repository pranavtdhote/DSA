#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    string specialization;
    string phone;
    Node* next;
    Node* prev;
};

class DoctorList {
    Node* head;
    Node* tail;
public:
    DoctorList() {
        head = NULL;
        tail = NULL;
    }

    void append() {
        string name, specialization, phone;
        cout << "Enter doctor's name: ";
        cin >> name;
        cout << "Enter doctor's specialization: ";
        cin >> specialization;
        cout << "Enter doctor's phone number: ";
        cin >> phone;

        Node* temp = new Node;
        temp->name = name;
        temp->specialization = specialization;
        temp->phone = phone;
        temp->next = NULL;
        temp->prev = tail;

        if (tail != NULL) {
            tail->next = temp;
        }
        tail = temp;

        if (head == NULL) {
            head = temp;
        }
    }

    void listBySpecialization() {
        string specialization;
        cout << "Enter specialization to list doctors: ";
        cin >> specialization;

        Node* current = head;
        while (current != NULL) {
            if (current->specialization == specialization) {
                cout << "Name: " << current->name << ", Phone: " << current->phone << endl;
            }
            current = current->next;
        }
    }

    void reverseList() {
        Node* current = head;
        Node* temp = NULL;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != NULL) {
            head = temp->prev;
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << "Name: " << current->name << ", Specialization: " << current->specialization << ", Phone: " << current->phone << endl;
            current = current->next;
        }
    }
};

int main() {
    DoctorList list;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Append a new doctor to the list\n";
        cout << "2. List all doctors with phone numbers for given specialization\n";
        cout << "3. Reverse the list\n";
        cout << "4. Display all doctors\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.append();
                break;
            case 2:
                list.listBySpecialization();
                break;
            case 3:
                list.reverseList();
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
