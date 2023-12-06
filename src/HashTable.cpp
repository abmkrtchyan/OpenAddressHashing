#include "HashTable.h"

HashTable::HashTable(size_t size) {
    if ((size & (size - 1)) != 0) {
        int count = 0;
        while (size != 0) {
            count++;
            size >>= 1;
        }
        size = 1 << (count);
    }
    this->size = size;
    this->table = new Node[size];
}

HashTable::~HashTable() {
    delete[] table;
}

bool HashTable::search(int key) const {
    auto firstPosition = (h1(key)) % size;
    auto step = (h2(key)) % size;
    auto currentPosition = firstPosition;
    while (true) {
        if (table[currentPosition].status == OCCUPIED && table[currentPosition].key == key) {
            return true;
        }
        if (table[currentPosition].status == FREE) {
            return false;
        }
        currentPosition = (currentPosition + step) % size;
        if (currentPosition == firstPosition) {
            return false;
        }
    }
}

void HashTable::insert(int key) {
    if (search(key)) {
        return;
    }
    auto currentPosition = (h1(key)) % size;
    auto step = (h2(key)) % size;
    while (table[currentPosition].status == OCCUPIED) {
        currentPosition = (currentPosition + step) % size;
    }
    table[currentPosition].status = OCCUPIED;
    table[currentPosition].key = key;
}

void HashTable::remove(int key) {
    auto firstPosition = (h1(key)) % size;
    auto step = (h2(key)) % size;
    auto currentPosition = firstPosition;

    while (true) {
        if (table[currentPosition].status == OCCUPIED && table[currentPosition].key == key) {
            break;
        }
        currentPosition = (currentPosition + step) % size;
    }

    table[currentPosition].status = DELETED;
}

void HashTable::print() const {
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "pos=" << i << ": ";
        if (table[i].status == OCCUPIED) {
            std::cout << table[i].key << std::endl;
        } else if (table[i].status == FREE) {
            std::cout << "FREE" << std::endl;
        } else {
            std::cout << "DELETED" << std::endl;
        }
    }
    std::cout << std::endl;
}
