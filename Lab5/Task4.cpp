#include <iostream>
#include <string>
using namespace std;
struct Node {
    string location;
    Node* prev;
    Node* next;
    Node(string loc) {
        location = loc;
        prev = next = nullptr;
    }
};
class DeliveryRoute {
private:
    Node* head;
    Node* tail;
    Node* current;
public:
    DeliveryRoute() {
        head = tail = current = nullptr;
    }
    void addLocation(string loc) {
        Node* newNode = new Node(loc);
        if (!head) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added location: " << loc << endl;
    }
    void completeDelivery(string loc) {
        Node* temp = head;
        while (temp) {
            if (temp->location == loc) {
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                cout << "Completed and removed: " << loc << endl;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Location not found: " << loc << endl;
    }
    void moveForward() {
        if (current && current->next) {
            current = current->next;
            cout << "Moved forward to: " << current->location << endl;
        } else {
            cout << "No next delivery.\n";
        }
    }

    void moveBackward() {
        if (current && current->prev) {
            current = current->prev;
            cout << "Moved backward to: " << current->location << endl;
        } else {
            cout << "No previous delivery.\n";
        }
    }
    void swapConsecutive(string firstLoc) {
        Node* first = head;
        while (first && first->next) {
            if (first->location == firstLoc) {
                Node* second = first->next;

                // adjust previous node
                if (first->prev)
                    first->prev->next = second;
                else
                    head = second;

                // adjust next node
                if (second->next)
                    second->next->prev = first;
                else
                    tail = first;

                // swap links
                first->next = second->next;
                second->prev = first->prev;
                second->next = first;
                first->prev = second;

                cout << "Swapped: " << firstLoc << " <-> " << second->location << endl;
                return;
            }
            first = first->next;
        }
        cout << "Cannot swap: " << firstLoc << " not found or no next node.\n";
    }
    void calculateOptimalRoute() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp && temp->next) {
                if (temp->location > temp->next->location) {
                    swap(temp->location, temp->next->location);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
        cout << "Route reordered alphabetically (simple optimization).\n";
    }
    void showRoute() {
        cout << "\n--- Current Delivery Route ---\n";
        Node* temp = head;
        int i = 1;
        while (temp) {
            cout << i++ << ". " << temp->location;
            if (temp == current) cout << "  <-- current";
            cout << endl;
            temp = temp->next;
        }
        if (!head) cout << "No deliveries scheduled.\n";
    }
    ~DeliveryRoute() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};
int main() {
    DeliveryRoute route;

    route.addLocation("Lahore");
    route.addLocation("Karachi");
    route.addLocation("Islamabad");
    route.addLocation("Multan");

    route.showRoute();

    route.moveForward();  
    route.moveForward();  
    route.moveBackward(); 

    route.swapConsecutive("Karachi");
    route.showRoute();

    route.completeDelivery("Multan");
    route.showRoute();

    route.calculateOptimalRoute();
    route.showRoute();

    return 0;
}