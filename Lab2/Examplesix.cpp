#include <iostream>
using namespace std;
void selectionSortAlgo(int arr[], int n)
{
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if(arr[i] < arr[j])
            {
                min = arr[i];
                arr[i] = arr[j];
                arr[j] = min;
            }
        }
    }
}
void print(int *arr, int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {9,8,4,5,1, 3, 0, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSortAlgo(arr, n);
    cout << "Sorted array:"<<endl;
    print(arr, n);
    return 0;
}
