#ifndef Fixed_hpp
#define Fixed_hpp
#include <iostream>

class Fixed{

private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed();

    Fixed(const Fixed &other); //copy constructor

    ~Fixed();

    Fixed & operator=(const Fixed &other); //operator overloading

    int getRawBits( void ) const;

    void setRawBits( int const raw );
};
#endif