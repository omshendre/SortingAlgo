#include <iostream>
using namespace std;

// heapify OR maxHeap
void maxHeap(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;  // Corrected the index calculation for left child
    int r = 2 * i + 2;  // Corrected the index calculation for right child

    if (l < n && arr[l] > arr[largest]) // Corrected the comparison to find the largest
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) // Corrected the comparison to find the largest
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeap(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeap(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) // Changed the loop condition to i > 0
    {
        swap(arr[0], arr[i]);
        maxHeap(arr, i, 0);  // Passed i as the new size of the heap
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
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapSort(arr, n);
    cout << "Sorted Array" << endl;
    printArray(arr, n);
    return 0;
}
// 10 20 50 30 35 15