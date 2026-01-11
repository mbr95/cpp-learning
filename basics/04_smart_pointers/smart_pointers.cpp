#include <iostream>
#include <memory>
#include <string>

namespace
{
void separator()
{
    std::cout << "\n----------------------------------------\n";
}
} // namespace

// 1. unique_ptr: exclusive ownership

void uniquePtrBasics()
{
    separator();
    std::cout << "unique_ptr basics\n";

    auto ptr = std::make_unique<int>(42);

    std::cout << "*ptr = " << *ptr << '\n';

    // auto copy = ptr; // ❌ compilation error (cannot copy)

    auto moved = std::move(ptr); // ownership transfer

    if (!ptr)
    {
        std::cout << "ptr is now empty\n";
    }

    std::cout << "*moved = " << *moved << '\n';
}

// 2. unique_ptr as function parameter

void takesOwnership(std::unique_ptr<int> value)
{
    std::cout << "takesOwnership got " << *value << '\n';
}

void uniquePtrAsParameter()
{
    separator();
    std::cout << "unique_ptr as parameter\n";

    auto ptr = std::make_unique<int>(100);

    takesOwnership(std::move(ptr));

    // ptr is now empty
}

// 3. unique_ptr as return value

std::unique_ptr<int> createValue()
{
    return std::make_unique<int>(7);
}

void uniquePtrReturn()
{
    separator();
    std::cout << "unique_ptr return\n";

    auto ptr = createValue();
    std::cout << "*ptr = " << *ptr << '\n';
}

// 4. shared_ptr: shared ownership

void sharedPtrBasics()
{
    separator();
    std::cout << "shared_ptr basics\n";

    auto ptr1 = std::make_shared<int>(50);
    auto ptr2 = ptr1;

    std::cout << "use_count = " << ptr1.use_count() << '\n';
}

// 5. shared_ptr pitfalls

struct Node
{
    std::shared_ptr<Node> next;
    ~Node() { std::cout << "Node destroyed\n"; }
};

void sharedPtrCycle()
{
    separator();
    std::cout << "shared_ptr cycle (leak)\n";

    auto a = std::make_shared<Node>();
    auto b = std::make_shared<Node>();

    a->next = b;
    b->next = a; // ❌ cycle

    std::cout << "Cycle created\n";
}

// 6. weak_ptr: observing, not owning

struct SafeNode
{
    std::weak_ptr<SafeNode> next;
    ~SafeNode() { std::cout << "SafeNode destroyed\n"; }
};

void weakPtrBreakCycle()
{
    separator();
    std::cout << "weak_ptr breaks cycle\n";

    auto a = std::make_shared<SafeNode>();
    auto b = std::make_shared<SafeNode>();

    a->next = b;
    b->next = a; // ok

    std::cout << "No leak\n";
}

// 7. When NOT to use shared_ptr

void avoidSharedPtr()
{
    separator();
    std::cout << "Avoid shared_ptr unless necessary\n";

    auto ptr = std::make_unique<int>(123);

    std::cout << *ptr << '\n';
}

// main

int main()
{
    uniquePtrBasics();
    uniquePtrAsParameter();
    uniquePtrReturn();
    sharedPtrBasics();
    sharedPtrCycle();
    weakPtrBreakCycle();
    avoidSharedPtr();

    return 0;
}
