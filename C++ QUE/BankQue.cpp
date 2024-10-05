#include <iostream>
#include <queue>
#include <string>

// Node class for LinkedList
class Node {
public:
    std::string data;
    Node* next;

    Node(const std::string& d) : data(d), next(nullptr) {}
};

// LinkedList class to maintain the history of served customers
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void append(const std::string&);
    void display();

private:
    Node* head;
};

void LinkedList::append(const std::string& data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* lastNode = head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void LinkedList::display() {
    Node* current = head;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

// BankQueue class to manage and serve customers
class BankQueue {
public:
    BankQueue();
    void addCustomer(const std::string&);
    void serveCustomer();
    void displayServedCustomers();

private:
    std::queue<std::string> customerQueue; // Queue to store customers
    LinkedList servedHistory; // LinkedList to store served customer history
};

BankQueue::BankQueue() {}

void BankQueue::addCustomer(const std::string& customer) {
    customerQueue.push(customer);
    std::cout << "Added customer: " << customer << std::endl;
}

void BankQueue::serveCustomer() {
    if (!customerQueue.empty()) {
        std::string customer = customerQueue.front();
        customerQueue.pop();
        std::cout << "Serving customer: " << customer << std::endl;
        servedHistory.append("Served customer: " + customer);
    } else {
        std::cout << "No customers to serve." << std::endl;
    }
}

void BankQueue::displayServedCustomers() {
    servedHistory.display();
}

int main() {
    BankQueue bank;
    int choice;
    std::string customer;

    std::cout << "Bank Queue Simulation\n";
    std::cout << "1. Add Customer\n";
    std::cout << "2. Serve Customer\n";
    std::cout << "3. Display Served Customers\n";
    std::cout << "4. Exit\n";

    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter customer name: ";
                std::getline(std::cin, customer);
                bank.addCustomer(customer);
                break;
            case 2:
                bank.serveCustomer();
                break;
            case 3:
                std::cout << "Served Customers:\n";
                bank.displayServedCustomers();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
