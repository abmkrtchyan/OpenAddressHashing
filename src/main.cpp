#include "HashTable.h"
#include <iostream>

int main() {
    std::cout << std::endl << "***** OPEN ADDRESS HASHING *****" << std::endl;
    HashTable table(8);

    table.search(50);

    std::cout << std::endl << "////////////////////////////////////////////////" << std::endl;

    std::cout << std::endl << "2, 11, 5, 10, 3, 9 are inserted:" << std::endl;
    table.insert(2);
    table.insert(11);
    table.insert(5);
    table.insert(10);
    table.insert(3);
    table.insert(9);
    table.print();

    std::cout << "5 and 9 are deleted, then 9 is inserted again:" << std::endl;
    table.remove(5);
    table.remove(9);
    table.insert(9);
    table.print();
    std::cout << "////////////////////////////////////////////////" << std::endl;

    return 0;
}

