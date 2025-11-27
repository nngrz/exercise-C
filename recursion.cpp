#include <iostream>
using namespace std;

// Returns the greatest common divisor of two natural (positive, integral) numbers.
int gcdRec(int a, int b) {
    return (b == 0) ? a : gcdRec(b, a % b);
}

// Returns the sum of (decimal) digits of a given natural number
int sumDigits(int n) {
    return (n < 10) ? n : (n % 10) + sumDigits(n / 10);
}


// Returns the number of (decimal) digits of a given natural number
int numDigits(int n) {
    return (n < 10) ? 1 : 1 + numDigits(n / 10);
}

// printOddEven
void printOddEven(int n) {
    if (n <= 0) {
        return;
    }

    if (n % 2 != 0) {
        if (n <= 1) {
            cout << 1 << " ";
            return;
        }
    } else {
        if (n <= 2) {
            cout << 2 << " ";
            return;
        }
    }

    printOddEven(n - 2);
    cout << n << " ";
}

// hailstone
void hailstone(int n) {
    cout << n << " ";
    if (n == 1) {
        return;
    }

    if (n % 2 == 0) {
        hailstone(n / 2);
    } else {
        hailstone(3 * n + 1);
    }
}


int main() {
    std::cout << "gcdRec(12, 42) = " << gcdRec(12, 42) << std::endl
            << "gcdRec(12, 25) = " << gcdRec(12, 25) << std::endl;
    std::cout << "sumDigits(123) = " << sumDigits(123) << std::endl
            << "sumDigits(971) = " << sumDigits(971) << std::endl;
    std::cout << "numDigits(12345) = " << numDigits(12345) << std::endl
            << "numDigits(971) = " << numDigits(971) << std::endl;
    std::cout << "printOddEven(15): ";
    printOddEven(15);
    std::cout << std::endl;
    std::cout << "printOddEven(14): ";
    printOddEven(14);
    std::cout << std::endl;
    std::cout << "hailstone(13): ";
    hailstone(13);
    std::cout << std::endl;
}
