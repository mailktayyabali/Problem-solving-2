#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(nullptr) {}
};

class BrowserHistory {
private:
    Node* head;

public:
    BrowserHistory() : head(nullptr) {}

    // 1. Add new page to history
    void visitPage(const string& url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
        cout << "Visited: " << url << endl;
    }

    // 2. Navigate backward (show last few pages)
    void showHistory(int count = 5) {
        Node* temp = head;
        int i = 0;
        cout << "\n--- Browsing History ---\n";
        while (temp && i < count) {
            cout << i + 1 << ". " << temp->url << endl;
            temp = temp->next;
            i++;
        }
        if (i == 0) cout << "No history available.\n";
    }

    // 3. Remove entries by domain
    void removeDomain(const string& domain) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            if (temp->url.find(domain) != string::npos) {
                if (prev) prev->next = temp->next;
                else head = temp->next;

                delete temp;
                temp = (prev) ? prev->next : head;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        cout << "Removed all entries for domain: " << domain << endl;
    }

    // 4. Clear last N entries
    void clearRecent(int N) {
        if (!head || N <= 0) return;

        Node* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }

        if (N >= length) {
            while (head) {
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
            }
            cout << "Cleared all history.\n";
            return;
        }

        int stop = length - N - 1;
        temp = head;
        for (int i = 0; i < stop; ++i) temp = temp->next;

        Node* del = temp->next;
        temp->next = nullptr;

        while (del) {
            Node* toDelete = del;
            del = del->next;
            delete toDelete;
        }

        cout << "Cleared last " << N << " history entries.\n";
    }

    // 5. Detect circular reference
    bool detectCycle() {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    ~BrowserHistory() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// --- Main Driver ---
int main() {
    BrowserHistory history;

    history.visitPage("https://google.com");
    history.visitPage("https://openai.com");
    history.visitPage("https://youtube.com");
    history.visitPage("https://openai.com/blog");
    history.showHistory();

    history.removeDomain("openai");
    history.showHistory();

    history.clearRecent(2);
    history.showHistory();

    // Simulate circular reference
    // (For testing only)
    // history.head->next->next = history.head;

    cout << (history.detectCycle() ? "Cycle detected!" : "No cycle detected.") << endl;
}
