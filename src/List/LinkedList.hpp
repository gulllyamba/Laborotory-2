#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <functional>
#include <tuple>
#include <utility>
#include <sstream>

template <typename T>
class LinkedList;

template <typename T, bool IsConst>
class ListIterator;

template <typename T>
class TNode {
    public:
        TNode(T value) : Value(value), Next_Node(nullptr) {}
    private:
        template<typename U>
        friend class LinkedList;
        template <typename U, bool IsConst>
        friend class ListIterator;
        T Value;
        TNode<T>* Next_Node;
};

template <typename T, bool IsConst>
class ListIterator {
    public:
        using value_type = T;
        using pointer = std::conditional_t<IsConst, const T*, T*>;
        using reference = std::conditional_t<IsConst, const T&, T&>;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        ListIterator(TNode<T>* node) : current(node) {}

        reference operator*() const {
            if (!current) {
                throw std::out_of_range("Iterator out of range");
            }
            return current->Value;
        }

        pointer operator->() const {
            if (!current) {
                throw std::out_of_range("Iterator out of range");
            }
            return &(current->Value);
        }

        ListIterator& operator++() {
            if (current) {
                current = current->Next_Node;
            }
            return *this;
        }

        ListIterator operator++(int) {
            ListIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const ListIterator& other) const {
            return current == other.current;
        }
        bool operator!=(const ListIterator& other) const {
            return !(*this == other);
        } 

    private:
        friend class LinkedList<T>;
        TNode<T>* current;
};

template <typename T>
using Iterator = ListIterator<T, false>;
template <typename T>
using ConstIterator = ListIterator<T, true>;

template <typename T>
class LinkedList {
    public:
        using value_type = T;
        using iterator = Iterator<T>;
        using const_iterator = ConstIterator<T>;

        iterator begin() { 
            return iterator(Head);
        }
        iterator end() {
            return iterator(nullptr);
        }
        const_iterator begin() const {
            return const_iterator(Head);
        }
        const_iterator end() const {
            return const_iterator(nullptr);
        }
        const_iterator cbegin() const {
            return const_iterator(Head);
        }
        const_iterator cend() const {
            return const_iterator(nullptr);
        }

        LinkedList(const T* items, int count);
        LinkedList();
        LinkedList(int size);
        LinkedList(const LinkedList<T>& other);

        void Append(const T& value);
        void Prepend(const T& value);
        void Set(int index, const T& value);
        void InsertAt(int index, const T& value);
        void Resize(int size);

        T GetFirst() const;
        T GetLast() const;
        T Get(int index) const;
        int GetSize() const;

        LinkedList<T>* GetSubList(int startIndex, int endIndex) const;
        LinkedList<T>* Concat(LinkedList<T> *other) const;

        std::string toString() const;

        T& operator[](int index) {
            if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
            TNode<T>* Actual_Node = Head;
            for (int i = 1; i <= index; i++) {
                Actual_Node = Actual_Node->Next_Node;
            }
            return Actual_Node->Value;
        }
        const T& operator[](int index) const {
            if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
            TNode<T>* Actual_Node = Head;
            for (int i = 1; i <= index; i++) {
                Actual_Node = Actual_Node->Next_Node;
            }
            return Actual_Node->Value;
        }
        LinkedList& operator=(const LinkedList<T>& other) {
            if (this == &other) return *this;
            if (!other.Head || !other) {
                Head = nullptr;
                Last = nullptr;
            }
            if (Head) Delete();
            TNode<T>* Actual_Node = other.Head;
            Head = new TNode<T>(Actual_Node->Value);
            Last = Head;
            for (int i = 1; i < other.Size; i++) {
                Actual_Node = Actual_Node->Next_Node;
                Last->Next_Node = new TNode<T>(Actual_Node->Value);
                Last = Last->Next_Node;
            }
            Size = other.Size;
            return *this;
        }

        template <typename Container>
        LinkedList<T>* From(const Container& container);
        template <typename U>
        LinkedList<U>* Map(std::function<U(T)> f) const;
        template <typename U>
        LinkedList<T>* FlatMap(std::function<LinkedList<T>*(U)> f) const;
        LinkedList<T>* Where(std::function<bool(T)> f) const;
        T Reduce(std::function<T(T, T)> f, const LinkedList<T>* other, const T& c) const;

