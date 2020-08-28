#include <iostream>
#include <vector>

using std::vector;
using std::swap;

void selectionSort(int weights[], int values[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        // if (arr[j] < arr[min_idx])  
        if(((double) values[j])/ weights[j] > ( (double) values[min_idx])/ weights[min_idx])
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        int temp1 = values[i];
        values[i] = values[min_idx];
        values[min_idx] = temp1;

        // swap(&values[min_idx], &values[i]);
        // swap(&weights[min_idx], &weights[i]);

        int temp2 = weights[i];
        weights[i] = weights[min_idx];
        weights[min_idx] = temp2;
    }  
}  

double get_optimal_value(int weights[], int values[], int capacity, int size) {
  double value = 0.0;

  selectionSort(weights, values, size);

  // std::cout << "0 - " << weights[0] << std::endl;
  // std::cout << "1 - " << weights[1] << std::endl;
  // std::cout << "2 - " << weights[2] << std::endl;

  for(int i = 0; i < size && capacity > 0; i ++){
    if(weights[i] <= capacity){
      capacity -= weights[i];
      value += values[i];
    }
    else{
      value += values[i] * ((float) capacity )/weights[i];
      capacity = 0;
    }
    // std::cout << value << std::endl;
  }

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  int values[n];
  int weights[n];

  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(weights, values, capacity, n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
