#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

// 1. Exceptions: basic usage

int divide(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error("division by zero");
    }
    return a / b;
}

void exceptionsBasics()
{
    std::cout << "\nExceptions basics\n";

    try
    {
        int result = divide(10, 2);
        std::cout << "result = " << result << '\n';

        result = divide(10, 0); // throws
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
}

// 2. RAII + exceptions (CRITICAL)

class Resource
{
  public:
    Resource() { std::cout << "Resource acquired\n"; }

    ~Resource() { std::cout << "Resource released\n"; }
};

void raiiWithExceptions()
{
    std::cout << "\nRAII with exceptions\n";

    try
    {
        Resource r;
        throw std::runtime_error("something failed");
    }
    catch (...)
    {
        std::cout << "Exception handled\n";
    }
}

// 3. Why return codes don’t scale

bool parseInt(const std::string& text, int& outValue)
{
    try
    {
        outValue = std::stoi(text);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

void returnCodeExample()
{
    std::cout << "\nReturn code example\n";

    int value{};
    if (parseInt("123", value))
    {
        std::cout << "Parsed: " << value << '\n';
    }
    else
    {
        std::cout << "Parse failed\n";
    }
}

// 4. std::optional: absence is normal

std::optional<int> tryParseInt(const std::string& text)
{
    try
    {
        return std::stoi(text);
    }
    catch (...)
    {
        return std::nullopt;
    }
}

void optionalExample()
{
    std::cout << "\nstd::optional example\n";

    auto value = tryParseInt("456");

    if (value)
    {
        std::cout << "Parsed: " << *value << '\n';
    }
    else
    {
        std::cout << "No value\n";
    }
}

// 5. std::expected (C++23 style, conceptual)

struct Error
{
    std::string message;
};

template <typename T> struct Expected
{
    std::optional<T> value;
    std::optional<Error> error;
};

Expected<int> tryParseIntExpected(const std::string& text)
{
    try
    {
        return {std::stoi(text), std::nullopt};
    }
    catch (...)
    {
        return {std::nullopt, Error{"invalid integer"}};
    }
}

void expectedExample()
{
    std::cout << "\nExpected-style example\n";

    auto result = tryParseIntExpected("abc");

    if (result.value)
    {
        std::cout << "Parsed: " << *result.value << '\n';
    }
    else
    {
        std::cout << "Error: " << result.error->message << '\n';
    }
}

// main

int main()
{
    exceptionsBasics();
    raiiWithExceptions();
    returnCodeExample();
    optionalExample();
    expectedExample();

    return 0;
}
