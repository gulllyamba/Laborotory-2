#ifndef MUTABLESEQUENCE_HPP
#define MUTABLESEQUENCE_HPP

#include "Sequence.hpp"

template <typename T>
class MutableSequence : public Sequence<T>{
    public:
    virtual MutableSequence<T>* Set(int index, const T& value) = 0;
    virtual MutableSequence<T>* Append(const T& value) = 0;
    virtual MutableSequence<T>* Prepend(const T& value) = 0;
    virtual MutableSequence<T>* InsertAt(int index, const T&value) = 0;
    virtual MutableSequence<T>* Resize(int size) = 0;

    virtual MutableSequence<T>* GetSubSequence(int startIndex, int endIndex) const = 0;
    virtual MutableSequence<T>* Concat(MutableSequence<T>* other) const = 0;

    // template <typename Container>
    // virtual MutableSequence<T>* From(const Container& container) = 0;
    // template <typename U>
    // virtual MutableSequence<U>* Map(std::function<U(T)> f) const = 0;
    // virtual MutableSequence<T>* Where(std::function<bool(T)> f) const = 0;
    // virtual T Reduce(std::function<T(T, T)> f, MutableSequence<T>* other, const T& c) const = 0;


    virtual ~MutableSequence() = default;
};

#endif // MUTABLESEQUENCE_HPP 