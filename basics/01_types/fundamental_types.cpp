#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
namespace
{
void printSeparator()
{
    std::cout << "\n----------------------------\n";
}
} // namespace

int main()
{

    // 1. Integer types and sizes

    printSeparator();
    std::cout << "Integer type sizes (bytes)\n";

    std::cout << "sizeof(bool):     " << sizeof(bool) << '\n';
    std::cout << "sizeof(char):     " << sizeof(char) << '\n';
    std::cout << "sizeof(short):     " << sizeof(short) << '\n';
    std::cout << "sizeof(int):     " << sizeof(int) << '\n';
    std::cout << "sizeof(long):     " << sizeof(long) << '\n';
    std::cout << "sizeof(long long):     " << sizeof(long long) << '\n';

    // Guaranteed ordering
    static_assert(sizeof(short) <= sizeof(int));
    static_assert(sizeof(short) <= sizeof(int));

    // 2. Fixed-widh Integer types

    printSeparator();
    std::cout << "Fixed-width Integer types\n";

    std::int32_t i32 = 42;
    std::uint64_t u64 = 42;

    std::cout << "int32_t value:  " << i32 << '\n';
    std::cout << "uint64_t value:  " << u64 << '\n';

    static_assert(sizeof(std::int32_t) == 4);
    static_assert(sizeof(std::uint64_t) == 8);

    // 3. Signed vs Unsigned pitfall

    printSeparator();
    std::cout << "Signed vs unsigned comparison pitfall\n";

    int signedValue = -1;
    unsigned int unsignedValue = 1;

    std::cout << "signed value =  " << signedValue << '\n';
    std::cout << "unsigned value =  " << unsignedValue << '\n';

    if (signedValue < unsignedValue)
    {
        std::cout << "signedValue < unsignedValue (unexpected)\n";
    }
    else
    {
        std::cout << "signedValue >= unsignedValue (actual result)\n";
    }

    // 4. Integer limits

    printSeparator();
    std::cout << "Integer limits\n";

    std::cout << "int min:  " << std::numeric_limits<int>::min() << '\n';
    std::cout << "int max:  " << std::numeric_limits<int>::max() << '\n';

    std::cout << "unsigned int max:  " << std::numeric_limits<unsigned int>::max() << '\n';

    // 5. Floating point types

    printSeparator();
    std::cout << "Floating-point types\n";

    float f = 0.1f;
    double d = 0.1;

    std::cout << std::setprecision(17);
    std::cout << "float 0.1f =  " << f << '\n';
    std::cout << "double 0.1 =  " << d << '\n';

    double a = 0.1 + 0.2;
    double b = 0.3;

    std::cout << "0.1 + 0.2 == 0.3 ? " << (a == b) << '\n';

    // 6. Brace initialization and narrowing

    printSeparator();
    std::cout << "Brace initialization\n";

    int safeInt{42};
    std::cout << "safeInt = " << safeInt << '\n';

    // Uncommenting the following line should FAIL to compile:
    // int narrowing{3.14};

    // 7. sizeof and Object layout

    printSeparator();
    std::cout << "sizeof and layout\n";

    struct Example
    {
        char c;
        int i;
    };

    std::cout << "sizeof(Example): " << sizeof(Example) << '\n';
    std::cout << "sizeof(char) + sizeof(int): " << sizeof(char) + sizeof(int) << '\n';

    std::cout << "Padding exists due to alignment\n";

    printSeparator();
    std::cout << "End of fundamental types demo\n";
}
