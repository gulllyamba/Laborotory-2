#ifndef SEGMENTEDLIST_HPP
#define SEGMENTEDLIST_HPP

#include "Array/DynamicArray.hpp"

template <typename T>
class Segment;

template <typename T>
class SegmentedList;

template <typename T, bool IsConst>
class SegmentedListIterator : public IIterator<T, IsConst> {
    public:
        using value_type = typename IIterator<T, IsConst>::value_type;
        using pointer = std::conditional_t<IsConst, const T*, T*>;
        using reference = typename IIterator<T, IsConst>::reference;
        using difference_type = typename IIterator<T, IsConst>::difference_type;
        using iterator_category = std::bidirectional_iterator_tag;

        SegmentedListIterator(DynamicArray<Segment<T>>* segments, int segmentIndex, int elementIndex) : segments(segments), segmentIndex(segmentIndex), elementIndex(elementIndex) {}

        bool HasNext() const override {
            return segments && segmentIndex < segments->GetSize() && elementIndex < (*segments)[segmentIndex].Array_Size;
        }
        reference Current() override {
            return **this;
        }
        void MoveNext() override {
            ++(*this);
        }

        reference operator*() const {
            if (!segments || segmentIndex >= segments->GetSize() || elementIndex >= (*segments)[segmentIndex].Array_Size) throw std::out_of_range("Iterator out of range");
            return (*(*segments)[segmentIndex].Array)[elementIndex];
        }

        pointer operator->() const {
            if (!segments || segmentIndex >= segments->GetSize() || elementIndex >= (*segments)[segmentIndex].Array_Size) throw std::out_of_range("Iterator out of range");
            return &(*(*segments)[segmentIndex].Array)[elementIndex];
        }

        SegmentedListIterator operator++() {
            if (!segments || segmentIndex >= segments->GetSize()) throw std::out_of_range("Iterator out of range");
            elementIndex++;
            while (segmentIndex < segments->GetSize() && elementIndex >= (*segments)[segmentIndex].Array_Size) {
                elementIndex = 0;
                segmentIndex++;
            }
            return *this;
        }
        SegmentedListIterator operator++(int) {
            SegmentedListIterator temp = *this;
            ++(*this);
            return temp;
        }

        SegmentedListIterator operator--() {
            if (!segments || (segmentIndex == 0 && elementIndex == 0)) throw std::out_of_range("Iterator out of range");
            elementIndex--;
            while (segmentIndex > 0 && elementIndex < 0) {
                segmentIndex--;
                elementIndex = (*segments)[segmentIndex].Array_Size - 1;
            }
            return *this;
        }
        SegmentedListIterator operator--(int) {
            SegmentedListIterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const SegmentedListIterator& other) const {
            return segments == other.segments && segmentIndex == other.segmentIndex && elementIndex == other.elementIndex;
        }
        bool operator!=(const SegmentedListIterator& other) const {
            return !(*this == other);
        }

    private:
        DynamicArray<Segment<T>>* segments;
        int segmentIndex;
        int elementIndex;
};

template <typename T>
using SLIterator = SegmentedListIterator<T, false>;
template <typename T>
using SLConstIterator = SegmentedListIterator<T, true>;

template <typename T>
class Segment {
    public:
        Segment(T* items, int size) : Array(new DynamicArray<T>(items, size)), Array_Size(size) {}
        Segment(int size) : Array(new DynamicArray<T>(size)), Array_Size(size) {}
        Segment() : Array(new DynamicArray<T>()), Array_Size(0) {}
        Segment(const Segment<T>& other) : Array(new DynamicArray<T>(*other.Array)), Array_Size(other.Array_Size) {}
        Segment(Segment<T>&& other) : Array(new DynamicArray<T>(*other.Array)), Array_Size(other.Array_Size) {
            other.Array = nullptr;
            other.Array_Size = 0;
        }

