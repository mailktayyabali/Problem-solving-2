#include<iostream>
using namespace std;
int main(){
    int arr[5]={6,6, 15, 20, 25};
    int n = 5;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]+arr[i]==12){
            cout << arr[j]<<" " << arr[i];                
            }
            
        }
       
    }    
}