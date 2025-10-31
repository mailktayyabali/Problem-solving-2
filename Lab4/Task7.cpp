#include <iostream>
using namespace std;
#define MAX 100
class Queue {
private:
    int arr[MAX];
    int front;  
    int rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    bool isFull() {
        return rear == MAX - 1;
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
        cout << value << " enqueued to queue." << endl;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int value = arr[front++];
        cout << value << " dequeued from queue." << endl;
        return value;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
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
    Queue taskQueue;
    taskQueue.enqueue(1);
    taskQueue.enqueue(2);
    taskQueue.enqueue(3);
    taskQueue.display();
    taskQueue.dequeue();
    taskQueue.display();
    return 0;
}