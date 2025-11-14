#include <iostream>
using namespace std;

class TwoStacks {
private:
    int arr[50];
    int top1;
    int top2;
    int size;

public:
    TwoStacks() {
        size = 50;
        top1 = -1;
        top2 = size;
    }

    void push1(int value) {
        arr[++top1] = value;
    }

    void push2(int value) {
        arr[--top2] = value;
    }

    int getTop1Index() {
        return top1;
    }

    int getTop2Index() {
        return top2;
    }

    int getValue(int index) {
        return arr[index];
    }
};

int main() {
    TwoStacks ts;
    int n1, n2, value;

    cout << "How many values for Stack 1: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> value;
        ts.push1(value);
    }

    cout << "How many values for Stack 2: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> value;
        ts.push2(value);
    }

    int mergedSize = n1 + n2;
    int merged[50];

    int k = 0;
    for (int i = 0; i <= ts.getTop1Index(); i++) {
        merged[k++] = ts.getValue(i);
    }
    for (int i = ts.getTop2Index(); i < 50; i++) {
        merged[k++] = ts.getValue(i);
    }

    cout << "Merged Array: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}