        T& operator[](int index) {
            if (index < 0 || index >= Array_Size) throw std::out_of_range("Index out of range");
            return (*Array)[index];
        }
        const T& operator[](int index) const {
            if (index < 0 || index >= Array_Size) throw std::out_of_range("Index out of range");
            return (*Array)[index];
        }
        Segment& operator=(const Segment<T>& other) {
            if (this != &other) {
                delete Array;
                Array = new DynamicArray<T>(*other.Array);
                Array_Size = other.Array_Size;
            }
            return *this;
        }
        Segment& operator=(Segment<T>&& other) noexcept {
            if (this != &other) {
                delete Array;
                Array = other.Array;
                Array_Size = other.Array_Size;
                other.Array = nullptr;
                other.Array_Size = 0;
            }
            return *this;
        }

        int GetSegmentCapacity() const {
            return Array->GetCapacity();
        }

        int GetSegmentSize() const {
            return Array_Size;
        }

        ~Segment() {
            delete Array;
        }
    private:
        DynamicArray<T>* Array = nullptr;
        int Array_Size = 0;
        friend class SegmentedList<T>;
        friend class SegmentedListIterator<T, false>;
        friend class SegmentedListIterator<T, true>;
};

template <typename T>
class SegmentedList : public IEnumerable<T> {
    public:
        using value_type = T;
        using iterator = SLIterator<T>;
        using const_iterator = SLConstIterator<T>;

        iterator begin() { 
            return iterator(Segments, 0, 0);
        }
        iterator end() {
            return iterator(Segments, Segments_Size, 0);
        }
        const_iterator begin() const {
            return const_iterator(Segments, 0, 0);
        }
        const_iterator end() const {
            return const_iterator(Segments, Segments_Size, 0);
        }
        const_iterator cbegin() const {
            return const_iterator(Segments, 0, 0);
        }
        const_iterator cend() const {
            return const_iterator(Segments, Segments_Size, 0);
        }

        std::unique_ptr<IIterator<T, false>> GetIterator() override {
            return std::make_unique<iterator>(Segments, 0, 0);
        }
        std::unique_ptr<IIterator<T, true>> GetConstIterator() const override {
            return std::make_unique<const_iterator>(Segments, 0, 0);
        }

        SegmentedList(T* items, int size) {
            if (size < 0) throw std::invalid_argument("Size cannot be negative");
            Segments_Size = (size + (MAX_SEGMENT_CAPACITY / 2) - 1) / (MAX_SEGMENT_CAPACITY / 2);
            Segments = new DynamicArray<Segment<T>>(Segments_Size);
            for (int i = 0; i < Segments_Size; i++) {
                int start = i * (MAX_SEGMENT_CAPACITY / 2);
                int array_size = std::min(MAX_SEGMENT_CAPACITY / 2, size - start);
                Elements_Size += array_size;
                if (items) (*Segments)[i] = Segment<T>(items + start, array_size);
                else (*Segments)[i] = Segment<T>(array_size);
            }
            if (Segments_Size > 0) (*Segments)[Segments_Size - 1].Array->Reserve(MAX_SEGMENT_CAPACITY);
        }
        SegmentedList() : SegmentedList<T>(nullptr, 0) {}
        SegmentedList(int size) : SegmentedList<T>(nullptr, size) {}
        SegmentedList(const SegmentedList<T>& other) {
            if (other.Elements_Size < 0) throw std::out_of_range("SegmentedList is empty");
            Segments_Size = other.Segments_Size;
            Elements_Size = other.Elements_Size;
            Segments = new DynamicArray<Segment<T>>(Segments_Size);
            for (int i = 0; i < Segments_Size; i++) {
                (*Segments)[i] = Segment<T>((*other.Segments)[i]);
            }
        }


        T GetFirst() const {
            if (!Segments || Segments_Size <= 0) throw std::out_of_range("SegmentedList is empty");
            return (*Segments)[0].Array->GetFirst();
        }
        T GetLast() const {
            if (!Segments || Segments_Size <= 0) throw std::out_of_range("SegmentedList is empty");
            return (*Segments)[Segments_Size - 1].Array->GetLast();
        }
        T Get(int index) const {
            if (!Segments || Segments_Size <= 0) throw std::out_of_range("SegmentedList is empty");
            if (index >= Elements_Size || index < 0) throw std::out_of_range("Index out of range");
            for (int i = 0; i < Segments_Size; i++) {
                int local_size = (*Segments)[i].Array_Size;
                if (index >= local_size) index -= local_size;
                else return (*Segments)[i].Array->Get(index);
            }
        }
        
