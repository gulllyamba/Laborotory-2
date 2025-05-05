#ifndef SEGMENTEDLIST_HPP
#define SEGMENTEDLIST_HPP

#include "Array/DynamicArray.hpp"

template <typename T>
class SegmentedList {
    public:
        SegmentedList() : Elements_Cnt(0), Segments_Capacity(0) {
            Segments = new DynamicArray<Segment>();
        }

        T GetFirst() const {
            return Segments[0]->Data[0];
        }
        T GetLast() const {
            return Segments[Segments->GetSize() - 1]->Data[Data->GetSize() - 1];
        }
        T Get(int index) const {
            
        }
        int GetSize() const {
            return Segments->GetSize();
        }

        void Append(const T& value) {
            if (Segments->GetSize() == 0 || 
                Segments[Segments->GetSize() - 1]->Data->GetSize() == Segments[Segments->GetSize() - 1]->capacity && Segments[Segments->GetSize() - 1]->capacity >= MAX_SEGMENT_CAPACITY) {
                allocate_new_segment();
            }
            else if (Segments[Segments->GetSize() - 1]->Data->GetSize() == Segments[Segments->GetSize() - 1]->capacity) {
                resize_segment(Segments[Segments->GetSize() - 1]);
            }
            Segment* last_Segment = Segments[Segments->GetSize() - 1];
            last_Segment->Data->Append(value);
            
        }

        ~SegmentedList() {
            for (int i = 0; i < Segments->GetSize(); i++) {
                delete Segments[i]->Data;
            }
            delete Segments;
        }

    private:
        class Segment {
            public:
                Segment(int init_capacity) : capacity(init_capacity) {
                    Data = new DynamicArray<T>();
                }

                ~Segment() {
                    delete Data;
                }
            private:
                DynamicArray<T>* Data;
                int capacity;
        };

        static const int INIT_SEGMENT_SIZE = 2;
        static const int MAX_SEGMENT_CAPACITY = 8;
        DynamicArray<Segment>* Segments;
        int Segments_Cnt;
        int Elements_Cnt;
        int Segments_Capacity;

        void allocate_new_segment() {
            if (Segments_Cnt == Segments_Capacity) {
                int new_capacity = (Segments_Capacity == 0) ? 1 : Segments_Capacity * 2;
                DynamicArray<Segment>* new_Segments = new DynamicArray<Segment>(new_capacity);
                for (int i = 0; i < Segments_Cnt; i++) {
                    new_Segments[i] = Segments[i];
                }
                delete Segments;
                Segments = new_Segments;
                Segments_Capacity = new_capacity;
            }
            Segments[Segments_Cnt] = new Segment(INIT_SEGMENT_SIZE);
            Segments_Cnt++;
        }

        void resize_segment(Segment segment) {
            int new_capacity = segment->capacity * 2;
            DynamicArray<T>* new_Data = new DynamicArray<T>(new_capacity);
            for (int i = 0; i < segment->Data->GetSize(); i++) {
                new_Data[i] = segment->Data[i];
            }
            delete segment->Data;
            segment->Data = new_Data;
            segment->capacity = new_capacity;
        }
};  

#endif // SEGMENTEDLIST_HPP