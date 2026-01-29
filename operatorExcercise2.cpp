#include <iostream>
using namespace std;

class B {
    int x;
public:
    B(int v) : x(v) {}

    friend B operator+ (const B& a, const B& b);

    friend ostream& operator<<(ostream& os, const B& obj);
};

B operator+(const B& a, const B& b) {
    return B(a.x + b.x);
}

ostream& operator<<(ostream& os, const B& obj) {
    os << obj.x;
    return os;
}

int main() {
    B a(2);
    B b(5);

    B c = a + b;
    cout << "a + b = " << c << endl;
}
