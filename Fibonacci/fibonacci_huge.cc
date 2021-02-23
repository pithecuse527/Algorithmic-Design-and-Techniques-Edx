#include <iostream>

long long get_pisano_period(long long m) {
    // calculate the pisano period number
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;

        // if the last digit is 01, then the period is completed
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    // using the pisano period makes the calculation faster!

    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    // no need to think about every calculation as we just need to know the very last digit
    // using pisano period
    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
