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
        void reverseList();
        void middleOfList();
};

// CONSTRUCTOR = initialize head and tail pointers to NULL
SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
    tail = NULL;
}

// checks if the list has any contents
bool SinglyLinkedList::isEmpty() {
    return (head == NULL);
}

// returns the value of head's data
int SinglyLinkedList::front() {
    return (head->data);
}

// returns the value of tail's data
int SinglyLinkedList::back() {
    return (tail->data);
}

// helper function for printing the linked list
void SinglyLinkedList::printList() {
    node* trav = head;
    while (trav != NULL) {
        cout << "[" << trav->data << "] -> ";
        trav = trav->next;
    }
    cout << "NULL" << endl;
}

// adds a node to the end of the list
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

// adds a node to the front of the list
void SinglyLinkedList::prepend(int val) {
    node* newNode = new node;
    newNode->data = val;
    if(isEmpty()) {
        head = newNode;
        tail = newNode;
        newNode->next = NULL;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// reverses the linked list
void SinglyLinkedList::reverseList() {
    node* dummyHead = new node;
    dummyHead->data = 0;
    dummyHead->next = head;

    while(head->next != NULL) {
        node* oldHead = dummyHead->next;
        node* newHead = head->next;

        dummyHead->next = newHead;
        head->next = newHead->next;
        newHead->next = oldHead;
    }
    head = dummyHead->next;
    delete dummyHead;
    printList();
}

// finds the middle value of the linked list
void SinglyLinkedList::middleOfList() {
    node* slowPtr = head;
    node* fastPtr = head;
    while(fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    cout << "The middle of the linked list is: " << slowPtr->data << "." << endl;
}

int main() {
    SinglyLinkedList list;
    //cout << "Result of isEmpty() : " << list.isEmpty() << endl;
    for (int i = 1; i < 5; i++) {
        list.append(i);
    }
    list.printList();
    list.middleOfList();
    //cout << "The front of the list is: " << list.front() << endl;
    //cout << "The back of the list is: " << list.back() << endl;

    // for (int i = 10; i > 5; i--) {
    //     list.prepend(i);
    // }
    // list.printList();

    list.reverseList();
    list.middleOfList();

    return 0;
}

