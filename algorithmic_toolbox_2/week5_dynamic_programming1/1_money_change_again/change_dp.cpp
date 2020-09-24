#include <iostream>

int get_change(int m) {
  int arr[m]; arr[0] = 0;
  for(int i = 1; i <= m; i ++){
    int coin_count = 100000;
    if(i >= 1 && coin_count > arr[i - 1] + 1){
      coin_count = arr[i - 1] + 1;
    }
    if(i >= 3 && coin_count > arr[i - 3] + 1){
      coin_count = arr[i - 3] + 1;
    }
    if(i >= 4 && coin_count > arr[i - 4] + 1){
      coin_count = arr[i - 4] + 1;
    }
    arr[i] = coin_count;
  }

  return arr[m];
  
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
