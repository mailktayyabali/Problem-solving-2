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
void deleteNode(Node*& head, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node *curr = head, *prev = NULL;
    do {
        if (curr->data == value) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                
                Node* tail = head;
                while (tail->next != head) {
                    tail = tail->next;
                }
                if (head->next == head) {
                    
                    head = NULL;
                } else {
                    tail->next = head->next;
                    head = head->next;
                }
            }
            delete curr;
            cout << "Node with value " << value << " deleted.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    cout << "Value " << value << " not found in the list.\n";
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
        if (i == n)

            temp->next = head;
    }
}
int main() {
    Node *head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    createCircularList(head, n);
    display(head);

    cout << "Enter value to delete: ";
    cin >> value;

    deleteNode(head, value);
    display(head);

    return 0;
}