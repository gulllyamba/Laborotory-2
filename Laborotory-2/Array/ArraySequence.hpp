#ifndef ARRAYSEQUENCE_HPP
#define ARRAYSEQUENCE_HPP

#include "../Sequence/Sequence.hpp"
#include "DynamicArray.hpp"

template <typename T>
class ArraySequence : public Sequence<T>{
    protected:
        DynamicArray<T>* array;

        virtual int GetCapacity() const = 0;

        ArraySequence<T>* ReserveInternal(int newCapacity) {
            array->Reserve(newCapacity);
            return this;
        }

        ArraySequence<T>* SetInternal(int index, const T& value) {
            array->Set(index, value);
            return this;
        }

        ArraySequence<T>* AppendInternal(const T& value) {
            array->Append(value);
            return this;
        }

        ArraySequence<T>* PrependInternal(const T& value) {
            array->Prepend(value);
            return this;
        }

        ArraySequence<T>* InsertAtInternal(int index, const T& value) {
            array->InsertAt(index, value);
            return this;
        }

        ArraySequence<T>* ResizeInternal(int size) {
            array->Resize(size);
            return this;
        }

        ArraySequence<T>* RemoveAtInternal(int index) {
            array->RemoveAt(index);
            return this;
        }

        virtual ArraySequence<T>* Instance() = 0;
        
    public:
        ArraySequence(const T* items, int count) {
            array = new DynamicArray<T>(items, count);
        }
        ArraySequence() : ArraySequence<T>(nullptr, 0) {}
        ArraySequence(int size) : ArraySequence<T>(nullptr, size) {}
        ArraySequence(const ArraySequence<T>& other) {
            array = new DynamicArray<T>(*(other.array));
        }
        ArraySequence(const DynamicArray<T>& other) {
            array = new DynamicArray<T>(other);
        }

        T& operator[](int index) {
            return array->operator[](index);
        }
        const T& operator[](int index) const {
            return array->operator[](index);
        }

        DynamicArray<T>* GetArray() const {
            return array;
        }
};

#endif // ARRAYSEQUENCE_HPP