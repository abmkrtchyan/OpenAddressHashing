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
    auto lastPosition = firstPosition;
    auto step = (h2(key)) % size;
    Node *currentSlot = table + lastPosition;
    while (true) {
        if (currentSlot->status == FREE) {
            return false;
        }
        if (currentSlot->status == OCCUPIED && currentSlot->key == key) {
            return true;
        }
        lastPosition = (lastPosition + step) % size;
        if (lastPosition == firstPosition) {
            return false;
        }
        currentSlot = table + lastPosition;
    }
}

void HashTable::insert(int key) {
    if (search(key)) {
        return;
    }
    auto lastPosition = (h1(key)) % size;
    auto step = (h2(key)) % size;
    Node *currentSlot = table + lastPosition;
    while (currentSlot->status == OCCUPIED) {
        lastPosition = (lastPosition + step) % size;
        currentSlot = table + lastPosition;
    }
    currentSlot->status = OCCUPIED;
    currentSlot->key = key;
}

void HashTable::remove(int key) {
    auto firstPosition = (h1(key)) % size;
    auto lastPosition = firstPosition;
    auto step = (h2(key)) % size;
    Node *currentSlot = table + lastPosition;

    while (true) {
        if (currentSlot->status == OCCUPIED && currentSlot->key == key) {
            break;
        }
        lastPosition = (lastPosition + step) % size;
        currentSlot = table + lastPosition;
    }

    currentSlot->status = DELETED;
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
