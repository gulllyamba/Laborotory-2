#include "Array/MutableArraySequence.hpp"
#include "Array/ImmutableArraySequence.hpp"
#include "List/MutableListSequence.hpp"
#include "AdaptiveSequence.hpp"
#include <cmath>
template <typename T>
std::string toString(MutableListSequence<T>* list) {
    return list->GetList()->toString();
}
template <typename T>
std::string toString(const MutableListSequence<T>& list) {
    return list.GetList()->toString();
}
template <typename T>
std::string toString(MutableArraySequence<T>* array) {
    return array->GetArray()->toString();
}
template <typename T>
std::string toString(const MutableArraySequence<T>& array) {
    return array.GetArray()->toString();
}
template <typename T>
std::string toString(ImmutableArraySequence<T>* array) {
    return array->GetArray()->toString();
}
template <typename T>
std::string toString(const ImmutableArraySequence<T>& array) {
    return array.GetArray()->toString();
}

int main() {
    // ADAPTIVE SEQUENCE

    // int items[] = {1, 2, 3};
    // AdaptiveSequence<int>* A = new AdaptiveSequence<int>(items, 3);
    // std::cout << "A: " << A->toString(0) << "\t" << A->toString(1) << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // AdaptiveSequence<int>* C = A->Map(square);
    // AdaptiveSequence<int>* D = A->Where(If);
    // std::cout << "Map: " << C->toString(0) << "\t" << C->toString(1) << "\n";
    // std::cout << "Where: " << D->toString(0) << "\t" << D->toString(1) << "\n";
    // std::cout << "Reduce: " << A->Reduce(foo, 4) << "\n";

    // std::vector<std::string> temp(5, "1234");
    // AdaptiveSequence<std::string>* result = new AdaptiveSequence<std::string>();
    // result->From(temp);
    // std::cout << "From: " << result->toString(0) << "\t" << result->toString(1) << "\n";
    // AdaptiveSequence<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << B->toString(0) << "\t" << B->toString(1) << '\n';

    // int aaa[] = {123, 345, 678};
    // AdaptiveSequence<int>* F = new AdaptiveSequence<int>(aaa, 3);
    // std::cout << "F: "<< F->toString(0) << "\t" << F->toString(1) << "\n";
    // AdaptiveSequence<int>* answer = F->FlatMap<int>([](int n) {
    //     AdaptiveSequence<int>* tmp = new AdaptiveSequence<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         tmp->Append(n % 10);
    //         n /= 10;
    //     }
    //     return tmp;
    // });
    // std::cout << "FlatMap: "<< answer->toString(0) << "\t" << answer->toString(1) << "\n";

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

    // std::tuple<AdaptiveSequence<int>, AdaptiveSequence<int>, AdaptiveSequence<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "]\nUnZip: (" << first.toString(0) << ", " << second.toString(0) << ", " << third.toString(0) << ")\n";

    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete A;
    // delete C;
    // delete D;

    // int items[] = {1, 2, 3, 4, 5};
    // AdaptiveSequence<int>* E = new AdaptiveSequence<int>(items, 5);
    // for (int i = 0; i < E->GetSize(); i++) std::cout << E->Get(i) << " ";
    // std::cout << "\n";

    // AdaptiveSequence<int>* Sub = E->GetSubSequence(1, 4);
    // std::cout << Sub->toString(0) << "\t" << Sub->toString(1) << "\n";

    // AdaptiveSequence<int>* Con = E->Concat(Sub);
    // std::cout << Con->toString(0) << "\t" << Con->toString(1) << "\n";
    // delete Con;
    // delete Sub;
    // delete E;

    // AdaptiveSequence<int>* A = new AdaptiveSequence<int>(items, 5);
    // std::cout << A->toString(0) << "\n" << A->toString(1) << "\n";
    // A->Append(99);
    // std::cout << A->toString(0) << "\n" << A->toString(1) << "\n";
    // A->Append(99);
    // std::cout << A->toString(0) << "\n" << A->toString(1) << "\n";
    // A->Append(99);
    // std::cout << A->toString(0) << "\n" << A->toString(1) << "\n";
    // delete A;

    // AdaptiveSequence<int>* B = new AdaptiveSequence<int>(items, 5);
    // std::cout << B->GetCorrectLeft() << " " << B->GetCorrectRight() << "\n";
    // std::cout << B->toString(0) << "\n" << B->toString(1) << "\n";
    // B->Prepend(99);
    // std::cout << B->GetCorrectLeft() << " " << B->GetCorrectRight() << "\n";
    // std::cout << B->toString(0) << "\n" << B->toString(1) << "\n";
    // B->Prepend(99);
    // std::cout << B->GetCorrectLeft() << " " << B->GetCorrectRight() << "\n";
    // std::cout << B->toString(0) << "\n" << B->toString(1) << "\n";
    // B->Prepend(99);
    // std::cout << B->GetCorrectLeft() << " " << B->GetCorrectRight() << "\n";
    // std::cout << B->toString(0) << "\n" << B->toString(1) << "\n";
    // delete B;
    // AdaptiveSequence<int>* C = new AdaptiveSequence<int>(items, 5);
    // std::cout << C->toString(0) << "\t" << C->toString(1) << "\n";
    // for (int i = 0; i < C->GetSize(); i++) {
    //     C->Set(i, i);
    // }
    // std::cout << C->toString(0) << "\t" << C->toString(1) << "\n";
    // delete C;

    // AdaptiveSequence<int>* D = new AdaptiveSequence<int>(items, 5);
    // std::cout << D->toString(0) << "\t" << D->toString(1) << "\n";
    // int size = D->GetSize();
    // for (int i = 0; i < size; i++) {
    //     D->InsertAt(i, 9);
    //     std::cout << D->toString(0) << "\t" << D->toString(1) << "\n";
    // }
    // delete D;



    //////////////////////////////////////////////////////////////////////////////////
    //  IMMUTABLE ARRAY SEQUENCE

    // int items[] = {1, 2, 3};
    // ImmutableArraySequence<int>* A = new ImmutableArraySequence<int>(items, 3);
    // std::cout << "A: " << toString(A) << "\n";
    // ImmutableArraySequence<int>* B = A->Set(1, 100);
    // std::cout << "B: " << toString(B) << "\n";
    // ImmutableArraySequence<int>* C = A->Append(999);
    // std::cout << "C: " << toString(C) << "\n";
    // ImmutableArraySequence<int>* D = A->Prepend(999);
    // std::cout << "D: " << toString(D) << "\n";
    // ImmutableArraySequence<int>* E = A->InsertAt(1, 100);
    // std::cout << "E: " << toString(E) << "\n";
    // ImmutableArraySequence<int>* F = A->Resize(1);
    // std::cout << "F: " << toString(F) << "\n";
    // ImmutableArraySequence<int>* con = A->Concat(B);
    // std::cout << "Concat: " << toString(con) << "\n";
    // ImmutableArraySequence<int>* sub = con->GetSubSequence(1, 5);
    // std::cout << "SubSequence: " << toString(sub) << "\n"; 

    // delete A;
    // delete B;
    // delete C;
    // delete D;
    // delete E;
    // delete F;
    // delete con;
    // delete sub;

    // int items[] = {1, 2, 3};
    // ImmutableArraySequence<int>* A = new ImmutableArraySequence<int>(items, 3);
    // std::cout << "A: " << toString(A) << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x < 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // ImmutableArraySequence<int>* C = A->Map(square);
    // ImmutableArraySequence<int>* D = A->Where(If);
    // std::cout << "Map: " << toString(C) << "\n";
    // std::cout << "Where: " << toString(D) << "\n";
    // std::cout << "Reduce: " << A->Reduce(foo, 4) << "\n";

    // std::vector<std::string> temp(5, "1234");
    // MutableArraySequence<std::string>* result = new MutableArraySequence<std::string>();
    // result = result->From(temp);
    // std::cout << "From: " << toString(result) << "\n";
    // MutableArraySequence<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << toString(B) << '\n';

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
    // std::cout << "FlatMap: "<< toString(answer) << "\n";

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

    // std::tuple<MutableArraySequence<int>, MutableArraySequence<int>, MutableArraySequence<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "]\nUnZip: (" << toString(first) << " " << toString(second) << " " << toString(third) << ")\n";

    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete A;
    // delete C;
    // delete D;

    ////////////////////////////////////////////////////////////////////////////////////////////

    // MUTABLE ARRAY SEQUENCE

    // int items[] = {1, 2, 3};
    // MutableArraySequence<int>* A = new MutableArraySequence<int>(items, 3);
    // std::cout << "A: " << toString(A) << "\n";
    // A->Set(1, 100);
    // std::cout << "Set: " << toString(A) << "\n";
    // A->Append(999);
    // std::cout << "Append: " << toString(A) << "\n";
    // A->Prepend(999);
    // std::cout << "Prepend: " << toString(A) << "\n";
    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << toString(A) << "\n";
    // MutableArraySequence<int>* con = A->Concat(A);
    // std::cout << "Concat: " << toString(con) << "\n";
    // MutableArraySequence<int>* sub = con->GetSubSequence(1, 5);
    // std::cout << "SubSequence: " << toString(sub) << "\n"; 
    // A->Resize(1);
    // std::cout << "Resize: " << toString(A) << "\n";

    // delete A;
    // delete con;
    // delete sub;

    // int items[] = {1, 2, 3};
    // MutableArraySequence<int>* A = new MutableArraySequence<int>(items, 3);
    // std::cout << "A: " << toString(A) << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // MutableArraySequence<int>* C = A->Map(square);
    // MutableArraySequence<int>* D = A->Where(If);
    // std::cout << "Map: " << toString(C) << "\n";
    // std::cout << "Where: " << toString(D) << "\n";
    // std::cout << "Reduce: " << A->Reduce(foo, A, 4) << "\n";

    // std::vector<std::string> temp(5, "1234");
    // MutableArraySequence<std::string>* result = new MutableArraySequence<std::string>();
    // result = result->From(temp);
    // std::cout << "From: " << toString(result) << "\n";
    // MutableArraySequence<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << toString(B) << '\n';

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
    // std::cout << "FlatMap: "<< toString(answer) << "\n";

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

    // std::tuple<MutableArraySequence<int>, MutableArraySequence<int>, MutableArraySequence<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "]\nUnZip: (" << toString(first) << " " << toString(second) << " " << toString(third) << ")\n";

    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete A;
    // delete C;
    // delete D;

    ////////////////////////////////////////////////////////////////////////////////////////////

    // MUTABLE LIST SEQUENCE

    // int items[] = {1, 2, 3};
    // MutableListSequence<int>* A = new MutableListSequence<int>(items, 3);
    // std::cout << "A: " << toString(A) << "\n";
    // A->Set(1, 100);
    // std::cout << "Set: " << toString(A) << "\n";
    // A->Append(999);
    // std::cout << "Append: " << toString(A) << "\n";
    // A->Prepend(999);
    // std::cout << "Prepend: " << toString(A) << "\n";
    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << toString(A) << "\n";
    // MutableListSequence<int>* con = A->Concat(A);
    // std::cout << "Concat: " << toString(con) << "\n";
    // MutableListSequence<int>* sub = con->GetSubSequence(1, 5);
    // std::cout << "SubSequence: " << toString(sub) << "\n"; 
    // A->Resize(1);
    // std::cout << "Resize: " << toString(A) << "\n";

    // delete A;
    // delete con;
    // delete sub;

    // int items[] = {1, 2, 3};
    // MutableListSequence<int>* A = new MutableListSequence<int>(items, 3);
    // std::cout << "A: " << toString(A) << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // MutableListSequence<int>* C = A->Map(square);
    // MutableListSequence<int>* D = A->Where(If);
    // std::cout << "Map: " << toString(C) << "\n";
    // std::cout << "Where: " << toString(D) << "\n";
    // std::cout << "Reduce: " << A->Reduce(foo, A, 4) << "\n";

    // std::vector<std::string> temp(5, "1234");
    // MutableListSequence<std::string>* result = new MutableListSequence<std::string>();
    // result = result->From(temp);
    // std::cout << "From: " << toString(result) << "\n";
    // MutableListSequence<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << toString(B) << '\n';

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

    // std::tuple<MutableListSequence<int>, MutableListSequence<int>, MutableListSequence<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "]\nUnZip: (" << toString(first) << " " << toString(second) << " " << toString(third) << ")\n";

    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete A;
    // delete C;
    // delete D;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    // DYNAMIC ARRAY TESTS

    // int items[] = {1, 2, 3};
    // DynamicArray<int>* A = new DynamicArray<int>(items, 3);
    // std::cout << "A: " << A->toString() << "\n";
    // A->Set(1, 100);
    // std::cout << "Set: " << A->toString() << "\n";
    // A->Append(999);
    // std::cout << "Append: " << A->toString() << "\n";
    // A->Prepend(999);
    // std::cout << "Prepend: " << A->toString() << "\n";
    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << A->toString() << "\n";
    // DynamicArray<int>* con = A->Concat(A);
    // std::cout << "Concat: " << con->toString() << "\n";
    // DynamicArray<int>* sub = con->GetSubDynamicArray(1, 5);
    // std::cout << "SubSequence: " << sub->toString() << "\n"; 
    // A->Resize(1);
    // std::cout << "Resize: " << A->toString() << "\n";

    // delete A;
    // delete con;
    // delete sub;

    // int items[] = {1, 2, 3};
    // DynamicArray<int>* A = new DynamicArray<int>(items, 3);
    // std::cout << "A: " <<  A->toString() << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // DynamicArray<int>* C = A->Map(square);
    // DynamicArray<int>* D = A->Where(If);
    // std::cout << "Map: " << C->toString() << "\n";
    // std::cout << "Where: " << D->toString() << "\n";
    // std::cout << "Reduce: " << A->Reduce(foo, A, 4) << "\n";

    // std::vector<std::string> temp(5, "1234");
    // DynamicArray<std::string>* result = new DynamicArray<std::string>();
    // result = result->From(temp);
    // std::cout << "From: " << result->toString() << "\n";
    // DynamicArray<int>* B = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << "Map из типа в тип: " << B->toString() << '\n';

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
    // std::cout << "FlatMap: " << answer->toString() << "\n";

    // int values[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // int ff[] = {-1, -2, -3, -4, -5};
    // DynamicArray<int>* I = new DynamicArray<int>(values, 5);
    // DynamicArray<int>* J = new DynamicArray<int>(f, 5);
    // DynamicArray<int>* K = new DynamicArray<int>(ff, 5);
    // DynamicArray<std::tuple<int, int, int>>* ans = I->Zip(*I, *J, *K);
    // std::cout << "Zip: [";
    // for (int i = 0; i < ans->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = ans->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ") ";
    // }

    // std::tuple<DynamicArray<int>, DynamicArray<int>, DynamicArray<int>>* res = ans->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*res);
    // auto& second = std::get<1>(*res);
    // auto& third = std::get<2>(*res);

    // std::cout << "]\nUnZip: (" << first.toString() << " " << second.toString() << " " << third.toString() << ")\n";

    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    // delete answer;
    // delete F;
    // delete result;
    // delete B;
    // delete A;
    // delete C;
    // delete D;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // LINKED LIST TESTS

    // int items[] = {1, 2, 3};
    // LinkedList<int>* A = new LinkedList<int>(items, 3);
    // std::cout << "A: " << A->toString() << "\n";
    // A->Set(1, 100);
    // std::cout << "Set: " << A->toString() << "\n";
    // A->Append(999);
    // std::cout << "Append: " << A->toString() << "\n";
    // A->Prepend(999);
    // std::cout << "Prepend: " << A->toString() << "\n";
    // A->InsertAt(1, 100);
    // std::cout << "InsertAt: " << A->toString() << "\n";
    // LinkedList<int>* con = A->Concat(A);
    // std::cout << "Concat: " << con->toString() << "\n";
    // LinkedList<int>* sub = con->GetSubList(1, 5);
    // std::cout << "SubSequence: " << sub->toString() << "\n"; 
    // A->Resize(1);
    // std::cout << "Resize: " << A->toString() << "\n";

    // delete A;
    // delete con;
    // delete sub;

    // int items[] = {1, 2, 3};
    // LinkedList<int>* A = new LinkedList<int>(items, 3);
    // (*A)[0];
    // (*A)[3];
    // delete A;
    // std::vector<std::string> temp(5, "1234");
    // LinkedList<std::string>* result = new LinkedList<std::string>();
    // result = result->From(temp);
    // std::cout << result->toString() << "\n";
    // LinkedList<int>* A = result->Map<int>([](std::string s){
    //     return std::atoi(s.c_str());
    // });
    // std::cout << A->toString() << '\n';
    // delete result;
    // delete A;

    // int items[] = {123, 345, 678};
    // LinkedList<int>* A = new LinkedList<int>(items, 3);
    // LinkedList<int>* result = A->FlatMap<int>([](int n) {
    //     LinkedList<int>* result = new LinkedList<int>();
    //     n = abs(n);
    //     while (n > 0) {
    //         result->Append(n % 10);
    //         n /= 10;
    //     }
    //     return result;
    // });
    // std::cout << result->toString() << "\n";
    // delete result;
    // delete A;

    // double temp[] = {1.1, 2.2, 3.3};
    // LinkedList<double> temp1(temp, 3);
    // LinkedList<double> temp2(temp, 3);
    // LinkedList<double> temp3(temp, 3);
    // LinkedList<double> items[] = {temp1, temp2, temp3};
    // LinkedList<LinkedList<double>>* B = new LinkedList<LinkedList<double>>(items, 3);
    // LinkedList<LinkedList<double>> C[] = {*B, *B, *B};
    // LinkedList<LinkedList<LinkedList<double>>>* A = new LinkedList<LinkedList<LinkedList<double>>>(C, 3);
    // for (int i = 0; i < A->GetSize(); i++) {
    //     for (int j = 0; j < B->GetSize(); j++) {
    //         std::cout << (((*A)[i])[j]).toString() << "\n";
    //     }
    // }
    // delete A;
    // delete B;

    // std::vector<int> temp1 = {1, 2, 3};
    // std::vector<int> temp2 = {4, 5, 6};
    // std::vector<int> temp3 = {7, 8, 9};
    // std::vector<int> items[] = {temp1, temp2, temp3};
    // LinkedList<std::vector<int>>* A = new LinkedList<std::vector<int>>(items, 3);
    // for (int i = 0; i < A->GetSize(); i++) {
    //     for (int j = 0; j < 3; j++) {
    //         std::cout << (*A)[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    // delete A;

    // int items[] = {1, 2, 3, 4, 5};
    // int f[] = {0, 0, 0, 0, 0};
    // LinkedList<int>* A = new LinkedList<int>(items, 5);
    // LinkedList<int>* B = new LinkedList<int>(f, 5);
    // LinkedList<int>* F = new LinkedList<int>(f, 5);
    // LinkedList<std::tuple<int, int, int>>* C = A->Zip(A, B, F);
    // for (int i = 0; i < C->GetSize(); i++) {
    //     std::tuple<int, int, int> temp = C->Get(i);
    //     std::cout << "("
    //     << std::get<0>(temp) << ", "
    //     << std::get<1>(temp)  << ", "
    //     << std::get<2>(temp) <<  ")\n";
    // }
    // delete A;
    // delete B;
    // delete F;
    // delete C;

    // std::tuple<LinkedList<int>, LinkedList<int>, LinkedList<int>>* result = C->UnZip<int, int, int>();
    
    // auto& first = std::get<0>(*result);
    // auto& second = std::get<1>(*result);
    // auto& third = std::get<2>(*result);

    // std::cout << first.toString() << "\n" << second.toString() << "\n" << third.toString() << "\n";

    // delete A;
    // delete B;
    // delete C;
    // delete F;
    // delete result;


    // int items[] = {1, 2, 3};
    // MutableListSequence<int>* A = new MutableListSequence<int>(items, 3);
    // std::cout << A->toString() << "\n";
    // std::function<int(int)> square = [](int x) ->int {return x * x;};
    // std::function<bool(int)> If = [](int x) ->int {return x < 0;};
    // std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    // MutableListSequence<int>* C = A->Map(square);
    // MutableListSequence<int>* D = A->Where(If);
    // std::cout << C->toString() << "\n";
    // std::cout << D->toString() << "\n";
    // std::cout << A->Reduce(foo, A, 4) << "\n";
    // delete A;
    // delete C;
    // delete D;

    // ImmutableArraySequence<int>* A = new ImmutableArraySequence<int>(items, 5);
    // ImmutableArraySequence<int>* B = A->Concat(A);
    // MutableArraySequence<MutableArraySequence<int>> C;
    // std::cout << B->toString() << "\n";
    // delete A;
    // delete B;

    // int items[5] = {10, 20, 30, 40, 50};
    // ImmutableArraySequence<int>* A = new ImmutableArraySequence<int>(items, 5);
    // std::cout << A->toString() << "\n";
    // ImmutableArraySequence<int>* B = A->Set(4, -9);
    // std::cout << B->toString() << "\n";
    // std::cout << (*A)[2] << "\n";
    // delete A;
    // delete B;



    // MutableArraySequence<int>* A = new MutableArraySequence<int>(items, 5);
    // std::cout << "\n";
    // MutableArraySequence<int>* B = A->GetSubSequence(1, 2);
    // A->Concat(B);
    // std::cout << "\n";
    // std::cout << B->toString() << "\n";
    // std::cout << A->toString() << "\n";
    // std::cout << "\n";
    // delete A;
    // std::cout << "\n";
    // delete B;


    // LinkedList<int>* B = new LinkedList<int> (temp, 5);
    // B->Print();
    // std::cout << B->GetSize() << "\n";

    // LinkedList<int>* C = new LinkedList<int> (*B);
    // C->Print();
    // std::cout << C->GetSize() << "\n";

    // LinkedList<int>* D = B->Concat(C);
    // D->Print();
    // std::cout << D->GetSize() << "\n"; // тогда конструктор копирования не нужен, это странно

    // delete D;
    // delete C;
    // delete B;
    // LinkedList <int> A = *(B.GetSubList(1, 3));
    // A.Print();
    // std::cout << A.GetSize() << "\n";
    // LinkedList <int> D = *(B.Concat(&A));
    // D.Print();
    // std::cout << D.GetSize() << "\n";
    // DynamicArray <int> arr(temp, 5);
    // DynamicArray <int> brr(5);
    // brr = arr;
    // // for (int i = 0; i < 5; i++) {
    // //     brr.Set(i, i*10);
    // // }
    // brr.Print();

    // std::cout << arr.GetSize() << "\n";

    // arr.Resize(10);
    // arr.Print();
    // std::cout << arr.GetSize() << "\n";

    // arr.Resize(3);
    // arr.Print();
    // std::cout << arr.GetSize() << "\n"
}