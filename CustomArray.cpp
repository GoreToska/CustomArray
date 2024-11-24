#include <iostream>
#include <string>

#include "Classes/CustomArray.hpp"

int main()
{
    array<int> test_array;
    test_array.insert(0, 10);

    for (int i = 1; i < 20; ++i)
    {
        test_array.insert(i);
    }

    for (auto iterator = test_array.get_iterator(); iterator.has_next(); ++iterator)
    {
        //std::cout << iterator.get() << " ";
    }
    test_array.insert(5, 123);


    //test_array.insert(2, 10);
    for (auto array : test_array)
    {
        std::cout << array << " ";
    }
    std::cout << std::endl;


    test_array.remove(5);

    for (auto array : test_array)
    {
        std::cout << array << " ";
    }

    std::cin.ignore(1);
    return 0;
}
