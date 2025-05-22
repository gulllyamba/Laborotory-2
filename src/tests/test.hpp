#ifndef TEST_HPP
#define TEST_HPP

#include "../../include/Array/MutableArraySequence.hpp"
#include "../../include/Array/ImmutableArraySequence.hpp"
#include "../../include/List/MutableListSequence.hpp"
#include "../../include/AdaptiveSequence.hpp"
#include "../../include/SegmentedList.hpp"
#include <cmath>

template <typename T>
std::string toString(MutableListSequence<T>* list) {
    return list->GetList().toString();
}
template <typename T>
std::string toString(const MutableListSequence<T>& list) {
    return list.GetList().toString();
}
template <typename T>
std::string toString(MutableArraySequence<T>* array) {
    return array->GetArray().toString();
}
template <typename T>
std::string toString(const MutableArraySequence<T>& array) {
    return array.GetArray().toString();
}
template <typename T>
std::string toString(ImmutableArraySequence<T>* array) {
    return array->GetArray().toString();
}
template <typename T>
std::string toString(const ImmutableArraySequence<T>& array) {
    return array.GetArray().toString();
}

void TestDynamicArray() {
    std::cout << "DynamicArray testing...\n\n";

    bool flag = true;
    DynamicArray<int>* A = new DynamicArray<int>();

    std::cout << "Empty container:\n";

    try {
        if (A->GetSize() != 0) throw std::runtime_error("Size must be 0");
        if (A->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    DynamicArray<int>* GetSub = A->GetSubContainer(0, 2);
    try {
        if (GetSub->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    DynamicArray<int>* Con = A->Concat(A);
    try {
        if (Con->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 4) throw std::runtime_error("[3] element must be 4");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 0) throw std::runtime_error("[2] element must be 0");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Reserve(3);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->GetCapacity() != 3) throw std::runtime_error("Capacity must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";

    delete A;

    std::cout << "\n";

    flag = true;
    int items[] = {1, 2, 3};
    A = new DynamicArray<int>(items, 3);

    std::cout << "Container[3] = {1, 2, 3}:\n";

    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->Get(3) != 1) throw std::runtime_error("[3] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    GetSub = A->GetSubContainer(0, 4);
    try {
        if (GetSub->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (GetSub->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (GetSub->GetCapacity() != 8) throw std::runtime_error("Capacity must be 8");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    Con = A->Concat(A);
    try {
        if (Con->GetSize() != 12) throw std::runtime_error("Size must be 12");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->Get(6) != 4) throw std::runtime_error("[6] element must be 4");
        if (Con->Get(7) != 3) throw std::runtime_error("[7] element must be 3");
        if (Con->Get(8) != 1) throw std::runtime_error("[8] element must be 1");
        if (Con->Get(9) != 2) throw std::runtime_error("[9] element must be 2");
        if (Con->Get(10) != 3) throw std::runtime_error("[10] element must be 3");
        if (Con->Get(11) != 1) throw std::runtime_error("[11] element must be 1");
        if (Con->GetCapacity() != 24) throw std::runtime_error("Capacity must be 24");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(6);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->Get(5) != 0) throw std::runtime_error("[5] element must be 0");
        if (A->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Reserve(7);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->GetCapacity() != 7) throw std::runtime_error("Capacity must be 7");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";
    std::cout << "\n";

    delete A;
}

void TestLinkedList() {
    std::cout << "LinkedList testing...\n\n";

    bool flag = true;
    LinkedList<int>* A = new LinkedList<int>();

    std::cout << "Empty container:\n";

    try {
        if (A->GetSize() != 0) throw std::runtime_error("Size must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    LinkedList<int>* GetSub = A->GetSubContainer(0, 2);
    try {
        if (GetSub->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    LinkedList<int>* Con = A->Concat(A);
    try {
        if (Con->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 4) throw std::runtime_error("[3] element must be 4");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 0) throw std::runtime_error("[2] element must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";

    delete A;

    std::cout << "\n";

    flag = true;
    int items[] = {1, 2, 3};
    A = new LinkedList<int>(items, 3);

    std::cout << "Container[3] = {1, 2, 3}:\n";

    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->Get(3) != 1) throw std::runtime_error("[3] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    GetSub = A->GetSubContainer(0, 4);
    try {
        if (GetSub->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (GetSub->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    Con = A->Concat(A);
    try {
        if (Con->GetSize() != 12) throw std::runtime_error("Size must be 12");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->Get(6) != 4) throw std::runtime_error("[6] element must be 4");
        if (Con->Get(7) != 3) throw std::runtime_error("[7] element must be 3");
        if (Con->Get(8) != 1) throw std::runtime_error("[8] element must be 1");
        if (Con->Get(9) != 2) throw std::runtime_error("[9] element must be 2");
        if (Con->Get(10) != 3) throw std::runtime_error("[10] element must be 3");
        if (Con->Get(11) != 1) throw std::runtime_error("[11] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(6);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->Get(5) != 0) throw std::runtime_error("[5] element must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";
    std::cout << "\n";

    delete A;
}

void TestMutableArraySequence() {
    std::cout << "MutableArraySequence testing...\n\n";

    bool flag = true;
    MutableArraySequence<int>* A = new MutableArraySequence<int>();

    std::cout << "Empty container:\n";

    try {
        if (A->GetSize() != 0) throw std::runtime_error("Size must be 0");
        if (A->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    MutableArraySequence<int>* GetSub = A->GetSubSequence(0, 2);
    try {
        if (GetSub->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    MutableArraySequence<int>* Con = A->Concat(A);
    try {
        if (Con->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 4) throw std::runtime_error("[3] element must be 4");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 0) throw std::runtime_error("[2] element must be 0");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Reserve(3);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->GetCapacity() != 3) throw std::runtime_error("Capacity must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";

    delete A;

    std::cout << "\n";

    flag = true;
    int items[] = {1, 2, 3};
    A = new MutableArraySequence<int>(items, 3);

    std::cout << "Container[3] = {1, 2, 3}:\n";

    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->Get(3) != 1) throw std::runtime_error("[3] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    GetSub = A->GetSubSequence(0, 4);
    try {
        if (GetSub->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (GetSub->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (GetSub->GetCapacity() != 8) throw std::runtime_error("Capacity must be 8");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    Con = A->Concat(A);
    try {
        if (Con->GetSize() != 12) throw std::runtime_error("Size must be 12");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->Get(6) != 4) throw std::runtime_error("[6] element must be 4");
        if (Con->Get(7) != 3) throw std::runtime_error("[7] element must be 3");
        if (Con->Get(8) != 1) throw std::runtime_error("[8] element must be 1");
        if (Con->Get(9) != 2) throw std::runtime_error("[9] element must be 2");
        if (Con->Get(10) != 3) throw std::runtime_error("[10] element must be 3");
        if (Con->Get(11) != 1) throw std::runtime_error("[11] element must be 1");
        if (Con->GetCapacity() != 24) throw std::runtime_error("Capacity must be 24");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(6);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->Get(5) != 0) throw std::runtime_error("[5] element must be 0");
        if (A->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Reserve(7);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->GetCapacity() != 7) throw std::runtime_error("Capacity must be 7");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";
    std::cout << "\n";

    delete A;
}

void TestMutableListSequence() {
    std::cout << "MutableListSequence testing...\n\n";

    bool flag = true;
    MutableListSequence<int>* A = new MutableListSequence<int>();

    std::cout << "Empty container:\n";

    try {
        if (A->GetSize() != 0) throw std::runtime_error("Size must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    MutableListSequence<int>* GetSub = A->GetSubSequence(0, 2);
    try {
        if (GetSub->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    MutableListSequence<int>* Con = A->Concat(A);
    try {
        if (Con->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 4) throw std::runtime_error("[3] element must be 4");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 0) throw std::runtime_error("[2] element must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";

    delete A;

    std::cout << "\n";

    flag = true;
    int items[] = {1, 2, 3};
    A = new MutableListSequence<int>(items, 3);

    std::cout << "Container[3] = {1, 2, 3}:\n";

    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->Get(3) != 1) throw std::runtime_error("[3] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    GetSub = A->GetSubSequence(0, 4);
    try {
        if (GetSub->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (GetSub->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    Con = A->Concat(A);
    try {
        if (Con->GetSize() != 12) throw std::runtime_error("Size must be 12");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->Get(6) != 4) throw std::runtime_error("[6] element must be 4");
        if (Con->Get(7) != 3) throw std::runtime_error("[7] element must be 3");
        if (Con->Get(8) != 1) throw std::runtime_error("[8] element must be 1");
        if (Con->Get(9) != 2) throw std::runtime_error("[9] element must be 2");
        if (Con->Get(10) != 3) throw std::runtime_error("[10] element must be 3");
        if (Con->Get(11) != 1) throw std::runtime_error("[11] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(6);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->Get(5) != 0) throw std::runtime_error("[5] element must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";
    std::cout << "\n";

    delete A;
}

void TestImmutableArraySequence() {
    std::cout << "ImmutableArraySequence testing...\n\n";

    bool flag = true;
    ImmutableArraySequence<int>* A = new ImmutableArraySequence<int>();

    std::cout << "Empty container:\n";

    try {
        if (A->GetSize() != 0) throw std::runtime_error("Size must be 0");
        if (A->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* B = A->Append(1);
    try {
        if (B->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (B->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (B->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (B->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (B->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* C = B->Prepend(2);
    try {
        if (C->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (C->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (C->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (C->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (C->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (C->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* D = C->InsertAt(1, 3);
    try {
        if (D->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (D->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (D->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (D->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (D->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (D->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (D->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* E = D->Set(0, 4);
    try {
        if (E->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (E->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (E->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (E->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (E->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (E->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (E->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* GetSub = E->GetSubSequence(0, 2);
    try {
        if (GetSub->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    ImmutableArraySequence<int>* Con = E->Concat(E);
    try {
        if (Con->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 4) throw std::runtime_error("[3] element must be 4");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;


    ImmutableArraySequence<int>* F = E->RemoveAt(2);
    try {
        if (F->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (F->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (F->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (F->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (F->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (F->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* G = F->Resize(3);
    try {
        if (G->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (G->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (G->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (G->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (G->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (G->Get(2) != 0) throw std::runtime_error("[2] element must be 0");
        if (G->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* H = G->Resize(1);
    try {
        if (H->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (H->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (H->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (H->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (H->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    ImmutableArraySequence<int>* I = H->Reserve(3);
    try {
        if (I->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (I->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (I->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (I->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (I->GetCapacity() != 3) throw std::runtime_error("Capacity must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";

    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    delete G;
    delete H;
    delete I;

    std::cout << "\n";

    flag = true;
    int items[] = {1, 2, 3};
    A = new ImmutableArraySequence<int>(items, 3);

    std::cout << "Container[3] = {1, 2, 3}:\n";

    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    B = A->Append(1);
    try {
        if (B->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (B->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (B->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (B->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (B->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (B->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (B->Get(3) != 1) throw std::runtime_error("[3] element must be 1");
        if (B->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    C = B->Prepend(2);
    try {
        if (C->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (C->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (C->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (C->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (C->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (C->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (C->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (C->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (C->GetCapacity() != 8) throw std::runtime_error("Capacity must be 8");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    D = C->InsertAt(1, 3);
    try {
        if (D->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (D->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (D->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (D->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (D->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (D->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (D->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (D->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (D->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (D->GetCapacity() != 10) throw std::runtime_error("Capacity must be 10");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    E = D->Set(0, 4);
    try {
        if (E->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (E->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (E->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (E->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (E->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (E->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (E->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (E->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (E->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (E->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    GetSub = E->GetSubSequence(0, 4);
    try {
        if (GetSub->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (GetSub->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (GetSub->GetCapacity() != 8) throw std::runtime_error("Capacity must be 8");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    Con = E->Concat(E);
    try {
        if (Con->GetSize() != 12) throw std::runtime_error("Size must be 12");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->Get(6) != 4) throw std::runtime_error("[6] element must be 4");
        if (Con->Get(7) != 3) throw std::runtime_error("[7] element must be 3");
        if (Con->Get(8) != 1) throw std::runtime_error("[8] element must be 1");
        if (Con->Get(9) != 2) throw std::runtime_error("[9] element must be 2");
        if (Con->Get(10) != 3) throw std::runtime_error("[10] element must be 3");
        if (Con->Get(11) != 1) throw std::runtime_error("[11] element must be 1");
        if (Con->GetCapacity() != 24) throw std::runtime_error("Capacity must be 24");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    F = E->RemoveAt(2);
    try {
        if (F->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (F->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (F->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (F->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (F->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (F->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (F->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (F->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (F->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    G = F->Resize(6);
    try {
        if (G->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (G->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (G->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (G->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (G->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (G->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (G->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (G->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (G->Get(5) != 0) throw std::runtime_error("[5] element must be 0");
        if (G->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    H = G->Resize(3);
    try {
        if (H->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (H->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (H->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (H->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (H->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (H->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (H->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    I = H->Reserve(7);
    try {
        if (I->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (I->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (I->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (I->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (I->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (I->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (I->GetCapacity() != 7) throw std::runtime_error("Capacity must be 7");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";
    std::cout << "\n";

    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    delete G;
    delete H;
    delete I;
}

void TestAdaptiveSequence() {
    std::cout << "AdaptiveSequence testing...\n\n";

    bool flag = true;
    AdaptiveSequence<int>* A = new AdaptiveSequence<int>();

    std::cout << "Empty container:\n";

    try {
        if (A->GetSize() != 0) throw std::runtime_error("Size must be 0");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 0) throw std::runtime_error("CorrectRight must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 0) throw std::runtime_error("CorrectRight must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    AdaptiveSequence<int>* GetSub = A->GetSubContainer(0, 2);
    try {
        if (GetSub->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->GetCorrectLeft() != 1) throw std::runtime_error("CorrectLeft must be 3");
        if (GetSub->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    AdaptiveSequence<int>* Con = A->Concat(A);
    try {
        if (Con->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 4) throw std::runtime_error("[3] element must be 4");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->GetCorrectLeft() != 3) throw std::runtime_error("CorrectLeft must be 3");
        if (Con->GetCorrectRight() != 3) throw std::runtime_error("CorrectRight must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->GetCorrectLeft() != 1) throw std::runtime_error("CorrectLeft must be 1");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 0) throw std::runtime_error("[2] element must be 0");
        if (A->GetCorrectLeft() != 1) throw std::runtime_error("CorrectLeft must be 1");
        if (A->GetCorrectRight() != 2) throw std::runtime_error("CorrectRight must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";

    delete A;

    std::cout << "\n";

    flag = true;
    int items[] = {1, 2, 3};
    A = new AdaptiveSequence<int>(items, 3);

    std::cout << "Container[3] = {1, 2, 3}:\n";

    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->GetCorrectLeft() != 1) throw std::runtime_error("CorrectLeft must be 1");
        if (A->GetCorrectRight() != 2) throw std::runtime_error("CorrectRight must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->Get(3) != 1) throw std::runtime_error("[3] element must be 1");
        if (A->GetCorrectLeft() != 1) throw std::runtime_error("CorrectLeft must be 1");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 0) throw std::runtime_error("CorrectRight must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 0) throw std::runtime_error("CorrectRight must be 0");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    GetSub = A->GetSubContainer(0, 4);
    try {
        if (GetSub->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (GetSub->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (GetSub->GetCorrectLeft() != 2) throw std::runtime_error("CorrectLeft must be 2");
        if (GetSub->GetCorrectRight() != 2) throw std::runtime_error("CorrectRight must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    Con = A->Concat(A);
    try {
        if (Con->GetSize() != 12) throw std::runtime_error("Size must be 12");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->Get(6) != 4) throw std::runtime_error("[6] element must be 4");
        if (Con->Get(7) != 3) throw std::runtime_error("[7] element must be 3");
        if (Con->Get(8) != 1) throw std::runtime_error("[8] element must be 1");
        if (Con->Get(9) != 2) throw std::runtime_error("[9] element must be 2");
        if (Con->Get(10) != 3) throw std::runtime_error("[10] element must be 3");
        if (Con->Get(11) != 1) throw std::runtime_error("[11] element must be 1");
        if (Con->GetCorrectLeft() != 6) throw std::runtime_error("CorrectLeft must be 6");
        if (Con->GetCorrectRight() != 6) throw std::runtime_error("CorrectRight must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCorrectLeft() != 0) throw std::runtime_error("CorrectLeft must be 0");
        if (A->GetCorrectRight() != 1) throw std::runtime_error("CorrectRight must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(6);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->Get(5) != 0) throw std::runtime_error("[5] element must be 0");
        if (A->GetCorrectLeft() != 3) throw std::runtime_error("CorrectLeft must be 3");
        if (A->GetCorrectRight() != 3) throw std::runtime_error("CorrectRight must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->GetCorrectLeft() != 1) throw std::runtime_error("CorrectLeft must be 1");
        if (A->GetCorrectRight() != 2) throw std::runtime_error("CorrectRight must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";
    std::cout << "\n";

    delete A;
}

void TestSegmentedList() {
    std::cout << "SegmentedList testing...\n\n";

    bool flag = true;
    SegmentedList<int>* A = new SegmentedList<int>();

    std::cout << "Empty container:\n";

    try {
        if (A->GetSize() != 0) throw std::runtime_error("Size must be 0");
        if (A->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->GetCapacity() != 1) throw std::runtime_error("Capacity must be 1");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    SegmentedList<int>* GetSub = A->GetSubContainer(0, 2);
    try {
        if (GetSub->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    SegmentedList<int>* Con = A->Concat(A);
    try {
        if (Con->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 4) throw std::runtime_error("[3] element must be 4");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->GetCapacity() != 6) throw std::runtime_error("Capacity must be 6");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 2) throw std::runtime_error("Size must be 2");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 3) throw std::runtime_error("Last element must be 3");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 0) throw std::runtime_error("[2] element must be 0");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(1);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->GetCapacity() != 2) throw std::runtime_error("Capacity must be 2");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Reserve(3);
    try {
        if (A->GetSize() != 1) throw std::runtime_error("Size must be 1");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 4) throw std::runtime_error("Last element must be 4");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->GetCapacity() != 3) throw std::runtime_error("Capacity must be 3");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n";

    delete A;

    std::cout << "\n";

    flag = true;
    int items[] = {1, 2, 3};
    A = new SegmentedList<int>(items, 3);

    std::cout << "Container[3] = {1, 2, 3}:\n";

    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Append(1);
    try {
        if (A->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (A->GetFirst() != 1) throw std::runtime_error("First element must be 1");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 1) throw std::runtime_error("[0] element must be 1");
        if (A->Get(1) != 2) throw std::runtime_error("[1] element must be 2");
        if (A->Get(2) != 3) throw std::runtime_error("[2] element must be 3");
        if (A->Get(3) != 1) throw std::runtime_error("[3] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Prepend(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 1) throw std::runtime_error("[1] element must be 1");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->InsertAt(1, 3);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 2) throw std::runtime_error("First element must be 2");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 2) throw std::runtime_error("[0] element must be 2");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    A->Set(0, 4);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (A->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (A->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (A->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }

    GetSub = A->GetSubContainer(0, 4);
    try {
        if (GetSub->GetSize() != 4) throw std::runtime_error("Size must be 4");
        if (GetSub->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (GetSub->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (GetSub->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (GetSub->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (GetSub->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (GetSub->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (GetSub->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete GetSub;

    Con = A->Concat(A);
    try {
        if (Con->GetSize() != 12) throw std::runtime_error("Size must be 12");
        if (Con->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (Con->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (Con->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (Con->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (Con->Get(2) != 1) throw std::runtime_error("[2] element must be 1");
        if (Con->Get(3) != 2) throw std::runtime_error("[3] element must be 2");
        if (Con->Get(4) != 3) throw std::runtime_error("[4] element must be 3");
        if (Con->Get(5) != 1) throw std::runtime_error("[5] element must be 1");
        if (Con->Get(6) != 4) throw std::runtime_error("[6] element must be 4");
        if (Con->Get(7) != 3) throw std::runtime_error("[7] element must be 3");
        if (Con->Get(8) != 1) throw std::runtime_error("[8] element must be 1");
        if (Con->Get(9) != 2) throw std::runtime_error("[9] element must be 2");
        if (Con->Get(10) != 3) throw std::runtime_error("[10] element must be 3");
        if (Con->Get(11) != 1) throw std::runtime_error("[11] element must be 1");
        if (Con->GetCapacity() != 12) throw std::runtime_error("Capacity must be 12");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error!" << "\n";
        flag = false;
    }
    delete Con;

    A->RemoveAt(2);
    try {
        if (A->GetSize() != 5) throw std::runtime_error("Size must be 5");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 1) throw std::runtime_error("Last element must be 1");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(6);
    try {
        if (A->GetSize() != 6) throw std::runtime_error("Size must be 6");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 0) throw std::runtime_error("Last element must be 0");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->Get(3) != 3) throw std::runtime_error("[3] element must be 3");
        if (A->Get(4) != 1) throw std::runtime_error("[4] element must be 1");
        if (A->Get(5) != 0) throw std::runtime_error("[5] element must be 0");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Resize(3);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->GetCapacity() != 4) throw std::runtime_error("Capacity must be 4");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    A->Reserve(5);
    try {
        if (A->GetSize() != 3) throw std::runtime_error("Size must be 3");
        if (A->GetFirst() != 4) throw std::runtime_error("First element must be 4");
        if (A->GetLast() != 2) throw std::runtime_error("Last element must be 2");
        if (A->Get(0) != 4) throw std::runtime_error("[0] element must be 4");
        if (A->Get(1) != 3) throw std::runtime_error("[1] element must be 3");
        if (A->Get(2) != 2) throw std::runtime_error("[2] element must be 2");
        if (A->GetCapacity() != 5) throw std::runtime_error("Capacity must be 5");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error. " << e.what() << "\n";
        flag = false;
    }
    catch (...) {
        std::cerr << "Unknown error" << "\n";
        flag = false;
    }

    if (flag) std::cout << "Tests completed\n";
    else std::cout << "Tests not completed\n\n";
    std::cout << "\n";

    delete A;
}

#endif // TEST_HPP