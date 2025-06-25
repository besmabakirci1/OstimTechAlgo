// Ara Ekleme Sorusu
// Bir tek yönlü bağlı liste {3 → 7 → 12 → 18} verilmiştir.
// 12 düğümünün sonrasına 15 değerini eklemek istiyorsun.
// • Hangi düğümlerin işaretçileri değişecek?
// • Bunu yaparken listeyi baştan taramaya gerek var mı?

#include <iostream>

struct Node {
	int data;
	Node* next;
	Node(int x): data(x), next(nullptr) {}
};

Node* buildList(const int vals[], int count) {
    Node* head = nullptr;
    Node* end = nullptr;
    for (int i = 0; i < count; ++i) {
        Node* node = new Node(vals[i]);
        if (!head) {
            head = end = node;
        }
        else {
            end->next = node;
            end = node;
        }
    }
    return head;
}

void InsertAfter(Node* nodeBefore, int value) {
    if (nodeBefore == nullptr) return;
    Node* newNode = new Node(value);
    newNode->next = nodeBefore->next;
    nodeBefore->next = newNode;
}

int main() {
    int values[] = { 3, 7, 12, 18 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildList(values, n);

    Node* p = begin;
    while (p != nullptr && p->data != 12) {
        p = p->next;
    }

    InsertAfter(p, 15);

    for (Node* current = begin; current; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << "\n";

    return 0;
}