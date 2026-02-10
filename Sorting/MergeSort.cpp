/*
    File Name   : merge_sort.cpp
    Author      : Om Yadav
    Description : Implementation of Merge Sort using Divide and Conquer technique.
                  The array is recursively divided into halves and then merged
                  in sorted order.
    Time Complexity:
        Best Case    : O(n log n)
        Average Case : O(n log n)
        Worst Case   : O(n log n)
    Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
using namespace std;
void mergeTwoArrays(vector<int> &a, vector<int> &b, vector<int> &result) {        
    int i = 0, j = 0, k = 0;
    int n = a.size();
    int m = b.size();
    result.resize(n + m);
    while (i < n && j < m) {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }
    while (i < n)
        result[k++] = a[i++];

    while (j < m)
        result[k++] = b[j++];
}

void mergesort(vector<int> &v) {        
    int n = v.size();
    if (n <= 1) return;
    int n1 = n / 2;
    int n2 = n - n1;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++)
        a[i] = v[i];
    for (int i = 0; i < n2; i++)
        b[i] = v[i + n1];
    mergesort(a);
    mergesort(b);
    mergeTwoArrays(a, b, v);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Before sorting: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    mergesort(arr);
    cout << "After sorting: ";
    for (int x : arr)
        cout << x << " ";
    return 0;
}
