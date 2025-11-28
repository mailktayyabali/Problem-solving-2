#include <iostream>
#include <string>
using namespace std;
struct Node {
    string text;
    Node* prev;
    Node* next;

    Node(string t) {
        text = t;
        prev = next = nullptr;
    }
};
class TextEditor {
private:
    Node* current;   
    Node* head;      
    int historySize; 
    const int MAX_HISTORY = 5; 
public:
    TextEditor() {
        current = head = nullptr;
        historySize = 0;
    }
    void saveState(string newText) {
        if (current && current->next) {
            clearRedo();
        }
        Node* newNode = new Node(newText);
        if (!head) {
            head = current = newNode;
        } else {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        historySize++;
        limitHistory();
        cout << "Saved new version: \"" << newText << "\"\n";
    }
    void undo() {
        if (current && current->prev) {
            current = current->prev;
            cout << "Undo -> Current text: \"" << current->text << "\"\n";
        } else {
            cout << "No more undo steps available.\n";
        }
    }
    void redo() {
        if (current && current->next) {
            current = current->next;
            cout << "Redo -> Current text: \"" << current->text << "\"\n";
        } else {
            cout << "No more redo steps available.\n";
        }
    }
    void showCurrent() {
        if (current)
            cout << "Current document: \"" << current->text << "\"\n";
        else
            cout << "Document is empty.\n";
    }
    void clearRedo() {
        Node* temp = current->next;
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
            historySize--;
        }
        current->next = nullptr;
    }
    void limitHistory() {
        while (historySize > MAX_HISTORY) {
            Node* oldHead = head;
            head = head->next;
            head->prev = nullptr;
            delete oldHead;
            historySize--;
        }
    }
    ~TextEditor() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};
int main() {
    TextEditor editor;

    editor.saveState("Hello");
    editor.saveState("Hello World");
    editor.saveState("Hello World!");
    editor.undo();
    editor.undo();
    editor.saveState("Hi again"); // clears redo
    editor.saveState("Hi again, version 2");
    editor.saveState("Hi again, version 3");
    editor.saveState("Hi again, version 4");
    editor.showCurrent();
    editor.undo();
    editor.redo();

    return 0;
}
