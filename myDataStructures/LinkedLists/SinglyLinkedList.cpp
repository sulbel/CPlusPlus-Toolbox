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
};

SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
    tail = NULL;
}

