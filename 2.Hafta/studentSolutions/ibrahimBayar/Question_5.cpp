// Silme sorusu:
// {100 ⇆ 150 ⇆ 200 ⇆ 250 ⇆ 300} listesinden 200 değerli düğümü silmek istiyorsun.
// • Hangi iki düğümün işaretçilerini nasıl güncellemen gerekir?
// • Listenin güncel hali nedir?

#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

Node* buildList(const int vals[], int count) {
    if (count == 0) return nullptr;
    Node* begin = new Node(vals[0]);
    Node* end = begin;
    for (int i = 1; i < count; ++i) {
        Node* n = new Node(vals[i]);
        end->next = n;
        n->prev = end;
        end = n;
    }
    return begin;
}

void DeleteNode(Node*& begin, int value) {

    Node* nodePtr = begin;

    while (nodePtr && nodePtr->data != value) {
        nodePtr = nodePtr->next;
    }

    if (nodePtr == nullptr) return;

    if (nodePtr->prev != nullptr) {
        nodePtr->prev->next = nodePtr->next;
    }
    else {
        begin = nodePtr->next;
    }

    if (nodePtr->next != nullptr) {
        nodePtr->next->prev = nodePtr->prev;
    }

    delete nodePtr;
}

int main() {
    int values[] = { 100, 150, 200, 250, 300 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildList(values, n);

    DeleteNode(begin, 200);

    for (Node* p = begin; p; p = p->next) {
        std::cout << p->data << " ";
    }
    std::cout << "\n";

    return 0;
}