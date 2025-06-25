// Ters çevirme sorusu:
// {4 → 6 → 8 → 10 → 12} listesini ters çevirmek istiyorsun.
// • Bunu iteratif yöntemle yaparsan, adım adım hangi işaretçiler nasıl değişir?

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

Node* ReverseList(Node* begin) {
    Node* prev = nullptr;
    Node* curr = begin;
    Node* next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    int values[] = { 4, 6, 8, 10, 12 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildList(values, n);


    begin = ReverseList(begin);

    for (Node* current = begin; current; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << "\n";

    return 0;
}