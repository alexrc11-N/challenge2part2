/****************
*Name: Alex Rosado
*Challenge 2 par 2
*
*This source file contains the main() function which *tests the HashTable class. Various operations like *adding, *removing, and retrieving entries from the hash *table are *demonstrated, ensuring 
* the correctness and functionality of the hash table *implementation.
*******/
#include "main.h"

int main() {
    // Creando y añadiendo entradas a la tabla hash
    HashTable hashTable(10);
    hashTable.addEntry(5);
    hashTable.addEntry(15);
    hashTable.addEntry(25);
    hashTable.addEntry(6);
    hashTable.addEntry(16);
    hashTable.addEntry(35);  // Test para colisión en un índice diferente
    hashTable.addEntry(45);  // Test para colisión en el mismo índice anterior

    std::cout << "-Hash table contents-" << std::endl;
    hashTable.displayTable();

    // Eliminando entradas
    hashTable.removeEntry(15);
    hashTable.removeEntry(35);

    std::cout << "\nHash table contents after removing 15 and 35:" << std::endl;
    hashTable.displayTable();

    // Buscando entradas específicas
    int searchKeys[] = {5, 6, 15, 16, 25, 35, 45, 55}; // Algunas claves existen, otras no
    for (int key : searchKeys) {
        Node* entry = hashTable.getEntry(key);
        if (entry) {
            std::cout << "\nFound entry with key " << key << ": " << entry->data;
        } else {
            std::cout << "\nEntry with key " << key << " not found.";
        }
    }

    // Contando las entradas
    std::cout << "\n\nTotal number of entries: " << hashTable.count() << std::endl;

    return 0;
}
