#include <iostream>
using namespace std;

// ===============================
// File/Folder NODE
// ===============================
struct Node {
    char name[50];
    bool isDirectory;
    Node* child;     // First file/folder inside this directory
    Node* next;      // Next file/folder at same directory level
    Node* parent;    // To move back
};

// ===============================
// Utility: Copy string manually
// ===============================
void copyString(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// ===============================
// FILE SYSTEM CLASS
// ===============================
class FileSystem {
private:
    Node* root;
    Node* current;

public:
    FileSystem() {
        root = createNode("root", true, NULL);
        current = root;
    }

    // ---------------------------
    // Create a new node
    // ---------------------------
    Node* createNode(const char name[], bool isDirectory, Node* parent) {
        Node* n = new Node();
        copyString(n->name, name);
        n->isDirectory = isDirectory;
        n->child = NULL;
        n->next = NULL;
        n->parent = parent;
        return n;
    }

    // ---------------------------
    // Add file/folder
    // ---------------------------
    void addItem(const char name[], bool isDirectory) {
        Node* newNode = createNode(name, isDirectory, current);

        // Insert at beginning of linked list (O(1))
        newNode->next = current->child;
        current->child = newNode;

        cout << name << " added successfully.\n";
    }

    // ---------------------------
    // List all items in directory
    // ---------------------------
    void listItems() {
        cout << "\nListing inside: " << current->name << "\n";
        Node* temp = current->child;

        if (!temp) {
            cout << "(empty)\n";
            return;
        }

        while (temp != NULL) {
            cout << (temp->isDirectory ? "[DIR] " : "[FILE] ");
            cout << temp->name << "\n";
            temp = temp->next;
        }
    }

    // ---------------------------
    // Navigate into subdirectory
    // ---------------------------
    void goToDir(const char name[]) {
        Node* temp = current->child;

        while (temp != NULL) {
            if (temp->isDirectory) {
                // Manual string compare
                int i = 0;
                bool match = true;
                while (name[i] != '\0' || temp->name[i] != '\0') {
                    if (name[i] != temp->name[i]) {
                        match = false;
                        break;
                    }
                    i++;
                }

                if (match) {
                    current = temp;
                    cout << "Moved into " << name << "\n";
                    return;
                }
            }
            temp = temp->next;
        }

        cout << "Directory not found.\n";
    }

    // ---------------------------
    // Move back to parent
    // ---------------------------
    void goBack() {
        if (current->parent != NULL) {
            current = current->parent;
            cout << "Returned to " << current->name << "\n";
        } else {
            cout << "Already at root.\n";
        }
    }

    // ---------------------------
    // Search file by name/extension
    // ---------------------------
    void search(const char name[]) {
        cout << "\nSearching for " << name << "...\n";
        searchRecursive(root, name);
    }

    void searchRecursive(Node* dir, const char name[]) {
        if (!dir) return;

        Node* temp = dir->child;

        while (temp != NULL) {
            // Manual string compare
            int i = 0;
            bool match = true;
            while (name[i] != '\0' || temp->name[i] != '\0') {
                if (name[i] != temp->name[i]) {
                    match = false;
                    break;
                }
                i++;
            }

            if (match) {
                cout << (temp->isDirectory ? "[DIR] " : "[FILE] ");
                cout << temp->name << " found inside " << dir->name << "\n";
            }

            if (temp->isDirectory) {
                searchRecursive(temp, name);
            }

            temp = temp->next;
        }
    }

    // ---------------------------
    // Detect duplicate file names
    // ---------------------------
    void duplicateCheck() {
        Node* temp1 = current->child;

        while (temp1 != NULL) {
            Node* temp2 = temp1->next;

            while (temp2 != NULL) {
                bool match = true;
                int i = 0;

                // Manual string compare
                while (temp1->name[i] != '\0' || temp2->name[i] != '\0') {
                    if (temp1->name[i] != temp2->name[i]) {
                        match = false;
                        break;
                    }
                    i++;
                }

                if (match) {
                    cout << "Duplicate found: " << temp1->name << "\n";
                }

                temp2 = temp2->next;
            }

            temp1 = temp1->next;
        }
    }
};

// ===============================
// MAIN (DEMO)
// ===============================
int main() {
    FileSystem fs;

    fs.addItem("docs", true);
    fs.addItem("image.png", false);
    fs.addItem("notes.txt", false);

    fs.listItems();

    fs.goToDir("docs");
    fs.addItem("resume.pdf", false);
    fs.addItem("project", true);

    fs.listItems();

    fs.goBack();
    fs.search("notes.txt");

    fs.duplicateCheck();

    return 0;
}
