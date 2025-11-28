#include <iostream>
#include <cstring>
#include <cstdlib> // for rand()
using namespace std;

#define MAX 50

struct PrintJob {
    int jobId;
    char userName[30];
    int priority;   
    int pageCount;
    bool failed;
};

struct Queue {
    PrintJob jobs[MAX];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front == -1;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, PrintJob j) {
    if (isFull(q)) {
        cout << "Queue full. Cannot add new print job.\n";
        return;
    }
    if (isEmpty(q)) q.front = 0;
    q.jobs[++q.rear] = j;
}

PrintJob dequeue(Queue &q) {
    PrintJob temp;
    if (isEmpty(q)) {
        temp.jobId = -1;
        return temp;
    }
    temp = q.jobs[q.front];
    if (q.front == q.rear) q.front = q.rear = -1;
    else q.front++;
    return temp;
}

void cancelJob(Queue &q, int jobId) {
    if (isEmpty(q)) return;
    bool found = false;
    for (int i = q.front; i <= q.rear; i++) {
        if (q.jobs[i].jobId == jobId) {
            found = true;
            for (int j = i; j < q.rear; j++) {
                q.jobs[j] = q.jobs[j + 1];
            }
            q.rear--;
            if (q.rear < q.front) q.front = q.rear = -1;
            cout << "Job " << jobId << " canceled.\n";
            break;
        }
    }
    if (!found) cout << "Job ID " << jobId << " not found.\n";
}

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        cout << "(Empty)\n";
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        cout << "[" << q.jobs[i].jobId << "] " << q.jobs[i].userName
             << " | Priority: " << q.jobs[i].priority
             << " | Pages: " << q.jobs[i].pageCount << "\n";
    }
}

void processJob(Queue &high, Queue &medium, Queue &low) {
    PrintJob job;
    if (!isEmpty(high)) job = dequeue(high);
    else if (!isEmpty(medium)) job = dequeue(medium);
    else if (!isEmpty(low)) job = dequeue(low);
    else {
        cout << "No jobs in queue.\n";
        return;
    }

    cout << "\nProcessing Job #" << job.jobId << " (" << job.userName << ")...\n";

    // Simulate printer error (10% chance)
    if (rand() % 10 == 0) {
        cout << " Printer error! Re-queuing job...\n";
        job.failed = true;
        enqueue(high, job); // failed jobs go to top priority
        return;
    }

    cout << "✅ Job completed successfully.\n";
}

void fairSchedule(Queue &high, Queue &medium, Queue &low) {
    cout << "\n=== CURRENT QUEUE STATUS ===\n";
    cout << "\nHigh Priority:\n"; displayQueue(high);
    cout << "\nMedium Priority:\n"; displayQueue(medium);
    cout << "\nLow Priority:\n"; displayQueue(low);
}

int main() {
    Queue high, medium, low;
    initQueue(high);
    initQueue(medium);
    initQueue(low);

    int choice, jobIdCounter = 1;

    do {
        cout << "\n=== PRINT SPOOLER MENU ===\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Next Job\n";
        cout << "3. Cancel Job\n";
        cout << "4. View Queues\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            PrintJob j;
            j.jobId = jobIdCounter++;
            cout << "Enter user name: ";
            cin >> j.userName;
            cout << "Enter priority (3=High, 2=Medium, 1=Low): ";
            cin >> j.priority;
            cout << "Enter page count: ";
            cin >> j.pageCount;
            j.failed = false;
            if (j.priority == 3 && (rand() % 5 == 0)) j.priority = 2;

            if (j.priority == 3) enqueue(high, j);
            else if (j.priority == 2) enqueue(medium, j);
            else enqueue(low, j);

            cout << "Job added successfully.\n";
        }

        else if (choice == 2) {
            processJob(high, medium, low);
        }

        else if (choice == 3) {
            int id;
            cout << "Enter Job ID to cancel: ";
            cin >> id;
            cancelJob(high, id);
            cancelJob(medium, id);
            cancelJob(low, id);
        }

        else if (choice == 4) {
            fairSchedule(high, medium, low);
        }

    } while (choice != 0);

    cout << "Exiting Print Spooler...\n";
    return 0;
}
