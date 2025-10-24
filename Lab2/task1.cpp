#include<iostream>
using namespace std;
int main(){
    int sum = 0;
    int arr[5]={5, 10, 15, 20, 25};
    int n = 5;
    for(int i=0;i<n;i++){
        sum += arr[i];  
    }
    cout<<"sum of arr is "<<sum;
}