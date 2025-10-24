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

// Function to insert node at beginning
void insertAtBeginning(Node*& head) {
    Node* newNode = new Node;
    cout << "Enter value for new node: ";
    cin >> newNode->data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    // Move to the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert new node before head
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
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
            temp->next = head;
    }

    cout << "\nBefore Insertion:\n";
    display(head);

    // Insert at beginning
    insertAtBeginning(head);

    cout << "\nAfter Insertion:\n";
    display(head);

    return 0;
}
