#include <iostream>

#include "Classes/CustomArray.hpp"


class Example
{
public:
    char* symbol;
    int i;

    Example(int i): i(i)
    {
        symbol = static_cast<char*>(malloc(1 * sizeof(char)));
        symbol[0] = 'a';
    }

    ~Example()
    {
        std::cout << "\nDestructor! " << i;
        free(symbol);
    }
};

int main()
{
    array<int> test_array;

    for (int i = 0; i < 20; ++i)
    {
        std::cout << test_array.insert(i) << std::endl;
    }

    for (auto iterator = test_array.get_iterator(); iterator.has_next(); ++iterator)
    {
        std::cout << iterator.get() << " ";
    }

    std::cout << std::endl;

    test_array.insert(2, 10);
    for (auto array : test_array)
    {
        std::cout << array << " ";
    }

    std::cin.ignore(1);
    return 0;
}
