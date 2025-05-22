#ifndef UI_HPP
#define UI_HPP

#include "../../include/Array/MutableArraySequence.hpp"
#include "../../include/Array/ImmutableArraySequence.hpp"
#include "../../include/List/MutableListSequence.hpp"
#include "../../include/AdaptiveSequence.hpp"
#include "../../include/SegmentedList.hpp"
#include <cmath>
#include <iomanip>

Container<int>* container;
MutableSequence<int>* mut_sequence;
ImmutableSequence<int>* immut_sequence;

int container_num, method;

template <typename T>
Container<T>* create_container() {
    switch (container_num) {
        case 1: return new DynamicArray<int>();
        case 2: return new LinkedList<int>();
        case 3: return new AdaptiveSequence<int>();
        case 4: return new SegmentedList<int>();
        default: break;
    }
    return nullptr;
}

template <typename T>
Container<T>* create_container(T* items, int size) {
    switch (container_num) {
        case 1: return new DynamicArray<int>(items, size);
        case 2: return new LinkedList<int>(items, size);
        case 3: return new AdaptiveSequence<int>(items, size);
        case 4: return new SegmentedList<int>(items, size);
        default: break;
    }
    return nullptr;
}

template <typename T>
Container<T>* create_container(Container<T>* other) {
    switch (container_num) {
        case 1: return new DynamicArray<int>(*dynamic_cast<DynamicArray<int>*>(other));
        case 2: return new LinkedList<int>(*dynamic_cast<LinkedList<int>*>(other));
        case 3: return new AdaptiveSequence<int>(*dynamic_cast<AdaptiveSequence<int>*>(other));
        case 4: return new SegmentedList<int>(*dynamic_cast<SegmentedList<int>*>(other));
        default: break;
    }
    return nullptr;
}

template <typename T>
MutableSequence<T>* create_mut_sequence() {
    switch (container_num) {
        case 5: return new MutableArraySequence<int>();
        case 6: return new MutableListSequence<int>();
        default: break;
    }
    return nullptr;
}

template <typename T>
MutableSequence<T>* create_mut_sequence(T* items, int size) {
    switch (container_num) {
        case 5: return new MutableArraySequence<int>(items, size);
        case 6: return new MutableListSequence<int>(items, size);
        default: break;
    }
    return nullptr;
}

template <typename T>
MutableSequence<T>* create_mut_sequence(MutableSequence<T>* other) {
    switch (container_num)
    {
    case 5: return new MutableArraySequence<int>(*dynamic_cast<MutableArraySequence<int>*>(other));
    case 6: return new MutableListSequence<int>(*dynamic_cast<MutableListSequence<int>*>(other));
    default:
        break;
    }
    return nullptr;
}

template <typename T>
ImmutableArraySequence<T>* create_immut_sequence() {
    return new ImmutableArraySequence<int>();
}

template <typename T>
ImmutableArraySequence<T>* create_immut_sequence(T* items, int size) {
    return new ImmutableArraySequence<int>(items, size);
}

template <typename T>
ImmutableArraySequence<T>* create_immut_sequence(ImmutableSequence<T>* other) {
    return new ImmutableArraySequence<int>(*dynamic_cast<ImmutableArraySequence<int>*>(other));
}

void print(const Container<int>& other) {
    std::cout << "[";
    if (other.GetSize() > 0) {
        std::cout << other.Get(0);
        for (int i = 1; i < other.GetSize(); i++) {
            std::cout << ", " << other.Get(i);
        }
    }
    std::cout << "]\n";
}

void print(const MutableSequence<int>& other) {
    std::cout << "[";
    if (other.GetSize() > 0) {
        std::cout << other.Get(0);
        for (int i = 1; i < other.GetSize(); i++) {
            std::cout << ", " << other.Get(i);
        }
    }
    std::cout << "]\n";
}

void print(const ImmutableSequence<int>& other) {
    std::cout << "[";
    if (other.GetSize() > 0) {
        std::cout << other.Get(0);
        for (int i = 1; i < other.GetSize(); i++) {
            std::cout << ", " << other.Get(i);
        }
    }
    std::cout << "]\n";
}

