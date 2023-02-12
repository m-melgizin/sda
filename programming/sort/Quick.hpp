#ifndef QUICK_HPP
#define QUICK_HPP

#include <vector>

template <typename T>
size_t Partition(std::vector<T>& a, size_t l, size_t r)
{
    T x = a[r];
    size_t less = l;

    for (size_t i = l; i < r; ++i)
    {
        if (a[i] <= x)
        {
            std::swap(a[i], a[less]);
            ++less;
        }
    }
    std::swap(a[less], a[r]);
    return less;
}

template <typename T>
void QuickSortImpl(std::vector<T>& a, size_t l, size_t r)
{
    if (l < r)
    {
        size_t p = Partition(a, l, r);
        QuickSortImpl(a, l, p - 1);
        QuickSortImpl(a, p + 1, r);
    }
}

template <typename T>
void QuickSort(std::vector<T>& a)
{
    if (!a.empty())
        QuickSortImpl(a, 0, a.size() - 1);
}

#endif // !QUICK_HPP