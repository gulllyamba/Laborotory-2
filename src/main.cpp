#include "Array/MutableArraySequence.hpp"
#include "Array/ImmutableArraySequence.hpp"
#include "List/MutableListSequence.hpp"
#include <cmath>

int main() {
    int items[] = {1, 2, 3};
    MutableListSequence<int>* A = new MutableListSequence<int>(items, 3);
    std::cout << "A: " <<  A->toString() << "\n";
    std::function<int(int)> square = [](int x) ->int {return x * x;};
    std::function<bool(int)> If = [](int x) ->int {return x > 0;};
    std::function<int(int, int)> foo = [](int x1, int x2) ->int {return 2 * x1 + 3 * x2;};
    MutableListSequence<int>* C = A->Map(square);
    MutableListSequence<int>* D = A->Where(If);
    std::cout << "Map: " << C->toString() << "\n";
    std::cout << "Where: " << D->toString() << "\n";
    std::cout << "Reduce: " << A->Reduce(foo, A, 4) << "\n";

    std::vector<std::string> temp(5, "1234");
    MutableListSequence<std::string>* result = new MutableListSequence<std::string>();
    result = result->From(temp);
    std::cout << "From: " << result->toString() << "\n";
    MutableListSequence<int>* B = result->Map<int>([](std::string s){
        return std::atoi(s.c_str());
    });
    std::cout << "Map из типа в тип: " << B->toString() << '\n';

    int aaa[] = {123, 345, 678};
    MutableListSequence<int>* F = new MutableListSequence<int>(aaa, 3);
    MutableListSequence<int>* answer = F->FlatMap<int>([](int n) {
        LinkedList<int>* tmp = new LinkedList<int>();
        n = abs(n);
        while (n > 0) {
            tmp->Append(n % 10);
            n /= 10;
        }
        return tmp;
    });
    std::cout << "FlatMap: " << answer->toString() << "\n";

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

    // std::cout << "]\nUnZip: (" << first.toString() << " " << second.toString() << " " << third.toString() << ")\n";

    // delete I;
    // delete J;
    // delete K;
    // delete ans;
    // delete res;
    delete answer;
    delete F;
    delete result;
    delete B;
    delete A;
    delete C;
    delete D;

    
    
    // DYNAMIC ARRAY TESTS

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
    // LinkedList<LinkedList<double>> pizda[] = {*B, *B, *B};
    // LinkedList<LinkedList<LinkedList<double>>>* A = new LinkedList<LinkedList<LinkedList<double>>>(pizda, 3);
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