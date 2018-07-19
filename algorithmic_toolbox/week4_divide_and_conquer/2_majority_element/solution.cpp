#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];


  int mid_index = (left + right - 1) / 2  + 1 ;
  int l_ele = get_majority_element(a , left , mid_index );
  int r_ele = get_majority_element(a , mid_index , right );

  int l_ele_count = 0 ; 
  for(int i = left ; i < right ; i ++ ){
    if(a[i] == l_ele)
      {l_ele_count ++ ;}
  }
  if ( l_ele_count > (right - left) / 2) return l_ele ;

  int r_ele_count = 0 ; 
  for(int i = left ; i < right ; i ++ ){
    if(a[i] == r_ele)
      {r_ele_count ++ ;}
    //r_ele_count ++ ;
  }
  if ( r_ele_count > (right - left) / 2) return r_ele ;
  //write your code here
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}