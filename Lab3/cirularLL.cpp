#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *head = NULL, *temp = NULL, *newNode;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of nodes must be positive.\n";
        return 0;
    }

    // Creating circular linked list
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

        // At last node, connect it to head to make it circular
        if (i == n)
            temp->next = head;
    }

    // Displaying the circular linked list
    cout << "\nCircular Linked List: ";
    temp = head;
    int count = 0;
    do {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    } while (temp != head && count < n);

    cout << endl;

    return 0;
}
