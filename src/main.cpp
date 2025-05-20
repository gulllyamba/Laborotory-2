#include "Array/MutableArraySequence.hpp"
#include "Array/ImmutableArraySequence.hpp"
#include "List/MutableListSequence.hpp"
#include "AdaptiveSequence.hpp"
#include "SegmentedList.hpp"
#include <cmath>

template <typename T>
std::string toString(MutableListSequence<T>* list) {
    return list->GetList().toString();
}
template <typename T>
std::string toString(const MutableListSequence<T>& list) {
    return list.GetList().toString();
}
template <typename T>
std::string toString(MutableArraySequence<T>* array) {
    return array->GetArray().toString();
}
template <typename T>
std::string toString(const MutableArraySequence<T>& array) {
    return array.GetArray().toString();
}
template <typename T>
std::string toString(ImmutableArraySequence<T>* array) {
    return array->GetArray().toString();
}
template <typename T>
std::string toString(const ImmutableArraySequence<T>& array) {
    return array.GetArray().toString();
}

int main() {
    // SEGMENTED LIST

    // int items[] = {1, 2, 3, 4, 5};
    // SegmentedList<int>* A = new SegmentedList<int>(items, 5);
    // SegmentedList<int>* B = new SegmentedList<int>(items, 5);
    // SegmentedList<int>* C = new SegmentedList<int>();
    // SegmentedList<int>* D = new SegmentedList<int>();
    // SegmentedList<int>* E = new SegmentedList<int>(items, 5);
    // SegmentedList<int>* F = new SegmentedList<int>(items, 5);

    // std::cout << "Iterator cout:\n";
    // for (SLIterator<int> it = A->begin(); it != A->end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

    // std::cout << "Работа с Size = 0:\n";
    // C->Append(1);
    // std::cout << C->toString_Segments() << "\t" << C->GetSize() << "\n"; 
    // D->Prepend(5);
    // std::cout << D->toString_Segments() << "\t" << D->GetSize() << "\n\n"; 

    // std::cout << "Append:\n";
    // std::cout << A->toString_Segments() << "\t" << A->GetSize() << "\n";
    // for (int i = 0; i < 16; i++) {
    //     A->Append(i);
    //     std::cout << A->toString_Segments() << "\t" << A->GetSize() << " " << A->GetCapacity() << "\n";
    // }
    // for (int i = 0; i < A->GetSize(); i++) {
    //     std::cout << A->Get(i) << " ";
    // }
    // std::cout << "\n\n";

    // std::cout << "Prepend:\n";
    // std::cout << B->toString_Segments() << "\t" << B->GetSize() << " " << B->GetCapacity() << "\n";
    // for (int i = 0; i < 16; i++) {
    //     B->Prepend(i);
    //     std::cout << B->toString_Segments() << "\t" << B->GetSize() << " " << B->GetCapacity() << "\n";
    // }
    // for (int i = 0; i < B->GetSize(); i++) {
    //     std::cout << B->Get(i) << " ";
    // }
    // std::cout << "\n\n";

    // std::cout << "Set:\n";
    // for (int i = 0; i < E->GetSize(); i++) {
    //     E->Set(i, i * 10);
    // }
    // std::cout << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // std::cout << "\n";

    // std::cout << "InsertAt:\n";
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";
    // F->InsertAt(F->GetSize(), -10);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";
    // F->InsertAt(F->GetSize(), -9);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";
    // F->InsertAt(F->GetSize(), -8);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";
    // F->InsertAt(F->GetSize(), -7);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";
    // F->InsertAt(F->GetSize(), -6);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";
    // F->InsertAt(0, -5);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";

    // std::cout << "\n";
    // std::cout << "Resize:\n";
    // F->Resize(5);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";
    // F->Resize(2);
    // std::cout << F->toString_Segments() << "\t" << F->GetSize() << "\n";

    // std::cout << "\n";
    // std::cout << "RemoveAt:\n";
    // int E_size = E->GetSize();
    // for (int i = 0; i < E_size; i++) {
    //     E->RemoveAt(0);
    //     std::cout << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // }

    // std::cout << "\n";
    // std::cout << "Работа с Size = 0:\n";
    // std::cout << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // E->Append(1);
    // std::cout << "Append: " << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // E->RemoveAt(0);
    // std::cout << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // E->Prepend(9);
    // std::cout << "Prepend: " << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // E->RemoveAt(0);
    // std::cout << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // E->InsertAt(0, 1);
    // std::cout << "InsertAt: " << E->toString_Segments() << "\t" << E->GetSize() << "\n";
    // E->InsertAt(1, 2);
    // std::cout << "InsertAt: " << E->toString_Segments() << "\t" << E->GetSize() << "\n";

    // std::cout << "\n";
    // std::cout << "GetSubSegmentedList:\n";
    // SegmentedList<int>* G = A->GetSubSegmentedListArray(3, 14);
    // std::cout << G->toString_Segments() << "\t" << G->GetSize() << "\n";

    // std::cout << "\n";
    // std::cout << "Concat:\n";
    // SegmentedList<int>* H = F->Concat(F);
    // std::cout << H->toString_Segments() << "\t" << H->GetSize() << "\n";

    // delete A;
    // delete B;
    // delete C;
    // delete D;
    // delete E;
    // delete F;
    // delete G;
    // delete H;

    ////////////////////////////////////////////////////////////////////////////
    // ADAPTIVE SEQUENCE

    // int cur[] = {1, 2, 3};
    // int cur2[] = {1, 1, 1};
    // AdaptiveSequence<int> Cur(cur, 3);
    // std::cout << "Cur: " << Cur.toString(0) << "\t" << Cur.toString(1) << "\t" << Cur.GetCorrectLeft() << " " << Cur.GetCorrectRight() << "\n";
    // AdaptiveSequence<int> Copy(cur2, 3);
    // std::cout << "Copy: " << Copy.toString(0) << "\t" << Copy.toString(1) << "\t" << Copy.GetCorrectLeft() << " " << Copy.GetCorrectRight() << "\n";
    // Copy = Cur;
    // std::cout << "Copy: " << Copy.toString(0) << "\t" << Copy.toString(1) << "\t" << Copy.GetCorrectLeft() << " " << Copy.GetCorrectRight() << "\n";

    // int items[] = {1, 2, 3, 4, 5};
    // AdaptiveSequence<int>* A = new AdaptiveSequence<int>(items, 5);

    // std::cout << "\n";
    // std::cout << "Iterator cout:\n";
    // for (AdIterator<int> it = A->begin(); it != A->end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

    // std::cout << "Append:\n";
    // std::cout << "A: " << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // int A_size = A->GetSize();
    // for (int i = 0; i < A_size + 1; i++) {
    //     A->Append(9);
    //     std::cout << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // }

    // std::cout << "\n";
    // std::cout << "Prepend:\n";
    // AdaptiveSequence<int>* B = new AdaptiveSequence<int>(items, 5);
    // std::cout << "B: " << B->toString(0) << "\t" << B->toString(1) << "\t" << B->GetCorrectLeft() << " " << B->GetCorrectRight() << "\n";
    // int B_size = B->GetSize();
    // for (int i = 0; i < B_size + 1; i++) {
    //     B->Prepend(9);
    //     std::cout << B->toString(0) << "\t" << B->toString(1) << "\t" << B->GetCorrectLeft() << " " << B->GetCorrectRight() << "\n";
    // }

    // std::cout << "\n";
    // std::cout << "SET:\n";
    // AdaptiveSequence<int>* C = new AdaptiveSequence<int>(items, 5);
    // std::cout << "C: " << C->toString(0) << "\t" << C->toString(1) << "\t" << C->GetCorrectLeft() << " " << C->GetCorrectRight() << "\n";
    // int C_size = C->GetSize();
    // for (int i = 0; i < C_size; i++) {
    //     C->Set(i, (*C)[i] + 10);
    // }
    // std::cout << "Set: " << C->toString(0) << "\t" << C->toString(1) << "\t" << C->GetCorrectLeft() << " " << C->GetCorrectRight() << "\n";

    // std::cout << "\n";
    // std::cout << "InsertAt:\n";
    // AdaptiveSequence<int>* D = new AdaptiveSequence<int>(items, 5);
    // std::cout << "D: " << D->toString(0) << "\t" << D->toString(1) << "\t" << D->GetCorrectLeft() << " " << D->GetCorrectRight() << "\n";
    // int D_size = D->GetSize();
    // for (int i = 0; i < D_size + 1; i++) {
    //     D->InsertAt(i, 9);
    //     std::cout << D->toString(0) << "\t" << D->toString(1) << "\t" << D->GetCorrectLeft() << " " << D->GetCorrectRight() << "\n";
    // }

    // std::cout << "\n";
    // std::cout << "RemoveAt:\n";
    // A_size = A->GetSize();
    // for (int i = 0; i < A_size; i++) {
    //     A->RemoveAt(0);
    //     std::cout << A->toString(0) << "\t" << A->toString(1) << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // }

    // std::cout << "\n";
    // std::cout << "Работа с Size = 0:\n";
    // A->Append(1);
    // std::cout << "Append: " << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // A->RemoveAt(0);
    // std::cout << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // A->Prepend(1);
    // std::cout << "Prepend: " << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // A->RemoveAt(0);
    // std::cout << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // A->InsertAt(0, 1);
    // std::cout << "InsertAt: " << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";
    // A->InsertAt(1, 2);
    // std::cout << "InsertAt: " << A->toString(0) << "\t" << A->toString(1) << "\t" << A->GetCorrectLeft() << " " << A->GetCorrectRight() << "\n";

    // std::cout << "\n";
    // AdaptiveSequence<int>* E = new AdaptiveSequence<int>(items, 5);
    // std::cout << "Get(i):\n";
    // for (int i = 0; i < E->GetSize(); i++) std::cout << E->Get(i) << " ";
    // std::cout << "\t" << E->GetCorrectLeft() << " " << E->GetCorrectRight() << "\n";

    // std::cout << "\n";
    // AdaptiveSequence<int>* Sub = E->GetSubSequence(1, 4);
    // std::cout << "Sub: " << Sub->toString(0) << "\t" << Sub->toString(1) << "\t" << Sub->GetCorrectLeft() << " " << Sub->GetCorrectRight() << "\n";

    // std::cout << "\n";
    // AdaptiveSequence<int>* Con = E->Concat(Sub);
    // std::cout << "Con: " << Con->toString(0) << "\t" << Con->toString(1) << "\t" << Con->GetCorrectLeft() << " " << Con->GetCorrectRight() << "\n";

    // std::cout << "\n";
    // AdaptiveSequence<int>* G = new AdaptiveSequence<int>(items, 5);
    // std::cout << "G: " << G->toString(0) << "\t" << G->toString(1) << "\t" << G->GetCorrectLeft() << " " << G->GetCorrectRight() << "\n" << "G[i]: ";
    // for (int i = 0; i < G->GetSize(); i++) {
    //     std::cout << (*G)[i] << " ";
    // }
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // AdaptiveSequence<int>* Map = G->Map(square);
    // AdaptiveSequence<int>* Where = G->Where(If);
    // std::cout << "\n";
    // std::cout << "\nMap: " << Map->toString(0) << "\t" << Map->toString(1) << "\t" << Map->GetCorrectLeft() << " " << Map->GetCorrectRight() << "\n";
    // std::cout << "\n";
    // std::cout << "Where: " << Where->toString(0) << "\t" << Where->toString(1) << "\t" << Where->GetCorrectLeft() << " " << Where->GetCorrectRight() << "\n";
    // std::cout << "\n";
    // std::cout << "Reduce: " << G->Reduce(foo, 4) << "\n";
    // std::cout << "\n";

    // std::vector<std::string> temp(5, "1234");
    // AdaptiveSequence<std::string>* From = new AdaptiveSequence<std::string>();
    // From->From(temp);
    // std::cout << "From: " << From->toString(0) << "\t" << From->toString(1) << "\t" << From->GetCorrectLeft() << " " << From->GetCorrectRight() << "\n";
    // AdaptiveSequence<int>* Map_2 = From->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "\n";
    // std::cout << "Map из типа в тип: " << Map_2->toString(0) << "\t" << Map_2->toString(1) << "\t" << Map_2->GetCorrectLeft() << " " << Map_2->GetCorrectRight() << '\n';

    // std::cout << "\n";
    // int aaa[] = {123, 345, 678};
    // AdaptiveSequence<int>* F = new AdaptiveSequence<int>(aaa, 3);
    // std::cout << "F: "<< F->toString(0) << "\t" << F->toString(1) << "\t" << F->GetCorrectLeft() << " " << F->GetCorrectRight() << "\n";
    // AdaptiveSequence<int>* answer = F->FlatMap<int>([](int n) {
    //     AdaptiveSequence<int>* tmp = new AdaptiveSequence<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         tmp->Append(n % 10);
    //         n /= 10;
    //     }
    //     return tmp;
    // });
    // std::cout << "FlatMap: "<< answer->toString(0) << "\t" << answer->toString(1) << "\t" << answer->GetCorrectLeft() << " " << answer->GetCorrectRight() << "\n";

    // std::cout << "\n";
    // int values[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // int ff[] = {-1, -2, -3, -4, -5};
    // AdaptiveSequence<int>* I = new AdaptiveSequence<int>(values, 5);
    // AdaptiveSequence<int>* J = new AdaptiveSequence<int>(f, 5);
    // AdaptiveSequence<int>* K = new AdaptiveSequence<int>(ff, 5);
    // AdaptiveSequence<std::tuple<int, int, int>>* ans = I->Zip(I, J, K);
    // std::cout << "Zip: [";
    // for (int i = 0; i < ans->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = ans->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ") ";
    // }

    // std::cout << "\n";
    // std::tuple<AdaptiveSequence<int>, AdaptiveSequence<int>, AdaptiveSequence<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "\nUnZip: (" << first.toString(0) << ", " << second.toString(0) << ", " << third.toString(0) << ")\n";

    // delete A;
    // delete B;
    // delete C;
    // delete D;
    // delete Con;
    // delete Sub;
    // delete E;
    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete From;
    // delete Map_2;
    // delete G;
    // delete Map;
    // delete Where;

    //////////////////////////////////////////////////////////////////////////////////
    //  IMMUTABLE ARRAY SEQUENCE

    // int cur[] = {1, 2, 3};
    // int cur2[] = {1, 1, 1};
    // ImmutableArraySequence<int> Cur(cur, 3);
    // std::cout << "Cur: " << toString(Cur) << "\t" << Cur.GetCapacity() << "\n";
    // ImmutableArraySequence<int> Copy(cur2, 3);
    // std::cout << "Copy: " << toString(Copy) << "\t" << Copy.GetCapacity() << "\n";
    // Copy = Cur;
    // std::cout << "Copy: " << toString(Copy) << "\t" << Copy.GetCapacity() << "\n";
    // std::cout << "\n";

    // int items[] = {1, 2, 3};
    // ImmutableArraySequence<int>* A = new ImmutableArraySequence<int>(items, 3);

    // std::cout << "Iterator cout:\n";
    // for (ASIterator<int> it = A->begin(); it != A->end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* Set = A->Set(1, 100);
    // std::cout << "Set: " << toString(Set) << "\t" << Set->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* Append= A->Append(999);
    // std::cout << "Append: " << toString(Append) << "\t" << Append->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* Prepend = A->Prepend(999);
    // std::cout << "Prepend: " << toString(Prepend) << "\t" << Prepend->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* InsertAt = A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << toString(InsertAt) << "\t" << InsertAt->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* RemoveAt = A->RemoveAt(2);
    // std::cout << "RemoveAt: " << toString(RemoveAt) << "\t" << RemoveAt->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* Resize = A->Resize(1);
    // std::cout << "Resize: " << toString(Resize) << "\t" << Resize->GetCapacity() << "\n";
    // std::cout << "\n";

    // std::cout << "Работа с Size = 0:\n";
    // ImmutableArraySequence<int>* Resize_x2 = Resize->RemoveAt(0);
    // std::cout << toString(Resize_x2) << "\t" << Resize_x2->GetCapacity() << "\n";
    // ImmutableArraySequence<int>* a1 = Resize_x2->Append(1);
    // std::cout << toString(a1) << "\t" << a1->GetCapacity() << "\n";
    // ImmutableArraySequence<int>* a2 = Resize_x2->Prepend(1);
    // std::cout << toString(a2) << "\t" << a2->GetCapacity() << "\n";
    // ImmutableArraySequence<int>* a3 = Resize_x2->InsertAt(0, 1);
    // std::cout << toString(a3) << "\t" << a3->GetCapacity() << "\n";
    // ImmutableArraySequence<int>* a4 = a3->InsertAt(1, 2);
    // std::cout << toString(a4) << "\t" << a4->GetCapacity() << "\n";
    // delete a1;
    // delete a2;
    // delete a3;
    // delete a4;
    // delete Resize_x2;

    // ImmutableArraySequence<int>* Reserve = A->Reserve(5);
    // std::cout << "Reserve: " << toString(Reserve) << "\t" << Reserve->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* con = A->Concat(Set);
    // std::cout << "Concat: " << toString(con) << "\t" << con->GetCapacity() << "\n";
    // std::cout << "\n";

    // ImmutableArraySequence<int>* sub = con->GetSubSequence(1, 5);
    // std::cout << "SubSequence: " << toString(sub) << "\t" << sub->GetCapacity() << "\n"; 
    // std::cout << "\n";

    // ImmutableArraySequence<int>* G = new ImmutableArraySequence<int>(items, 3);
    // std::cout << "G: " << toString(G) << "\t" << G->GetCapacity() << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // ImmutableArraySequence<int>* C = G->Map(square);
    // ImmutableArraySequence<int>* D = G->Where(If);
    // std::cout << "Map: " << toString(C) << "\t" << C->GetCapacity() << "\n";
    // std::cout << "\n";
    // std::cout << "Where: " << toString(D) << "\t" << D->GetCapacity() << "\n";
    // std::cout << "\n";
    // std::cout << "Reduce: " << G->Reduce(foo, 4) << "\n";
    // std::cout << "\n";

    // std::vector<std::string> temp(5, "1234");
    // ImmutableArraySequence<std::string>* result = new ImmutableArraySequence<std::string>();
    // result = result->From(temp);
    // std::cout << "From: " << toString(result) << "\t" << result->GetCapacity() << "\n";
    // std::cout << "\n";
    // ImmutableArraySequence<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << toString(B) << "\t" << B->GetCapacity() << '\n';
    // std::cout << "\n";

    // int aaa[] = {123, 345, 678};
    // ImmutableArraySequence<int>* F = new ImmutableArraySequence<int>(aaa, 3);
    // ImmutableArraySequence<int>* answer = F->FlatMap<int>([](int n) {
    //     DynamicArray<int>* tmp = new DynamicArray<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         tmp->Append(n % 10);
    //         n /= 10;
    //     }
    //     return tmp;
    // });
    // std::cout << "FlatMap: "<< toString(answer) << "\t" << answer->GetCapacity() << "\n";
    // std::cout << "\n";

    // int values[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // int ff[] = {-1, -2, -3, -4, -5};
    // ImmutableArraySequence<int>* I = new ImmutableArraySequence<int>(values, 5);
    // ImmutableArraySequence<int>* J = new ImmutableArraySequence<int>(f, 5);
    // ImmutableArraySequence<int>* K = new ImmutableArraySequence<int>(ff, 5);
    // ImmutableArraySequence<std::tuple<int, int, int>>* ans = I->Zip(I, J, K);
    // std::cout << "Zip: [";
    // for (int i = 0; i < ans->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = ans->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ") ";
    // }
    // std::cout << "]\t" << ans->GetCapacity() << "\n";
    // std::cout << "\n";

    // std::tuple<ImmutableArraySequence<int>, ImmutableArraySequence<int>, ImmutableArraySequence<int>>* res = ans->UnZip<int, int, int>();
    
    // ImmutableArraySequence<int> first = std::get<0>(*res);
    // ImmutableArraySequence<int> second = std::get<1>(*res);
    // ImmutableArraySequence<int> third = std::get<2>(*res);

    // std::cout << "UnZip: (" << toString(first) << " " << toString(second) << " " << toString(third) << ")\n";

    
    // delete A;
    // delete Set;
    // delete Append;
    // delete Prepend;
    // delete InsertAt;
    // delete Resize;
    // delete con;
    // delete sub;
    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete G;
    // delete C;
    // delete D;

    ////////////////////////////////////////////////////////////////////////////////////////////

    // MUTABLE ARRAY SEQUENCE

    // int cur[] = {1, 2, 3};
    // int cur2[] = {1, 1, 1};
    // MutableArraySequence<int> Cur(cur, 3);
    // std::cout << "Cur: " << toString(Cur) << "\t" << Cur.GetCapacity() << "\n";
    // MutableArraySequence<int> Copy(cur2, 3);
    // std::cout << "Copy: " << toString(Copy) << "\t" << Copy.GetCapacity() << "\n";
    // Copy = Cur;
    // std::cout << "Copy: " << toString(Copy) << "\t" << Copy.GetCapacity() << "\n";
    // std::cout << "\n";
    
    // int items[] = {1, 2, 3};
    // MutableArraySequence<int>* A = new MutableArraySequence<int>(items, 3);

    // std::cout << "Iterator cout:\n";
    // for (ASIterator<int> it = A->begin(); it != A->end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";
    
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";
    
    // A->Set(1, 100);
    // std::cout << "Set: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->Append(999);
    // std::cout << "Append: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->Prepend(999);
    // std::cout << "Prepend: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->RemoveAt(2);
    // std::cout << "RemoveAt: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // MutableArraySequence<int>* con = A->Concat(A);
    // std::cout << "Concat: " << toString(con) << "\t" << con->GetCapacity() << "\n";
    // std::cout << "\n";

    // MutableArraySequence<int>* sub = con->GetSubSequence(1, 5);
    // std::cout << "SubSequence: " << toString(sub) << "\t" << sub->GetCapacity() << "\n"; 
    // std::cout << "\n";

    // A->Resize(1);
    // std::cout << "Resize: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // std::cout << "Работа с Size = 0:\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // A->Append(1);
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // A->Prepend(1);
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // A->InsertAt(0, 1);
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // A->InsertAt(1, 2);
    // std::cout << "A: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->Reserve(5);
    // std::cout << "Reserve: " << toString(A) << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // MutableArraySequence<int>* G = new MutableArraySequence<int>(items, 3);
    // std::cout << "G: " << toString(G) << "\t" << G->GetCapacity() << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // MutableArraySequence<int>* C = G->Map(square);
    // MutableArraySequence<int>* D = G->Where(If);
    // std::cout << "Map: " << toString(C) << "\t" << C->GetCapacity() << "\n";
    // std::cout << "\n";
    // std::cout << "Where: " << toString(D) << "\t" << D->GetCapacity() << "\n";
    // std::cout << "\n";
    // std::cout << "Reduce: " << G->Reduce(foo, 4) << "\n";
    // std::cout << "\n";

    // std::vector<std::string> temp(5, "1234");
    // MutableArraySequence<std::string>* result = new MutableArraySequence<std::string>();
    // result = result->From(temp);
    // std::cout << "From: " << toString(result) << "\t" << result->GetCapacity() << "\n";
    // std::cout << "\n";
    // MutableArraySequence<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << toString(B) << "\t" << B->GetCapacity() << '\n';
    // std::cout << "\n";

    // int aaa[] = {123, 345, 678};
    // MutableArraySequence<int>* F = new MutableArraySequence<int>(aaa, 3);
    // MutableArraySequence<int>* answer = F->FlatMap<int>([](int n) {
    //     DynamicArray<int>* tmp = new DynamicArray<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         tmp->Append(n % 10);
    //         n /= 10;
    //     }
    //     return tmp;
    // });
    // std::cout << "FlatMap: "<< toString(answer) << "\t" << answer->GetCapacity() << "\n";
    // std::cout << "\n";

    // int values[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // int ff[] = {-1, -2, -3, -4, -5};
    // MutableArraySequence<int>* I = new MutableArraySequence<int>(values, 5);
    // MutableArraySequence<int>* J = new MutableArraySequence<int>(f, 5);
    // MutableArraySequence<int>* K = new MutableArraySequence<int>(ff, 5);
    // MutableArraySequence<std::tuple<int, int, int>>* ans = I->Zip(I, J, K);
    // std::cout << "Zip: [";
    // for (int i = 0; i < ans->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = ans->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ") ";
    // }
    // std::cout << "]\t" << ans->GetCapacity() << "\n";
    // std::cout << "\n";

    // std::tuple<MutableArraySequence<int>, MutableArraySequence<int>, MutableArraySequence<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "UnZip: (" << toString(first) << " " << toString(second) << " " << toString(third) << ")\n";

    
    // delete A;
    // delete con;
    // delete sub;
    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete G;
    // delete C;
    // delete D;

    ////////////////////////////////////////////////////////////////////////////////////////////

    // MUTABLE LIST SEQUENCE

    // int cur[] = {1, 2, 3};
    // int cur2[] = {1, 1, 1};
    // MutableListSequence<int> Cur(cur, 3);
    // std::cout << "Cur: " << toString(Cur) << "\n";
    // MutableListSequence<int> Copy(cur2, 3);
    // std::cout << "Copy: " << toString(Copy) << "\n";
    // Copy = Cur;
    // std::cout << "Copy: " << toString(Copy) << "\n";
    // std::cout << "\n";

    // int items[] = {1, 2, 3};
    // MutableListSequence<int>* A = new MutableListSequence<int>(items, 3);

    // std::cout << "Iterator cout:\n";
    // for (LSIterator<int> it = A->begin(); it != A->end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

    // A->Set(1, 100);
    // std::cout << "Set: " << toString(A) << "\n";
    // std::cout << "\n";

    // A->Append(999);
    // std::cout << "Append: " << toString(A) << "\n";
    // std::cout << "\n";

    // A->Prepend(999);
    // std::cout << "Prepend: " << toString(A) << "\n";
    // std::cout << "\n";

    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << toString(A) << "\n";
    // std::cout << "\n";

    // A->RemoveAt(2);
    // std::cout << "RemoveAt: " << toString(A) << "\n";
    // std::cout << "\n";

    // MutableListSequence<int>* con = A->Concat(A);
    // std::cout << "Concat: " << toString(con) << "\n";
    // std::cout << "\n";

    // MutableListSequence<int>* sub = con->GetSubSequence(1, 5);
    // std::cout << "SubSequence: " << toString(sub) << "\n"; 
    // std::cout << "\n";

    // A->Resize(1);
    // std::cout << "Resize: " << toString(A) << "\n";
    // std::cout << "\n";

    // std::cout << "Работа с Size = 0:\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << toString(A) << "\n";
    // A->Append(1);
    // std::cout << "A: " << toString(A) << "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << toString(A) << "\n";
    // A->Prepend(1);
    // std::cout << "A: " << toString(A) << "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << toString(A) << "\n";
    // A->InsertAt(0, 1);
    // std::cout << "A: " << toString(A) << "\n";
    // A->InsertAt(1, 2);
    // std::cout << "A: " << toString(A) << "\n";
    // std::cout << "\n";

    // MutableListSequence<int>* G = new MutableListSequence<int>(items, 3);
    // std::cout << "G: " << toString(G) << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // MutableListSequence<int>* C = G->Map(square);
    // MutableListSequence<int>* D = G->Where(If);
    // std::cout << "Map: " << toString(C) << "\n";
    // std::cout << "\n";
    // std::cout << "Where: " << toString(D) << "\n";
    // std::cout << "\n";
    // std::cout << "Reduce: " << G->Reduce(foo, 4) << "\n";
    // std::cout << "\n";

    // std::vector<std::string> temp(5, "1234");
    // MutableListSequence<std::string>* result = new MutableListSequence<std::string>();
    // result = result->From(temp);
    // std::cout << "From: " << toString(result) << "\n";
    // std::cout << "\n";
    // MutableListSequence<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << toString(B) << '\n';
    // std::cout << "\n";

    // int aaa[] = {123, 345, 678};
    // MutableListSequence<int>* F = new MutableListSequence<int>(aaa, 3);
    // MutableListSequence<int>* answer = F->FlatMap<int>([](int n) {
    //     LinkedList<int>* tmp = new LinkedList<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         tmp->Append(n % 10);
    //         n /= 10;
    //     }
    //     return tmp;
    // });
    // std::cout << "FlatMap: "<< toString(answer) << "\n";
    // std::cout << "\n";

    // int values[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // int ff[] = {-1, -2, -3, -4, -5};
    // MutableListSequence<int>* I = new MutableListSequence<int>(values, 5);
    // MutableListSequence<int>* J = new MutableListSequence<int>(f, 5);
    // MutableListSequence<int>* K = new MutableListSequence<int>(ff, 5);
    // MutableListSequence<std::tuple<int, int, int>>* ans = I->Zip(I, J, K);
    // std::cout << "Zip: [";
    // for (int i = 0; i < ans->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = ans->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ") ";
    // }
    // std::cout << "]\n";

    // std::tuple<MutableListSequence<int>, MutableListSequence<int>, MutableListSequence<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "\nUnZip: (" << toString(first) << " " << toString(second) << " " << toString(third) << ")\n";

    // delete A;
    // delete con;
    // delete sub;
    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete G;
    // delete C;
    // delete D;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    // DYNAMIC ARRAY TESTS

    // int cur[] = {1, 2, 3};
    // int cur2[] = {1, 1, 1};
    // DynamicArray<int> Cur(cur, 3);
    // std::cout << "Cur: " << Cur.toString() << "\t" << Cur.GetCapacity() << "\n";
    // DynamicArray<int> Copy(cur2, 3);
    // std::cout << "Copy: " << Copy.toString() << "\t" << Copy.GetCapacity() << "\n";
    // Copy = Cur;
    // std::cout << "Copy: " << Copy.toString() << "\t" << Copy.GetCapacity() << "\n";
    // std::cout << "\n";

    // int iii[] = {1, 2, 3};
    // DynamicArray<int>* A = new DynamicArray<int>(iii, 3);

    // std::cout << "Iterator cout:\n";
    // for (AIterator<int> it = A->begin(); it != A->end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

    // std::cout << "A: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // A->Set(1, 100);
    // std::cout << "Set: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->Append(999);
    // std::cout << "Append: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->Prepend(999);
    // std::cout << "Prepend: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->InsertAt(1, 100);
    // std::cout << "InsertAt x2: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // A->RemoveAt(2);
    // std::cout << "RemoveAt: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // DynamicArray<int>* con = A->Concat(A);
    // std::cout << "Concat: " << con->toString() << "\t" << con->GetCapacity() << "\n";
    // std::cout << "\n";

    // DynamicArray<int>* sub = con->GetSubDynamicArray(1, 5);
    // std::cout << "SubSequence: " << sub->toString() << "\t" << sub->GetCapacity() << "\n"; 
    // std::cout << "\n";

    // A->Resize(1);
    // std::cout << "Resize: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";


    // std::cout << "Работа с Size = 0:\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << A->toString() << "\n";
    // A->Append(1);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->Prepend(1);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->InsertAt(0, 1);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->InsertAt(1, 2);
    // std::cout << "A: " << A->toString()<< "\n";
    // std::cout << "\n";

    // A->Reserve(5);
    // std::cout << "Reserve: " << A->toString() << "\t" << A->GetCapacity() << "\n";
    // std::cout << "\n";

    // int items[] = {1, 2, 3};
    // DynamicArray<int>* H = new DynamicArray<int>(items, 3);
    // std::cout << "H: " <<  H->toString() << "\t" << H->GetCapacity() << "\n";
    // std::cout << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // DynamicArray<int>* C = H->Map(square);
    // DynamicArray<int>* D = H->Where(If);
    // std::cout << "Map: " << C->toString() << "\t" << C->GetCapacity() << "\n";
    // std::cout << "\n";
    // std::cout << "Where: " << D->toString() << "\t" << D->GetCapacity() << "\n";
    // std::cout << "\n";
    // std::cout << "Reduce: " << H->Reduce(foo, 4) << "\n";
    // std::cout << "\n";

    // std::vector<std::string> temp(5, "1234");
    // DynamicArray<std::string>* result = new DynamicArray<std::string>();
    // result->From(temp);
    // std::cout << "From: " << result->toString() << "\t" << result->GetCapacity() << "\n";
    // std::cout << "\n";
    // DynamicArray<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << B->toString() << "\t" << B->GetCapacity() << '\n';
    // std::cout << "\n";

    // int aaa[] = {123, 345, 678};
    // DynamicArray<int>* F = new DynamicArray<int>(aaa, 3);
    // DynamicArray<int>* answer = F->FlatMap<int>([](int n) {
    //     DynamicArray<int>* tmp = new DynamicArray<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         tmp->Append(n % 10);
    //         n /= 10;
    //     }
    //     return tmp;
    // });
    // std::cout << "FlatMap: " << answer->toString() << "\t" << answer->GetCapacity() << "\n";
    // std::cout << "\n";

    // int values[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // int ff[] = {-1, -2, -3, -4, -5};
    // DynamicArray<int>* I = new DynamicArray<int>(values, 5);
    // DynamicArray<int>* J = new DynamicArray<int>(f, 5);
    // DynamicArray<int>* K = new DynamicArray<int>(ff, 5);
    // DynamicArray<std::tuple<int, int, int>>* ans = I->Zip(I, J, K);
    // std::cout << "Zip: [";
    // for (int i = 0; i < ans->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = ans->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ") ";
    // }
    // std::cout << "]" << "\t" << ans->GetCapacity() << "\n";

    // std::tuple<DynamicArray<int>, DynamicArray<int>, DynamicArray<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "\nUnZip: (" << first.toString() << " " << second.toString() << " " << third.toString() << ")\n";

    // delete A;
    // delete con;
    // delete sub;
    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete C;
    // delete D;
    // delete H;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // LINKED LIST TESTS

    // int cur[] = {1, 2, 3};
    // int cur2[] = {1, 1, 1};
    // LinkedList<int> Cur(cur, 3);
    // std::cout << "Cur: " << Cur.toString() << "\n";
    // LinkedList<int> Copy(cur2, 3);
    // std::cout << "Copy: " << Copy.toString() << "\n";
    // Copy = Cur;
    // std::cout << "Copy: " << Copy.toString() << "\n";
    // std::cout << "\n";

    // int items[] = {1, 2, 3};
    // LinkedList<int>* A = new LinkedList<int>(items, 3);

    // std::cout << "Iterator cout:\n";
    // for (LIterator<int> it = A->begin(); it != A->end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n\n";

    // std::cout << "A: " << A->toString() << "\n";
    // A->Set(1, 100);
    // std::cout << "Set: " << A->toString() << "\n";
    // std::cout << "\n";

    // A->Append(99);
    // std::cout << "Append: " << A->toString() << "\n";
    // std::cout << "\n";

    // A->Prepend(999);
    // std::cout << "Prepend: " << A->toString() << "\n";
    // std::cout << "\n";

    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << A->toString() << "\n";
    // std::cout << "\n";

    // A->RemoveAt(2);
    // std::cout << "RemoveAt: " << A->toString() << "\n";
    // std::cout << "\n";

    // LinkedList<int>* con = A->Concat(A);
    // std::cout << "Concat: " << con->toString() << "\n";
    // std::cout << "\n";

    // LinkedList<int>* sub = con->GetSubList(1, 5);
    // std::cout << "SubSequence: " << sub->toString() << "\n"; 
    // std::cout << "\n";

    // A->Resize(1);
    // std::cout << "Resize: " << A->toString() << "\n";
    // std::cout << "\n";

    // std::cout << "Работа с Size = 0:\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << A->toString() << "\n";
    // A->Append(1);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->Prepend(1);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->RemoveAt(0);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->InsertAt(0, 1);
    // std::cout << "A: " << A->toString()<< "\n";
    // A->InsertAt(1, 2);
    // std::cout << "A: " << A->toString()<< "\n";
    // std::cout << "\n";

    // std::vector<std::string> temp(5, "1234");
    // LinkedList<std::string>* From = new LinkedList<std::string>();
    // From = From->From(temp);
    // std::cout << "From: " << From->toString() << "\n";
    // std::cout << "\n";
    // LinkedList<int>* Map = From->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map: " << Map->toString() << '\n';
    // std::cout << "\n";

    // int iii[] = {123, 345, 678};
    // LinkedList<int>* B = new LinkedList<int>(iii, 3);
    // LinkedList<int>* FlatMap = B->FlatMap<int>([](int n) {
    //     LinkedList<int>* FlatMap = new LinkedList<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         FlatMap->Append(n % 10);
    //         n /= 10;
    //     }
    //     return FlatMap;
    // });
    // std::cout << "FlatMap: " << FlatMap->toString() << "\n";
    // std::cout << "\n";

    // int items_5[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // LinkedList<int>* L = new LinkedList<int>(items_5, 5);
    // LinkedList<int>* M = new LinkedList<int>(f, 5);
    // LinkedList<int>* N = new LinkedList<int>(f, 5);
    // LinkedList<std::tuple<int, int, int>>* P = L->Zip(L, M, N);
    // std::cout << "Zip: [";
    // for (int i = 0; i < P->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = P->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ") ";
    // }
    // std::cout << "]\n";
    // std::cout << "\n";

    // std::tuple<LinkedList<int>, LinkedList<int>, LinkedList<int>>* result_2 = P->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*result_2);
    // auto& second = std::get<1>(*result_2);
    // auto& third = std::get<2>(*result_2);

    // std::cout << "UnZip: (" << first.toString() << "\t" << second.toString() << "\t" << third.toString() << ")\n";
    // std::cout << "\n";

    // double pupupu[] = {1.1, 2.2, 3.3};
    // LinkedList<double> temp1(pupupu, 3);
    // LinkedList<double> temp2(pupupu, 3);
    // LinkedList<double> temp3(pupupu, 3);
    // LinkedList<double> pupupu_x3[] = {temp1, temp2, temp3};
    // LinkedList<LinkedList<double>>* BBB = new LinkedList<LinkedList<double>>(pupupu_x3, 3);
    // LinkedList<LinkedList<double>> C[] = {*BBB, *BBB, *BBB};
    // LinkedList<LinkedList<LinkedList<double>>>* F = new LinkedList<LinkedList<LinkedList<double>>>(C, 3);
    // std::cout << "Вложенные LinkedList: [";
    // for (int i = 0; i < F->GetSize(); i++) {
    //     for (int j = 0; j < BBB->GetSize(); j++) {
    //         std::cout << (((*F)[i])[j]).toString() << " ";
    //     }
    // }
    // std::cout << "]\n\n";

    // std::cout << "Вложенный vector:\n";
    // std::vector<int> temp11 = {1, 2, 3};
    // std::vector<int> temp22 = {4, 5, 6};
    // std::vector<int> temp33 = {7, 8, 9};
    // std::vector<int> items_10[] = {temp11, temp22, temp33};
    // LinkedList<std::vector<int>>* H = new LinkedList<std::vector<int>>(items_10, 3);
    // for (int i = 0; i < H->GetSize(); i++) {
    //     for (int j = 0; j < 3; j++) {
    //         std::cout << (*H)[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    
    // delete A;
    // delete con;
    // delete sub;
    // delete From;
    // delete Map;
    // delete FlatMap;
    // delete B;
    // delete L;
    // delete M;
    // delete N;
    // delete F;
    // delete BBB;
    // delete H;
    // delete result_2;
}