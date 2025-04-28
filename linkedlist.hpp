#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next_h;   
    Node* next_v;   
    Node* prev;     

    Node(string n, Node* h = nullptr, Node* p = nullptr, Node* v = nullptr)
        : data(n), next_h(h), next_v(v), prev(p) {}
};

class LinkedList {
private:
    Node* head;

public:
    Node* current;

    LinkedList() {
        head = new Node("C", nullptr, nullptr, nullptr);
        current = head;
    }

    void insert(string value) {
        Node* newDir = new Node(value, nullptr, current); 
        if (!current->next_v) {
            current->next_v = newDir;
        } else {
            Node* temp = current->next_v;
            while (temp->next_h) {
                temp = temp->next_h;
            }
            temp->next_h = newDir;
        }
    }

    void display() {
        Node* temp = current->next_v;
        while (temp) {
            cout << temp->data << "\n";
            temp = temp->next_h;
        }
    }

    void remove(const string& value, bool& found) {
        Node* prev_v = current;
        Node* temp = prev_v->next_v;
        Node* prev_h = nullptr;

        while (temp) {
            if (temp->data == value) {
                if (prev_h) {
                    prev_h->next_h = temp->next_h; 
                } else {
                    prev_v->next_v = temp->next_h; 
                }
                delete temp;
                found = true;
                return;
            }
            prev_h = temp;
            temp = temp->next_h;
        }

        found = false;
    }

    ~LinkedList() {
        deleteAll(head);
    }

private:
    void deleteAll(Node* node) {
        if (!node) return;

        deleteAll(node->next_h);
        deleteAll(node->next_v);
        delete node;
    }
};

#endif
