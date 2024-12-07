#include "TestClass.h"

#include <algorithm>
#include <cstdlib>

test_class::test_class()
{
    numbers_ = static_cast<int*>(malloc(10 * sizeof(int)));

    for (size_t i = 0; i < 10; ++i)
    {
        numbers_[i] = i;
    }
}

test_class::test_class(const test_class& other) noexcept
{
    numbers_ = static_cast<int*>(malloc(10 * sizeof(int)));

    for (size_t i = 0; i < 10; ++i)
    {
        numbers_[i] = other.numbers_[i];
    }
}

/*test_class::test_class(test_class&& other) noexcept
{
    numbers_ = other.numbers_;
    other.numbers_ = nullptr;
}*/

test_class::~test_class()
{
    free(numbers_);
}

/*test_class& test_class::operator=(test_class&& other) noexcept
{
    test_class temp(std::move(other));
    std::swap(numbers_, temp.numbers_);

    return *this;
}*/
