// Write a program that prompts the user to input values for the binary tree and then performs the traversals: Inorder, preorder and postorder.
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
int main() {
    int n, val;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "The tree must have at least one node." << endl;
        return 0;
    }
    
    cout << "Enter the value for the root node: ";
    cin >> val;
    Node* root = new Node(val);
    
    for (int i = 1; i < n; ++i) {
        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> val;
        // For simplicity, we will insert nodes in a level order manner
        Node* newNode = new Node(val);
        Node* temp = root;
        while (true) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                break;
            } else if (temp->right == nullptr) {
                temp->right = newNode;
                break;
            } else {
                // Move to the next node in level order
                if (temp->left != nullptr) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;    
    
    return 0;
}
