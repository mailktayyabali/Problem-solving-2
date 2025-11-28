#include <iostream>
#include <string>
using namespace std;

#define MAX 50

struct Patient {
    string name;
    int priority; 
    bool ambulance;
};

struct Queue {
    Patient arr[MAX];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue &q) {
    return q.front == -1;
}

bool isFull(Queue &q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, Patient p) {
    if (isFull(q)) {
        cout << "Queue full! Cannot add patient.\n";
        return;
    }
    if (isEmpty(q)) q.front = 0;
    q.arr[++q.rear] = p;
}

Patient dequeue(Queue &q) {
    Patient temp;
    if (isEmpty(q)) {
        cout << "Queue empty!\n";
        temp.name = "N/A";
        return temp;
    }
    temp = q.arr[q.front];
    if (q.front == q.rear) q.front = q.rear = -1;
    else q.front++;
    return temp;
}

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        cout << "No patients in this queue.\n";
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        cout << i - q.front + 1 << ". " << q.arr[i].name;
        if (q.arr[i].ambulance) cout << " (Ambulance)";
        cout << "\n";
    }
}

void treatPatient(Queue &critical, Queue &serious, Queue &stable) {
    if (!isEmpty(critical)) {
        cout << "\nTreating critical patient: " << dequeue(critical).name << "\n";
    } else if (!isEmpty(serious)) {
        cout << "\nTreating serious patient: " << dequeue(serious).name << "\n";
    } else if (!isEmpty(stable)) {
        cout << "\nTreating stable patient: " << dequeue(stable).name << "\n";
    } else {
        cout << "\nNo patients waiting.\n";
    }
}

void upgradePriority(Queue &fromQ, Queue &toQ, string name) {
    bool found = false;
    for (int i = fromQ.front; i <= fromQ.rear; i++) {
        if (fromQ.arr[i].name == name) {
            Patient p = fromQ.arr[i];
            p.priority++;
            enqueue(toQ, p);
            // Shift elements left
            for (int j = i; j < fromQ.rear; j++) {
                fromQ.arr[j] = fromQ.arr[j + 1];
            }
            fromQ.rear--;
            if (fromQ.rear < fromQ.front) fromQ.front = fromQ.rear = -1;
            found = true;
            cout << "Patient " << name << " upgraded to higher priority.\n";
            break;
        }
    }
    if (!found) cout << "Patient not found in this priority.\n";
}

void estimatedWaitTime(Queue critical, Queue serious, Queue stable) {
    cout << "\n--- Estimated Wait Times ---\n";
    cout << "Critical: " << (critical.rear - critical.front + 1) * 5 << " mins\n";
    cout << "Serious: " << (serious.rear - serious.front + 1) * 10 << " mins\n";
    cout << "Stable: " << (stable.rear - stable.front + 1) * 15 << " mins\n";
}

int main() {
    Queue critical, serious, stable;
    initQueue(critical);
    initQueue(serious);
    initQueue(stable);

    int choice;
    do {
        cout << "\n--- HOSPITAL ER TRIAGE SYSTEM ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Next Patient\n";
        cout << "3. Upgrade Patient Priority\n";
        cout << "4. Show Queue Status\n";
        cout << "5. Show Estimated Wait Times\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            cout << "Enter patient name: ";
            cin >> p.name;
            cout << "Enter priority (3=Critical, 2=Serious, 1=Stable): ";
            cin >> p.priority;
            cout << "Ambulance arrival? (1=Yes, 0=No): ";
            cin >> p.ambulance;

            if (p.ambulance && p.priority < 3) p.priority = 3; // upgrade for ambulance

            if (p.priority == 3) enqueue(critical, p);
            else if (p.priority == 2) enqueue(serious, p);
            else enqueue(stable, p);
        }

        else if (choice == 2) {
            treatPatient(critical, serious, stable);
        }

        else if (choice == 3) {
            string name;
            int level;
            cout << "Enter priority level to search in (1=Stable, 2=Serious): ";
            cin >> level;
            cout << "Enter patient name: ";
            cin >> name;

            if (level == 1) upgradePriority(stable, serious, name);
            else if (level == 2) upgradePriority(serious, critical, name);
            else cout << "Invalid level.\n";
        }

        else if (choice == 4) {
            cout << "\n--- Critical Patients ---\n"; displayQueue(critical);
            cout << "\n--- Serious Patients ---\n"; displayQueue(serious);
            cout << "\n--- Stable Patients ---\n"; displayQueue(stable);
        }

        else if (choice == 5) {
            estimatedWaitTime(critical, serious, stable);
        }

    } while (choice != 0);

    return 0;
}
