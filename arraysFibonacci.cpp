#include<iostream>
using namespace std;

int main() {
    int k;
    cout<<"Enter k: "<<endl;
    cin>>k;

    if (k < 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    int array[105];
    array[0] = 0;
    array[1] = 1;

    for (int i = 2; i <= k; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }
    cout<<"Fibonacci(" <<k<< ") = " <<array[k]<<endl;
    return 0;
}
