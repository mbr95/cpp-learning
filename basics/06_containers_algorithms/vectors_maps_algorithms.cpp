#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

namespace
{
void separator()
{
    std::cout << "\n----------------------------------------\n";
}
} // namespace

// 1. std::vector: the default container

void vectorBasics()
{
    separator();
    std::cout << "vector basics\n";

    std::vector<int> v{1, 2, 3};

    v.push_back(4);
    v.emplace_back(5);

    for (int value : v)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

// 2. vector capacity vs size

void vectorCapacity()
{
    separator();
    std::cout << "vector capacity vs size\n";

    std::vector<int> v;
    v.reserve(10);

    std::cout << "size = " << v.size() << ", capacity = " << v.capacity() << '\n';

    v.push_back(1);
    v.push_back(2);

    std::cout << "size = " << v.size() << ", capacity = " << v.capacity() << '\n';
}

// 3. std::array vs std::vector

void arrayVsVector()
{
    separator();
    std::cout << "array vs vector\n";

    std::array<int, 3> arr{1, 2, 3};
    std::vector<int> vec{1, 2, 3};

    std::cout << "array size = " << arr.size() << '\n';
    std::cout << "vector size = " << vec.size() << '\n';
}

// 4. std::map vs std::unordered_map

void mapVsUnorderedMap()
{
    separator();
    std::cout << "map vs unordered_map\n";

    std::map<int, std::string> ordered;
    ordered[1] = "one";
    ordered[2] = "two";

    std::unordered_map<int, std::string> unordered;
    unordered[1] = "one";
    unordered[2] = "two";

    std::cout << "ordered map:\n";
    for (const auto& [k, v] : ordered)
    {
        std::cout << k << " -> " << v << '\n';
    }

    std::cout << "unordered map:\n";
    for (const auto& [k, v] : unordered)
    {
        std::cout << k << " -> " << v << '\n';
    }
}

// 5. Algorithms work on iterators

void algorithmsBasics()
{
    separator();
    std::cout << "algorithms basics\n";

    std::vector<int> v{1, 2, 3, 4, 5};

    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "sum = " << sum << '\n';

    std::reverse(v.begin(), v.end());

    for (int i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

// 6. find_if and lambdas

void findIfExample()
{
    separator();
    std::cout << "find_if example\n";

    std::vector<int> v{1, 3, 5, 8, 9};

    auto it = std::find_if(v.begin(), v.end(), [](int value) { return value % 2 == 0; });

    if (it != v.end())
    {
        std::cout << "First even value = " << *it << '\n';
    }
}

// 7. erase-remove idiom

void eraseRemoveIdiom()
{
    separator();
    std::cout << "erase-remove idiom\n";

    std::vector<int> v{1, 2, 3, 4, 5, 6};

    v.erase(std::remove_if(v.begin(), v.end(), [](int value) { return value % 2 == 0; }), v.end());

    for (int i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

// main

int main()
{
    vectorBasics();
    vectorCapacity();
    arrayVsVector();
    mapVsUnorderedMap();
    algorithmsBasics();
    findIfExample();
    eraseRemoveIdiom();

    return 0;
}
