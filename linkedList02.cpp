#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void fun(Node* head, int d) {
    Node* curr = head;
    int pos = 1;

    while (curr != nullptr) {
        if (pos % 2 == 1) {
            curr->data += d;
        }

        curr = curr->next;
        pos++;
    }
}

int main() {
    Node n4 = {4, nullptr};
    Node n3 = {3, &n4};
    Node n2 = {2, &n3};
    Node n1 = {1, &n2};

    Node* head = &n1;

    fun(head, 10);

    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}
