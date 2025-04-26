#ifndef DOS_HPP
#define DOS_HPP

#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;
LinkedList DOS;

string curentDir(Node* node) {
    if (node->isRoot) return node->data + ":\\";
    return curentDir(node->prev) + node->data + "\\";
}

void mkdir(const string& name) {
    DOS.insert(name);
    cout << "Directory '" << name << "' created.\n";
}

void rmdir(const string& name) {
    bool found = false;
    DOS.remove(name, found);
    if (found) {
        cout << "Directory '" << name << "' deleted.\n";
    } else {
        cout << "Directory '" << name << "' not found.\n";
    }
}

void dir() {
    cout << "List of directories:\n";
    DOS.display();
}

void cd(const string& name) {
    if (name == "..") {
        if (DOS.temp->isRoot) {
            cout << "Already at root directory.\n";
        } else {
            DOS.temp = DOS.temp->prev;
        }
    } else {
        Node* current = DOS.temp->next_v;
        while (current) {
            if (current->data == name) {
                DOS.temp = current;
                return;
            }
            current = current->next_h;
        }
        cout << "Directory not found.\n";
    }
}

#endif // DOS_HPP
