#include <iostream>
#include <string>
#include <vector>

namespace
{
void separator()
{
    std::cout << "\n----------------------------------------\n";
}
} // namespace

// 1. Copy vs move (observable behavior)

class Buffer
{
  public:
    explicit Buffer(size_t size) : m_size(size), m_data(new int[size])
    {
        std::cout << "Constructed (" << m_size << ")\n";
    }

    // Copy constructor
    Buffer(const Buffer& other) : m_size(other.m_size), m_data(new int[other.m_size])
    {
        std::cout << "Copied (" << m_size << ")\n";
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept : m_size(other.m_size), m_data(other.m_data)
    {
        other.m_size = 0;
        other.m_data = nullptr;
        std::cout << "Moved (" << m_size << ")\n";
    }

    ~Buffer()
    {
        delete[] m_data;
        std::cout << "Destroyed (" << m_size << ")\n";
    }

  private:
    size_t m_size{};
    int* m_data{};
};

// 2. Returning objects (RVO / move)

Buffer createBuffer()
{
    Buffer b{10};
    return b; // no copy, no move (RVO)
}

void returnValueOptimization()
{
    separator();
    std::cout << "Return value optimization\n";

    Buffer buf = createBuffer();
}

// 3. std::move usage

void stdMoveExample()
{
    separator();
    std::cout << "std::move example\n";

    Buffer a{5};
    Buffer b = std::move(a);

    // a is now in a valid but unspecified state
}

// 4. Move semantics in containers
void moveInContainers()
{
    separator();
    std::cout << "Move semantics in containers\n";

    std::vector<Buffer> buffers;
    buffers.reserve(3);

    buffers.emplace_back(10);
    buffers.emplace_back(20);
    buffers.emplace_back(30);
}

// 5. Why noexcept matters

class RiskyBuffer
{
  public:
    explicit RiskyBuffer(size_t size) : m_data(new int[size]) {}

    RiskyBuffer(RiskyBuffer&& other) // not noexcept!
        : m_data(other.m_data)
    {
        other.m_data = nullptr;
    }

    ~RiskyBuffer() { delete[] m_data; }

  private:
    int* m_data{};
};

void noexceptMatters()
{
    separator();
    std::cout << "noexcept matters\n";

    std::vector<RiskyBuffer> v;
    v.reserve(2);

    v.emplace_back(10);
    v.emplace_back(20); // may copy instead of move
}

// main

int main()
{
    returnValueOptimization();
    stdMoveExample();
    moveInContainers();
    noexceptMatters();

    return 0;
}
