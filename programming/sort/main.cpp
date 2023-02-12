#include <iostream>
#include <iomanip>
#include <vector>

#include "Bubble.hpp"
#include "Insertion.hpp"
#include "Quick.hpp"
#include "Merge.hpp"

enum class SortType
{
    BUBBLE,
    INSERTATION,
    QUICK,
    MERGE
};

template <typename T>
void Sort(SortType st, std::vector<T>& a);

std::ostream& operator<<(std::ostream& os, const std::vector<int32_t>& v);

int main(int argc, char* argv[]) try
{
    std::vector<int32_t> a =
        {5, 2, 4, 6, 1, 3};
    std::cout << a << std::endl;
    Sort(SortType::BUBBLE, a);
    std::cout << a << std::endl;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}

template <typename T>
void Sort(SortType st, std::vector<T>& a)
{
    switch (st)
    {
    case SortType::BUBBLE:
        BubbleSort(a);
        break;
    case SortType::INSERTATION:
        InsertionSort(a);
        break;
    case SortType::QUICK:
        QuickSort(a);
        break;
    case SortType::MERGE:
        MergeSort(a);
        break;
    default:
        throw std::invalid_argument(
            std::string("void Sort<")
            + typeid(T).name()
            + ">(SortType st, std::vector<"
            + typeid(T).name()
            + ">& a): invalid sort type");
        break;
    }
}

std::ostream& operator<<(std::ostream& os, const std::vector<int32_t>& v)
{
    for (const auto& i : v)
        os << std::setw(12) << i;
    return os;
}