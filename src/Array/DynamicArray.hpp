#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class DynamicArray;

template <typename T, bool IsConst>
class ArrayIterator {
    public:
        using value_type = T;
        using pointer = std::conditional_t<IsConst, const T*, T*>;
        using reference = std::conditional_t<IsConst, const T&, T&>;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;

        ArrayIterator(pointer ptr) : current(ptr) {}

        reference operator*() const {
            if (!current) {
                throw std::out_of_range("Iterator out of range");
            }
            return *current;
        }

        pointer operator->() const {
            if (!current) {
                throw std::out_of_range("Iterator out of range");
            }
            return current;
        }

        ArrayIterator& operator++() {
            ++current;
            return *this;
        }
        ArrayIterator operator++(int) {
            ArrayIterator temp = *this;
            ++current;
            return temp;
        }

        ArrayIterator& operator--() {
            --current;
            return *this;
        }
        ArrayIterator operator--(int) {
            ArrayIterator temp = *this;
            --current;
            return temp;
        }

        ArrayIterator operator+(difference_type n) const {
            return ArrayIterator(current + n);
        }
        ArrayIterator operator-(difference_type n) const {
            return ArrayIterator(current - n);
        }
        difference_type operator-(const ArrayIterator& other) const {
            return current - other.current;
        }

        bool operator==(const ArrayIterator& other) const {
            return current == other.current;
        }
        bool operator!=(const ArrayIterator& other) const {
            return !(current == other.current);
        }
        bool operator<(const ArrayIterator& other) const {
            return current < other.current;
        }
        bool operator>(const ArrayIterator& other) const {
            return current > other.current;
        }
        bool operator<=(const ArrayIterator& other) const {
            return current <= other.current;
        }
        bool operator>=(const ArrayIterator& other) const {
            return current >= other.current;
        }
    
        reference operator[](difference_type n) const {
            return *(current + n);
        }


    private:
        friend class DynamicArray<T>;
        pointer current;
};

template <typename T>
using AIterator = ArrayIterator<T, false>;
template <typename T>
using AConstIterator = ArrayIterator<T, true>;

template <typename T>
class DynamicArray {
    public:
        using value_type = T;
        using iterator = AIterator<T>;
        using const_iterator = AConstIterator<T>;

        iterator begin() { 
            return iterator(Data);
        }
        iterator end() {
            return iterator(Data + Size);
        }
        const_iterator begin() const {
            return const_iterator(Data);
        }
        const_iterator end() const {
            return const_iterator(Data + Size);
        }
        const_iterator cbegin() const {
            return const_iterator(Data);
        }
        const_iterator cend() const {
            return const_iterator(Data + Size);
        }

        DynamicArray(const T* items, int count);
        DynamicArray();
        DynamicArray(int size);
        DynamicArray(const DynamicArray<T> &other);
        DynamicArray(DynamicArray<T>&& other) noexcept;

        T GetFirst() const;
        T GetLast() const;
        T Get(int index) const;
        int GetSize() const;

        void Append(const T& value);
        void Prepend(const T& value);
        void Set(int index, const T& value);
        // void Set(int index, T&& value);
        void InsertAt(int index, const T& value);
        void Resize(int size);

        DynamicArray<T>* GetSubDynamicArray(int startIndex, int endIndex) const;
        DynamicArray<T>* Concat(const DynamicArray<T>* other) const;

        std::string toString() const;

        T& operator[](int index) {
            if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
            return Data[index];
        }
        const T& operator[](int index) const {
            if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
            return Data[index];
        }
        DynamicArray& operator=(const DynamicArray<T>& other) {
            if (this == &other) return *this;
            if (Data) delete [] Data;
            Size = other.Size;
            Data = new T[Size]{};
            for (int i = 0; i < Size; i++) {
                Data[i] = other.Data[i];
            }
            return *this;
        }
        DynamicArray& operator=(DynamicArray<T>&& other) noexcept {
            if (this == &other) return *this;
            if (Data) delete [] Data;
            Data = other.Data;
            Size = other.Size;
            other.Data = nullptr;
            other.Size = 0;
            return *this;
        }

