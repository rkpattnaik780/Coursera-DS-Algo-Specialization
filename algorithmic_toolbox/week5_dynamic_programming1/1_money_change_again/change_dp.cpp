#include <vector>
#include <iostream>

using std::vector;
using namespace std;

int get_change(int m) {
    vector<int> min_coins(m + 1);
    int num_coins ;
    min_coins[0] = 0 ; 
    vector<int> denominations{ 1,3,4};
    for(int i = 1 ; i <= m ; i ++){
      min_coins[i] = 1000 ;
      for(int j = 0 ; j < 3 ; j ++){
        if ( i >= denominations[j]){
          num_coins = min_coins[i - denominations[j]] + 1 ;
          if(num_coins < min_coins[i]){
            min_coins[i] = num_coins;
          }
        }
      }
    }
    return min_coins[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
