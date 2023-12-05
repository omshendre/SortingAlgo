#include <iostream>
#include <vector>
using namespace std;

// // Function to merge two sorted arrays into one sorted array
// void merge(vector<int> &arr, int low, int mid, int high)
// {
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;

//     // Merge the two sorted subarrays into a temporary vector
//     while (left <= mid && right <= high)
//     {
//         if (arr[left] <= arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // Copy any remaining elements from the left subarray
//     while (left <= mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     // Copy any remaining elements from the right subarray
//     while (right <= high)
//     {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // Copy the sorted elements from the temporary vector back to the original array
//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = temp[i - low]; // Use i - low to index temp correctly
//     }
// }

// // Function to recursively sort the array using merge sort
// void mergeSort(vector<int> &arr, int low, int high)
// {
//     if (low < high)
//     {
//         int mid = (low + high) / 2;
//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid + 1, high);
//         merge(arr, low, mid, high);
//     }
// }
void merge(vector<int> &a, int l, int q, int r)
{
    int n1 = q - l + 1;
    int n2 = r - q;
    vector<int> L(n1 + 1); 
    vector<int> R(n2 + 1); 
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[i + l];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j]; 
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = l; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int q = (l + r) / 2;
        mergeSort(a, l, q);
        mergeSort(a, q + 1, r);
        merge(a, l, q, r);
    }
}

// Function to print the elements of the array
void printArray(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    printArray(n, arr);
    return 0;
}
