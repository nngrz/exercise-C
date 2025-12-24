#include <iostream>
#include <iterator>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* arrayToList(const T arr[], size_t size) {
    if (size == 0) return nullptr;

    Node<T>* head = new Node<T>{arr[0], nullptr};
    Node<T>* tail = head;

    for (size_t i = 1; i < size; ++i) {
        tail->next = new Node<T>{arr[i], nullptr};
        tail = tail->next;
    }

    return head;
}

template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p) {

    // remove bad nodes from the front
    while (head && p(head->data)) {
        std::cout << "DEL " << head->data << "; ";
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }

    if (!head) return;

    Node<T>* curr = head;
    while (curr->next) {
        if (p(curr->next->data)) {
            std::cout << "DEL " << curr->next->data << "; ";
            Node<T>* bad = curr->next;
            curr->next = bad->next;
            delete bad;
        } else {
            curr = curr->next;
        }
    }
}

template <typename T>
void showList(const Node<T>* head) {
    if (!head) {
        std::cout << "Empty list\n";
        return;
    }

    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

template <typename T>
void deleteList(Node<T>*& head) {
    while (head) {
        std::cout << "deleting " << head->data << "; ";
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    std::cout << "\n";
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    size_t size = std::size(arr);

    Node<int>* head = arrayToList(arr,size);
    showList(head);

    removeBad(head, [](int n) {return n%2 != 0;});
    std::cout << "\n";
    showList(head);

    removeBad(head, [](int n) {return n < 5;});
    std::cout << "\n";
    showList(head);

    removeBad(head, [](int n) {return n > 9;});
    std::cout << "\n";
    showList(head);

    deleteList(head);
    showList(head);
}
