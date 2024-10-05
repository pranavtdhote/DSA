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

// LinkedList class to maintain the history of processed tickets
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

// TicketingSystem class to manage and process tickets
class TicketingSystem {
public:
    TicketingSystem();
    void issueTicket(const std::string&);
    void processTicket();
    void displayProcessedTickets();

private:
    std::queue<std::string> ticketQueue; // Queue to store tickets
    LinkedList processedHistory; // LinkedList to store processed ticket history
};

TicketingSystem::TicketingSystem() {}

void TicketingSystem::issueTicket(const std::string& ticket) {
    ticketQueue.push(ticket);
    std::cout << "Issued ticket: " << ticket << std::endl;
}

void TicketingSystem::processTicket() {
    if (!ticketQueue.empty()) {
        std::string ticket = ticketQueue.front();
        ticketQueue.pop();
        std::cout << "Processing ticket: " << ticket << std::endl;
        processedHistory.append("Processed ticket: " + ticket);
    } else {
        std::cout << "No tickets to process." << std::endl;
    }
}

void TicketingSystem::displayProcessedTickets() {
    processedHistory.display();
}

int main() {
    TicketingSystem system;
    int choice;
    std::string ticket;

    std::cout << "Ticketing System Simulation\n";
    std::cout << "1. Issue Ticket\n";
    std::cout << "2. Process Ticket\n";
    std::cout << "3. Display Processed Tickets\n";
    std::cout << "4. Exit\n";

    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter ticket description: ";
                std::getline(std::cin, ticket);
                system.issueTicket(ticket);
                break;
            case 2:
                system.processTicket();
                break;
            case 3:
                std::cout << "Processed Tickets:\n";
                system.displayProcessedTickets();
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
