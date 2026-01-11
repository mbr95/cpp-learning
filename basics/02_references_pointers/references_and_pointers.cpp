#include <iostream>

namespace
{
void separator()
{
    std::cout << "\n----------------------------------------\n";
}
} // namespace

// 1. References: what they really are

void referencesBasics()
{
    separator();
    std::cout << "References basics\n";

    int x = 10;
    int& ref = x;

    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';

    ref = 20; // modifies x

    std::cout << "x after ref = 20: " << x << '\n';
}

// 2. References cannot be reseated

void referencesCannotRebind()
{
    separator();
    std::cout << "References cannot be reseated\n";

    int a = 1;
    int b = 2;

    int& ref = a;
    ref = b; // assigns b's VALUE to a, does NOT rebind

    std::cout << "a = " << a << '\n'; // 2
    std::cout << "b = " << b << '\n'; // 2
}

// 3. References must be initialized

void referencesMustBeInitialized()
{
    separator();
    std::cout << "References must be initialized\n";

    int x = 5;
    int& ref = x;

    std::cout << "ref = " << ref << '\n';

    // int& badRef; // ❌ illegal
}

// 4. Pointers: explicit indirection

void pointersBasics()
{
    separator();
    std::cout << "Pointers basics\n";

    int x = 10;
    int* ptr = &x;

    std::cout << "x = " << x << '\n';
    std::cout << "*ptr = " << *ptr << '\n';

    *ptr = 30;
    std::cout << "x after *ptr = 30: " << x << '\n';
}

// 5. Pointers can be null

void nullPointers()
{
    separator();
    std::cout << "Null pointers\n";

    int* ptr = nullptr;

    if (ptr)
    {
        std::cout << *ptr << '\n';
    }
    else
    {
        std::cout << "ptr is null\n";
    }
}

// 6. Pointer reassignment

void pointerReassignment()
{
    separator();
    std::cout << "Pointer reassignment\n";

    int a = 10;
    int b = 20;

    int* ptr = &a;
    std::cout << "*ptr = " << *ptr << '\n';

    ptr = &b;
    std::cout << "*ptr after reassignment = " << *ptr << '\n';
}

// 7. References vs pointers in function parameters

void incrementByReference(int& value)
{
    value++;
}

void incrementByPointer(int* value)
{
    if (value)
    {
        (*value)++;
    }
}

void referencesVsPointers()
{
    separator();
    std::cout << "References vs pointers\n";

    int x = 10;

    incrementByReference(x);
    std::cout << "x after ref increment = " << x << '\n';

    incrementByPointer(&x);
    std::cout << "x after pointer increment = " << x << '\n';

    incrementByPointer(nullptr); // safe
}

// 8. Dangling references (DANGEROUS)

int& danglingReference()
{
    int local = 42;
    return local; // ❌ undefined behavior
}

void danglingReferenceDemo()
{
    separator();
    std::cout << "Dangling reference (DO NOT COPY)\n";

    // int& ref = danglingReference();
    // std::cout << ref << '\n'; // undefined behavior
}

// 9. Dangling pointers

int* danglingPointer()
{
    int local = 100;
    return &local; // ❌ undefined behavior
}

void danglingPointerDemo()
{
    separator();
    std::cout << "Dangling pointer (DO NOT COPY)\n";

    // int* ptr = danglingPointer();
    // std::cout << *ptr << '\n'; // undefined behavior
}

// 10. Summary comparison

void summary()
{
    separator();
    std::cout << "Summary\n";

    std::cout << "References:\n";
    std::cout << "  - must be initialized\n";
    std::cout << "  - cannot be null\n";
    std::cout << "  - cannot be reseated\n";
    std::cout << "  - usually safer\n";

    std::cout << "\nPointers:\n";
    std::cout << "  - can be null\n";
    std::cout << "  - can be reassigned\n";
    std::cout << "  - require explicit dereference\n";
    std::cout << "  - more flexible\n";
}

int main()
{
    referencesBasics();
    referencesCannotRebind();
    referencesMustBeInitialized();
    pointersBasics();
    nullPointers();
    pointerReassignment();
    referencesVsPointers();
    danglingReferenceDemo();
    danglingPointerDemo();
    summary();

    return 0;
}
