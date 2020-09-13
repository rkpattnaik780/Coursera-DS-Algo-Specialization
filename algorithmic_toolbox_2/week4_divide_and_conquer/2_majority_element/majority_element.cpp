#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::sort;

int count(int arr[], int beg, int end, int ele){
  int occurence = 0;

  for(int i = beg; i <= end; i ++){
    if(arr[i] == ele) occurence++;
  }

  return occurence;
}

int get_majority_element(int arr[], int beg, int end){
  if(beg > end) return -1;
  if(beg == end) return arr[beg];
  int mid = (beg + (end - beg) / 2);

  int leftMajCount = get_majority_element(arr, beg, mid);
  int rightMajCount = get_majority_element(arr, mid + 1, end);

  if(leftMajCount == -1 && rightMajCount == -1){
    return -1;
  }
  else if(leftMajCount != -1 && rightMajCount == -1){
    if(count(arr, beg, end, leftMajCount) > (end - beg + 1) / 2){
      return leftMajCount;
    }
    return -1;
  }
  else if(leftMajCount == -1 && rightMajCount != -1){
    if(count(arr, beg, end, rightMajCount) > (end - beg + 1) / 2){
      return rightMajCount;
    }
    return -1;
  }
  else if(leftMajCount != -1 && rightMajCount != -1){
    if(count(arr, beg, end, rightMajCount) > (end - beg + 1) / 2){
      return rightMajCount;
      // return 1;
    }
    else if(count(arr, beg, end, leftMajCount) > (end - beg + 1) / 2){
      return  leftMajCount;
    }
    return -1;
  }

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  int ans = get_majority_element(arr, 0, n - 1);
  if(ans == -1) std::cout << 0 << '\n';
  else std::cout << 1 << '\n';
}
