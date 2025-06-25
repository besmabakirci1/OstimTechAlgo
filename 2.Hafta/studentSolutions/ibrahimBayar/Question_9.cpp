// Silme sorusu:
// Dairesel bağlı listede {30 → 40 → 50 → 60 → 30 (baş)} içinde 50 değerli düğümü silmek istiyorsun.
// • Hem önceki hem sonraki düğümlerin işaretçileri nasıl etkilenir?
// • Listenin yeni yapısı ne olur?

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

Node* deleteNode(Node* begin, int value) {
    if (begin == nullptr) return nullptr;

    Node* nodePtr = begin;
    bool found = false;

    do {
        if (nodePtr->data == value) { 
            found = true; 
            break; 
        }

        nodePtr = nodePtr->next;
    } while (nodePtr != begin);
    if (!found) return begin;

    if (nodePtr->next == nodePtr) {
        delete nodePtr;
        return nullptr;
    }

    nodePtr->prev->next = nodePtr->next;
    nodePtr->next->prev = nodePtr->prev;

    if (nodePtr == begin) begin = nodePtr->next;
    delete nodePtr;
    return begin;
}

void printCircular(Node* begin) {
    if (begin == nullptr) return;
    Node* nodePtr = begin;
    do {
        std::cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    } while (nodePtr != begin);
    std::cout << "\n";
}

int main() {
    int values[] = { 30, 40, 50, 60, 70 };
    int n = sizeof(values) / sizeof(values[0]);

    Node* begin = buildCircularList(values, n);

    begin = deleteNode(begin, 50);

    printCircular(begin);

    return 0;
}