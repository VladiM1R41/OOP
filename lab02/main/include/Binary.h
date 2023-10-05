#pragma once

#include <string>
#include <iostream>

class Binary
{ 
public:

//Constructors

   Binary();
   Binary(const size_t & n, unsigned char t = 0);
   Binary(const std::initializer_list< unsigned char> &t);
   Binary(const std::string &t);
   Binary(const Binary& other);
   Binary(Binary&& other) noexcept;      
//Methods

   Binary add(const Binary& other);
   Binary remove(const Binary& other);
   bool equals(const Binary& other) const;
   bool is_bigger(const Binary& other) const;
   bool is_smaller(const Binary& other) const;

// Friends

   friend std::ostream& operator<<(std::ostream& os, Binary const & t);

//Destructor

   virtual ~Binary() noexcept;


private:
    int to_decimal() const; //private method for converting to a decimal system
    size_t _size;
    unsigned char* _array;
};