#include "TestClass.h"
#include "gtest/gtest.h"
#include "../Classes/CustomArray.hpp"

TEST(Insert, InsertTest01)
{
    array<int> test_array;
    for (int i = 0; i < 8; i++)
    {
        test_array.insert(i); // 0 1 2 3 4 5 6 7
    }

    for (int i = 0; i < 8; i++)
    {
        EXPECT_EQ(test_array[i], i); // 0 1 2 3 4 10 5 6 7
    }
    
    test_array.insert(5, 10);

    EXPECT_EQ(test_array[0], 0);
    EXPECT_EQ(test_array[1], 1);
    EXPECT_EQ(test_array[2], 2);
    EXPECT_EQ(test_array[3], 3);
    EXPECT_EQ(test_array[4], 4);
    EXPECT_EQ(test_array[5], 10);
    EXPECT_EQ(test_array[6], 5);
    EXPECT_EQ(test_array[7], 6);
    EXPECT_EQ(test_array[8], 7);
}

TEST(Remove, RemoveAt)
{
    array<int> test_array;
    for (int i = 0; i < 8; i++)
    {
        test_array.insert(i);
    }

    test_array.remove(5);

    EXPECT_EQ(test_array[5], 6);
    EXPECT_EQ(test_array.size(), 7);
}

TEST(Size, IncreasingSize)
{
    array<int> test_array;
    EXPECT_EQ(test_array.size(), 0);

    for (int i = 0; i < 8; i++)
    {
        test_array.insert(i);
    }

    EXPECT_EQ(test_array.size(), 8);
}

TEST(Size, Resize)
{
    array<int> test_array(2);
    test_array.insert(1);
    test_array.insert(2);

    EXPECT_NO_THROW(test_array.insert(3));
    EXPECT_NO_THROW(test_array.insert(4));
    EXPECT_NO_THROW(test_array.insert(5));
    EXPECT_EQ(test_array.size(), 5);
}

TEST(Iterator, IteratorEqualsArray)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto iterator = test_array.get_iterator();

    for (int i = 0; i < 5; ++i, iterator.next())
    {
        EXPECT_EQ(test_array[i], iterator.get());
    }
}

TEST(Iterator, IteratorSet)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto iterator = test_array.get_iterator();
    iterator.set(10);

    EXPECT_EQ(test_array[0], iterator.get());
}

TEST(Iterator, IncrementOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto pre_iterator = test_array.get_iterator();
    for (int i = 0; pre_iterator.has_next(); ++pre_iterator, ++i)
    {
        EXPECT_EQ(pre_iterator.get(), test_array[i]);
    }

    auto post_iterator = test_array.get_iterator();
    for (int i = 0; post_iterator.has_next(); post_iterator++, ++i)
    {
        EXPECT_EQ(post_iterator.get(), test_array[i]);
    }
}

TEST(Iterator, PointerOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto pre_iterator = test_array.get_iterator();
    for (int i = 0; pre_iterator.has_next(); ++pre_iterator, ++i)
    {
        EXPECT_EQ(*pre_iterator, test_array[i]);
    }
}

TEST(ReverseIterator, IteratorEqualsArray)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto iterator = test_array.get_reverse_iterator();

    for (int i = 4; i > 0; --i, iterator.next())
    {
        EXPECT_EQ(test_array[i], iterator.get());
    }
}

TEST(ReverseIterator, IteratorSet)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto iterator = test_array.get_reverse_iterator();
    iterator.set(10);
    EXPECT_EQ(test_array[4], iterator.get());
}

TEST(ReverseIterator, IncrementOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto pre_iterator = test_array.get_reverse_iterator();
    for (int i = test_array.size() - 1; pre_iterator.has_next(); ++pre_iterator, --i)
    {
        EXPECT_EQ(pre_iterator.get(), test_array[i]);
    }

    auto post_iterator = test_array.get_reverse_iterator();
    for (int i = test_array.size() - 1; post_iterator.has_next(); post_iterator++, --i)
    {
        EXPECT_EQ(post_iterator.get(), test_array[i]);
    }
}

TEST(ReverseIterator, PointerOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    auto pre_iterator = test_array.get_reverse_iterator();
    for (int i = test_array.size() - 1; pre_iterator.has_next(); ++pre_iterator, --i)
    {
        EXPECT_EQ(*pre_iterator, test_array[i]);
    }
}

TEST(ConstIterator, IteratorEqualsArray)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    const array<int> const_array = test_array;
    auto iterator = const_array.get_iterator();

    for (int i = 0; i < 5; ++i, iterator.next())
    {
        EXPECT_EQ(test_array[i], iterator.get());
    }
}

TEST(ConstIterator, IncrementOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    const array<int> const_array = test_array;
    auto pre_iterator = const_array.get_iterator();

    for (int i = 0; i < 5; ++i, ++pre_iterator)
    {
        EXPECT_EQ(test_array[i], pre_iterator.get());
    }

    auto post_iterator = const_array.get_iterator();
    for (int i = 0; i < 5; ++i, post_iterator++)
    {
        EXPECT_EQ(test_array[i], post_iterator.get());
    }
}

TEST(ConstIterator, PointerOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    const array<int> const_array = test_array;
    auto pre_iterator = const_array.get_iterator();

    for (int i = 0; pre_iterator.has_next(); ++pre_iterator, ++i)
    {
        EXPECT_EQ(*pre_iterator, test_array[i]);
    }
}

TEST(ReverseConstIterator, IteratorEqualsArray)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    const array<int> const_array = test_array;
    auto iterator = const_array.get_reverse_iterator();

    for (int i = const_array.size() - 1; i >= 0; --i, iterator.next())
    {
        EXPECT_EQ(test_array[i], iterator.get());
    }
}

TEST(ReverseConstIterator, IncrementOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    const array<int> const_array = test_array;
    auto pre_iterator = const_array.get_reverse_iterator();
    for (int i = const_array.size() - 1; i >= 0; --i, ++pre_iterator)
    {
        EXPECT_EQ(test_array[i], pre_iterator.get());
    }

    auto post_iterator = const_array.get_reverse_iterator();
    for (int i = const_array.size() - 1; i >= 0; --i, post_iterator++)
    {
        EXPECT_EQ(test_array[i], post_iterator.get());
    }
}

TEST(ReverseConstIterator, PointerOverload)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    const array<int> const_array = test_array;
    auto iterator = const_array.get_reverse_iterator();

    for (int i = const_array.size() - 1; i >= 0; --i, iterator.next())
    {
        EXPECT_EQ(test_array[i], *iterator);
    }
}

TEST(Iterator, BeginEnd)
{
    array<int> test_array(5);
    for (int i = 0; i < 5; ++i)
    {
        test_array.insert(i);
    }

    int i = 0;
    for (auto array : test_array)
    {
        ++i;
        EXPECT_EQ(array, i-1);
    }

    EXPECT_EQ(test_array.size(), i);
}

TEST(Destructor)
{
    {
        array<test_class> test_array;
        test_class test01{};
        test_class test02{};
        test_array.insert(test01);
        test_array.insert(test02);
    }
    EXPECT_NO_THROW();

    {
        array<test_class> test_array;
        {
            test_class test01{};
            test_class test02{};
            test_array.insert(test01);
            test_array.insert(test02);
        }
    }
    EXPECT_NO_THROW();

    {
        test_class test01{};
        test_class test02{};
        {
            array<test_class> test_array;
            test_array.insert(test01);
            test_array.insert(test02);
        }
    }
    EXPECT_NO_THROW();
}