#ifndef ADAPTIVESEQUENCE_HPP
#define ADAPTIVESEQUENCE_HPP

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class AdaptiveSequence;

template <typename T, bool IsConst>
class AdaptIterator {
    public:
        using value_type = T;
        using pointer = std::conditional_t<IsConst, const T*, T*>;
        using reference = std::conditional_t<IsConst, const T&, T&>;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;

        AdaptIterator(pointer ptr) : current(ptr) {}

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

        AdaptIterator& operator++() {
            ++current;
            return *this;
        }
        AdaptIterator operator++(int) {
            AdaptIterator temp = *this;
            ++current;
            return temp;
        }

        AdaptIterator& operator--() {
            --current;
            return *this;
        }
        AdaptIterator operator--(int) {
            AdaptIterator temp = *this;
            --current;
            return temp;
        }

        AdaptIterator operator+(difference_type n) const {
            return AdaptIterator(current + n);
        }
        AdaptIterator operator-(difference_type n) const {
            return AdaptIterator(current - n);
        }
        difference_type operator-(const AdaptIterator& other) const {
            return current - other.current;
        }

        bool operator==(const AdaptIterator& other) const {
            return current == other.current;
        }
        bool operator!=(const AdaptIterator& other) const {
            return !(current == other.current);
        }
        bool operator<(const AdaptIterator& other) const {
            return current < other.current;
        }
        bool operator>(const AdaptIterator& other) const {
            return current > other.current;
        }
        bool operator<=(const AdaptIterator& other) const {
            return current <= other.current;
        }
        bool operator>=(const AdaptIterator& other) const {
            return current >= other.current;
        }
    
        reference operator[](difference_type n) const {
            return *(current + n);
        }


    private:
        friend class AdaptiveSequence<T>;
        pointer current;
};

template <typename T>
using AdIterator = AdaptIterator<T, false>;
template <typename T>
using AdConstIterator = AdaptIterator<T, true>;

template <typename T>
class AdaptiveSequence {
    public:
        using value_type = T;
        using iterator = AdIterator<T>;
        using const_iterator = AdConstIterator<T>;

        iterator begin() {
            return iterator(Data + correctLeft);
        }
        iterator end() {
            return iterator(Data + correctLeft + Size);
        }
        const_iterator begin() const {
            return const_iterator(Data + correctLeft);
        }
        const_iterator end() const {
            return const_iterator(Data + correctLeft + Size);
        }
        const_iterator cbegin() const {
            return const_iterator(Data + correctLeft);
        }
        const_iterator cend() const {
            return const_iterator(Data + correctLeft + Size);
        }

        AdaptiveSequence(T* items, int size) {
            if (size < 0) throw std::invalid_argument("Size cannot be negative");
            else if (size == 0) {
                Data = nullptr;
                Size = 0;
                correctLeft = 0;
                correctRight = 0;
                return;
            }
            else if (items) {
                Size = size;
                correctLeft = Size / 2;
                if (size % 2 == 0) correctRight = Size / 2;
                else correctRight = Size / 2 + 1;
                Data = new T[Size * 2]{};
                for (int i = 0; i < Size; i++) {
                    Data[i + correctLeft] = items[i];
                }
            }
            else {
                Size = size;
                correctLeft = Size / 2;
                if (size % 2 == 0) correctRight = Size / 2;
                else correctRight = Size / 2 + 1;
                Data = new T[Size * 2]{};
            }
        }
        AdaptiveSequence(): AdaptiveSequence(nullptr, 0) {}
        AdaptiveSequence(int size): AdaptiveSequence(nullptr, size) {}
        AdaptiveSequence(const AdaptiveSequence<T>& other) : AdaptiveSequence(other.Data, other.Size) {}
        AdaptiveSequence(AdaptiveSequence<T>&& other) noexcept {
            Data = other.Data;
            Size = other.Size;
            correctLeft = other.correctLeft;
            correctRight = other.correctRight;
        
            other.Data = nullptr;
            other.Size = 0;
            other.correctLeft = 0;
            other.correctRight = 0;
        }

        T& operator[](int index) {
            if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
            return Data[correctLeft + index];
        }
        const T& operator[](int index) const {
            if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
            return Data[correctLeft + index];
        }
        AdaptiveSequence& operator=(const AdaptiveSequence<T>& other) {
            if (this == &other) return *this;
            if (Data) delete [] Data;
            Size = other.Size;
            Data = new T[Size * 2]{};
            correctLeft = other.correctLeft;
            correctRight = other.correctRight;
            for (int i = 0; i < Size; i++) {
                Data[correctLeft + i] = other.Data[other.correctLeft + i];
            }
            return *this;
        }
        AdaptiveSequence& operator=(AdaptiveSequence<T>&& other) noexcept {
            if (this == &other) return *this;
            if (Data) delete [] Data;
            Data = other.Data;
            Size = other.Size;
            correctLeft = other.correctLeft;
            correctRight = other.correctRight;
            other.Data = nullptr;
            other.Size = 0;
            other.correctLeft = 0;
            other.correctRight = 0;
            return *this;
        }
        
