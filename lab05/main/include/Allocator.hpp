#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>

//#define DEBUG
template <typename T, std::size_t BatchSize>
class Allocator {
    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        template <typename U>
        struct rebind {
            using other = Allocator<U, BatchSize>;
        };

        Allocator() {
            for (std::size_t i = 0; i < BatchSize; ++i) {
                T* ptr = new T();
                freeList.push_back(ptr);
            }
        }

        ~Allocator() {
            if (!freeList.empty()){
                for (T* ptr : freeList) {
                    delete ptr;
                }
            }
        }

        template <typename U>
        Allocator(const Allocator<U, BatchSize>&) {
            for (std::size_t i = 0; i < BatchSize; ++i) {
                T* ptr = new T();
                freeList.push_back(ptr);
            }
        }

        T* allocate(std::size_t n) {
            if (n > BatchSize || n == 0) {
                throw std::bad_alloc();
            }

            if (freeList.empty()) {
                for (std::size_t i = 0; i < BatchSize; ++i) {
                    T* ptr = new T();
                    freeList.push_back(ptr);
                }
            }

            std::list<T*> allocatedBlocks;
            for (std::size_t i = 0; i < n; ++i) {
                T* ptr = freeList.front();
                freeList.pop_front();
                allocatedBlocks.push_back(ptr);
            }

            return allocatedBlocks.front();
        }

        void deallocate(T* ptr, std::size_t n) {
            //if (n != 1) {
            //    throw std::bad_alloc();
            //}
            //freeList.push_back(ptr);
            for (std::size_t i = 0; i < n; ++i) {
                T* elementPtr = ptr + i;
                freeList.push_back(elementPtr);
            }
        }

    private:
        std::list<T*> freeList;
};

