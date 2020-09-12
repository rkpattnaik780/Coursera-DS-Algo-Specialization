#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search_recursive(const vector<int> &a, int left, int right, int key){

  if(right < left) return - 1;

  int mid = left + (right - left)/2;

  if(a[mid] == key){
    return mid;
  }
  else if(a[mid] > key) return binary_search_recursive(a, left, mid - 1, key);
  else if(a[mid] < key) return binary_search_recursive(a, mid + 1, right, key);

  return - 1;
}

// int binary_search(const vector<int> &a, int x) {
//   int left = 0, right = (int)a.size();

//   int mid = left + (right - left)/2;

//   if(a[mid] == x) return mid;
//   else if(a[mid] > x) binary_search(a, left, mid - 1, x);
//   else if(a[mid] < x)
//   //write your code here
// }

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search_recursive(a, 0, n - 1 ,b[i]) << ' ';
  }
}
