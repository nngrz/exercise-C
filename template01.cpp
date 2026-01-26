#include <iostream>

template <typename T>
T* maxElement(T* arr, int size) {
    T* maxPtr = &arr[0];

    for (int i = 0; i < size; i++) {
        if (*maxPtr < arr[i]) {
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

int main() {
    int a[] = {3, 7, 2, 9, 5};
    int* p = maxElement(a, 5);
    std::cout << *p << std::endl;
}
