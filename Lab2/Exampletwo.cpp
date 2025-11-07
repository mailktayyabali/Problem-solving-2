#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the dynamic array: ";
    cin >> size;
    int* dynamicArray = new int[size];
    cout << "Enter elements for the dynamic array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Enter Element at index " << i+1 << ": ";
        cin >> dynamicArray[i];
    }
    cout << "\n===================================";
    cout << "\nDynamic Array Elements: ";
    for (int i = 0; i < size; ++i) {
        cout << dynamicArray[i] << " ";
    }
    delete[] dynamicArray;
    return 0;
}
