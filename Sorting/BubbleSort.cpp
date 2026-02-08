// Bubble Sort
// Time Complexity:
//   Worst & Average: O(n^2)
//   Best (already sorted): O(n)
// Space Complexity: O(1)
// Stable: Yes

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {   // passes
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;  // array already sorted
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