        template <typename... Lists>
        LinkedList<std::tuple<T, typename Lists::value_type...>>* Zip(const LinkedList<T>* first, const Lists*... lists) const;
        template <typename... Tuples>
        std::tuple<LinkedList<Tuples>...>* UnZip() const;

        void Delete();

        ~LinkedList();

    private:
        TNode<T>* Head = nullptr;
        TNode<T>* Last = nullptr;
        int Size = 0;

        template<typename U>
        friend class LinkedList;
};

template <typename T>
LinkedList<T>::LinkedList(const T* items, int count) {
    if (count < 0) throw std::invalid_argument("Size cannot be negative");
    else if (count == 0 || !items) {
        Head = nullptr;
        Last = nullptr;
        Size = 0;
        return;
    }
    else if (items) {
        Size = count;
        Head = new TNode<T>(items[0]);
        Last = Head;
        for (int i = 1; i < Size; i++) {
            Last->Next_Node = new TNode<T>(items[i]);
            Last = Last->Next_Node;
        }
    }
    else {
        Size = count;
        Head = new TNode<T>(T{});
        Last = Head;
        for (int i = 1; i < Size; i++) {
            Last->Next_Node = new TNode<T>(T{});
            Last = Last->Next_Node;
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList() : LinkedList(nullptr, 0) {}

template <typename T>
LinkedList<T>::LinkedList(int size) : LinkedList(nullptr, size) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : Head(nullptr), Last(nullptr), Size(0) {
    if (other.Head) {
        TNode<T>* Actual_Node = other.Head;
        Head = new TNode<T>(Actual_Node->Value);
        Last = Head;
        for (int i = 1; i < other.Size; i++) {
            Actual_Node = Actual_Node->Next_Node;
            Last->Next_Node = new TNode<T>(Actual_Node->Value);
            Last = Last->Next_Node;
        }
        Size = other.Size;
    }
}

template <typename T>
T LinkedList<T>::GetFirst() const {
    if (Size <= 0 || !Head || !Last) throw std::out_of_range("List is empty");
    return Head->Value;
}

template <typename T>
T LinkedList<T>::GetLast() const {
    if (Size <= 0 || !Head || !Last) throw std::out_of_range("List is empty");
    return Last->Value;
}

template <typename T>
T LinkedList<T>::Get(int index) const {
    if (!Head || !Last || Size <= 0) throw std::out_of_range("List is empty");
    if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
    TNode<T>* Actual_Node = Head;
    for (int i = 1; i <= index; i++) {
        Actual_Node = Actual_Node->Next_Node;
    }
    return Actual_Node->Value;
}

template <typename T>
int LinkedList<T>::GetSize() const {
    return Size;
}

template <typename T>
void LinkedList<T>::Append(const T& value) {
    TNode<T>* new_Node = new TNode<T>(value);
    if (!Head) {
        Head = new_Node;
        Last = new_Node;
    }
    else {
        Last->Next_Node = new_Node;
        Last = new_Node;
    } 
    Size++;
    return;
}

template <typename T>
void LinkedList<T>::Prepend(const T& value) {
    TNode<T>* new_Node = new TNode<T>(value);
    if (Head == nullptr) {
        Head = new_Node;
        Last = new_Node;
    }
    else {
        new_Node->Next_Node = Head;
        Head = new_Node;
    }
    Size++;
    return;
}

template <typename T>
void LinkedList<T>::Set(int index, const T& value) {
    if (!Head || !Last || Size <= 0) return;
    if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
    TNode<T>* Actual_Node = Head;
    for (int i = 1; i <= index; i++) {
        Actual_Node = Actual_Node->Next_Node;
    }
    Actual_Node->Value = value;
    return;
}

template <typename T>
void LinkedList<T>::InsertAt(int index, const T& value) {
    if (index < 0 || index > Size) throw std::out_of_range("Index out of range");
    else if (index == 0 || index == Size) Append(value);
    else {
        TNode<T>* Actual_Node = Head;
        for (int i = 1; i < index; i++) {
            Actual_Node = Actual_Node->Next_Node;
        }
        TNode<T>* new_Node = new TNode<T>(value);
        new_Node->Next_Node = Actual_Node->Next_Node;
        Actual_Node->Next_Node = new_Node;
        Size++;
    }
    return;
}

template <typename T>
void LinkedList<T>::Resize(int size) {
    if (size < 0) throw std::invalid_argument("Size cannot be negative");
    else if (size == 0) {
        Delete();
        Head = nullptr;
        Last = nullptr;
    }
    else if (Head == nullptr) {
        Head = new TNode<T>(T{});
        Last = Head;
        for (int i = 1; i < size; i++) {
            Last->Next_Node = new TNode<T>(T{});
            Last = Last->Next_Node;
        }
    }
    else {
        if (size < Size) {
            TNode<T>* last = Head;
            for (int i = 1; i < size; i++) {
                last = last->Next_Node;
            }
            Last = last;
            last = last->Next_Node;
            while (last != nullptr) {
                TNode<T>* deleted_Node = last;
                last = last->Next_Node;
                delete deleted_Node;
            }
            if (Last->Next_Node) Last->Next_Node = nullptr;
        }
        else if (size > Size) {
            for (int i = size; i < Size; i++) {
                Last->Next_Node = new TNode<T>(T{});
                Last = Last->Next_Node;
            }
        }
    }
    Size = size;
    return;

}

template <typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex) const {
    if (!Head || !Last || Size <= 0) return new LinkedList<T>();
    if (startIndex < 0 || startIndex >= Size || endIndex > Size || startIndex > endIndex) throw std::out_of_range("Index out of range");
    LinkedList<T>* list = new LinkedList<T>(endIndex - startIndex);
    TNode<T>* Actual_Node = Head;
    for (int i = 1; i <= startIndex; i++) {
        Actual_Node = Actual_Node->Next_Node;
    }
    list->Head->Value = Actual_Node->Value;
    list->Last = list->Head;
    for (int i = startIndex + 1; i < endIndex; i++) {
        Actual_Node = Actual_Node->Next_Node;
        list->Last = list->Last->Next_Node;
        list->Last->Value = Actual_Node->Value;
    }
    return list;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *other) const {
    LinkedList<T>* result = new LinkedList<T>(*this);
    if (!other || !other->Head || !other->Last || other->Size <= 0) return result;
    TNode<T>* Actual_Node = other->Head;
    result->Last->Next_Node = new TNode<T>(Actual_Node->Value);
    result->Last = result->Last->Next_Node;
    for (int i = 1; i < other->Size; i++) {
        Actual_Node = Actual_Node->Next_Node;
        result->Last->Next_Node = new TNode<T>(Actual_Node->Value);
        result->Last = result->Last->Next_Node;
    }
    result->Size += other->Size;
    return result;
}

template <typename T>
std::string LinkedList<T>::toString() const {
    // if constexpr (!std::is_same_v<T, int> && 
    //           !std::is_same_v<T, double> && 
    //           !std::is_same_v<T, char> && 
    //           !std::is_same_v<T, std::string>) return "This type is not allowed for toString";
    std::ostringstream oss;
    oss << "[";
    if (Size > 0 && Head ) {
        TNode<T>* Actual_Node = Head;
        oss << Actual_Node->Value;
        for (int i = 1; i < Size; i++) {
            Actual_Node = Actual_Node->Next_Node;
            oss << ", " << Actual_Node->Value;
        }
    }
    oss << "]";
    return oss.str();
}

template <typename T>
template <typename Container>
LinkedList<T>* LinkedList<T>::From(const Container& container) {
    // LinkedList<T>* result = new LinkedList<T>();
    Delete();
    for (auto it = container.begin(); it != container.end(); ++it) {
        Append(*it);
    }
    return this;
}

template <typename T>
template <typename U>
LinkedList<U>* LinkedList<T>::Map(std::function<U(T)> f) const {
    LinkedList<U>* result = new LinkedList<U>();
    if (!Head || !Last || Size <= 0) return result;
    result->Size = Size;
    TNode<T>* temp = Head;
    result->Head = new TNode(f(temp->Value));
    TNode<U>* Actual_Node = result->Head;
    for (int i = 1 ; i < Size; i++) {
        temp = temp->Next_Node;
        Actual_Node->Next_Node = new TNode(f(temp->Value));
        Actual_Node = Actual_Node->Next_Node;
    }
    result->Last = Actual_Node;
    return result;
}

template <typename T>
template <typename U>
LinkedList<T>* LinkedList<T>::FlatMap(std::function<LinkedList<T>*(U)> f) const {
    LinkedList<T>* result = new LinkedList<T>();
    for (auto it = begin(); it != end(); ++it) {
        LinkedList<T>* temp = f(*it);
        for (auto tempIt = temp->begin(); tempIt != temp->end(); ++tempIt) {
            result->Append(*tempIt);
        }
        delete temp;
    }
    return result;
}

template <typename T>
LinkedList<T>* LinkedList<T>::Where(std::function<bool(T)> f) const {
    LinkedList<T>* result = new LinkedList<T>();
    if (!Head || !Last || Size <= 0) return result;
    TNode<T>* Actual_Node = Head;
    while (Actual_Node != nullptr && !f(Actual_Node->Value)) {
        Actual_Node = Actual_Node->Next_Node;
    }
    if (!Actual_Node) return result;
    result->Head = new TNode(Actual_Node->Value);
    result->Last = result->Head;
    result->Size++;
    TNode<T>* temp = result->Head;
    Actual_Node = Actual_Node->Next_Node;
    while (Actual_Node) {
        if (f(Actual_Node->Value)) {
            temp->Next_Node = new TNode(Actual_Node->Value);
            temp = temp->Next_Node;
            result->Last = temp;
            result->Size++;
        }
        Actual_Node = Actual_Node->Next_Node;
    }
    return result;
}

template <typename T>
T LinkedList<T>::Reduce(std::function<T(T, T)> f, const LinkedList<T>* other, const T& c) const {
    if (!other || !other->Head || !other->Last || other->Size <= 0) return c;
    T answer = f(other->Head->Value, c);
    TNode<T>* Actual_Node = other->Head->Next_Node;
    for (int i = 1; i < other->Size; i++) {
        answer = f(Actual_Node->Value, answer);
        Actual_Node = Actual_Node->Next_Node;
    }
    return answer;
}

template <typename T>
template <typename... Lists>
LinkedList<std::tuple<T, typename Lists::value_type...>>* LinkedList<T>::Zip(const LinkedList<T>* first, const Lists*... lists) const {
    LinkedList<std::tuple<T, typename Lists::value_type...>>* result = new LinkedList<std::tuple<T, typename Lists::value_type...>>();

    auto it_first = first->begin();
    auto iters = std::make_tuple(lists->begin()...);

    auto all_valid = [&](const auto& iters) {
        bool valid = it_first != first->end();
        if (!valid) return false;

        auto check = [&]<size_t... Is>(std::index_sequence<Is...>) {
            return ((std::get<Is>(iters) != lists->end()) && ...);
        };
        return valid && check(std::index_sequence_for<Lists...>{});
    };

    while (all_valid(iters)) {
        auto tuple = std::apply([&](const auto&... its) {
            return std::make_tuple(*it_first, (*its)...);
        }, iters);
        result->Append(tuple);

        ++it_first;
        std::apply([](auto&... its) {
            ((++its), ...);
        }, iters);
    }
    return result;
}

template <typename T>
template <typename... Tuples>
std::tuple<LinkedList<Tuples>...>* LinkedList<T>::UnZip() const {
    std::tuple<LinkedList<Tuples>...>* result = new std::tuple<LinkedList<Tuples>...>();
    for (auto it = begin(); it != end(); ++it) {
        auto unzip = [&]<size_t... Is>(std::index_sequence<Is...>) {
            ((std::get<Is>(*result).Append(std::get<Is>(*it))), ...);
        };
        unzip(std::index_sequence_for<Tuples...>{});
    }
    return result;
}

template <typename T>
void LinkedList<T>::Delete() {
    while (Head != nullptr) {
        TNode<T>* Actual_Node = Head;
        Head = Head->Next_Node;
        delete Actual_Node;
    }
    Last = nullptr;
    Size = 0;
    return;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Delete();
}

#endif // LINKED_LIST_HPP