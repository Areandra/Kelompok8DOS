#ifndef DOS_HPP
#define DOS_HPP

#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;
LinkedList DOS;

string curentDir(Node* node) {
    if (!(node->parent)) return node->data + ":\\";
    return curentDir(node->parent) + node->data + "\\";
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
        if (!(DOS.current->parent)) {
            cout << "Already at root directory.\n";
        } else {
            DOS.current = DOS.current->parent;
        }
    } else {
        Node* temp = DOS.current->anakanPertama;
        while (temp) {
            if (temp->data == name) {
                DOS.current = temp;
                return;
            }
            temp = temp->saudara;
        }
        cout << "Directory not found.\n";
    }
}

#endif // DOS_HPP
