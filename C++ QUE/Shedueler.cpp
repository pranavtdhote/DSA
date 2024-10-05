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

// LinkedList class to maintain the history of executed tasks
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

// TaskScheduler class to manage and execute tasks
class TaskScheduler {
public:
    TaskScheduler();
    void addTask(const std::string&, int);
    void executeTask();
    void displayTaskHistory();

private:
    std::queue<std::pair<std::string, int>> taskQueue; // Queue to store tasks and their priorities
    LinkedList history; // LinkedList to store executed task history
};

TaskScheduler::TaskScheduler() {}

void TaskScheduler::addTask(const std::string& task, int priority) {
    taskQueue.push(std::make_pair(task, priority));
    std::cout << "Added task: " << task << " with priority: " << priority << std::endl;
}

void TaskScheduler::executeTask() {
    if (!taskQueue.empty()) {
        auto task = taskQueue.front();
        taskQueue.pop();
        std::cout << "Executing task: " << task.first << " with priority: " << task.second << std::endl;
        history.append("Executed task: " + task.first + " with priority: " + std::to_string(task.second));
    } else {
        std::cout << "No tasks to execute." << std::endl;
    }
}

void TaskScheduler::displayTaskHistory() {
    history.display();
}

int main() {
    TaskScheduler scheduler;
    int choice, priority;
    std::string task;

    std::cout << "Task Scheduler\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Execute Task\n";
    std::cout << "3. Display Task History\n";
    std::cout << "4. Exit\n";

    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, task);
                std::cout << "Enter task priority: ";
                std::cin >> priority;
                scheduler.addTask(task, priority);
                break;
            case 2:
                scheduler.executeTask();
                break;
            case 3:
                std::cout << "Task History:\n";
                scheduler.displayTaskHistory();
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
