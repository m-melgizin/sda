#ifndef MERGE_HPP
#define MERGE_HPP

#include <vector>

template <typename T>
void MergeSortImpl(std::vector<T>& a, std::vector<T>& b, size_t l, size_t r)
{
    if (l < r)
    {
        size_t m = (l + r) / 2;
        MergeSortImpl(a, b, l, m);
        MergeSortImpl(a, b, m + 1, r);

        size_t k = l;
        size_t i = l;
        size_t j = m + 1;
        for (; i <= m || j <= r;)
        {
            if (j > r || (i <= m && a[i] < a[j]))
            {
                b[k] = a[i];
                ++i;
            }
            else
            {
                b[k] = a[j];
                ++j;
            }
            ++k;
        }
        for (i = l; i <= r; ++i)
            a[i] = b[i];
    }
}

template <typename T>
void MergeSort(std::vector<T>& a)
{
    if (!a.empty())
    {
        std::vector<T> b(a.size());
        MergeSortImpl(a, b, 0, a.size() - 1);
    }
}

#endif // !MERGE_HPP