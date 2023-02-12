#ifndef INSERTION_HPP
#define INSERTION_HPP

#include <vector>

template <typename T>
void InsertionSort(std::vector<T>& a)
{
    size_t n = a.size();
    for (size_t i = 1; i < n; ++i)
    {
        T x = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > x)
        {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = x;
    }
}

#endif // !INSERTION_HPP