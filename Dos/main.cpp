#include <iostream>
#include <string>

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

int main() {
    cout << "Kelompok 8" << endl;
    cout << "Nama Anggota:" << endl;
    cout << "1. Muh. Ariel (F55124049)" << endl;
    cout << "2. Surya Kusuma Pamungkas (F55124062)" << endl;
    cout << "3. Latifah Putri Fakhruddin (F55124067)" << endl;
    cout << "4. Aul Zikri (F55124046)" << endl << endl;
    
    string cmd, arg;
    while (true) {
        cout << curentDir(DOS.current) << ">";
        cin >> cmd;

        if (cmd == "mkdir") {
            cin >> arg;
            mkdir(arg);
        } else if (cmd == "rmdir") {
            cin >> arg;
            rmdir(arg);
        } else if (cmd == "cd") {
            cin >> arg;
            cd(arg);
        } else if (cmd == "dir") {
            dir();
        } else if (cmd == "exit") {
            break;
        } else {
            cout << "Perintah tidak dikenali.\n";
        }
    }
    
    return 0;
}