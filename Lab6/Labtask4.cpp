#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    bool isEmpty() {
        return top == NULL;
    }
    void push(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = top;
        top = temp;
        cout << value << " pushed\n";
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << top->data << " popped\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* t = top;
        cout << "Stack elements: ";
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
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
