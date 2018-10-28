#include <iostream>
#include <vector>
#include "Zuku271_counting_sort.hpp"

std::vector<int> counting_sort(const std::vector<int> &input, const unsigned int range)
{
    const size_t n = input.size();
    std::vector<int> count(range + 1, 0);
    std::vector<int> result(n, 0);

    // Creates count array
    for (size_t i = 0; i < n; i++)
    {
        count[input[i]] += 1;
    }

    // Each index of count[] stores the sum of previous counts. 
    for (size_t i = 1; i <= range; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    
    // result[] will now contain sorted input[] vector
    for (size_t i = 0; i < n; i++)
    {
        result[count[input[i]]-1] = input[i];
        count[input[i]] -= 1;
    }

    return result;
}


int main()
{
    std::vector<int> arr = {1, 4, 1, 2, 9, 5, 2};

    std::vector<int> res = counting_sort(arr, 9);

    for (int t : res)
    {
        std::cout << t << '\n';
    }
    return 0;
}