// Geriye doğru dolaşım sorusu:
// Bir çift yönlü bağlı listenin son düğümünden başlayarak başa kadar tüm elemanları ekrana bastırmak istiyorsun.
// • Bu işlem için nasıl bir döngü kullanırsın?
// • Neden çift yönlü bağlı liste bu işlemi kolaylaştırır?

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

void PrintBackwards(Node* begin) {
    Node* end = begin;

    while (end->next) {
        end = end->next;
    }

    for (Node* p = end; p; p = p->prev) {
        std::cout << p->data << " ";
    }
    std::cout << "\n";
}

int main() {
    int values[] = { 100, 150, 200, 250, 300 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildList(values, n);

    PrintBackwards(begin);

    return 0;
}