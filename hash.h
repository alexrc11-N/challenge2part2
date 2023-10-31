/****************
*Name: Alex Rosado
*Challenge 2 par 2
*
*This header file defines the Node structure for linked 
*list chaining and the HashTable class with methods for 
*basic hash table operations. The HashTable class uses 
*separate chaining to handle hash collisions and directly 
*incorporates linked list operations within the class.
*******/

#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <string>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class HashTable {
private:
    std::vector<Node*> table;
    int tableSize;

    // Hash function
    int hash(int key);

public:
    HashTable(int size);
    ~HashTable();

    void addEntry(int key);
    void removeEntry(int key);
    Node* getEntry(int key);
    int count();
    void displayTable();
};

#endif // HASH_H
