// Başlangıca ekleme sorusu:
// {20 ⇆ 25 ⇆ 30} çift yönlü bağlı listesine başa 15 değerini eklemek istiyorsun.
// • Hem next hem de prev işaretçileri nasıl ayarlanır?
// • Listenin yeni hali nedir?

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

Node* InsertBeginning(Node* begin, int value) {
    Node* node = new Node(value);
    node->next = begin;
    if (begin != nullptr) begin->prev = node;
    return node;
}

int main() {
    int values[] = { 20, 25, 30 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildList(values, n);

    begin = InsertBeginning(begin, 15);

    for (Node* p = begin; p; p = p->next) {
        std::cout << p->data << " ";
    }
    std::cout << "\n";

    return 0;
}