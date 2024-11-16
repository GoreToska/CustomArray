#pragma once

class test_class
{
public:
    explicit test_class();
    test_class(const test_class& other);
    test_class(test_class&& other) noexcept;
    ~test_class();

private:
    int* numbers_;
};
