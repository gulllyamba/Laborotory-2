#ifndef LISTSEQUENCE_HPP
#define LISTSEQUENCE_HPP

#include "../Sequence/Sequence.hpp"
#include "LinkedList.hpp"

template <typename T>
class ListSequence : public Sequence<T> {
    protected:

        ListSequence<T>* SetInternal(int index, const T& value) {
            list->Set(index, value);
            return this;
        }

        ListSequence<T>* AppendInternal(const T& value) {
            list->Append(value);
            return this;
        }

        ListSequence<T>* PrependInternal(const T& value) {
            list->Prepend(value);
            return this;
        }

        ListSequence<T>* InsertAtInternal(int index, const T& value) {
            list->InsertAt(index, value);
            return this;
        }

        ListSequence<T>* ResizeInternal(int size) {
            list->Resize(size);
            return this;
        }

        virtual ListSequence<T>* Instance() = 0;

    public:
        ListSequence(const T* items, int count) {
            list = new LinkedList<T>(items, count);
        }
        ListSequence() : ListSequence(nullptr, 0) {}
        ListSequence(int size) : ListSequence(nullptr, size) {}
        ListSequence(const ListSequence<T>& other) {
            list = new LinkedList<T>(*(other.list));
        }
        ListSequence(const LinkedList<T>& other) {
            list = new LinkedList<T>(other);
        }

        T& operator[](int index) {
            return list->operator[](index);
        }
        const T& operator[](int index) const {
            return list->operator[](index);
        }

        virtual ~ListSequence() {
            if (list) delete list;
        }

        LinkedList<T>* list;
};

#endif // LISTSEQUENCE_HPP