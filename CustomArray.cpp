#include <iostream>
#include <string>

#include "Classes/CustomArray.hpp"
#include "CustomArrayTests/TestClass.cpp"
#include <vector>

int main()
{
    /*array<test_class> test_array(1);
    std::vector<test_class> test_vector(1);
    test_class test1;
    test_class test2;
    test_class test3;

    test_array.insert(test1);
    test_array.insert(test2);
    test_array.insert(test3);*/
    //test_vector.insert(test_vector.begin(), std::move_if_noexcept(test1));
    //test_array.insert(test1);
    //std::cout << test_array[0].numbers_[1];
    //test_array.insert(test2);
    //test_vector.emplace(test_vector.begin());
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
