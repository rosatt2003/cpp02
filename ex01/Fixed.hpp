#ifndef Fixed_hpp
#define Fixed_hpp
#include <iostream>

class Fixed{

private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed();

    Fixed(int intValue);

    Fixed(float floatValue);

    Fixed(const Fixed &other); //copy constructor

    ~Fixed();

    Fixed & operator=(const Fixed &other); //copy assignment operator
    
    int getRawBits( void ) const;
    
    void setRawBits( int const raw );
    
    int toInt( void ) const;
    
    float toFloat( void ) const;
};

std::ostream & operator<<(std::ostream &out, const Fixed &fixed);

#endif