        int GetSize() const {
            return Elements_Size;
        }
        
        int GetCapacity() const {
            return Segments->GetCapacity();
        }

        void Reserve(int newCapacity) {
            Segments->Reserve(newCapacity);
        }

        void Append(const T& value) {
            if (Segments_Size >= GetCapacity()) Reserve(Segments_Size * 2);
            if (Segments_Size > 0 && (*Segments)[Segments_Size - 1].Array_Size < MAX_SEGMENT_CAPACITY) {
                (*Segments)[Segments_Size - 1].Array->Append(value);
                (*Segments)[Segments_Size - 1].Array_Size++;
            }
            else {
                Segment<T>* temp_segment = new Segment<T>();
                temp_segment->Array->Reserve(MAX_SEGMENT_CAPACITY);
                temp_segment->Array->Append(value);
                temp_segment->Array_Size++;
                Segments->Append(*temp_segment);
                Segments_Size++;
                delete temp_segment;
            }
            Elements_Size++;
        }
        void Append(const T&& value) {
            if (Segments_Size >= GetCapacity()) Reserve(Segments_Size * 2);
            if (Segments_Size > 0 && (*Segments)[Segments_Size - 1].Array_Size < MAX_SEGMENT_CAPACITY) {
                (*Segments)[Segments_Size - 1].Array->Append(std::move(value));
                (*Segments)[Segments_Size - 1].Array_Size++;
            }
            else {
                Segment<T>* temp_segment = new Segment<T>();
                temp_segment->Array->Reserve(MAX_SEGMENT_CAPACITY);
                temp_segment->Array->Append(std::move(value));
                temp_segment->Array_Size++;
                Segments->Append(*temp_segment);
                Segments_Size++;
                delete temp_segment;
            }
            Elements_Size++;
        }

        void Prepend(const T& value) {
            if (Segments_Size >= GetCapacity()) Reserve(Segments_Size * 2);
            if (Segments_Size > 0 && (*Segments)[0].Array_Size < MAX_SEGMENT_CAPACITY) {
                (*Segments)[0].Array->Prepend(value);
                (*Segments)[0].Array_Size++;
            }
            else {
                Segment<T>* temp_segment = new Segment<T>();
                temp_segment->Array->Reserve(MAX_SEGMENT_CAPACITY);
                temp_segment->Array->Prepend(value);
                temp_segment->Array_Size++;
                Segments->Prepend(*temp_segment);
                Segments_Size++;
                delete temp_segment;
            }
            Elements_Size++;
        }
        void Prepend(const T&& value) {
            if (Segments_Size >= GetCapacity()) Reserve(Segments_Size * 2);
            if (Segments_Size > 0 && (*Segments)[0].Array_Size < MAX_SEGMENT_CAPACITY) {
                (*Segments)[0].Array->Prepend(std::move(value));
                (*Segments)[0].Array_Size++;
            }
            else {
                Segment<T>* temp_segment = new Segment<T>();
                temp_segment->Array->Reserve(MAX_SEGMENT_CAPACITY);
                temp_segment->Array->Prepend(std::move(value));
                temp_segment->Array_Size++;
                Segments->Prepend(*temp_segment);
                Segments_Size++;
                delete temp_segment;
            }
            Elements_Size++;
        }

        void Set(int index, const T& value) {
            if (!Segments || Segments_Size <= 0) throw std::out_of_range("SegmentedList is empty");
            if (index >= Elements_Size || index < 0) throw std::out_of_range("Index out of range");
            for (int i = 0; i < Segments_Size; i++) {
                int local_size = (*Segments)[i].Array_Size;
                if (index >= local_size) index -= local_size;
                else (*Segments)[i].Array->Set(index, value);
            }
        }
        void Set(int index, const T&& value) {
            if (!Segments || Segments_Size <= 0) throw std::out_of_range("SegmentedList is empty");
            if (index >= Elements_Size || index < 0) throw std::out_of_range("Index out of range");
            for (int i = 0; i < Segments_Size; i++) {
                int local_size = (*Segments)[i].Array_Size;
                if (index >= local_size) index -= local_size;
                else (*Segments)[i].Array->Set(index, std::move(value));
            }
        }

