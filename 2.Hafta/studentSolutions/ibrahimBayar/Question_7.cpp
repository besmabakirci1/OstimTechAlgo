// Sonsuz döngü tespiti sorusu:
// Bir dairesel bağlı liste {8 → 16 → 24 → 8 (baş)} oluşturulmuş.
// • Listenin elemanlarını yazdırmak istediğinde, sonsuz döngüye girmemek için algoritmanı nasıl tasarlarsın?

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

void printCircular(Node* begin) {
    if (!begin) return;
    Node* p = begin;
    do { // This does print the begin only once.
        std::cout << p->data << " ";
        p = p->next;
    } while (p != begin);
    std::cout << "\n";
}

int main() {
    int values[] = { 8, 16, 24 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildCircularList(values, n);

    printCircular(begin);

    return 0;
}