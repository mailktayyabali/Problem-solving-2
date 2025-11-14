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

    void push(char c) {
        if (!isFull()) arr[++top] = c;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string reverseString(string s) {
    string rev = "";
    for (int i = s.length()-1; i >= 0; i--) {
        if (s[i] == '(') rev += ')';
        else if (s[i] == ')') rev += '(';
        else rev += s[i];
    }
    return rev;
}

string infixToPostfix(string infix) {
    Stack s;
    string post = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c >= '0' && c <= '9') {
            post += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                post += s.pop();
            }
            s.pop();
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                post += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        post += s.pop();
    }

    return post;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string rev = reverseString(infix);
    string post = infixToPostfix(rev);

    string prefix = "";
    for (int i = post.length() - 1; i >= 0; i--) {
        prefix += post[i];
    }

    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
