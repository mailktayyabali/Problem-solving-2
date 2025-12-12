#include <iostream>
using namespace std;

// =========================
// Node for Cart Items
// =========================
class CartNode {
public:
    int productId;
    string name;
    int quantity;
    double price;
    CartNode* prev;
    CartNode* next;

    CartNode(int id, string n, int q, double p) {
        productId = id;
        name = n;
        quantity = q;
        price = p;
        prev = NULL;
        next = NULL;
    }
};

// =========================
// Doubly Linked List for Cart
// =========================
class ShoppingCart {
private:
    CartNode* head;
    CartNode* tail;

public:
    ShoppingCart() {
        head = NULL;
        tail = NULL;
    }

    // Add item to cart
    void addItem(int id, string name, int qty, double price) {
        CartNode* newNode = new CartNode(id, name, qty, price);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Update quantity of an item
    void updateQuantity(int id, int newQty) {
        CartNode* temp = head;

        while (temp != NULL) {
            if (temp->productId == id) {
                temp->quantity = newQty;
                cout << "Quantity updated.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Item not found!\n";
    }

    // Move an item to "save for later"
    CartNode* removeItem(int id) {
        CartNode* temp = head;

        while (temp != NULL) {
            if (temp->productId == id) {
                // If only one node
                if (temp == head && temp == tail) {
                    head = tail = NULL;
                }
                else if (temp == head) {
                    head = head->next;
                    head->prev = NULL;
                }
                else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                temp->next = temp->prev = NULL;
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }

    // Calculate total price
    double calculateTotal() {
        double total = 0;
        CartNode* temp = head;

        while (temp != NULL) {
            total += temp->price * temp->quantity;
            temp = temp->next;
        }

        return total;
    }

    // Display cart items
    void display() {
        if (head == NULL) {
            cout << "Cart is empty.\n";
            return;
        }

        CartNode* temp = head;
        while (temp != NULL) {
            cout << temp->productId << " - " << temp->name 
                 << " | Qty: " << temp->quantity 
                 << " | Price: " << temp->price << endl;
            temp = temp->next;
        }
    }
};

// =========================
// Recently Viewed Products List
// =========================
class ViewedNode {
public:
    int productId;
    string name;
    ViewedNode* prev;
    ViewedNode* next;

    ViewedNode(int id, string n) {
        productId = id;
        name = n;
        prev = NULL;
        next = NULL;
    }
};

class RecentlyViewed {
private:
    ViewedNode* head;

public:
    RecentlyViewed() {
        head = NULL;
    }

    // Add product to top (most recent)
    void addViewed(int id, string name) {
        ViewedNode* newNode = new ViewedNode(id, name);

        if (head != NULL)
            head->prev = newNode;

        newNode->next = head;
        head = newNode;
    }

    // Smart Recommendation — return last viewed 3 items
    void recommend() {
        cout << "Recommended based on recent viewing:\n";

        ViewedNode* temp = head;
        int count = 0;

        while (temp != NULL && count < 3) {
            cout << "- " << temp->name << endl;
            temp = temp->next;
            count++;
        }
    }
};

// =========================
// MAIN DRIVER
// =========================
int main() {
    ShoppingCart cart;
    RecentlyViewed viewed;

    // Add items
    cart.addItem(1, "Keyboard", 1, 2500);
    cart.addItem(2, "Mouse", 2, 1200);
    cart.addItem(3, "Headphones", 1, 3500);

    // User views some products
    viewed.addViewed(10, "Laptop");
    viewed.addViewed(11, "Gaming Chair");
    viewed.addViewed(12, "Monitor");

    cout << "Cart Items:\n";
    cart.display();

    // Update quantity
    cart.updateQuantity(2, 5);

    cout << "\nUpdated Cart:\n";
    cart.display();

    // Remove item to save for later
    CartNode* saved = cart.removeItem(1);

    if (saved != NULL) {
        cout << "\nSaved for later: " << saved->name << endl;
    }

    cout << "\nTotal Price: " << cart.calculateTotal() << endl;

    cout << "\n--- Recommendations ---\n";
    viewed.recommend();

    return 0;
}
