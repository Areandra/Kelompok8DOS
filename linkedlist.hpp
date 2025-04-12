#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur Node
struct Node {
    string data;
    vector<Node*> next; 
    Node* prev;
    bool isRoot;

    Node(string n, Node* p = nullptr, bool root = false) : data(n), prev(p), isRoot(root) {}
};

// Kelas LinkedList
class LinkedList {
private:
    Node* head;

public:
    Node* temp;
    LinkedList() {
        head = new Node("C",nullptr , true);
        temp = head;
    }

    // Menambahkan node di akhir
    void insert(string value) {
        Node* newNode = new Node(value, temp);
        temp->next.push_back(newNode);
    }
    

    // Menampilkan isi list
    void display() {
        for (auto& node : temp->next) {
            cout << node->data << "\n";
        }
    }

    // Menghapus node berdasarkan nilai
    void remove(const string& value) {
        auto it = temp->next.begin();
        while (it != temp->next.end()) {
            if ((*it)->data == value) {
                delete *it;
                temp->next.erase(it);  // Hapus dari list
                return;
            }
            ++it;
        }
    }

    // Destructor untuk menghapus semua node
    ~LinkedList() {
        delete head;
    }
    
};

#endif