#include "test.hpp"

int main() {
    std::cout << "1) ";
    TestDynamicArray();

    std::cout << "2) ";
    TestLinkedList();

    std::cout << "3) ";
    TestMutableArraySequence();

    std::cout << "4) ";
    TestMutableListSequence();

    std::cout << "5) ";
    TestImmutableArraySequence();

    std::cout << "6) ";
    TestAdaptiveSequence();

    std::cout << "7) ";
    TestSegmentedList();
}