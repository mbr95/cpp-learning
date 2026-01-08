#include <iostream>
#include <string>

namespace
{
void printSeparator()
{
    std::cout << "\n----------------------------------------\n";
}
} // namespace

// 1. const variables

void constVariables()
{
    printSeparator();
    std::cout << "const variables\n";

    const int x = 42;
    std::cout << "x = " << x << '\n';

    // Uncommenting this line will NOT compile:
    // x = 10;
}

// 2. const references

void printValue(const int& value)
{
    // value cannot be modified here
    std::cout << "value = " << value << '\n';
}

void constReferences()
{
    printSeparator();
    std::cout << "const references\n";

    int a = 10;
    printValue(a);  // binds to non-const
    printValue(42); // binds to temporary

    const int b = 20;
    printValue(b);
}

// 3. Pointers and const (CRITICAL SECTION)

void constPointers()
{
    printSeparator();
    std::cout << "const and pointers\n";

    int value = 10;
    int other = 20;

    const int* ptrToConst = &value;
    // *ptrToConst = 30;   // ❌ cannot modify value through pointer
    ptrToConst = &other; // ✅ pointer itself can change

    int* const constPtr = &value;
    *constPtr = 30; // ✅ can modify value
    // constPtr = &other; // ❌ pointer cannot change

    const int* const constPtrToConst = &value;
    // *constPtrToConst = 40; // ❌
    // constPtrToConst = &other; // ❌

    std::cout << "value = " << value << '\n';
}

// 4. const member functions

class Counter
{
  public:
    explicit Counter(int value) : m_value(value) {}

    int get() const
    {
        // m_value++; // ❌ not allowed in const function
        return m_value;
    }

    void increment() { ++m_value; }

  private:
    int m_value;
};

void constMemberFunctions()
{
    printSeparator();
    std::cout << "const member functions\n";

    Counter c{10};
    c.increment();
    std::cout << "c.get() = " << c.get() << '\n';

    const Counter cc{100};
    std::cout << "cc.get() = " << cc.get() << '\n';

    // cc.increment(); // ❌ cannot call non-const function
}

// 5. const correctness in APIs (VERY IMPORTANT)

class User
{
  public:
    explicit User(std::string name) : m_name(std::move(name)) {}

    // Good: does not modify the object
    const std::string& name() const { return m_name; }

    // Good: modifies the object
    void setName(const std::string& name) { m_name = name; }

  private:
    std::string m_name;
};

void constCorrectApis()
{
    printSeparator();
    std::cout << "const correctness in APIs\n";

    User user{"Alice"};
    std::cout << user.name() << '\n';

    user.setName("Bob");
    std::cout << user.name() << '\n';

    const User readonlyUser{"Charlie"};
    std::cout << readonlyUser.name() << '\n';

    // readonlyUser.setName("Dave"); // ❌ not allowed
}

// 6. const is NOT immutability

class Weird
{
  public:
    void mutate() const
    {
        // const applies to *this*, not to everything reachable
        m_value++;
    }

    int value() const { return m_value; }

  private:
    mutable int m_value{0};
};

void constIsNotImmutability()
{
    printSeparator();
    std::cout << "const is not immutability\n";

    const Weird w{};
    w.mutate(); // allowed due to 'mutable'

    std::cout << "w.value() = " << w.value() << '\n';
}

// main

int main()
{
    constVariables();
    constReferences();
    constPointers();
    constMemberFunctions();
    constCorrectApis();
    constIsNotImmutability();

    printSeparator();
    std::cout << "End of const correctness demo\n";

    return 0;
}
