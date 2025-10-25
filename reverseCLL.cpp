#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to display circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to reverse circular linked list
void reverseList(Node*& head) {
    if (head == NULL || head->next == head) {
        return;  // nothing to reverse
    }

    Node *prev = NULL, *current = head, *nextNode;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    // Fix the last connection
    head->next = prev;
    head = prev;
}

int main() {
    Node *head = NULL, *temp = NULL, *newNode;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes.\n";
        return 0;
    }

    // Create circular linked list
    for (int i = 1; i <= n; i++) {
        newNode = new Node;
        cout << "Enter value for node " << i << ": ";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if (i == n)
            temp->next = head;  // make circular
    }

    cout << "\nOriginal Circular Linked List:\n";
    display(head);

    reverseList(head);

    cout << "\nReversed Circular Linked List:\n";
    display(head);

    return 0;
}
