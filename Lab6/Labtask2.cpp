#include <iostream>
using namespace std;

class Stack {
private:
    char arr[50];
    int top;
    int size;

public:
    Stack() {
        top = -1;
        size = 50;
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
    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};
bool isBalanced(string exp) {
    Stack s;
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}
int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}