        template <typename Container>
        DynamicArray<T>* From(const Container& container);
        template <typename U>
        DynamicArray<U>* Map(std::function<U(T)> f) const;
        template <typename U>
        DynamicArray<T>* FlatMap(std::function<DynamicArray<T>*(U)> f) const;
        DynamicArray<T>* Where(std::function<bool(T)> f) const;
        T Reduce(std::function<T(T, T)> f, const T& c) const;

        template <typename... Arrays>
        DynamicArray<std::tuple<T, typename Arrays::value_type...>>* Zip(const DynamicArray<T>* first, const Arrays*... arrays) const;
        template <typename... Tuples>
        std::tuple<DynamicArray<Tuples>...>* UnZip() const;

        ~DynamicArray();

    private:
        T* Data = nullptr;
        int Size = 0;

        template <typename U>
        friend class DynamicArray;
};

template <typename T>
DynamicArray<T>::DynamicArray(const T* items, int count) {
    if (count < 0) throw std::invalid_argument("Size cannot be negative");
    else if (count == 0) {
        Data = nullptr;
        Size = 0;
        return;
    }
    else if (items) {
        Size = count;
        Data = new T[Size]{};
        for (int i = 0; i < Size; i++) {
            Data[i] = items[i];
        }
    }
    else {
        Size = count;
        Data = new T[Size]{};
    }
}

template <typename T>
DynamicArray<T>::DynamicArray() : DynamicArray(nullptr, 0) {}

template <typename T>
DynamicArray<T>::DynamicArray(int size) : DynamicArray(nullptr, size) {}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other) : DynamicArray(other.Data, other.Size) {}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) noexcept {
    Data = other.Data;
    Size = other.Size;

    other.Data = nullptr;
    other.Size = 0;
}

template <typename T>
T DynamicArray<T>::GetFirst() const {
    if (!Data || Size <= 0) throw std::out_of_range("Array is empty");
    return Data[0];
}

template <typename T>
T DynamicArray<T>::GetLast() const {
    if (!Data || Size <= 0) throw std::out_of_range("Array is empty");
    return Data[Size - 1];
}

template <typename T>
T DynamicArray<T>::Get(int index) const {
    if (!Data || Size <= 0) throw std::out_of_range("Array is empty");
    if (index >= Size || index < 0) throw std::out_of_range("Index out of range");
    return Data[index];
}

template <typename T>
int DynamicArray<T>::GetSize() const {
    return Size;
}

template <typename T>
void DynamicArray<T>::Append(const T& value) {
    Resize(Size + 1);
    Data[Size - 1] = value;
}

template <typename T>
void DynamicArray<T>::Prepend(const T& value) {
    Resize(Size + 1);
    for (int i = Size - 1; i > 0; i--) {
        Data[i] = Data[i - 1];
    }
    Data[0] = value;
}

template <typename T>
void DynamicArray<T>::Set(int index, const T& value) {
    if (!Data || Size <= 0) return;
    if (index >= Size || index < 0) throw std::out_of_range("Index out of range");
    Data[index] = value;
    return;
}

// template <typename T>
// void DynamicArray<T>::Set(int index, T&& value) {
//     if (index >= Size || index < 0) {
//         //error
//         return;
//     }
//     Data[index] = std::move(value);
// }

template <typename T>
void DynamicArray<T>::InsertAt(int index, const T& value) {
    if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
    Resize(Size + 1);
    for (int i = Size - 1; i > index; i--) {
        Data[i] = Data[i - 1];
    }
    Data[index] = value;
    return;
}

template <typename T>
void DynamicArray<T>::Resize(int size) {
    if (size < 0) throw std::invalid_argument("Size cannot be negative");
    else if (size == 0) {
        delete [] Data;
        Data = nullptr;
    }
    else if (Size == size) return;
    else {
        T* newData = new T[size]{};
        for (int i = 0; i < std::min(Size, size); i++) {
            newData[i] = Data[i];
        }
        delete [] Data;
        Data = newData;
    }
    Size = size;
    return;
}

template <typename T>
DynamicArray<T>* DynamicArray<T>::GetSubDynamicArray(int startIndex, int endIndex) const {
    if (!Data || Size <= 0) return new DynamicArray<T>();
    if (startIndex < 0 || startIndex >= Size || endIndex > Size || startIndex > endIndex) throw std::out_of_range("Index out of range");
    DynamicArray<T>* array = new DynamicArray(endIndex - startIndex);
    for (int i = startIndex; i < endIndex; i++) {
        array->Data[i - startIndex] = Data[i];
    }
    return array;
}

