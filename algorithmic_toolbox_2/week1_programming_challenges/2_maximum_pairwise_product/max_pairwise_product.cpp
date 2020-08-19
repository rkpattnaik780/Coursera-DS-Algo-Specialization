#include <iostream>
#include <vector>
#include <algorithm>


// int MaxPairwiseProduct(const std::vector<int>& numbers) {
//     int max_product = 0;
//     int n = numbers.size();

//     for (int first = 0; first < n; ++first) {
//         for (int second = first + 1; second < n; ++second) {
//             max_product = std::max(max_product,
//                 numbers[first] * numbers[second]);
//         }
//     }

//     return max_product;
// }

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long b1 = 0, b2 = 0, temp;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        if(numbers[first] >= b1){
            temp = b1;
            b1 = numbers[first];
            b2 = temp;
        }
        if(numbers[first] < b1 && numbers[first] > b2){
            b2 = numbers[first];
        }
    }

    // std::cout << b1 << "\n";
    // std::cout << b2 << "\n";

    return b1 * b2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