        void InsertAt(int index, const T& value) {
            if (!Segments || Segments_Size < 0) throw std::out_of_range("SegmentedList is empty");
            if (index > Elements_Size || index < 0) throw std::out_of_range("Index out of range");
            if (Segments_Size >= GetCapacity()) Reserve(Segments_Size * 2);
            if (index == Elements_Size) {
                Append(value);
                return;
            }
            int i = 0;
            while (index >= (*Segments)[i].Array_Size) {
                index -= (*Segments)[i].Array_Size;
                i++;
            }
            if ((*Segments)[i].Array_Size < MAX_SEGMENT_CAPACITY) {
                (*Segments)[i].Array->InsertAt(index, value);
                (*Segments)[i].Array_Size++;
            }
            else {
                if (Segments_Size > i + 1 && (*Segments)[i + 1].Array_Size < MAX_SEGMENT_CAPACITY) {
                    (*Segments)[i + 1].Array->Prepend((*Segments)[i].Array->GetLast());
                    (*Segments)[i + 1].Array_Size++;
                }
                else {
                    Segment<T>* temp_segment = new Segment<T>();
                    temp_segment->Array->Reserve(MAX_SEGMENT_CAPACITY);
                    temp_segment->Array->Prepend((*Segments)[i].Array->GetLast());
                    temp_segment->Array_Size++;
                    Segments->InsertAt(i + 1, *temp_segment);
                    Segments_Size++;
                    delete temp_segment;
                }
                for (int j = MAX_SEGMENT_CAPACITY - 1; j > index; j--) {
                    (*Segments)[i].Array->Set(j, (*Segments)[i].Array->Get(j - 1));
                }
                (*Segments)[i].Array->Set(index, value);
            }
            Elements_Size++;
        } 
        void InsertAt(int index, const T&& value) {
            if (!Segments || Segments_Size < 0) throw std::out_of_range("SegmentedList is empty");
            if (index > Elements_Size || index < 0) throw std::out_of_range("Index out of range");
            if (Segments_Size >= GetCapacity()) Reserve(Segments_Size * 2);
            if (index == Elements_Size) {
                Append(std::move(value));
                return;
            }
            int i = 0;
            while (index >= (*Segments)[i].Array_Size) {
                index -= (*Segments)[i].Array_Size;
                i++;
            }
            if ((*Segments)[i].Array_Size < MAX_SEGMENT_CAPACITY) {
                (*Segments)[i].Array->InsertAt(index, std::move(value));
                (*Segments)[i].Array_Size++;
            }
            else {
                if (Segments_Size > i + 1 && (*Segments)[i + 1].Array_Size < MAX_SEGMENT_CAPACITY) {
                    (*Segments)[i + 1].Array->Prepend((*Segments)[i].Array->GetLast());
                    (*Segments)[i + 1].Array_Size++;
                }
                else {
                    Segment<T>* temp_segment = new Segment<T>();
                    temp_segment->Array->Reserve(MAX_SEGMENT_CAPACITY);
                    temp_segment->Array->Prepend((*Segments)[i].Array->GetLast());
                    temp_segment->Array_Size++;
                    Segments->InsertAt(i + 1, *temp_segment);
                    Segments_Size++;
                    delete temp_segment;
                }
                for (int j = MAX_SEGMENT_CAPACITY - 1; j > index; j--) {
                    (*Segments)[i].Array->Set(j, (*Segments)[i].Array->Get(j - 1));
                }
                (*Segments)[i].Array->Set(index, std::move(value));
            }
            Elements_Size++;
        } 

        void Resize(int size) {
            if (size < 0) throw std::invalid_argument("Size cannot be negative");
            else if (size == 0) {
                delete Segments;
                Segments_Size = 0;
                Elements_Size = 0;
                Segments = new DynamicArray<Segment<T>>();
            }
            else {
                DynamicArray<Segment<T>>* newSegments = new DynamicArray<Segment<T>>(size);
                int i;
                for (i = 0; i < std::min(Segments_Size, size); i++) {
                    (*newSegments)[i] = Segment<T>((*Segments)[i]);
                }
                for (int j = i; j < Segments_Size; j++) {
                    Elements_Size -= (*Segments)[j].Array_Size;
                }
                delete Segments;
                Segments = newSegments;
                Segments_Size = size;
            }
        }

