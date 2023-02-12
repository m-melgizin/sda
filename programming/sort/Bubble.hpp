#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include <vector>

template <typename T>
void BubbleSort(std::vector<T>& a)
{
    size_t n = a.size();
    for (size_t i = 0; i + 1 < n; ++i)
        for (size_t j = 0; j + 1 < n - i; ++j)
            if (a[j + 1] < a[j])
                std::swap(a[j], a[j + 1]);
}

#endif // !BUBBLE_HPP