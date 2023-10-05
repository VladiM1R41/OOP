#include "Binary.h"


int Binary::to_decimal() const{
    std::string str;

    if (_size > 10) throw std::logic_error("too huge a number");

    for(size_t i = 0;i<_size;i++){ 
        str = char(_array[i]) + str;
    }
    int num =  std::stoi(str);
    int i = 1;
    unsigned res = num % 10;
    num /= 10;

    while (num)
    {
        res = res +  ((num % 10) << i);
        num /= 10;
        ++i;
    }

    return res;
}

Binary::Binary() : _size(0), _array{nullptr}
{
    std::cout << "Default constructor" << std::endl;
}

Binary::Binary(const size_t &n, unsigned char t)
{
    std::cout << "Fill constructor" << std::endl;
    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

Binary::Binary(const std::initializer_list<unsigned char> &t)
{
    std::cout << "Initializer list constructor" << std::endl;
    _array = new unsigned char[t.size()];
    size_t i{0};
    for (auto &c : t)
        _array[i++] = c;
    _size = t.size();
}

Binary::Binary(const std::string &t)
{
    std::cout << "Copy string constructor" << std::endl;
    _array = new unsigned char[t.size()];
    _size  = t.size();

    for(size_t i{0};i<_size;++i) _array[i] = t[i];
}

Binary::Binary(const Binary &other)
{
    std::cout << "Copy constructor" << std::endl;
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
}

Binary::Binary(Binary &&other) noexcept
{
    std::cout << "Move constructor" << std::endl;
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Binary Binary::add(const Binary &other)
{
    std::string res_num;
    int res = to_decimal() + other.to_decimal();
    while(res){
        res_num = res_num + std::to_string(res % 2);
        res /= 2;
    }

    return Binary(res_num);

}

Binary Binary::remove(const Binary &other)
{

    if(_size<other._size) throw std::logic_error("negative number");
    else if(to_decimal() < other.to_decimal()) throw std::logic_error("negative number");

    std::string res_num;
    int res = to_decimal() - other.to_decimal();

    while(res){
        res_num =res_num + std::to_string(res % 2);
        res /= 2;
    }

    return Binary(res_num);
}

bool Binary::equals(const Binary &other) const
{
    return to_decimal() == other.to_decimal();
}

bool Binary::is_bigger(const Binary &other) const
{
    return to_decimal() > other.to_decimal();
}

bool Binary::is_smaller(const Binary &other) const
{
    return to_decimal() < other.to_decimal();
}

std::ostream& operator<<(std::ostream& os, Binary const & t) {
    for (size_t i = 0; i < t._size; ++i) {
        os << t._array[t._size - i - 1];
    }
    return os; 
}

Binary::~Binary() noexcept
{
    _size = 0;
    delete[] _array;
    _array = nullptr;
}