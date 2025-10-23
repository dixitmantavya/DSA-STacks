#include <iostream>
#include<stack>
using namespace std;

class Node {
public:
    int data;    // stores value of node
    Node *next;  // pointer to next node

    // Constructor to initialize node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList {
public:
    Node *head;
    Node *tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }
void push(int d) {
        Node *temp = new Node(d);
        if (tail == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
void pop() {
    if (head == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    // If only one node
    if (head->next == NULL) {
        delete head;
        head = tail = NULL;
        return;
    }

    // Move to second last node
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;
    temp->next = NULL;
    tail = temp;
}

int peek() {
    if (head == NULL) {
        cout << "Stack is empty\n";
        return -1; // or throw exception
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp->data;
}

bool isempty() {
    return head == NULL;
}

};