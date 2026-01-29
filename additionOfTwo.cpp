#include <iostream>
using namespace std;

class A {
    int num;

    public:
    A(int n) : num(n) {}
    int get() const {
        return num;
    }

    friend A operator+(const A& a, const A& b);
};

A operator+(const A& a, const A& b) {
    return A(a.num + b.num);
}

int main() {
    A a(2);
    A b(3);

    A c = a + b;
    cout << c.get() << endl;
}
