#include<iostream>
using namespace std;

int main() {

    int numberOfStudent;
    int a[90];
    cin>>numberOfStudent;

    int sum = 0;
    int studentCount = 0;

    for (int i = 0; i < 10; i++) {
        cin>>a[i];
        sum += a[i];
    }

    double avg = sum * 1.0 / numberOfStudent; // average score

    for (int i = 0; i < 10; i++) {
        if (a[i] < avg) {
            studentCount++;
        }
    }

    cout<<studentCount<<endl;
}
