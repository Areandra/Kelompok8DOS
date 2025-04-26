#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct Node {
    string data;
    Node* next_h;   
    Node* next_v;   
    Node* prev;     
    bool isRoot;

    Node(string n, Node* h = nullptr, Node* p = nullptr, Node* v = nullptr, bool root = false)
        : data(n), next_h(h), next_v(v), prev(p), isRoot(root) {}
};

class LinkedList {
private:
    Node* head;

public:
    Node* temp;

    LinkedList() {
        head = new Node("C", nullptr, nullptr, nullptr, true);
        temp = head;
    }

    void insert(string value) {
        Node* newDir = new Node(value, nullptr, temp); 
        if (!temp->next_v) {
            temp->next_v = newDir;
        } else {
            Node* current = temp->next_v;
            while (current->next_h) {
                current = current->next_h;
            }
            current->next_h = newDir;
        }
    }

    void display() {
        Node* current = temp->next_v;
        while (current) {
            cout << current->data << "\n";
            current = current->next_h;
        }
    }

    void remove(const string& value, bool& found) {
        Node* parent = temp;
        Node* current = parent->next_v;
        Node* prev = nullptr;

        while (current) {
            if (current->data == value) {
                if (prev) {
                    prev->next_h = current->next_h; 
                } else {
                    parent->next_v = current->next_h; 
                }
                delete current;
                found = true;
                return;
            }
            prev = current;
            current = current->next_h;
        }

        found = false;
    }

    // Destructor
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
