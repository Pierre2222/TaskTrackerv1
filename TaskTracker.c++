#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Task {
public:
    std::string name;
    std::string due_date;
    std::string status;

    Task(std::string n, std::string d, std::string s) 
        : name(n), due_date(d), status(s) {}

    void display() const {
        std::cout << "Task: " << name << ", Due: " << due_date << ", Status: " << status << std::endl;
    }
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& name, const std::string& due_date) {
        tasks.emplace_back(name, due_date, "pending");
        std::cout << "Task added successfully!" << std::endl;
    }

    void listTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks found." << std::endl;
            return;
        }
        
        std::cout << "\nAll Tasks:" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            tasks[i].display();
        }
        std::cout << "----------------------------------------" << std::endl;
    }

    void updateTaskStatus(size_t index, const std::string& new_status) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index-1].status = new_status;
            std::cout << "Task status updated successfully!" << std::endl;
        } else {
            std::cout << "Invalid task number!" << std::endl;
        }
    }

    void deleteTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + (index-1));
            std::cout << "Task deleted successfully!" << std::endl;
        } else {
            std::cout << "Invalid task number!" << std::endl;
        }
    }
};

void showHelp() {
    std::cout << "\nTaskTracker Commands:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "add <task_name> <due_date>  - Add a new task" << std::endl;
    std::cout << "list                        - Show all tasks" << std::endl;
    std::cout << "update <task_number> <status> - Update task status" << std::endl;
    std::cout << "delete <task_number>        - Delete a task" << std::endl;
    std::cout << "help                        - Show this help message" << std::endl;
    std::cout << "exit                        - Exit the program" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

int main() {
    TaskManager manager;
    std::string command;

    std::cout << "Welcome to TaskTracker!" << std::endl;
    showHelp();

    while (true) {
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);
        
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "exit") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else if (cmd == "help") {
            showHelp();
        } else if (cmd == "add") {
            std::string name, due_date;
            std::getline(iss >> std::ws, name, ',');
            iss >> due_date;
            
            if (!name.empty() && !due_date.empty()) {
                manager.addTask(name, due_date);
            } else {
                std::cout << "Usage: add <task_name>, <due_date>" << std::endl;
            }
        } else if (cmd == "list") {
            manager.listTasks();
        } else if (cmd == "update") {
            size_t index;
            std::string status;
            if (iss >> index >> status) {
                manager.updateTaskStatus(index, status);
            } else {
                std::cout << "Usage: update <task_number> <new_status>" << std::endl;
            }
        } else if (cmd == "delete") {
            size_t index;
            if (iss >> index) {
                manager.deleteTask(index);
            } else {
                std::cout << "Usage: delete <task_number>" << std::endl;
            }
        } else {
            std::cout << "Unknown command. Type 'help' for available commands." << std::endl;
        }
    }

    return 0;
}