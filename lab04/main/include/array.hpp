#pragma once
#include "figure.hpp"
#include <memory>
template <class T>
class Array {
private:
    size_t size;
    size_t cap;
    std::shared_ptr<T[]> arr;

    void reallocate(size_t new_cap) {
        std::shared_ptr<T[]> new_arr;

        if(cap >= new_cap) {
        return;
        }

        new_arr = std::shared_ptr<T[]>(new T[new_cap]);
        for(size_t i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }

        arr = new_arr;
        cap = new_cap;
    }  
public:
    Array() = default;
    Array(size_t _size, size_t _cap): size(_size), cap(_cap), arr(std::shared_ptr<T[]>(new T[cap])) {}
    Array(size_t _size): size(_size), cap(size > 0 ? 2*size : 2), arr(std::shared_ptr<T[]>(new T[cap])) {}
    ~Array() = default;


    void insert(size_t index, std::shared_ptr<T> figure)  {
        if(size == cap) {
            this -> reallocate(cap > 0 ? 2*cap : 2);
        }
        ++size;
        for(int i = size - 2; i >= index; --i) {
            arr[i+1] = arr[i]; 
        }
        arr[index] = figure;
    }


    void erase(size_t index)  {
    
        if(size == 0) {
            throw std::logic_error("the array is empty");
        } else if (index >= size) {
            throw std::logic_error("index out of rage");
        } else {
            for(int i = index + 1; i < size; ++i) {
                arr[i-1] = arr[i];
            }
            --size;
        }
    }

    T operator[](size_t index) const  {
        if(index >= size) {
            throw std::logic_error("index out of range");
        }

        return arr[index];
    }

    double total_area() const {
        double total = 0.0;
        for (const auto& figure: arr) {
            if (figure) {
                total += figure->operator double();
            }
        }
        return total;
    }

    size_t length(){
        return size;
    }

};