#include "HashTable.h"
#include <functional>
#include <unordered_map>
#include <iostream>
#include <algorithm>

void myClassTest() {
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
}

struct Node {
    int value;
    int wight;

    Node(int value = 0, int wight = 0) : value(value), wight(wight) {}

    bool operator==(const Node &other) const {
        return (value == other.value) && (wight == other.wight);
    }

    void print() const {
        std::cout << "Value: " << value << ", Wight: " << wight << std::endl;
    }
};

namespace std {
    template<>
    struct hash<Node> {
        size_t operator()(const Node &key) const {
            return std::hash<int>()(key.value);
        }
    };
}


struct HashFunction {
    size_t operator()(const int &key) const {
        // Custom hash function logic here
        return std::hash<int>()(key);
    }
};

void test1() {
    std::cout << "________________Test1_________________" << std::endl;
    std::unordered_map<int, int> intUnorderedMap;

    intUnorderedMap[42] = 42;
    intUnorderedMap[15] = 15;
    intUnorderedMap[15] = 16;
    intUnorderedMap[30] = 30;
    intUnorderedMap[10] = 10;

    std::cout << "Elements in the unordered_map:";
    for (const auto &element: intUnorderedMap) {
        std::cout << " " << element.second;
    }
    std::cout << std::endl;

    intUnorderedMap.erase(15);

    if (intUnorderedMap.empty()) {
        std::cout << "The unordered_map is empty." << std::endl;
    } else {
        std::cout << "The unordered_map is not empty." << std::endl;

        auto findIt = intUnorderedMap.find(30);
        if (findIt != intUnorderedMap.end()) {
            std::cout << "Element 30 found in the unordered_map." << std::endl;
        } else {
            std::cout << "Element 30 not found in the unordered_map." << std::endl;
        }
    }

    std::cout << "Size of the unordered_map: " << intUnorderedMap.size() << std::endl;

    intUnorderedMap.clear();

    std::unordered_map<int, int> anotherUnorderedMap;

    anotherUnorderedMap[5] = 5;
    anotherUnorderedMap[8] = 8;
    anotherUnorderedMap[12] = 12;

    intUnorderedMap.swap(anotherUnorderedMap);

    std::cout << "Elements in the unordered_map after swapping:";
    for (const auto &element: intUnorderedMap) {
        std::cout << " " << element.first;
    }
    std::cout << std::endl;
    std::cout << "______________________________________" << std::endl;
}

void test2() {
    std::cout << "________________Test2_________________" << std::endl;
    std::unordered_map<int, Node> map_apple;

    map_apple[3] = Node(3, 250);
    map_apple[1] = Node(1, 350);
    map_apple[2] = Node(2, 100);

    for (const auto &it: map_apple) {
        it.second.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test3() {
    std::cout << "________________Test3_________________" << std::endl;
    std::unordered_map<int, Node, HashFunction> map_apple;

    map_apple[3] = Node(3, 250);
    map_apple[1] = Node(1, 350);
    map_apple[2] = Node(2, 100);

    for (const auto &it: map_apple) {
        it.second.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test4() {
    std::cout << "________________Test4_________________" << std::endl;
    std::unordered_map<Node, int> map_apple;

    Node node1(3, 250);
    Node node2(1, 350);
    Node node3(2, 100);
    map_apple[node1] = 250;
    map_apple[node2] = 350;
    map_apple[node3] = 100;

    for (const auto &it: map_apple) {
        it.first.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test5() {
    std::cout << "________________Test5_________________" << std::endl;
    std::unordered_map<int, int, HashFunction> intUnorderedMap;

    intUnorderedMap[50] = 1;
    intUnorderedMap[40] = 1;
    intUnorderedMap[30] = 1;
    intUnorderedMap[30] = 1;
    intUnorderedMap[20] = 1;
    intUnorderedMap[10] = 1;

    std::cout << "Elements in the unordered_map:";
    for (const auto &element: intUnorderedMap) {
        std::cout << " " << element.first;
    }
    std::cout << std::endl;

    auto findIt = intUnorderedMap.find(30);
    if (findIt != intUnorderedMap.end()) {
        std::cout << "Element 30 found in the unordered_map." << std::endl;
    } else {
        std::cout << "Element 30 not found in the unordered_map." << std::endl;
    }

    std::cout << "______________________________________" << std::endl;

    auto count = intUnorderedMap.count(30);
    std::cout << "Occurrences of 30: " << count << std::endl;
    std::cout << "______________________________________" << std::endl;
}

void test6() {
    std::cout << "________________Test6_________________" << std::endl;
    std::unordered_map<int, int, HashFunction> intUnorderedMap;

    intUnorderedMap[50] = 1;
    intUnorderedMap[40] = 1;
    intUnorderedMap[30] = 1;
    intUnorderedMap[30] = 1;
    intUnorderedMap[20] = 1;
    intUnorderedMap[10] = 1;

    auto occurrences = std::count_if(intUnorderedMap.begin(), intUnorderedMap.end(),
                                     [value = 30](const auto &element) {
                                         return element.first == value;
                                     });

    std::cout << "Occurrences of 30: " << occurrences << std::endl;
    std::cout << "______________________________________" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}


