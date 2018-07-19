#include <iostream>

using namespace std;

void selectionSort(long long arr[], int n)
{
    int i, j, min_idx , temp ;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        // swap(&arr[min_idx], &arr[i]);
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main()
{
    int n;
    long long total = 0;
    cin >> n;
    long long ad1[n], ad2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ad1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ad2[i];
    }
    selectionSort(ad1,n);
    selectionSort(ad2,n);
    for (int i = 0; i < n; i++)
    {
        total += (long long) (ad1[i] * ad2[i]);
    }
    cout << total;
    return 0;
}