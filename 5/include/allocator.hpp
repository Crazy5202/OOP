#pragma once
#include <memory>
#include <array>

template <typename T, size_t N = 1000>
class MyAllocator {
public:
    using value_type = T;

    template <typename U>
    struct rebind {
        typedef MyAllocator<U, N> other;
    };

    MyAllocator() = default;
    ~MyAllocator() = default;

    T* allocate(std::size_t n) {
        static std::size_t counter = 0;
        if (n > N) {
            throw std::bad_alloc();
        }
        T* ptr = &data_[counter];
        counter+=n;
        return ptr;
    }

    void deallocate(T* p, size_t n) {}

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        new (p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* p) {
        p->~U();
    }
private:
    std::array<T, sizeof(T) * N> data_;
};

template <class T1, class T2, size_t count>
constexpr bool operator==(const MyAllocator<T1,count> &lhs, const MyAllocator<T2,count> &rhs) 
{
    return true;
}

template <typename T1, typename T2, size_t count>
constexpr bool operator!=(const MyAllocator<T1,count> &lhs, const MyAllocator<T2,count> &rhs)  
{
    return false;
}