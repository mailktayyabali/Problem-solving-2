#include <iostream>
using namespace std;
int main() {
    int staticArray[5] = {1, 2, 3, 4, 5};


    cout << "Static Array Elements: ";
    for (int i = 0; i < 5; ++i) {
        cout << staticArray[i] << " ";
    }
    
    return 0;
}