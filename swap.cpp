#include <iostream>
using namespace std;

int main() {

    int arr[] = {1, 3, 2, 5, 4};

    int arrLength = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrLength / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arrLength - 1 - i];
        arr[arrLength - 1 - i] = temp;
    }

    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << endl;
    }
}
