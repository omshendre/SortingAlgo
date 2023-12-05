#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swaped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                swaped = true;
            }
        }
        if (!swaped)
        {
            break;
        }
    }
    cout << "Bubble :";
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
        }
        if (minInd != i)
        {
            swap(arr[i], arr[minInd]);
        }
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1 + 1];
    int R[n2 + 1];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for (int k = l; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void maxHeap(int arr[], int size, int node)
{
    int largest = node;
    int l = 2 * node + 1;
    int r = 2 * node + 2;
    if (l < size && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (node != largest)
    {
        swap(arr[largest], arr[node]);
        maxHeap(arr, size, largest);
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
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeap(arr, i, 0);
    }
}
int partition(int arr[], int l, int r)
{
    int p = arr[r];
    int i = l - 1;
    for (int j = 1; j < r ; j++)
    {
        if (arr[j] < p)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int q = partition(arr, l, r);
        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
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
    quickSort(arr, 0,n-1);
    printArray(arr, n);
    return 0;
}