#include <iostream>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;  // take last digit
        n /= 10;        // remove last digit
    }
    return sum;
}

int main() {
    int num;
    int maxNum = 0;        // number with max digit sum
    int maxSum = -1;       // initial maximum digit sum

    while (true) {
        cout << "enter a natural number (0 if done): ";
        cin >> num;

        if (num == 0) break;   // stop when user enters 0

        int currentSum = digitSum(num);

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxNum = num;
        }
    }

    if (maxSum >= 0) {
        cout << "Max sum of digits was " << maxSum
             << " for " << maxNum << endl;
    } else {
        cout << "No numbers were entered." << endl;
    }

    return 0;
}
