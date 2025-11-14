#include <iostream>
using namespace std;
class Stack {
private:
    int arr[10];
    int top;
    int size;
public:
    Stack() {
        top = -1;
        size = 10;
    }
    bool isFull() {
        return (top == size - 1);
    }
    bool isEmpty() {
        return (top == -1);
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed\n";
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << arr[top] << " popped\n";
        top--;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    s.push(40);
    s.push(50);
    s.display();
    return 0;
}
