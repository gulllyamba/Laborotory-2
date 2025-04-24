#ifndef IMMUTABLEARRAYSEQUENCE
#define IMMUTABLEARRAYSEQUENCE

#include "ArraySequence.hpp"
#include "../Sequence/ImmutableSequence.hpp"

template <typename T>
class ImmutableArraySequence : virtual public ArraySequence<T>, virtual public ImmutableSequence<T> {
    public:
        ImmutableArraySequence(const T* items, int size) : ArraySequence<T>(items, size) {}
        ImmutableArraySequence() : ImmutableArraySequence<T>(nullptr, 0) {}
        ImmutableArraySequence(int size) : ImmutableArraySequence<T>(nullptr, size) {}
        ImmutableArraySequence(const ImmutableArraySequence<T>& other) : ArraySequence<T>(other) {}
        ImmutableArraySequence(const DynamicArray<T>& other) : ArraySequence<T>(other) {}

        T Get(int index) const override {
            return this->array->Get(index);
        }
        T GetFirst() const override {
            return this->array->GetFirst();
        }
        T GetLast() const override {
            return this->array->GetLast();
        }
        int GetSize() const override {
            return this->array->GetSize();
        }

        std::string toString() const override {
            return this->array->toString();
        }

        ImmutableArraySequence<T>* Set(int index, const T& value) const override {
            return (const_cast<ImmutableArraySequence<T>*>(this))->Instance()->SetInternal(index, value);
        }
        
        ImmutableArraySequence<T>* Append(const T& value) const override {
            return (const_cast<ImmutableArraySequence<T>*>(this))->Instance()->AppendInternal(value);
        }
        
        ImmutableArraySequence<T>* Prepend(const T& value) const override {
            return (const_cast<ImmutableArraySequence<T>*>(this))->Instance()->PrependInternal(value);
        }
        
        ImmutableArraySequence<T>* InsertAt(int index, const T& value) const override {
            return (const_cast<ImmutableArraySequence<T>*>(this))->Instance()->InsertAtInternal(index, value);
        }
        
        ImmutableArraySequence<T>* Resize(int size) const override {
            return (const_cast<ImmutableArraySequence<T>*>(this))->Instance()->ResizeInternal(size);
        }

        ImmutableArraySequence<T>* GetSubSequence(int startIndex, int endIndex) const override {
            DynamicArray<T>* temp_arr = this->array->GetSubDynamicArray(startIndex, endIndex);
            ImmutableArraySequence<T>* temp = new ImmutableArraySequence<T>(*temp_arr);
            delete temp_arr;
            return temp;
            return (const_cast<ImmutableArraySequence<T>*>(this))->Instance()->array->
        }
        ImmutableArraySequence<T>* Concat(ImmutableSequence <T>* other) const override {
            // ImmutableArraySequence<T>* temp = new ImmutableArraySequence<T>(*this);
            return dynamic_cast<ImmutableArraySequence<T>*>((const_cast<ImmutableArraySequence<T>*>(this))->Instance()->ConcatInternal(dynamic_cast<ImmutableArraySequence<T>*>(other)));
        }

    private:
        ImmutableArraySequence<T>* Instance() override {
            return new ImmutableArraySequence<T>(*this);
        }
};

#endif // IMMUTABLEARRAYSEQUENCE