        void RemoveAt(int index) {
            if (!Segments || Segments_Size < 0) throw std::out_of_range("SegmentedList is empty");
            if (index > Elements_Size || index < 0) throw std::out_of_range("Index out of range");
            int i = 0;
            while (index >= (*Segments)[i].Array_Size) {
                index -= (*Segments)[i].Array_Size;
                i++;
            }
            if ((*Segments)[i].Array_Size > 1) {
                (*Segments)[i].Array->RemoveAt(index);
                (*Segments)[i].Array_Size--;
            }
            else {
                delete (*Segments)[i].Array;
                (*Segments)[i].Array = nullptr;
                (*Segments)[i].Array_Size = 0;
                Segments->RemoveAt(i);
                Segments_Size--;
            }
            Elements_Size--;
        }

        SegmentedList<T>* GetSubSegmentedListArray(int startIndex, int endIndex) {
            if (!Segments || Elements_Size <= 0) return new SegmentedList<T>();
            if (startIndex < 0 || startIndex >= Elements_Size || endIndex > Elements_Size || startIndex > endIndex) throw std::out_of_range("Index out of range");
            int delta = endIndex - startIndex;
            T* items = new T[delta]{};
            int i = 0;
            while (startIndex >= (*Segments)[i].Array_Size) {
                startIndex -= (*Segments)[i].Array_Size;
                i++;
            }
            for (int j = 0, index = startIndex; j < delta; j++, index++) {
                if (index > (*Segments)[i].Array_Size - 1) {
                    index = 0;
                    i++;
                }
                items[j] = (*Segments)[i].Array->Get(index);
            }
            SegmentedList<T>* list = new SegmentedList<T>(items, delta);
            delete [] items;
            return list;
        }

        SegmentedList<T>* Concat(const SegmentedList<T>* other) {
            if (!other || !other->Segments || other->Elements_Size <= 0) {
                SegmentedList<T>* result = new SegmentedList<T>(*this);
                return result;
            }
            T* items = new T[Elements_Size + other->Elements_Size]{};
            int i = 0, j, index;
            for (j = 0, index = 0; j < Elements_Size; j++, index++) {
                if (index > (*Segments)[i].Array_Size - 1) {
                    index = 0;
                    i++;
                }
                items[j] = (*Segments)[i].Array->Get(index);
            }
            i = 0;
            for (index = 0; j < Elements_Size + other->Elements_Size; j++, index++) {
                if (index > (*other->Segments)[i].Array_Size - 1) {
                    index = 0;
                    i++;
                }
                items[j] = (*Segments)[i].Array->Get(index);
            }
            SegmentedList<T>* result = new SegmentedList<T>(items, Elements_Size + other->Elements_Size);
            delete [] items;
            return result;
        }

        std::string toString() const {
            std::ostringstream oss;
            oss << "[";
            if (Segments_Size > 0 && Segments) {
                bool first = true;
                for (int i = 0; i < Segments_Size; i++) {
                    if ((*Segments)[i].Array) {
                        for (int j = 0; j < (*Segments)[i].Array_Size; j++) {
                            if (!first) oss << ", ";
                            oss << (*Segments)[i].Array->Get(j);
                            first = false;
                        }
                    }
                }
            }
            oss << "]";
            return oss.str();
        }

        std::string toString_Segments() const {
            std::ostringstream oss;
            oss << "[";
            if (Segments_Size > 0 && Segments) {
                bool first = true;
                for (int i = 0; i < Segments_Size; i++) {
                    if (!first) oss << ", ";
                    oss << (*Segments)[i].Array->toString();
                    first = false;
                }
            }
            oss << "]";
            return oss.str();
        }

        ~SegmentedList() {
            delete Segments;
            Segments_Size = 0;
            Elements_Size = 0;
        }

    private:
        static const int MAX_SEGMENT_CAPACITY;
        DynamicArray<Segment<T>>* Segments = nullptr;
        int Segments_Size = 0;
        int Elements_Size = 0;

        friend class Segment<T>;
};  

template <typename T>
const int SegmentedList<T>::MAX_SEGMENT_CAPACITY = 4;

#endif // SEGMENTEDLIST_HPP