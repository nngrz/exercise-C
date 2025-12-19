#include <iostream>
using namespace std;

class A {
    int num;
public:
    A(int n) : num(n) {}

    int getNum() const { return num; }

    friend A operator+(const A& lhs, const A& rhs);
};

A operator+(const A& lhs, const A& rhs) {
    return A(lhs.num + rhs.num);
}

int main() {
    A a(10), b(7);
    A c = a + b;

    cout << "a = " << a.getNum() << "\n";
    cout << "b = " << b.getNum() << "\n";
    cout << "a + b = " << c.getNum() << "\n";
}
