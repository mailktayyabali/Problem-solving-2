#include<iostream>
using namespace std;
int main(){
    int sz;
    cout<<"Enter the size : ";
    cin>>sz;
    int *ptr;
    ptr = new int[sz];
    cout<<"Enter the numbers one by one\n";
    for(int i=0; i<sz; i++){
        cout<<"number "<<(i+1)<<": ";
        cin>>ptr[i];
    }
    cout<<"\nYour numbers are:\n";
    for(int i=0; i<sz; i++){
        cout<<ptr[i]<<" ";
    }
    delete[] ptr;
}