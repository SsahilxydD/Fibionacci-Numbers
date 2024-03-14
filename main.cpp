#include <iostream>
#include <vector>
#include <stdexcept>

// Function to compute Fibonacci series up to the nth Fibonacci number
std::vector<long long> fibonacci_series(int n) {
    // Check if n is within a reasonable range
    if (n < 0 || n > 1000) {
        throw std::invalid_argument("n must be a non-negative integer less than or equal to 1000");
    }

    std::vector<long long> series;
    series.reserve(n + 1); // Reserve space for n elements to avoid reallocation

    series.push_back(0); // Fibonacci of 0 is 0
    if (n == 0) return series;

    series.push_back(1); // Fibonacci of 1 is 1
    if (n == 1) return series;

    // Compute Fibonacci numbers up to the nth Fibonacci number
    for (int i = 2; i <= n; ++i) {
        long long fib = series[i - 1] + series[i - 2];
        series.push_back(fib);
    }
    return series;
}

// Function to print Fibonacci series
void print_fibonacci_series(const std::vector<long long>& series) {
    for (int i = 0; i < series.size(); ++i) {
        std::cout << "Fibonacci[" << i << "] = " << series[i] << std::endl;
    }
}

// Main function
int main() {
    try {
        int n = 100;
        std::vector<long long> fibonacci_series_result = fibonacci_series(n);

        std::cout << "Fibonacci series up to the " << n << "th Fibonacci number:" << std::endl;
        print_fibonacci_series(fibonacci_series_result);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
