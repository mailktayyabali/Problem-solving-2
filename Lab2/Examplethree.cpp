#include <iostream>
using namespace std;
void linear_search(int a[], int n, int key){
   int count = 0;
   for(int i = 0; i < n; i++) {
     if(a[i] == key) { 
       cout << "The element is found at position " << i+1 <<endl;
       count = count + 1;
     }
   }
   if(count == 0) 
     cout << "The element is not present in the array" <<endl;
}
int main(){
   int key;
   
   int a[10] = {12, 44, 32, 18, 4, 10};
   int n = sizeof(a) / sizeof(a[0]);
   key = 18;
   linear_search(a, n, key);
   key = 23;
   linear_search(a, n, key);
   return 0;
}
