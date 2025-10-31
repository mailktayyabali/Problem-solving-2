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
        if (front == -1)
            front = 0;
        arr[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int value = arr[front++];
        if (front > rear)
            front = rear = -1;
        return value;
    }

    int getSize() {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q1, firstHalf, interleaved;
    int n, value;

    cout << "Enter even number of elements: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Number of elements must be even\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q1.enqueue(value);
    }

    int half = n / 2;

    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q1.dequeue());
    }

    while (!firstHalf.isEmpty()) {
        interleaved.enqueue(firstHalf.dequeue());
        interleaved.enqueue(q1.dequeue());
    }

    cout << "\nInterleaved Queue: ";
    interleaved.display();

    return 0;
}
