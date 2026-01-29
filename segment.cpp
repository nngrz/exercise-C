#include <iostream>
#include <algorithm>

class Segment {
    double A, B;

public:
    Segment(double a, double b) : A(std::min(a, b)), B(std::max(a, b)) {}

    double left() const {
        return A;
    }

    double right() const {
        return B;
    }

    friend Segment operator*(double d, const Segment& s) {
        return Segment(d * s.A, d * s.B);
    }

    friend Segment operator*(const Segment& s, double d) {
        return d * s;
    }

    friend Segment operator/(const Segment& s, double d) {
        return Segment(s.A / d, s.B / d);
    }

    friend Segment operator+(const Segment& s, double d) {
        return Segment(s.A + d, s.B + d);
    }

    friend Segment operator+(double d, const Segment& s) {
        return s + d;
    }

    friend Segment operator-(const Segment& s, double d) {
        return Segment(s.A - d, s.B - d);
    }

    friend Segment operator+(const Segment& s1, const Segment& s2) {
        return Segment(
            std::min(s1.A, s2.A),
            std::max(s1.B, s2.B)
        );
    }

    bool operator()(double d) const {
        return d >= A && d <= B;
    }

    friend std::ostream& operator<<(std::ostream& os, const Segment& s) {
        os << "[" << s.A << "," << s.B << "]";
        return os;
    }
};

int main() {
    using std::cout; using std::endl;
    Segment seg{2,3}, s = 1 + 2*((seg-2)/2+seg)/3;
    cout << s << endl << std::boolalpha;
    for (double x = 0.5; x < 4; x += 1)
    cout << "x=" << x << ": " << s(x) << endl;
}
