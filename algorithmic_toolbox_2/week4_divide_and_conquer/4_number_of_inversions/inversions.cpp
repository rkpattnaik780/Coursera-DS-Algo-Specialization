#include <iostream>
#include <vector>

using namespace std;

int merge(int a[], int beg, int end){

    int inv_count = 0;

    int arr[end - beg + 1];
    int i = beg, k = 0;
    int mid = beg + (end - beg) / 2;
    int j = mid + 1;

    while(i <= mid && j <= end){
        if(a[i] > a[j]){
            arr[k++] = a[j++];
            inv_count += (mid - i + 1);
        } else {
            arr[k++] = a[i++];
        }
    }

    while(i <= mid){
        arr[k++] = a[i++];
    }

    while(j <= end){
        arr[k++] = a[j++];
    }

    for(int i = 0; i < end - beg + 1; i ++){
        a[beg + i] = arr[i];
    }

    return inv_count;
}

int mergeSort(int arr[], int beg, int end){

    int inv_count = 0;
    
    if(beg < end){
        int mid = beg + (end - beg) / 2;

        inv_count += mergeSort(arr, beg, mid);
        inv_count += mergeSort(arr, mid+1, end);


        inv_count += merge(arr, beg, end);
    }

    return inv_count;
}

int main(){

    int n;

    cin >> n;

    int inputArray[n];

    for(int i = 0; i < n; i ++){
        cin >> inputArray[i];
    }

    // cout << merge(inputArray, 0, n - 1) << endl;

    cout << mergeSort(inputArray, 0, n - 1) << endl;

    return 0;
}