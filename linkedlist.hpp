#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* saudara;   
    Node* anakanPertama;   
    Node* parent;     

    Node(string n, Node* h = nullptr, Node* p = nullptr, Node* v = nullptr)
        : data(n), saudara(h), anakanPertama(v), parent(p) {}
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
        if (!current->anakanPertama) {
            current->anakanPertama = newDir;
        } else {
            Node* temp = current->anakanPertama;
            
            while (temp->saudara) {
                temp = temp->saudara;
            }
            temp->saudara = newDir;
        }
    }

    void display() {
        Node* temp = current->anakanPertama;
        while (temp) {
            cout << temp->data << "\n";
            temp = temp->saudara;
        }
    }

    void remove(const string& value, bool& found) {
        Node* temp = current->anakanPertama;
        Node* prev_saudara = nullptr;

        while (temp) {
            if (temp->data == value) {
                if (prev_saudara) {
                    prev_saudara->saudara = temp->saudara; 
                } else {
                    current->anakanPertama = temp->saudara; 
                }
                delete temp;
                found = true;
                return;
            }
            prev_saudara = temp;
            temp = temp->saudara;
        }

        found = false;
    }

    ~LinkedList() {
        deleteAll(head);
    }

private:
    void deleteAll(Node* node) {
        if (!node) return;

        deleteAll(node->saudara);
        deleteAll(node->anakanPertama);
        delete node;
    }
};

#endif
