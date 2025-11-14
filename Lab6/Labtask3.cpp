#include <iostream>
using namespace std;
class Stack {
private:
    char arr[100];
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
    void push(char ch) {
        if (!isFull()) {
            arr[++top] = ch;
        }
    }
    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
};
int main() {
    Stack s;
    string str;
    cout << "Enter a string: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    string reversed = "";
    while (!s.isEmpty()) {
        reversed += s.pop();
    }
    cout << "Reversed string: " << reversed << endl;
    return 0;
}
