#include <iostream>
#include <string>
#include <vector>

template <typename T>
void pointerSort(const std::vector<T>& arr,
                std::vector<const T*>& ptrs) {
    std::size_t len = arr.size();

    for (std::size_t i = 0; i < len; i++) {
        ptrs[i] = &arr[i];
    }

    for (std::size_t i = 0; i < len - 1; ++i) {
        for (std::size_t j = 0; j < len - i - 1; ++j) {
            if (*ptrs[j] > *ptrs[j + 1]) {
                const T* temp = ptrs[j];
                ptrs[j] = ptrs[j + 1];
                ptrs[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArrPointer(const std::vector<const T*>& parr) {
    std::cout << "[ ";
    for (const T* p: parr) {
        std::cout << *p << " ";
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<int> arri{-3, 4, 8, 3};
    std::vector<const int*> parri(arri.size());

    pointerSort(arri, parri);
    printArrPointer(parri);

    std::vector<std::string> arrs{"Ela", "Ula", "Ala", "Ola"};
    std::vector<const std::string*> parrs(arrs.size());

    pointerSort(arrs, parrs);
    printArrPointer(parrs);
}