void run_container() {
    std::cout << "\nВыберите тип последовательности:\n";
    std::cout << "1. DynamicArray\n";
    std::cout << "2. LinkedList\n";
    std::cout << "3. AdaptiveSequence\n";
    std::cout << "4. SegmentedList\n";
    std::cout << "5. MutableArraySequence\n";
    std::cout << "6. MutableListSequence\n";
    std::cout << "7. ImmutableArraySequence\n";
    std::cout << "0. Выйти\n";
    std::cout << "Введите выбор: ";
    std::cin >>container_num;
    while (container_num < 0 || container_num > 7) {
        std::cout << "\nОшибка. Введите число от 0 до 7: ";
        std::cin >>container_num;
    }
    if (container_num > 0 && container_num < 5) {
        container = create_container<int>();
        switch (container_num)
        {
        case 1: {std::cout << "\nВы создали пустой DynamicArray()\n"; break;}
        case 2: {std::cout << "\nВы создали пустой LinkedList()\n"; break;}
        case 3: {std::cout << "\nВы создали пустой AdaptiveSequence()\n"; break;}
        case 4: {std::cout << "\nВы создали пустой SegmentedList()\n"; break;}
        default: break;
        }
    }
    else if (container_num > 4 && container_num < 7) {
        mut_sequence = create_mut_sequence<int>();
        switch (container_num)
        {
        case 5: {std::cout << "\nВы создали пустой MutableArraySequence()\n"; break;}
        case 6: {std::cout << "\nВы создали пустой MutableListSequence()\n"; break;}
        default: break;
        }
    }
    else if (container_num == 7) {
        immut_sequence = create_immut_sequence<int>();
        std::cout << "\nВы создали пустой ImmutableArraySequence()\n";
    }
    return;
}

