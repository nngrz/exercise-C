#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int fun(const Node* head) {
    const Node* prev = nullptr;
    const Node* curr = head;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    return prev->data + curr->data;
}

int main() {

    Node n4 = {4, nullptr};
    Node n3 = {3, &n4};
    Node n2 = {2, &n3};
    Node n1 = {1, &n2};

    Node* head = &n1;

    int result = fun(head);

    cout << "Sum of last two elements = " << result << endl;

    return 0;
}
