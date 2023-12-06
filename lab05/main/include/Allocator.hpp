#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>

//#define DEBUG
namespace mai{
    template <typename T, size_t N = 100>
    class Allocator {
        private:
            std::list<T> _used_blocks;
            std::list<T*> _free_blocks;
            size_t _free_count;
            size_t _max_count = N;

        public:
            using value_type = T;
            using pointer = T*;
            using const_pointer = const T*;
            using size_type = std::size_t;

            Allocator() {
                _free_count = _max_count;
                for (size_t i{0}; i < _max_count; ++i) {
                    _used_blocks.push_back(T{}); // Заполняем used_blocks для выделения памяти
                    _free_blocks.push_back(&_used_blocks.back());
                }
            }

            ~Allocator() = default;

            template <typename U>
            struct rebind {
                using other = Allocator<U, N>;
            };

            pointer allocate(size_t n) {
                pointer result = nullptr;
                if (n && (_free_count >= n)) {
                    auto it = std::prev(_free_blocks.end(), n);
                    result = *it;
                    _free_count -= n;
                    _free_blocks.erase(it, _free_blocks.end());
                } else if (_free_count < n) {
                    throw std::bad_alloc();
                }
                return result;
            }

            void deallocate(pointer ptr, size_t n) {
                for (size_t i{0}; i < n; ++i) {
                    _free_blocks.push_back(ptr + i);
                }
                _free_count += n;
            }

            template <typename U, typename... Args>
            void construct(U* p, Args &&...args) {
                new (p) U(std::forward<Args>(args)...);
            }

            void destroy(pointer p) {
                p->~T();
            }

            size_type max_size() const noexcept {
                return _max_count;
            }
    };
}
