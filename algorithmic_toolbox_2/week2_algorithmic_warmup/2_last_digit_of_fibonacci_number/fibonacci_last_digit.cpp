#include <iostream>

// int get_fibonacci_last_digit_naive(int n) {
//     if (n <= 1)
//         return n;

//     int previous = 0;
//     int current  = 1;

//     for (int i = 0; i < n - 1; ++i) {
//         int tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % 10;
// }

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;
    // write your code here
    int t1 = 0, t2 = 1, temp;
    for ( int i = 0; i < n - 2; i ++ ) {
        temp = t2 % 10;
        t2 = t2 % 10 + t1 % 10;
        t1 = temp;
    }

    return (t1 + t2) % 10;
}

int main() {
    int n;
    std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    int c2 = get_fibonacci_last_digit_fast(n);
    // std::cout << c << '\n';
    std::cout << c2 << '\n';
}