        int GetCorrectLeft() const {
            return correctLeft;
        }
        int GetCorrectRight() const {
            return correctRight;
        }
        T GetFirst() const {
            if (!Data || Size <= 0) throw std::out_of_range("Array is empty");
            return Data[correctLeft];
        }
        T GetLast() const {
            if (!Data || Size <= 0) throw std::out_of_range("Array is empty");
            return Data[correctLeft + Size - 1];   
        }
        T Get(int index) const {
            if (!Data || Size <= 0) throw std::out_of_range("Array is empty");
            if (index >= Size || index < 0) throw std::out_of_range("Index out of range");
            return Data[correctLeft + index]; 
        }
        int GetSize() const {
            return Size;
        }
        
        AdaptiveSequence<T>* Append(const T& value) {
            if (Size == 0) {
                Resize(Size + 1);
                Data[correctLeft] = value;
            }
            else if (correctLeft == 0 && correctRight == 0) {
                Resize(Size);
                Data[correctLeft + Size] = value;
                Size++;
                correctRight--;
            }
            else if (correctRight == 0) {
                for (int i = 0; i < Size; i++) {
                    Data[correctLeft + i - 1] = Data[correctLeft + i];
                }
                Data[correctLeft + Size - 1] = value;
                Size++;
                correctLeft--;
            }
            else {
                Data[correctLeft + Size] = value;
                Size++;
                correctRight--;
            }
            return this;
        }
        AdaptiveSequence<T>* Prepend(const T& value) {
            if (Size == 0) {
                Resize(Size + 1);
                Data[correctLeft] = value;
            }
            else if (correctLeft == 0 && correctRight == 0) {
                Resize(Size);
                Data[correctLeft - 1] = value;
                Size++;
                correctLeft--;
            }
            else if (correctLeft == 0) {
                for (int i = 0; i < Size; i++) {
                    Data[correctLeft + Size - i] = Data[correctLeft + Size - i - 1];
                }
                Data[correctLeft] = value;
                Size++;
                correctRight--;
            }
            else {
                Data[correctLeft - 1] = value;
                Size++;
                correctLeft--;
            }
            return this;
        }
        AdaptiveSequence<T>* Set(int index, const T& value) {
            if (!Data || Size <= 0) throw std::out_of_range("Array is empty");
            if (index >= Size || index < 0) throw std::out_of_range("Index out of range");
            Data[correctLeft + index] = value;
            return this;
        }
        AdaptiveSequence<T>* InsertAt(int index, const T& value) {
            if (index < 0 || index >= Size) throw std::out_of_range("Index out of range");
            if (Size == 0) Resize(Size + 1);
            if (correctRight == 0 && correctLeft == 0) Resize(Size);
            if (correctLeft > correctRight) {
                for (int i = 0; i < index; i++) {
                    Data[correctLeft - 1 + i] = Data[correctLeft + i];
                }
                Data[correctLeft - 1 + index] = value;
                correctLeft--;
            }
            else {
                for (int i = Size; i > index; i--) {
                    Data[correctLeft + i] = Data[correctLeft + i - 1];
                }
                Data[correctLeft + index] = value;
                correctRight--;
            }
            Size++;
            return this;
        }
        AdaptiveSequence<T>* Resize(int size) {
            if (size < 0) throw std::invalid_argument("Size cannot be negative");
            else if (size == 0) {
                delete [] Data;
                Data = nullptr;
                Size = 0;
                correctLeft = 0;
                correctRight = 0;
            }
            else if (Size == size) {
                T* newData = new T[Size * 2]{};
                int new_correctLeft = Size / 2;
                int new_correctRight = Size / 2 + 1;
                if (Size % 2 == 0) new_correctRight = Size / 2;
                for (int i = 0; i < Size; i++) {
                    newData[new_correctLeft + i] = Data[correctLeft + i];
                }
                delete [] Data;
                Data = newData;
                correctLeft = new_correctLeft;
                correctRight = new_correctRight;
            }
            else {
                T* newData = new T[size * 2]{};
                int new_correctLeft = size / 2;
                int new_correctRight = size / 2 + 1;
                if (size % 2 == 0) new_correctRight = size / 2;
                for (int i = 0; i < std::min(Size, size); i++) {
                    newData[new_correctLeft + i] = Data[correctLeft + i];
                }
                delete [] Data;
                Data = newData;
                Size = size;
                correctLeft = new_correctLeft;
                correctRight = new_correctRight;
            }
            return this;
        }
        