void run_method() {
    int index, value;
    std::cout << "\nВыберите метод:\n";
        std::cout << "1. GetFirst\n";
        std::cout << "2. GetLast\n"; 
        std::cout << "3. Get\n"; 
        std::cout << "4. GetSize\n";
        std::cout << "5. Append\n";
        std::cout << "6. Prepend\n";
        std::cout << "7. Set\n";
        std::cout << "8. InsertAt\n";
        std::cout << "9. Resize\n";
        std::cout << "10. RemoveAt\n";
        std::cout << "11. GetSubSequence\n";
        std::cout << "12. Concat\n";
        std::cout << "0. Выйти\n";
        std::cout << "Введите выбор: ";
    while (std::cin >> method && method) {
        while (method < 0 || method > 12) {
            std::cout << "\nОшибка. Введите число от 0 до 10: ";
            std::cin >>method;
        }
        switch (method)
        {
        case 1: {
            std::cout << "\n-----GetFirst-----\n";
            if (container_num > 0 && container_num < 5) std::cout << container->GetFirst() << "\n";
            else if (container_num > 4 && container_num < 7) std::cout << mut_sequence->GetFirst() << "\n";
            else if (container_num == 7) std::cout << immut_sequence->GetFirst() << "\n";
            break;
        }
        case 2: {
            std::cout << "\n-----GetLast------\n";
            if (container_num > 0 && container_num < 5) std::cout << container->GetLast() << "\n";
            else if (container_num > 4 && container_num < 7) std::cout << mut_sequence->GetLast() << "\n";
            else if (container_num == 7) std::cout << immut_sequence->GetLast() << "\n";
            break;
        }
        case 3: {
            std::cout << "\n-----Get----------\n";
            std::cout << "Введите индекс: ";
            std::cin >> index;
            if (container_num > 0 && container_num < 5) std::cout << container->Get(index) << "\n";
            else if (container_num > 4 && container_num < 7) std::cout << mut_sequence->Get(index) << "\n";
            else if (container_num == 7) std::cout << immut_sequence->Get(index) << "\n";
            break;
        }
        case 4: {
            std::cout << "\n-----GetSize------\n";
            if (container_num > 0 && container_num < 5) std::cout << container->GetSize() << "\n";
            else if (container_num > 4 && container_num < 7) std::cout << mut_sequence->GetSize() << "\n";
            else if (container_num == 7) std::cout << immut_sequence->GetSize() << "\n";
            break;
        }
        case 5: {
            std::cout << "\n-----Append-------\n";
            std::cout << "Введите значение: ";
            std::cin >> value;
            if (container_num > 0 && container_num < 5) container->Append(value);
            else if (container_num > 4 && container_num < 7) mut_sequence->Append(value);
            else if (container_num == 7) {
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->Append(value);
                delete copy;
            }
            break;
        }
        case 6: {
            std::cout << "\n-----Prepend------\n";
            std::cout << "Введите значение: ";
            std::cin >> value;
            if (container_num > 0 && container_num < 5) container->Prepend(value);
            else if (container_num > 4 && container_num < 7) mut_sequence->Prepend(value);
            else if (container_num == 7) {
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->Prepend(value);
                delete copy;
            }
            break;
        }
        case 7: {
            std::cout << "\n-----Set----------\n";
            std::cout << "Введите индекс: ";
            std::cin >> index;
            std::cout << "Введите значение: ";
            std::cin >> value;
            if (container_num > 0 && container_num < 5) container->Set(index, value);
            else if (container_num > 4 && container_num < 7) mut_sequence->Set(index, value);
            else if (container_num == 7) {
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->Set(index, value);
                delete copy;
            }
            break;
        }
        case 8: {
            std::cout << "\n-----InsertAt-----\n";
            std::cout << "Введите индекс: ";
            std::cin >> index;
            std::cout << "Введите значение: ";
            std::cin >> value;
            if (container_num > 0 && container_num < 5) container->InsertAt(index, value);
            else if (container_num > 4 && container_num < 7) mut_sequence->InsertAt(index, value);
            else if (container_num == 7) {
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->InsertAt(index, value);
                delete copy;
            }
            break;
        }
        case 9: {
            std::cout << "\n-----Resize-------\n";
            std::cout << "Введите размер: ";
            std::cin >> index;
            if (container_num > 0 && container_num < 5) container->Resize(index);
            else if (container_num > 4 && container_num < 7) mut_sequence->Resize(index);
            else if (container_num == 7) {
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->Resize(index);
                delete copy;
            }
            break;
        }
        case 10: {
            std::cout << "\n-----RemoveAt-----\n";
            std::cout << "Введите индекс: ";
            std::cin >> index;
            if (container_num > 0 && container_num < 5) container->RemoveAt(index);
            else if (container_num > 4 && container_num < 7) mut_sequence->RemoveAt(index);
            else if (container_num == 7) {
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->RemoveAt(index);
                delete copy;
            }
            break;
        }
        case 11: {
            std::cout << "\n-----GetSubSequence-------\n";
            std::cout << "Введите индексы начала и конца: ";
            int start, end;
            std::cin >> start >> end;
            if (container_num > 0 && container_num < 5) {
                Container<int>* copy = create_container<int>(container);
                delete container;
                container = copy->GetSubContainer(start, end);
                delete copy;
            }
            else if (container_num > 4 && container_num < 7) {
                MutableSequence<int>* copy = create_mut_sequence<int>(mut_sequence);
                delete mut_sequence;
                mut_sequence = copy->GetSubSequence(start, end);
                delete copy;
            }
            else if (container_num == 7) {
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->GetSubSequence(start, end);
                delete copy;
            }
            break;
        }
        case 12: {
            std::cout << "\n-----Concat-------\n";
            std::cout << "Введите размер последовательности: ";
            std::cin >> index;
            std::cout << "Введите последовательность <int>: ";
            int items[index];
            for (int i = 0; i < index; i++) {
                std::cin >> value;
                items[i] = value;
            }
            if (container_num > 0 && container_num < 5) {
                Container<int>* with_concat = create_container<int>(items, index);
                Container<int>* copy = create_container<int>(container);
                delete container;
                container = copy->Concat(with_concat);
                delete with_concat;
                delete copy;
            }
            else if (container_num > 4 && container_num < 7) {
                MutableSequence<int>* with_concat = create_mut_sequence<int>(items, index);
                MutableSequence<int>* copy = create_mut_sequence<int>(mut_sequence);
                delete mut_sequence;
                mut_sequence = copy->Concat(with_concat);
                delete with_concat;
                delete copy;
            }
            else if (container_num == 7) {
                ImmutableSequence<int>* with_concat = create_immut_sequence<int>(items, index);
                ImmutableSequence<int>* copy = create_immut_sequence<int>(immut_sequence);
                delete immut_sequence;
                immut_sequence = copy->Concat(with_concat);
                delete with_concat;
                delete copy;
            }
            break;
        }
        default: break;
        }
        std::cout << "Ваша последовательность: ";
        if (container_num > 0 && container_num < 5) print(*container);
        else if (container_num > 4 && container_num < 7) print(*mut_sequence);
        else if (container_num == 7) print(*immut_sequence);
        std::cout << "Нажмите Enter для выхода в меню";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        std::cout << "\nВыберите метод:\n";
        std::cout << "1. GetFirst\n";
        std::cout << "2. GetLast\n"; 
        std::cout << "3. Get\n"; 
        std::cout << "4. GetSize\n";
        std::cout << "5. Append\n";
        std::cout << "6. Prepend\n";
        std::cout << "7. Set\n";
        std::cout << "8. InsertAt\n";
        std::cout << "9. Resize\n";
        std::cout << "10. RemoveAt\n";
        std::cout << "11. GetSubSequence\n";
        std::cout << "12. Concat\n";
        std::cout << "0. Выйти\n";
        std::cout << "Введите выбор: ";
    }
    return;
}

#endif // UI_HPP