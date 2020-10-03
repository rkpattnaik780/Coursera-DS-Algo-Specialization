// Count the no of rotations in a circularly sorted array
#include<iostream>

using namespace std;

int findMinEle(int arr[], int beg, int end, int size){

  int mid = (beg + end) / 2;

  int next = (mid + 1) % size;
  int prev = (mid + size - 1) % size;

  if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
    return mid;
  }

  else if(arr[mid] < arr[end]){
    return findMinEle(arr, beg, end - 1, size);
  }

  else if(arr[mid] > arr[beg]){
    return findMinEle(arr, beg + 1, end, size);
  }

  return -1;

}

int main() {
  int n;

  cin >> n;

  int arr[n];

  for( int i = 0; i < n; i ++){
    cin >> arr[i];
  }

  int minEle = findMinEle(arr, 0, n - 1, n);

  cout << n - minEle;
  return 0;
}