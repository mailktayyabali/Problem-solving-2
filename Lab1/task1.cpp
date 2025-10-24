#include<iostream>
using namespace std;
int main(){
    int arr[5]={5, 10, 15, 20, 25};
    int n = 5;
    int max=arr[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
                
            }
            
        }
       
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}