// Write a C++ function to search for a given value in a circular linked list. If the value is found, display the position (index) of the node containing the value; otherwise, print a message indicating that the value was not found.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
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
void searchValue(Node* head, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    int position = 1;
    bool found = false;
    do {
        if (temp->data == value) {
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    if (found) {
        cout << "Value " << value << " found at position " << position << ".\n";
    } else {
        cout << "Value " << value << " not found in the list.\n";
    }
}
void createCircularList(Node*& head, int n) {
    if (n <= 0) {
        cout << "Invalid number of nodes.\n";
        return;
    }
    Node *temp = NULL, *newNode;
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
}
int main(){
    Node *head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    createCircularList(head, n);
    display(head);

    cout << "Enter value to search: ";
    cin >> value;

    searchValue(head, value);

    return 0; 

}