        std::string toString(bool flag) const {
            std::ostringstream oss;
            oss << "[";
            if (Size > 0 && Data) {
                if (flag) {
                    oss << Get(0);
                    for (int i = 1; i < Size; i++) {
                        oss << ", " << Get(i);
                    }
                }
                else {
                    if (correctLeft > 0) {
                        oss << Data[0];
                        for (int i = 1; i < correctLeft; i++) oss << ", " << Data[i];
                        for (int i = 0; i < Size; i++) {
                            oss << ", " << Get(i);
                        }
                    }
                    else {
                        oss << Get(0);
                        for (int i = 1; i < Size; i++) {
                            oss << ", " << Get(i);
                        }
                    }
                    for (int i = 0; i < correctRight; i++) {
                        oss << ", " << Data[correctLeft + Size + i];
                    }
                }
            }
            oss << "]";
            return oss.str();
        }

        AdaptiveSequence<T>* GetSubSequence(int startIndex, int endIndex) const {
            AdaptiveSequence<T>* result = new AdaptiveSequence<T>(endIndex - startIndex);
            for (int i = startIndex; i < endIndex; i++) {
                result->Data[result->correctLeft + i - startIndex] = Get(i);
            }
            return result;
        }

        AdaptiveSequence<T>* Concat(AdaptiveSequence<T>* other) const {
            AdaptiveSequence<T>* result = new AdaptiveSequence<T>(this->Size + other->Size);
            for (int i = 0; i < this->Size; i++) {
                result->Data[result->correctLeft + i] = this->Get(i);
            }
            for (int i = 0; i < other->Size; i++) {
                result->Data[result->correctLeft + this->Size + i] = other->Get(i);
            }
            return result;
        }   

        template <typename Container>
        AdaptiveSequence<T>* From(const Container& container) {
            if (Data) delete [] Data;
            Size = 0;
            for (auto it = container.begin(); it != container.end(); ++it) Size++;
            Data = new T[Size * 2]{};
            correctLeft = Size / 2;
            correctRight = Size / 2;
            for (auto it = container.begin(), i = 0; it != container.end(); ++it, i++) {
                Data[correctLeft + i] = *it;
            }
            return this;
        }

        template <typename U>
        AdaptiveSequence<U>* Map(std::function<U(T)> f) const {
            AdaptiveSequence<U>* result = new AdaptiveSequence<U>(Size);
            if (!Data || Size <= 0) return result;
            for (int i = 0; i < result->Size; i++) {
                result->Data[result->correctLeft + i] = f(Data[correctLeft + i]);
            }
            return result;
        }

        template <typename U>
        AdaptiveSequence<T>* FlatMap(std::function<AdaptiveSequence<T>*(U)> f) const {
            AdaptiveSequence<T>* result = new AdaptiveSequence<T>();
            for (auto it = begin(); it != end(); ++it) {
                AdaptiveSequence<T>* temp = f(*it);
                for (auto tempIt = temp->begin(); tempIt != temp->end(); ++tempIt) {
                    result->Append(*tempIt);
                }
                if (temp) delete temp;
            }
            result->Resize(result->Size);
            return result;
        }

        AdaptiveSequence<T>* Where(std::function<bool(T)> f) const {
            AdaptiveSequence<T>* result = new AdaptiveSequence<T>();
            if (!Data || Size <= 0) return result;
            for (int i = 0; i < Size; i++) {
                if (f(Data[correctLeft + i])) {
                    result->Append(Data[correctLeft + i]);
                }
            }
            result->Resize(result->Size);
            return result;
        }

        T Reduce(std::function<T(T, T)> f, const T& c) const {
            if (!Data || Size <= 0) return c;
            T answer = f(Data[correctLeft], c);
            for (int i = 1; i < Size; i++) {
                answer = f(Data[correctLeft + i], answer);
            }
            return answer;
        }

        template <typename... Arrays>
        AdaptiveSequence<std::tuple<T, typename Arrays::value_type...>>* Zip(const AdaptiveSequence<T>* first, const Arrays*... arrays) const {
            AdaptiveSequence<std::tuple<T, typename Arrays::value_type...>>* result = new AdaptiveSequence<std::tuple<T, typename Arrays::value_type...>>();

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
            result->Resize(result->Size);
            return result;
        }

        template <typename... Tuples>
        std::tuple<AdaptiveSequence<Tuples>...>* UnZip() const {
            std::tuple<AdaptiveSequence<Tuples>...>* result = new std::tuple<AdaptiveSequence<Tuples>...>();
            for (auto it = begin(); it != end(); ++it) {
                auto unzip = [&]<size_t... Is>(std::index_sequence<Is...>) {
                    ((std::get<Is>(*result).Append(std::get<Is>(*it))), ...);
                };
                unzip(std::index_sequence_for<Tuples...>{});
            }
            return result;
        }

        ~AdaptiveSequence() {
            if (Data) delete [] Data;
        }
    
    private:
        T* Data = nullptr;
        int Size = 0;
        int correctLeft = 0;
        int correctRight = 0;

        template <typename U>
        friend class AdaptiveSequence;
};

#endif // ADAPTIVESEQUENCE_HPP