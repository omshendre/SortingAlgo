#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum number to determine the number of digits
int findMax(vector<int>& arr) {
    int maxNum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    return maxNum;
}

// Using counting sort to sort the elements based on significant places
void countingSort(vector<int>& arr, int exp) {
    const int base = 10;
    int n = arr.size();
    
    vector<int> output(n);
    vector<int> count(base, 0);

    // Count occurrences of elements at each significant place
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % base]++;
    }

    // Update count to store the position of the next occurrence of each element
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing elements in their correct order
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int maxNum = findMax(arr);

    // Do counting sort for every digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Driver program to test the radixSort function
int main() {
    vector<int> arr;
    arr.push_back(170);
    arr.push_back(45);
    arr.push_back(75);
    arr.push_back(90);
    arr.push_back(802);
    arr.push_back(24);
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    radixSort(arr);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
