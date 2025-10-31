    // A print server receives print jobs from multiple users. Each job has a unique ID and a priority level (e.g., 1 for high, 2 for medium, 3 for low). The server should process jobs based on priority (high priority jobs first) and then by arrival time (FIFO for jobs with the same priority). Implement a system to manage the print queue.
#include <iostream>
using namespace std;
class Queue {
private:
    int arr[20];
    int front;
    int rear;
    int size;
public:
    Queue() {
        front = -1;
        rear = -1;
        size = 20;
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    bool isFull() {
        return (rear == size - 1);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " enqueued\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue highPriorityQueue;
    Queue mediumPriorityQueue;
    Queue lowPriorityQueue;
    int choice, jobID, priority;

    while (true) {
        cout << "\n1. Add Print Job\n2. Process Print Job\n3. Display Queues\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> jobID;
                cout << "Enter Priority (1-High, 2-Medium, 3-Low): ";
                cin >> priority;
                if (priority == 1) {
                    highPriorityQueue.enqueue(jobID);
                } else if (priority == 2) {
                    mediumPriorityQueue.enqueue(jobID);
                } else if (priority == 3) {
                    lowPriorityQueue.enqueue(jobID);
                } else {
                    cout << "Invalid priority level.\n";
                }
                break;

            case 2:
                if (!highPriorityQueue.isEmpty()) {
                    highPriorityQueue.dequeue();
                } else if (!mediumPriorityQueue.isEmpty()) {
                    mediumPriorityQueue.dequeue();
                } else if (!lowPriorityQueue.isEmpty()) {
                    lowPriorityQueue.dequeue();
                } else {
                    cout << "No print jobs to process.\n";
                }
                break;

            case 3:
                cout << "High Priority Queue:\n";
                highPriorityQueue.display();
                cout << "Medium Priority Queue:\n";
                mediumPriorityQueue.display();
                cout << "Low Priority Queue:\n";
                lowPriorityQueue.display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}