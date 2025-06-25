// Silme sorusu:
// Bir tek yönlü bağlı liste {5 → 9 → 13 → 22 → 27} içinde 22 değerli düğümü silmek istiyorsun.
// • Hangi düğümü bulman gerekiyor?
// • Silme işleminden sonra liste nasıl olur?

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* buildList(const int vals[], int count) {
    Node* begin = nullptr;
    Node* end = nullptr;
    for (int i = 0; i < count; ++i) {
        Node* node = new Node(vals[i]);
        if (!begin) {
            begin = end = node;
        }
        else {
            end->next = node;
            end = node;
        }
    }
    return begin;
}

void DeleteNode(Node*& begin, int value) {
    if (!begin) return;

    if (begin->data == value) {
        Node* tmp = begin;
        begin = begin->next;
        delete tmp;
        return;
    }

    Node* before = begin;
    while (before->next != nullptr && before->next->data != value) {
        before = before->next;
    }

    if (before->next != nullptr) {
        Node* toDelete = before->next;
        before->next = toDelete->next;
        delete toDelete;
    }
}


int main() {
    int values[] = { 5, 9, 13, 22, 27 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildList(values, n);


    DeleteNode(begin, 22);

    for (Node* current = begin; current; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << "\n";

    return 0;
}