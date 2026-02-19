/*
Randomized Quick Sort : 

  Time Complexity:
    Best Case:    O(n log n)
    Average Case: O(n log n)
    Worst Case:   O(n^2)   (very rare due to random pivot)
  
  Space Complexity:
    O(log n)  -> Due to recursion stack (average case)
    O(n)      -> Worst case recursion depth
*/

#include <bits/stdc++.h>
using namespace std;

// Partition function (Lomuto Scheme)
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized Partition
int randomizedPartition(vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);  // move random pivot to end
    return partition(arr, low, high);
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    srand(time(0));  // seed for randomness

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
