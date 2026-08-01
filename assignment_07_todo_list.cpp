// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function declarations
void showMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            // User typed something that isn't a number
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n\n";
            continue;
        }
        cin.ignore(10000, '\n'); // clear leftover newline for getline later

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

        cout << "\n";
    }

    return 0;
}

void showMenu() {
    cout << "====================================\n";
    cout << "         TO-DO LIST MENU\n";
    cout << "====================================\n";
    cout << "1. Add task\n";
    cout << "2. View tasks\n";
    cout << "3. Delete task\n";
    cout << "4. Quit\n";
}

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task: ";
    getline(cin, task);

    if (task.empty()) {
        cout << "Task cannot be empty. Nothing was added.\n";
        return;
    }

    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"\n";
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Add a task to get started!\n";
        return;
    }

    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "There are no tasks to delete.\n";
        return;
    }

    viewTasks(tasks);
    cout << "Enter task number to delete: ";

    int num;
    if (!(cin >> num)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. No task was deleted.\n";
        return;
    }
    cin.ignore(10000, '\n');

    if (num < 1 || num > static_cast<int>(tasks.size())) {
        cout << "Invalid task number. No task was deleted.\n";
        return;
    }

    string removed = tasks[num - 1];
    tasks.erase(tasks.begin() + (num - 1));
    cout << "Task \"" << removed << "\" has been removed.\n";
}
