#include <iostream>

int get_change(int m) {
  //write your code here
  int coin_count = 0;
   if(m >= 10){
     coin_count += m / 10;
     m = m % 10;
   }
   if(m >= 5){
     coin_count += m / 5;
     m = m % 5;
   }
   if(m >= 1){
     coin_count += m;
   }

  return coin_count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
