#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    int minidx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minidx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minidx] > arr[j])
            {
                minidx = j;
            }
        }
        if (minidx != i)
        {
            swap(arr[minidx], arr[i]);
        }
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
    cout << "Enter size of arr: ";
    cin >> n;
    int arr[n];
    cout << "Enter values in arr :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    cout << "Sorted Array " << endl;
    printArray(arr, n);
    return 0;
}
// Enter size of arr: 5
// Enter values in arr :12 11 13 5 6
