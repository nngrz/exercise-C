#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 5, 4};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    int *start = arr;
    int *end = arr + arrLength - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    for (int x : arr) {
        cout << x << endl;
    }
}
