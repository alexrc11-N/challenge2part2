/****************
*Name: Alex Rosado
*Challenge 2 part 2
*
*This file contains the detailed implementations of the *HashTable class methods. The HashTable is implemented *using separate chaining, where each bucket (or slot) in *the hash table points to a singly linked list  of nodes (entries).
*******/

#include "hash.h"

HashTable::HashTable(int size) : tableSize(size) {
    table.resize(tableSize, nullptr);
}

HashTable::~HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
}

int HashTable::hash(int key) {
    return key % tableSize;
}

void HashTable::addEntry(int key) {
    int index = hash(key);
    Node* newNode = new Node(key);

    if (!table[index]) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void HashTable::removeEntry(int key) {
    int index = hash(key);
    Node* temp = nullptr;

    if (table[index]) {
        if (table[index]->data == key) {
            temp = table[index];
            table[index] = table[index]->next;
        } else {
            Node* current = table[index];
            while (current->next && current->next->data != key) {
                current = current->next;
            }

            if (current->next) {
                temp = current->next;
                current->next = current->next->next;
            }
        }
    }

    if (temp) {
        delete temp;
    }
}


Node* HashTable::getEntry(int key) {
    int index = hash(key);
    Node* current = table[index];
    Node* result = nullptr;

    while (current && !result) {
        if (current->data == key) {
            result = current;
        }
        current = current->next;
    }

    return result;
}


int HashTable::count() {
    int count = 0;
    for (int i = 0; i < tableSize; ++i) {
        Node* current = table[i];
        while (current) {
            ++count;
            current = current->next;
        }
    }
    return count;
}

void HashTable::displayTable() {
    for (int i = 0; i < tableSize; ++i) {
        std::cout << "Bucket " << i << ": ";
        Node* current = table[i];
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
