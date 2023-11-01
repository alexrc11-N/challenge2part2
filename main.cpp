/****************
*Name: Alex Rosado
*Challenge 2 part 2
*
*This source file contains the main() function which *tests the HashTable class. Various operations like *adding, *removing, and retrieving entries from the hash *table are *demonstrated, ensuring 
* the correctness and functionality of the hash table *implementation.
*******/
#include "main.h"

#include "hash.h"

int main() {
    HashTable hashTable(15);

    // Basic tests
    hashTable.addEntry(5);
    hashTable.addEntry(15);
    hashTable.addEntry(25);
    hashTable.addEntry(6);
    hashTable.addEntry(16);

    std::cout << "Hash table contents:" << std::endl;
    hashTable.displayTable();

    hashTable.removeEntry(15);

    std::cout << "\nHash table contents after removing 15:" << std::endl;
    hashTable.displayTable();

    Node* entry = hashTable.getEntry(6);
    if (entry) {
        std::cout << "\nFound entry with key 6: " << entry->data << std::endl;
    } else {
        std::cout << "\nEntry with key 6 not found." << std::endl;
    }

    std::cout << "\nTotal number of entries: " << hashTable.count() << std::endl;

    // Edge testing
    hashTable.addEntry(0); // Add the smallest value
    hashTable.addEntry(9); // Add a number that falls right on the border
    hashTable.removeEntry(0);
    hashTable.removeEntry(9);

    // Crash tests
    hashTable.addEntry(20); // These all have the same hash value
    hashTable.addEntry(30);
    hashTable.addEntry(40);
    std::cout << "\nHash table after adding colliding entries:" << std::endl;
    hashTable.displayTable();
    hashTable.removeEntry(30); // Delete an intermediate value
    std::cout << "\nHash table after removing one of the colliding entries:" << std::endl;
    hashTable.displayTable();

    // Non-existing element test
    Node* missingEntry = hashTable.getEntry(100);
    if (!missingEntry) {
        std::cout << "\nCorrectly didn't find a missing entry." << std::endl;
    } else {
        std::cout << "\nUnexpectedly found an entry for 100!" << std::endl;
    }

    //Load testing (not really a massive load, but more than you'd expect on a table of size 10)
    for (int i = 50; i < 300; i++) {
        hashTable.addEntry(i);
    }
    std::cout << "\nHash table after adding a load of entries:" << std::endl;
    hashTable.displayTable();
    std::cout << "\nTotal number of entries after load: " << hashTable.count() << std::endl;

    return 0;
}
