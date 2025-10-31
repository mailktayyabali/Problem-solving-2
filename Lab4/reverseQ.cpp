#include <iostream>
using namespace std;
class Queue {
private:
    int arr[5];
    int front;
    int rear;
    int size;
public:
    Queue() {
        front = -1;
        rear = -1;
        size = 5;
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
    void reverse() {
        if (isEmpty()) {
            return;
        }
        int temp = arr[front];
        dequeue();
        reverse();
        enqueue(temp);
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.reverse();
    cout << "Queue after reversing:\n";
    q.display();
    return 0;
}