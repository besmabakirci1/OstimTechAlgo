// Başa ve sona ekleme sorusu:
// Dairesel bağlı liste {50 → 60 → 70 → 50 (baş)} verilmiş.
// • Başa 40 değerini ve sona 80 değerini eklemek için hangi işaretçiler nasıl değişir?

#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* buildCircularList(const int vals[], int count) {
    if (count == 0) return nullptr;
    Node* begin = new Node(vals[0]);
    Node* end = begin;
    for (int i = 1; i < count; ++i) {
        Node* n = new Node(vals[i]);
        end->next = n;
        n->prev = end;
        end = n;
    }
    end->next = begin;
    begin->prev = end;
    return begin;
}

Node* insertAtFront(Node* begin, int value) {
    Node* end = begin->prev;
    Node* node = new Node(value);
    node->next = begin;
    node->prev = end;
    end->next = node;
    begin->prev = node;
    return node;
}

Node* insertAtEnd(Node* begin, int value) {
    Node* end = begin->prev;
    Node* node = new Node(value);
    node->next = begin;
    node->prev = end;
    end->next = node;
    begin->prev = node;
    return begin;
}


void printCircular(Node* begin) {
    if (!begin) return;
    Node* nodePtr = begin;
    do {
        std::cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    } while (nodePtr != begin);
    std::cout << "\n";
}

int main() {
    int values[] = { 50, 60, 70 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildCircularList(values, n);

    begin = insertAtFront(begin, 40);
    begin = insertAtEnd(begin, 80);

    printCircular(begin);

    return 0;
}