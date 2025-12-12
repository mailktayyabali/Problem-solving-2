#include <iostream>
using namespace std;

// ====================================
// SENSOR TASK NODE
// ====================================

struct Task {
    int id;
    char name[50];
    int priority;          // 1 = normal, 2 = high (gets extra turns)
    Task* next;
};

// Utility: Copy string manually
void copyString(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}


// ====================================
// ROUND ROBIN SCHEDULER CLASS
// ====================================

class Scheduler {
private:
    Task* head;       // circular list start
    Task* current;    // pointer to currently running task
    int nextID;

public:
    Scheduler() {
        head = NULL;
        current = NULL;
        nextID = 1;
    }

    // Create new task node
    Task* createTask(const char name[], int priority) {
        Task* t = new Task();
        t->id = nextID++;
        copyString(t->name, name);
        t->priority = priority;
        t->next = NULL;
        return t;
    }

    // Add task to circular list
    void addTask(const char name[], int priority) {
        Task* newTask = createTask(name, priority);

        if (head == NULL) {
            head = newTask;
            newTask->next = newTask;
            current = newTask;
        } else {
            Task* temp = head;

            // Find last node
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newTask;
            newTask->next = head;
        }

        cout << "Task added: " << name << " (ID " << newTask->id << ")\n";
    }

    // Execute current task
    void executeTask() {
        if (current == NULL) {
            cout << "No tasks to execute.\n";
            return;
        }

        cout << "\nExecuting Task ID " << current->id
             << " | Name: " << current->name
             << " | Priority: " << current->priority << "\n";

        // Priority handling: high priority gets an extra turn
        if (current->priority == 2) {
            cout << "High priority — granting extra CPU slice.\n";
            // Do NOT move to next — give extra turn
            return;
        }

        // Move to next task (round robin)
        current = current->next;
    }

    // Remove a task by ID (completed/failed)
    void removeTask(int id) {
        if (head == NULL) {
            cout << "No tasks to remove.\n";
            return;
        }

        Task* temp = head;
        Task* prev = NULL;

        // Search for task
        do {
            if (temp->id == id) break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->id != id) {
            cout << "Task not found.\n";
            return;
        }

        // If only one task in list
        if (temp == head && temp->next == head) {
            head = NULL;
            current = NULL;
            delete temp;
            cout << "Task removed (only task).\n";
            return;
        }

        // Removing head
        if (temp == head) {
            Task* last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;
        } else {
            prev->next = temp->next;
        }

        // If current was removed → move forward
        if (current == temp) {
            current = temp->next;
        }

        delete temp;

        cout << "Task removed: " << id << "\n";
    }

    // Display all tasks
    void display() {
        if (head == NULL) {
            cout << "\nNo tasks in scheduler.\n";
            return;
        }

        cout << "\n--- Current Task Queue (Circular) ---\n";

        Task* temp = head;
        do {
            cout << "ID: " << temp->id << " | "
                 << temp->name << " | P=" << temp->priority << "\n";
            temp = temp->next;
        } while (temp != head);
    }
};


// ====================================
// MAIN — DEMO
// ====================================

int main() {
    Scheduler s;

    s.addTask("Temperature Sensor", 1);
    s.addTask("Humidity Sensor", 2);
    s.addTask("Motion Detector", 1);

    s.display();

    s.executeTask();  // temp → high priority extra turn?
    s.executeTask();  // temp again (if high)
    s.executeTask();  // next task

    s.removeTask(2);  // remove humidity sensor

    s.display();

    s.executeTask();
    s.executeTask();

    return 0;
}
