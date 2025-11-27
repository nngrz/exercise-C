#include<iostream>
using namespace std;

int main() {
    int arr[5] = {300, 350, 200, 400, 250};
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    int maxNum = 0;

    for (int i = 0; i < arrLength; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
        cout << arr[i] << endl;
    }

    cout << "The biggest number is " << maxNum << endl;
}
