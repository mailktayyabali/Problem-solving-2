#include <iostream>
using namespace std;
void linearsearch(int arr[], int n, int key){
   int count = 0;
   for(int i = 0; i < n; i++) {
     if(arr[i] == key) { 
       cout << "The element is found at position " << i+1 <<endl;
       count = count + 1;
     }
   }
   if(count == 0) 
     cout << "The element is not present in the array" <<endl;
}
int main(){
   int key;
   
   int arr[8] = {90, 44, 1, 8, 4, 10,23, 67};
   int n = sizeof(arr)/sizeof(arr[0]);
   key = 23;
   linearsearch(arr, n, key);
   key = 88;
   linearsearch(arr, n, key);
}