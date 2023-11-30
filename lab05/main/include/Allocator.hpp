#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>

//#define DEBUG
template <typename T>
class Allocator {
    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        Allocator() noexcept {}

        ~Allocator() {
            if (!usedBlocks.empty()){
                for (T* ptr : usedBlocks) {
                    delete ptr;
                }
            }
        }

        template <typename U>
        struct rebind {
            using other = Allocator<U>;
        };

        T* allocate(std::size_t n) {
            if (usedBlocks.empty()) {
                for (std::size_t i = 0; i < 10; ++i) {
                    T* ptr = new T();
                    usedBlocks.push_back(ptr);
                }
            }

            std::list<T*> allocatedBlocks;
            for (std::size_t i = 0; i < n; ++i) {
                T* ptr = usedBlocks.front();
                usedBlocks.pop_front();
                allocatedBlocks.push_back(ptr);
            }

            return allocatedBlocks.front();
        }

        void deallocate(T* ptr, std::size_t n) {
            //if (n != 1) {
            //    throw std::bad_alloc();
            //}
            // usedBlocks.push_back(ptr);
            for (std::size_t i = 0; i < n; ++i) {
                T* elementPtr = ptr + i;
                usedBlocks.push_back(elementPtr);
            }
        }

    private:
        std::list<T*> usedBlocks;
};

