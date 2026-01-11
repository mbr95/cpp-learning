#include <iostream>
#include <string>

namespace
{
void separator()
{
    std::cout << "\n----------------------------------------\n";
}
} // namespace

// 1. Automatic storage (stack)

void automaticStorage()
{
    separator();
    std::cout << "Automatic storage\n";

    int x = 42;
    std::string s = "hello";

    std::cout << "x = " << x << ", s = " << s << '\n';
    // Objects destroyed automatically at scope end
}

// 2. Static storage duration

void staticStorage()
{
    separator();
    std::cout << "Static storage\n";

    static int counter = 0;
    counter++;

    std::cout << "counter = " << counter << '\n';
}

// 3. Dynamic allocation (RAW - DANGEROUS)

void dynamicAllocationRaw()
{
    separator();
    std::cout << "Dynamic allocation (raw)\n";

    int* ptr = new int(10);
    std::cout << "*ptr = " << *ptr << '\n';

    delete ptr; // must be called exactly once
}

// 4. Memory leak example

void memoryLeakExample()
{
    separator();
    std::cout << "Memory leak example\n";

    int* ptr = new int(99);
    std::cout << "*ptr = " << *ptr << '\n';

    delete ptr; // ❌ leak if not deleted
}

// 5. Double delete example

void doubleDeleteExample()
{
    separator();
    std::cout << "Double delete example\n";

    int* ptr = new int(5);
    delete ptr;

    // delete ptr; // ❌ undefined behavior
}

// 6. RAII: Resource Acquisition Is Initialization

class File
{
  public:
    explicit File(const std::string& name) : m_name(name)
    {
        std::cout << "Opening file: " << m_name << '\n';
    }

    ~File() { std::cout << "Closing file: " << m_name << '\n'; }

  private:
    std::string m_name;
};

void raiiExample()
{
    separator();
    std::cout << "RAII example\n";

    {
        File f{"data.txt"};
        std::cout << "Using file\n";
    } // destructor automatically called here
}

// 7. Ownership transfer is explicit

class Owner
{
  public:
    explicit Owner(int* ptr) : m_ptr(ptr) {}

    ~Owner() { delete m_ptr; }

  private:
    int* m_ptr;
};

void ownershipExample()
{
    separator();
    std::cout << "Ownership example\n";

    Owner owner{new int(123)};
}

// 8. Stack vs heap comparison

void stackVsHeap()
{
    separator();
    std::cout << "Stack vs heap\n";

    int stackValue = 10;
    int* heapValue = new int(20);

    std::cout << "stackValue = " << stackValue << '\n';
    std::cout << "*heapValue = " << *heapValue << '\n';

    delete heapValue;
}

// main

int main()
{
    automaticStorage();
    staticStorage();
    dynamicAllocationRaw();
    memoryLeakExample();
    doubleDeleteExample();
    raiiExample();
    ownershipExample();
    stackVsHeap();

    return 0;
}
