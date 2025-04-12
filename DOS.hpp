#ifndef DOS_HPP
#define DOS_HPP

#include <iostream>
#include <string>
#include "linkedlist.hpp"

using namespace std;
LinkedList DOS;

void DiskOperatingSystem(){
    cout << ":\\>" << endl;
}

void createDirectory(string name) {;
    DOS.insert(name);
    cout << "Directory " << name << " created." << endl;
}

void deleteDirectory(string name) {
    DOS.remove(name);
    cout << "Directory " << name << " deleted." << endl;
}

void listDirectories() {
    cout << "List of directories:" << endl;
    DOS.display();
}

void cdCommand(string name) {
    if (name == "..") {
        if (DOS.temp->isRoot) {
            cout << "Already at root directory." << endl;
        } else {
            DOS.temp = DOS.temp->prev;
        }
    } else {
        for (auto& node : DOS.temp->next) {
            if (node->data == name) {
                DOS.temp = node;
                return;
            }
        }
        cout << "Directory not found." << endl;
    }
}

string curentDir(Node* node) {
    if (node->isRoot) return node->data + ":\\";
    return curentDir(node->prev) + "\\" + node->data;
}

#endif // DOS_HPP