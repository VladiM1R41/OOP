#pragma once
#include <iostream>

namespace mai{

    template <typename T>
    struct Node {
        T _data;
        Node<T>* _next;
    };

    template<typename T, template <typename> typename Allocator = std::allocator>
    class List {
    private:
        Node<T>* _head;
        Node<T>* _tail;
        size_t _size;
        Allocator<Node<T>> _allocator;

    public:
        class Const_List_Iterator {
        private:
            const Node<T>* _node;

        public:
            friend class List;

            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = const T;
            using pointer_type = T*;
            using reference_type = T&;

            Const_List_Iterator() = default;
            Const_List_Iterator(const Node<T>* ptr) : _node(ptr) {}

            T& operator*() const {
                if (!_node) {
                    throw std::runtime_error("Iterator error");
                }
                return _node->_data;
            }

            Const_List_Iterator& operator++() {
                if (!_node) {
                    throw std::runtime_error("Iterator error");
                }
                _node = _node->_next;
                return *this;
            }

            bool operator==(const Const_List_Iterator& other) const {
                return _node == other._node;
            }

            bool operator!=(const Const_List_Iterator& other) const {
                return !(*this == other);
            }

        };

        class List_Iterator {
        private:
            Node<T>* _node;

        public:
            friend class List;

            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer_type = T*;
            using reference_type = T&;

            List_Iterator() = default;
            List_Iterator(Node<T>* ptr) : _node(ptr) {}

            T& operator*() {
                if (!_node) {
                    throw std::runtime_error("List_Iterator error");
                }
                return _node->_data;
            }

            List_Iterator& operator++() {
                if (!_node) {
                    throw std::runtime_error("List_Iterator error");
                }
                _node = _node->_next;
                return *this;
            }

            bool operator==(const List_Iterator other) const {
                return _node == other._node;
            }
            bool operator!=(const List_Iterator other) const {
                return !(*this == other);
            }
        };

        List() : _size(0){
            _head = _tail = _allocator.allocate(1);
        }

        List(std::initializer_list<T> const & init) : _size(0){
            _head = _tail = _allocator.allocate(1);
            for (auto el : init) {
                this->push_back(el);
            }
        }

        List(List<T, Allocator> const & other) : _size(0) {
            List_Iterator it {other._head};
            List_Iterator end {other._tail};
            _head = _tail = _allocator.allocate(1);
            for (; it != end; ++it) {
                this->push_back(*it);
            }
        }

        List(List<T, Allocator>&& other) : _head(other._head), _tail(other._tail), _size(other._size) {
            _allocator = std::move(other._allocator);
            other._head = nullptr;
            other._tail = nullptr;
            other._size = 0;
        }

        ~List() {
            this->clear();
            _allocator.deallocate(_head, 1);
        }

        List<T, Allocator>& operator=(const List<T, Allocator>& other) {
            if (this == &other) {
                return *this;
            }
            this->clear();
            _size = 0;
            List_Iterator it {other._head};
            List_Iterator end {other._tail};
            for (; it != end; ++it) {
                this->push_back(*it);
            }
            return *this;
        }

        List<T, Allocator>& operator=(List<T, Allocator>&& other) noexcept {
            this->clear();
            _allocator.deallocate(_head, 1);
            _head = other._head;
            _tail = other._tail;
            _size = other._size;
            _allocator = std::move(other._allocator);
            other._head = nullptr;
            other._tail = nullptr;
            other._size = 0;

            return *this;
        }

        size_t size() const noexcept {
            return _size;
        }

        void clear() {
            while(!this->empty()) {
                this->erase(List_Iterator(_head));
            }
        }

        List_Iterator insert(List_Iterator pos, const T& value) {
            ++_size;
            Node<T>* node = _head;
            if(pos._node){ 
                while(node->_next != pos._node && node->_next != nullptr){
                    node = node->_next;
                }
            }else{
                while(node->_next != nullptr){
                    node = node->_next;
                }
            }
            Node<T>* tmp = _allocator.allocate(1);
            tmp->_data = value;
            tmp->_next = node->_next;
            node->_next = tmp;
            
            return List_Iterator(node ? node->_next : _head);
        }

        List_Iterator erase(List_Iterator pos) {
            Node<T>* node;
            if (pos._node){
                if (pos._node == _head){
                    node = _head;
                    _head = _head->_next;
                    --_size;
                    _allocator.deallocate(node, 1);
                    return List_Iterator(_head);
                }else if(pos._node == _tail){
                    node = _tail;
                    Node<T>* prev_tail = _head;
                    while(prev_tail->_next != _tail){
                        prev_tail = prev_tail->_next;
                    }
                    prev_tail->_next = nullptr;
                    _tail = prev_tail;
                    --_size;
                    _allocator.deallocate(node, 1);
                    return List_Iterator(_tail);
                }else{
                    node = _head;
                    while(node->_next != pos._node && node->_next != nullptr){
                        node = node->_next;
                    }
                    node->_next = pos._node->_next;
                    --_size;
                    _allocator.deallocate(pos._node, 1);
                    return List_Iterator(node);
                }
            }else{
                throw std::logic_error("Error: element not exist");
            }

        }

        void push_back(const T& value) {
            _tail->_next = _allocator.allocate(1);
            _tail->_data = value;
            _tail = _tail->_next;
            ++_size;
        }


        bool empty() const noexcept {
            return _head == _tail;
        }

        List_Iterator begin() {
            return List_Iterator(_head);
        }

        List_Iterator end() {
            return List_Iterator(_tail->_next);
        }

        Const_List_Iterator begin() const {
            return Const_List_Iterator(_head);
        }

        Const_List_Iterator end() const {
            return Const_List_Iterator(_tail->_next);
        }

        Const_List_Iterator cbegin() {
            return Const_List_Iterator(_head);
        }

        Const_List_Iterator cend() {
            return Const_List_Iterator(_tail->_next);
        }
    };
}