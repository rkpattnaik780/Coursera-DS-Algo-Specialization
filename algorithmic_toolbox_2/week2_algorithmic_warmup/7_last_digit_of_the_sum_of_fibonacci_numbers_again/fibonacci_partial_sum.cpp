#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_huge_fast(long long n) {

    if( n <= 1) return n;

    n = (n + 2) % 60;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current % 10;
        current = (tmp_previous + current) % 10;
    }
    // std::cout << "current " << current << std::endl;
    if (current == 0) return 9;
    return current - 1;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to){
    // if( from == to ) return get_fibonacci_huge_fast(from);

    if( from <= 1) return get_fibonacci_huge_fast(to);
    // else if(from == 1) {
    //     // std::cout << get_fibonacci_huge_fast(to) << '\n';
    //     return get_fibonacci_huge_fast(to) - 1;
    // }
    else {
        int ans = get_fibonacci_huge_fast(to) - get_fibonacci_huge_fast(from - 1);
        if( ans < 0 ) return (ans + 10);
        return ans;
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
