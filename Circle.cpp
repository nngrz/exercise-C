#include <iostream>

const double PI = 3.14;

class Circle {
    public:

        int r;

        double calculatePerimeter() {
            return 2 * PI * r;
        }
};

int main() {
    Circle c1;
    c1.r = 10;

    std::cout << "The Perimeter of c1 is " << c1.calculatePerimeter() << std::endl;
    return 0;
}
