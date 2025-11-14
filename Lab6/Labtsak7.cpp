#include <iostream>
using namespace std;
class Stack {
private:
    int arr[100];
    int top;
    int size;
public:
    Stack() {
        top = -1;
        size = 100;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == size - 1;
    }
    void push(int value) {
        if (!isFull()) {
            arr[++top] = value;
        }
    }
    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1; 
    }
    int peek() {
        if (!isEmpty()) return arr[top];
        return -1; 
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
    int getSize() {
        return top + 1;
    }
    void sortStack() {
        Stack tempStack;
        while (!isEmpty()) {
            int temp = pop();
            while (!tempStack.isEmpty() && tempStack.peek() > temp) {
                push(tempStack.pop());
            }
            tempStack.push(temp);
        }
        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }
};
int main() {
    Stack s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);
    cout << "Original Stack:\n";
    s.display();
    s.sortStack();
    cout << "Sorted Stack (Ascending Order):\n";
    s.display();
    return 0;
}

