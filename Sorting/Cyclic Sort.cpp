/*
Cyclic Sort  : 

Condition:
Array contains numbers from 1 to n (no duplicates)

Time Complexity:  O(n)
Space Complexity:  O(1)

Idea:
Place each number at its correct index.
Correct index of value x is (x - 1).
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void cyclicSort(vector<int> &arr) {
    int i = 0;
    while (i < arr.size()) {
        int correctIndex = arr[i] - 1;

        if (arr[i] != arr[correctIndex]) {
            swap(arr[i], arr[correctIndex]);
        } else {
            i++;
        }
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (1 to n): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cyclicSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
