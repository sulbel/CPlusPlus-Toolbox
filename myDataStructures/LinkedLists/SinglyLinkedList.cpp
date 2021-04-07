#include <iostream>
#include <vector>

using namespace std;

class SinglyLinkedList {
    private:
        struct node {
            int data;
            node* next;
        };
    
    private:
        node* head;
        node* tail;

    public:
        SinglyLinkedList();
        void append(int);
        void prepend(int);
        bool isEmpty();
        int front();
        int back();
        void printList();
};

SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
    tail = NULL;
}

bool SinglyLinkedList::isEmpty() {
    return (head == NULL);
}

int SinglyLinkedList::front() {
    return (head->data);
}

int SinglyLinkedList::back() {
    return (tail->data);
}

void SinglyLinkedList::printList() {
    node* trav = head;
    while (trav != NULL) {
        cout << "[" << trav->data << "] -> ";
        trav = trav->next;
    }
    cout << "NULL" << endl;
}

void SinglyLinkedList::append(int val) {
    node* newNode = new node;
    newNode->data = val;
    if(isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    newNode->next = NULL;
}

int main() {
    SinglyLinkedList list;
    //cout << "Result of isEmpty() : " << list.isEmpty() << endl;
    for (int i = 1; i < 5; i++) {
        list.append(i);
    }
    list.printList();
    return 0;
}

