#pragma once

#include <iostream>

enum Status {
    FREE, OCCUPIED, DELETED
};

struct Node {
    int key;
    Status status;

    Node(int key = 0, Status status = FREE) : key(key), status(status) {}
};

static size_t h1(int key) {
    return key * key + 1;
}

static size_t h2(int key) {
    return (key << 1) + 1;
}

class HashTable {
private:
    Node *table;
    size_t size;

public:
    HashTable(size_t size);

    ~HashTable();

    bool search(int key) const;

    void insert(int key);

    void remove(int key);

    void print() const;
};
