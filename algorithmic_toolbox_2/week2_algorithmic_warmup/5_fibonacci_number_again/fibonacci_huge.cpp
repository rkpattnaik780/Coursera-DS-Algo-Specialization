#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


int pasino_period(int m) {
    int a = 0, b = 1, c = 1;
    int i = 1;
    while(true){
        i ++;
        int temp = c;
        a = b % m;
        b = c;
        c = (a + b) % m;
        if(b == 0 && c == 1) break;
    }
    return i;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long t = m;
    m = pasino_period(m);
    // std::cout << m << '\n';
    n = n % m;
    // std::cout << n << '\n';

    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current % t;
        current = (tmp_previous + current) % t;
    }

    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    // std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    std::cout << pasino_period(10) << '\n';
    // std::cout << get_pa(m) << '\n';
}
