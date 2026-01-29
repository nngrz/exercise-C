#include <iostream>
using namespace std;

class A {
    int num;

    public:
        A(int n) : num(n) {}
        int get() const {
            return num;
        }

    A operator+(const A& b) {
        return A(num + b.num);
    }

};

int main() {
    A a(2);
    A b(5);

    A c = a + b;
    cout << c.get() << endl;
}
