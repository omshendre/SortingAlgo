#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the size of arr : ";
    cin >> n;
    int arr[n];
    cout << "Enter the values in arr : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout<<"Sorted Array"<<endl;
    printArray(arr, n);
    return 0;
}

// Enter size of arr: 5
// Enter values in arr :12 11 13 5 6

// The worst-case time complexity of the Insertion sort is O(N^2)
// The average case time complexity of the Insertion sort is O(N^2)
// The time complexity of the best case is O(N).
