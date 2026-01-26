#include <iostream>
#include <vector>

std::vector<int> operator-(const std::vector<int>& v, int n) {

    std::vector<int> result = v;
    for (int i = 0; i < n; i++) {
        result.pop_back();
    }

    return result;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::vector<int> u = v - 2;

    for (int x : u)
        std::cout << x << " ";
}
