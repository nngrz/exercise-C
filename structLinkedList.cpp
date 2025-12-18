#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int fun(const Node* head) {
    const Node* p = head;

    while (p->next->next != nullptr) {
        p = p->next;
    }

    return p->data + p->next->data;
}

int main() {
    Node n1{10, nullptr};
    Node n2{20, nullptr};
    Node n3{30, nullptr};

    n1.next = &n2;
    n2.next = &n3;

    cout << fun(&n1) << endl;
    return 0;
}
