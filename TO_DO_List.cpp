#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string title;
    string description;
    string dueDate; // YYYY-MM-DD
    int priority;
    bool isComplete;
};

// List to store all tasks
vector<Task> tasks;

// Function to add a new task
void addTask() {
    Task t;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, t.title);
    cout << "Enter description: ";
    getline(cin, t.description);
    cout << "Enter due date (YYYY-MM-DD): ";
    getline(cin, t.dueDate);
    cout << "Enter priority (1 = high, 5 = low): ";
    cin >> t.priority;
    t.isComplete = false;

    tasks.push_back(t);
    cout << "Task added successfully!\n";
}

// Function to remove a task by title
void removeTask() {
    string title;
    cout << "Enter title of task to remove: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].title == title) {
            tasks.erase(tasks.begin() + i);
            cout << "Task removed successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Task not found.\n";
    }
}

// Function to mark a task complete
void markTaskComplete() {
    string title;
    cout << "Enter title of task to mark complete: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].title == title) {
            tasks[i].isComplete = true;
            cout << "Task marked as complete.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Task not found.\n";
    }
}

// Function to display all tasks
void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); ++i) {
        cout << "\n--------------------\n";
        cout << "Title: " << tasks[i].title << endl;
        cout << "Description: " << tasks[i].description << endl;
        cout << "Due Date: " << tasks[i].dueDate << endl;
        cout << "Priority: " << tasks[i].priority << endl;
        cout << "Status: " << (tasks[i].isComplete ? "Completed" : "Pending") << endl;
    }
}

// Function to sort tasks by priority
void sortByPriority() {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.priority < b.priority;
    });
    cout << "Tasks sorted by priority.\n";
}

// Function to sort tasks by due date
void sortByDueDate() {
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
        return a.dueDate < b.dueDate;
    });
    cout << "Tasks sorted by due date.\n";
}

// Function to search task by title
void searchTask() {
    string title;
    cout << "Enter title to search: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].title == title) {
            cout << "\nTask Found:\n";
            cout << "Title: " << tasks[i].title << endl;
            cout << "Description: " << tasks[i].description << endl;
            cout << "Due Date: " << tasks[i].dueDate << endl;
            cout << "Priority: " << tasks[i].priority << endl;
            cout << "Status: " << (tasks[i].isComplete ? "Completed" : "Pending") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Task not found.\n";
    }
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n===== To-Do List Menu =====\n";
        cout << "1. Add Task"<<endl;
        cout << "2. Remove Task"<<endl;
        cout << "3. Mark Task Complete"<<endl;
        cout << "4. Display All Tasks"<<endl;
        cout << "5. Sort Tasks by Priority"<<endl;
        cout << "6. Sort Tasks by Due Date"<<endl;
        cout << "7. Search Task by Title"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: removeTask(); break;
            case 3: markTaskComplete(); break;
            case 4: displayTasks(); break;
            case 5: sortByPriority(); break;
            case 6: sortByDueDate(); break;
            case 7: searchTask(); break;
            case 0: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
