// Write a program to implement Merge Sort using both recursive and iterative methods.
// CODE BY ALMALE PRANAV CHANDRASHEKHAR
// ROLL NO. 25/DA/009

#include <iostream>
using namespace std;

// Merge two sorted parts
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSortRecursive(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Iterative Merge Sort
void mergeSortIterative(int arr[], int n)
{
    for (int size = 1; size < n; size *= 2)
    {
        for (int left = 0; left < n - 1; left += 2 * size)
        {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// Display array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    // Recursive method
    mergeSortRecursive(arr1, 0, n - 1);

    cout << "\nSorted array using Recursive Merge Sort: ";
    display(arr1, n);

    // Iterative method
    mergeSortIterative(arr2, n);

    cout << "Sorted array using Iterative Merge Sort: ";
    display(arr2, n);

    return 0;
}