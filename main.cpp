#include <iostream>
#include <vector>
using namespace std;

// Task structure with name, completed status, due date, and priority
struct Task {
    string name;
    bool completed;
    string dueDate;
    string priority;
};

// List of tasks
vector<Task> tasks;

// Function to display menu
void showMenu() {
    cout << "\n===== TO-DO LIST MENU =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Edit Task Name\n";
    cout << "6. Filter Tasks (Completed/Incomplete)\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

// Add a new task
void addTask() {
    Task newTask;
    cout << "Enter task name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newTask.name);

    cout << "Enter due date (e.g., 2025-05-15): ";
    getline(cin, newTask.dueDate);

    cout << "Enter priority (Low, Medium, High): ";
    getline(cin, newTask.priority);

    newTask.completed = false;
    tasks.push_back(newTask);

    cout << "Task added successfully!\n";
}

// View all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name;
        if (tasks[i].completed) cout << " [Completed]";
        cout << "\n   Due: " << tasks[i].dueDate;
        cout << "\n   Priority: " << tasks[i].priority << "\n";
    }
}

// Mark task as completed
void markTaskCompleted() {
    if (tasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }

    viewTasks();
    int number;
    cout << "Enter task number to mark as completed: ";
    cin >> number;

    if (number < 1 || number > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks[number - 1].completed = true;
        cout << "Task marked as completed!\n";
    }
}

// Delete a task
void deleteTask() {
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    viewTasks();
    int number;
    cout << "Enter task number to delete: ";
    cin >> number;

    if (number < 1 || number > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + number - 1);
        cout << "Task deleted successfully!\n";
    }
}

// Edit task name
void editTask() {
    if (tasks.empty()) {
        cout << "No tasks to edit.\n";
        return;
    }

    viewTasks();
    int number;
    cout << "Enter task number to edit: ";
    cin >> number;
    cin.ignore();

    if (number < 1 || number > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        cout << "Enter new task name: ";
        getline(cin, tasks[number - 1].name);
        cout << "Task name updated!\n";
    }
}

// Filter completed/incomplete tasks
void filterTasks() {
    if (tasks.empty()) {
        cout << "No tasks to filter.\n";
        return;
    }

    int filter;
    cout << "1. Show only completed tasks\n";
    cout << "2. Show only incomplete tasks\n";
    cout << "Choose filter option: ";
    cin >> filter;

    cout << "\nFiltered Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        if ((filter == 1 && tasks[i].completed) ||
            (filter == 2 && !tasks[i].completed)) {
            cout << i + 1 << ". " << tasks[i].name;
            if (tasks[i].completed) cout << " [Completed]";
            cout << "\n   Due: " << tasks[i].dueDate;
            cout << "\n   Priority: " << tasks[i].priority << "\n";
        }
    }
}

// Main function
int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            addTask();
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            markTaskCompleted();
        } else if (choice == 4) {
            deleteTask();
        } else if (choice == 5) {
            editTask();
        } else if (choice == 6) {
            filterTasks();
        } else if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
