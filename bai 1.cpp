#include <iostream>
using namespace std;

struct Node {
    string name;
    int size;
    double time;
    Node* next;
};

void insertFile(Node*& head, string name, int size, double time) {
    Node* newNode = new Node{name, size, time, nullptr};

    if (head == nullptr || head->time > time) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->time < time) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int calculateTotalSize(Node* head) {
    int totalSize = 0;
    Node* temp = head;
    while (temp != nullptr) {
        totalSize += temp->size;
        temp = temp->next;
    }
    return totalSize;
}
