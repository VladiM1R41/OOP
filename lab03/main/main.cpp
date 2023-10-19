#include "figure.hpp"
#include "rhomb.hpp"
#include "pentagone.hpp"
#include "hexagon.hpp"
#include<iostream>
#include<string.h>

struct Shapes_array {

  private:
    size_t len;
    size_t cap;
    Figure** arr;

    void memory_allocation(size_t new_cap) {
        if (arr == nullptr) {
            return;
        }
        Figure** tmp = new Figure*[len];
        memcpy(tmp, arr, len*sizeof(Figure*));

        delete[] arr;
        arr = new Figure*[new_cap];
        memcpy(arr, tmp, len*sizeof(Figure*));
        cap = new_cap;
    }
  public:
    Shapes_array() noexcept: len(0), cap(0), arr(nullptr){}

    Shapes_array(size_t _len): len(_len), cap(len > 0 ? 2*len : 1), arr(new Figure*[cap]){}

    ~Shapes_array() noexcept {
        if (arr != nullptr) {
            delete[] arr;
            len = 0;
            cap = 0;
            arr = nullptr;
        }
    }
    void erase(size_t index) {
        if (index >= len) {
            return;
        }

        for(int i = index+1; i < len; i++) {
            arr[i-1] = arr[i];
        }
        len--;
    }
    void insert(Figure* elem, int index) {
        if(index > len || index < 0) {
            return;
        }

        if(len == cap) {
            this -> memory_allocation(2*cap);
        }


        len++;
        for(int i = len - 2; i >= index; i--) {
            arr[i+1] = arr[i];
        }
        arr[index] = elem;
    }

    Figure* operator[](size_t index) {
        if(index >= len) {
            return nullptr;
        }

        return arr[index];
    }

    size_t length() {
        return len;
    }
};


int main() {
    Shapes_array arr(0);
    Rhomb r;
    Pentagone p;
    Hexagon h;
    std::cin >> r;
    arr.insert(&r,0);
    std::cin >> p;
    arr.insert(&p,1);
    std::cin >> h;
    arr.insert(&h,2);
    for(int i = 0; i < arr.length(); i++) {
        std::cout << arr[i]->area()<<"\n";
    }

    arr.erase(0);
    for(int i = 0; i < arr.length(); i++) {
        std::cout << arr[i]->perimetr()<<"\n";
    }
}   