template <typename T>
DynamicArray<T>* DynamicArray<T>::Concat(const DynamicArray<T>* other) const {
    DynamicArray<T>* result = new DynamicArray<T>(*this);
    if (!other || !other->Data || other->Size <= 0) return result;
    result->Resize(result->Size + other->Size);
    for (int i = other->Size; i > 0; i--) {
        result->Set(result->Size - i, other->Data[other->Size - i]);
    }
    return result;
}

template <typename T>
std::string DynamicArray<T>::toString() const {
    std::ostringstream oss;
    oss << "[";
    if (Size > 0 && Data) {
        oss << Get(0);
        for (int i = 1; i < Size; i++) {
            oss << ", " << Get(i);
        }
    }
    oss << "]";
    return oss.str();
}

template <typename T>
template <typename Container>
DynamicArray<T>* DynamicArray<T>::From(const Container& container) {
    if (Data) delete [] Data;
    Size = 0;
    for (auto it = container.begin(); it != container.end(); ++it) Size++;
    Data = new T[Size];
    for (auto it = container.begin(), i = 0; it != container.end(); ++it, i++) {
        Data[i] = *it;
    }
    return this;
}

template <typename T>
template <typename U>
DynamicArray<U>* DynamicArray<T>::Map(std::function<U(T)> f) const {
    DynamicArray<U>* result = new DynamicArray<U>(Size);
    if (!Data || Size <= 0) return result;
    for (int i = 0; i < result->Size; i++) {
        result->Data[i] = f(Data[i]);
    }
    return result;
}

template <typename T>
template <typename U>
DynamicArray<T>* DynamicArray<T>::FlatMap(std::function<DynamicArray<T>*(U)> f) const {
    DynamicArray<T>* result = new DynamicArray<T>();
    for (auto it = begin(); it != end(); ++it) {
        DynamicArray<T>* temp = f(*it);
        for (auto tempIt = temp->begin(); tempIt != temp->end(); ++tempIt) {
            result->Append(*tempIt);
        }
        if (temp) delete temp;
    }
    return result;
}

template <typename T>
DynamicArray<T>* DynamicArray<T>::Where(std::function<bool(T)> f) const {
    DynamicArray<T>* result = new DynamicArray<T>();
    if (!Data || Size <= 0) return result;
    for (int i = 0; i < Size; i++) {
        if (f(Data[i])) {
            result->Append(Data[i]);
        }
    }
    return result;
}

template <typename T>
T DynamicArray<T>::Reduce(std::function<T(T, T)> f, const T& c) const {
    if (!Data || Size <= 0) return c;
    T answer = f(Data[0], c);
    for (int i = 1; i < Size; i++) {
        answer = f(Data[i], answer);
    }
    return answer;
}

template <typename T>
template <typename... Arrays>
DynamicArray<std::tuple<T, typename Arrays::value_type...>>* DynamicArray<T>::Zip(const DynamicArray<T>* first, const Arrays*... arrays) const {
    DynamicArray<std::tuple<T, typename Arrays::value_type...>>* result = new DynamicArray<std::tuple<T, typename Arrays::value_type...>>();

    auto it_first = first->begin();
    auto iters = std::make_tuple(arrays->begin()...);

    auto all_valid = [&](const auto& iters) {
        bool valid = it_first != first->end();
        if (!valid) return false;

        auto check = [&]<size_t... Is>(std::index_sequence<Is...>) {
            return ((std::get<Is>(iters) != arrays->end()) && ...);
        };
        return valid && check(std::index_sequence_for<Arrays...>{});
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
std::tuple<DynamicArray<Tuples>...>* DynamicArray<T>::UnZip() const {
    std::tuple<DynamicArray<Tuples>...>* result = new std::tuple<DynamicArray<Tuples>...>();
    for (auto it = begin(); it != end(); ++it) {
        auto unzip = [&]<size_t... Is>(std::index_sequence<Is...>) {
            ((std::get<Is>(*result).Append(std::get<Is>(*it))), ...);
        };
        unzip(std::index_sequence_for<Tuples...>{});
    }
    return result;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    if (Data) delete [] Data;
}

#endif // DYNAMIC_ARRAY_HPP